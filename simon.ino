#include <math.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define CFG_DEBOUNCE_DELAY 200
#define CFG_MAX_GAME_LEN 512
#define CFG_DIFF_MIN 50
#define CFG_DIFF_CURVE 15

#define PINOUT_LED_BLU 0
#define PINOUT_SWC_BLU 1
#define PINOUT_LED_RED 2
#define PINOUT_SWC_RED 3
#define PINOUT_LED_YLW 4
#define PINOUT_SWC_YLW 5
#define PINOUT_LED_GRE 6
#define PINOUT_SWC_GRE 7
#define PINOUT_BUZZ A0
#define PINOUT_NOISE A1

#define TONE_BLU 659.26
#define TONE_YLW 277.18
#define TONE_RED 440.00
#define TONE_GRE 329.62

const int clockwise_leds[] = { PINOUT_LED_BLU, PINOUT_LED_YLW, PINOUT_LED_GRE, PINOUT_LED_RED };
const int clockwise_buttons[] = { PINOUT_SWC_BLU, PINOUT_SWC_YLW, PINOUT_SWC_GRE, PINOUT_SWC_RED };
const int clockwise_tones[] = { TONE_BLU, TONE_YLW, TONE_GRE, TONE_RED };

#define CFG_BN_COUNT 4
unsigned long bn_timings[CFG_BN_COUNT], led_timeouts[CFG_BN_COUNT];
unsigned char bn_state[CFG_BN_COUNT], bn_state_old[CFG_BN_COUNT], led_state[CFG_BN_COUNT];

unsigned long ignore_input_timing;
unsigned char ignore_input;

#define QUARTER_TL 0
#define QUARTER_TR 1
#define QUARTER_BL 2
#define QUARTER_BR 3

int turn_number, enter_number;
int combination[CFG_MAX_GAME_LEN];

typedef struct {
	unsigned char index;
	bool down;
	unsigned long timestamp;
} bn_event;

void generate_combination() {
	for (int i = 0; i < CFG_MAX_GAME_LEN; i++)
		combination[i] = random(4);
}

void all_leds(unsigned char state) {
	digitalWrite(PINOUT_LED_BLU, state);
	digitalWrite(PINOUT_LED_GRE, state);
	digitalWrite(PINOUT_LED_RED, state);
	digitalWrite(PINOUT_LED_YLW, state);
}

void boot_animation() {
	for (int i = 0; i < 8; i++) {
		digitalWrite(clockwise_leds[i % 4], HIGH);
		delay(100);
		digitalWrite(clockwise_leds[i % 4], LOW);
	}
	for (int i = 0; i < 2; i++) {
		all_leds(HIGH);
		delay(200);
		all_leds(LOW);
		delay(200);
	}
}

void setup() {
	pinMode(PINOUT_LED_RED, OUTPUT);
	pinMode(PINOUT_LED_GRE, OUTPUT);
	pinMode(PINOUT_LED_YLW, OUTPUT);
	pinMode(PINOUT_LED_BLU, OUTPUT);

	pinMode(PINOUT_BUZZ, OUTPUT);

	pinMode(PINOUT_SWC_RED, INPUT_PULLUP);
	pinMode(PINOUT_SWC_GRE, INPUT_PULLUP);
	pinMode(PINOUT_SWC_YLW, INPUT_PULLUP);
	pinMode(PINOUT_SWC_BLU, INPUT_PULLUP);

	pinMode(PINOUT_NOISE, INPUT); // random noise voor RNG
	randomSeed(analogRead(PINOUT_NOISE));

	delay(500);

	boot_animation();

	// laat de groene led knipperen tot de gebruiker die knop
	// indrukt om het spel te laten beginnen
	for (;;) {
		digitalWrite(PINOUT_LED_GRE, millis() % 1000 < 500);
		if(!digitalRead(PINOUT_SWC_GRE)) break;
	}

	generate_combination();

	digitalWrite(PINOUT_LED_GRE, 0);
	delay(500);

	simon_says();
}

/**
 * @brief difficulty calculator
 * 
 * de uitvoer van deze functie wordt gebruikt om de timing van de simon_says()
 * functie te berekenen. de timing is 2 * x voor de 'aan' periode, en x voor de
 * tijd tussen de 'aan' periode's. x is de uitvoer van deze functie in
 * milliseconden.
 */
unsigned int difficulty() {
	/**
	 * resultaat van max(200 * 0.5^(x/a), b) waar
	 * x = lengte van huidige combinatie
	 * a = hoe snel het spel lastiger wordt
	 * en b = maximale lastigheid
	 *
	 * lagere waardes = lastiger
	 */
	return MAX((int)(200 * pow(0.5, (float) turn_number / CFG_DIFF_CURVE)), CFG_DIFF_MIN);
}

/** @brief laat de combinatie zien die moet worden nagespeeld */
void simon_says() {
	ignore_input = true;
	for (int i = 0; i <= turn_number; i++)
		beep_quarter(combination[i]);
	ignore_input = false;
}

void beep_quarter(unsigned char quarter) {
	unsigned int diff = difficulty();

	digitalWrite(clockwise_leds[quarter], HIGH);
	tone(PINOUT_BUZZ, clockwise_tones[quarter]);
	delay(2 * diff);

	digitalWrite(clockwise_leds[quarter], LOW);
	noTone(PINOUT_BUZZ);
	delay(diff);
}

void bn_scan() {
	memcpy(&bn_state_old, bn_state, sizeof(bn_state_old));
	memset(&bn_state, 0, sizeof(bn_state));

	for (int i = 0; i < CFG_BN_COUNT; i++)
		bn_state[i] = !digitalRead(clockwise_buttons[i]);
}

void bad_press_routine() {
	ignore_input = true;

	unsigned long until = millis() + 2e3;
	while (millis() < until) {
		unsigned long offset = until - millis();
		all_leds(offset % 300 < 150);
		tone(PINOUT_BUZZ, 500 - (offset % 500));
	}
	noTone(PINOUT_BUZZ);
	all_leds(LOW);

	turn_number = 0;
	enter_number = 0;
	generate_combination();
	delay(200);

	simon_says();

	ignore_input = false;
}

/** @brief wordt uitgevoerd voor elke toetsaanslag */
void check_press(int index) {
	// verkeerde toets ingedrukt
	if (combination[enter_number] != index) {
		bad_press_routine();
		return;
	}

	// als alle toetsen in de goede volgorde zijn ingetoetst
	if(enter_number == turn_number) {
		turn_number++;

		// zorg dat er geen index out of bounds error kan gebeuren door uit te gaan
		if (turn_number == CFG_MAX_GAME_LEN) {
			all_leds(LOW);
			for(;;) {}
		}

		// laat de nieuwe combinatie zien
		enter_number = 0;
		delay(200);
		all_leds(LOW);
		delay(500);
		simon_says();
		return;
	}

	// als nog niet alle toetsen ingetoetst zijn
	enter_number++;
}

void bn_onevent(bn_event ev) {
	// stop gelijk als ignore_input aan is of het een key up event is
	if (ignore_input || !ev.down) return;

	// debounce correctie
	bool bounce = bn_timings[ev.index] + CFG_DEBOUNCE_DELAY > millis();
	bn_timings[ev.index] = ev.timestamp;
	if (bounce) return;

	// als er een toets ingedrukt wordt
	led_set_timeout(ev.index, 200);
	tone(PINOUT_BUZZ, clockwise_tones[ev.index], 200);
	ignore_input_for(200);

	check_press(ev.index);
}

void bn_event_gen() {
	for(int i = 0; i < CFG_BN_COUNT; i++) {
		if (bn_state[i] == bn_state_old[i]) continue;

		bn_event event = {
			.index = (unsigned char) i,
			.down = bn_state[i],
			.timestamp = millis()
		};

		bn_onevent(event);
	}
}

/** @brief helper voor timeout variabelen */
void set_timeout(unsigned char *state_ref, unsigned long *timeout_ref, unsigned long duration_millis) {
	*timeout_ref = millis() + duration_millis;
	*state_ref = 1;
}

void led_set_timeout(unsigned int led, unsigned long duration_millis) {
	set_timeout(&led_state[led], &led_timeouts[led], duration_millis);
	digitalWrite(clockwise_leds[led], HIGH);
}

void ignore_input_for(unsigned long duration_millis) {
	set_timeout(&ignore_input, &ignore_input_timing, duration_millis);
}

/** @brief update alle timers */
void timer_update() {
	unsigned long current_time = millis();

	// led update
	for (int i = 0; i < CFG_BN_COUNT; i++) {
		if (led_timeouts[i] > current_time) continue;
		if (led_state[i] == 0) continue;
		led_state[i] = 0;
		digitalWrite(clockwise_leds[i], LOW);
	}

	// input ignore mode
	if (ignore_input == 1 && current_time > ignore_input_timing) ignore_input = 0;
}

void loop() {
	bn_scan();
	bn_event_gen();
	timer_update();
}

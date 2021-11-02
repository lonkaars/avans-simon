/**
 * Simon game based on this wikipedia article:
 * https://en.wikipedia.org/wiki/Simon_(game)
 */

#define CFG_DEBOUNCE_DELAY 200
#define CFG_MAX_GAME_LEN 512

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

#define TONE_BLU 329.63
#define TONE_YLW 277.18
#define TONE_RED 440.00
#define TONE_GRE 164.81

const int clockwise_leds[] = { PINOUT_LED_BLU, PINOUT_LED_YLW, PINOUT_LED_GRE, PINOUT_LED_RED };
const int clockwise_buttons[] = { PINOUT_SWC_BLU, PINOUT_SWC_YLW, PINOUT_SWC_GRE, PINOUT_SWC_RED };
const int clockwise_tones[] = { TONE_BLU, TONE_YLW, TONE_GRE, TONE_RED };

#define CFG_BN_COUNT 4
unsigned long bn_timings[CFG_BN_COUNT], led_timeouts[CFG_BN_COUNT];
unsigned char bn_state[CFG_BN_COUNT], bn_state_old[CFG_BN_COUNT], led_state[CFG_BN_COUNT];

#define QUARTER_TL 0
#define QUARTER_TR 1
#define QUARTER_BL 2
#define QUARTER_BR 3

int turn_number;
int entered;
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

	pinMode(PINOUT_NOISE, INPUT); // random noise channel for RNG
	randomSeed(analogRead(PINOUT_NOISE));
}

void bn_scan() {
	memcpy(&bn_state_old, bn_state, sizeof(bn_state_old));
	memset(&bn_state, 0, sizeof(bn_state));

	for (int i = 0; i < CFG_BN_COUNT; i++)
		bn_state[i] = !digitalRead(clockwise_buttons[i]);
}

void bn_onevent(bn_event ev) {
	if (ev.down) {
		bool bounce = bn_timings[ev.index] + CFG_DEBOUNCE_DELAY > millis();
		bn_timings[ev.index] = ev.timestamp;
		if (bounce) return;
	}

	if (ev.down) {
		led_set_timeout(ev.index, 200);
		tone(PINOUT_BUZZ, clockwise_tones[ev.index], 200);
	}
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

void led_set_timeout(unsigned int led, unsigned long duration_millis) {
	led_timeouts[led] = millis() + duration_millis;
	led_state[led] = 1;
	digitalWrite(clockwise_leds[led], HIGH);
}

void led_update() {
	unsigned long current_time = millis();

	for (int i = 0; i < CFG_BN_COUNT; i++) {
		if (led_timeouts[i] > current_time) continue;
		if (led_state[i] == 0) continue;
		led_state[i] = 0;
		digitalWrite(clockwise_leds[i], LOW);
	}
}

void loop() {
	bn_scan();
	bn_event_gen();
	led_update();
}

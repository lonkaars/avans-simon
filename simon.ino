#include <math.h>

#define PINOUT_LED_BLU 0
#define PINOUT_SWC_BLU 1
#define PINOUT_LED_RED 2
#define PINOUT_SWC_RED 3
#define PINOUT_LED_YLW 4
#define PINOUT_SWC_YLW 5
#define PINOUT_LED_GRE 6
#define PINOUT_SWC_GRE 7

#define PINOUT_BUZZ A0

void setup() {
	pinMode(PINOUT_LED_RED, OUTPUT);
	pinMode(PINOUT_LED_GRE, OUTPUT);
	pinMode(PINOUT_LED_YLW, OUTPUT);
	pinMode(PINOUT_LED_BLU, OUTPUT);
	pinMode(PINOUT_BUZZ, OUTPUT);
}

int gert = 0;
float freq = 0;

int leds[] = { PINOUT_LED_BLU, PINOUT_LED_GRE, PINOUT_LED_YLW, PINOUT_LED_RED };

void loop() {
	freq = ( freq + 0.01 );
	if(freq > M_PI * 2) freq = 0;
	double freq2 = sin(freq) * 500 + 500;
	tone(PINOUT_BUZZ, (int) freq2);
	Serial.println(digitalRead(6), DEC);
	gert = (gert + 1) % 4;
	digitalWrite(leds[gert], HIGH);
	delay(10);
	digitalWrite(leds[gert], LOW);


}

/**
 * @brief Your main class
 * @author
 * @version
 */

#include "main.h"

/**
 * Calculates the distance to stop, before crashing an object
 *
 * @param distance the current distance to an object
 * @param speed the current speed
 *
 * @return true, if the nibo should stop driving, false otherwise
 */
bool stop(int distance, int speed) {
	int stop_distance_diff = ((float) speed * 0.75) * 112.93 / 40.0;
	int stop_distance = 247 - stop_distance_diff;
	return stop_distance <= distance;
}

/**
 * Displays the current speed on Display
 *
 * @param speed the speed to be displayed
 */
void displaySpeed(int speed) {
	// Display leeren
	gfx_fill(0);

	// Beschreibung
	gfx_move(0, 0);
	gfx_print_text("Speed");

	// Ausgabe
	char output[20] = "";
	sprintf(output, "%3i", speed);
	gfx_move(23 * 0, 10);
	gfx_print_text(output);
}

/**
 * inits all components
 */
void init() {
	// Aktivierung von Interrupts
	sei();

	// Initialisierung des Roboters (immer noetig)
	bot_init();

	// Initialisierung der SPI Schnittstelle
	spi_init();

	// Initialisierung der LEDs
	leds_init();

	// initialisiert das Display und die Grafikfunktionen
	display_init(DISPLAY_TYPE_TXT);
	gfx_init();

	// Distanzmessung anschalten
	copro_ir_startMeasure();
}

/**
 * Main Method of the program.
 */
int main() {
	init();

	int current_distance = 0;
	int speed = 5;
	displaySpeed(speed);

	while (1) {

		// Aktualisierung aller Daten vom Coprozessor
		copro_update();

		current_distance = copro_distance[2] / 256;

		if (stop(current_distance, speed)) {
			copro_stop();
		} else {
			copro_setSpeed(speed, speed);
		}

		if (s3_was_pressed()) {
			if (speed == 100) {
				speed = 0;
			}
			speed += 5;
			displaySpeed(speed);
		}

//		delay(10);

	}

}


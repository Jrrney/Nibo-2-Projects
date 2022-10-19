/**
 * @brief Your main class
 * @author
 * @version
 */

#include "main.h"

/**
 * calculates a color from distance to the object
 * @param distance to the object
 * @return calulates color
 */
int getDistanceColor(int distance) {
	// very close
	if (distance > 200) {
		return LEDS_RED;
	} else
	// close
	if (distance > 75) {
		return LEDS_ORANGE;
	} else
	// far away
	{
		return LEDS_GREEN;
	}
}

/**
 * shows distance via leds
 *
 * @param distance to an object
 * @param sensor the id of the distance given sensor
 */
void showDistance(int distance, int sensor) {
	int distance_color = getDistanceColor(distance);

	switch (sensor) {
	case 0:
		leds_set_status(distance_color, 7);
		break;
	case 1:
		leds_set_status(distance_color, 6);
		break;
	case 2:
		leds_set_status(distance_color, 5);
		leds_set_status(distance_color, 4);
		break;
	case 3:
		leds_set_status(distance_color, 3);
		break;
	case 4:
		leds_set_status(distance_color, 2);
		break;
	default:
		break;
	}
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

	// Ausgabetext
	char output[20] = "";

	//
	int current_distance;

	while (1) {

		// Display leeren
		gfx_fill(0);

		// Beschreibung
		gfx_move(0, 0);
		gfx_print_text("Distanzen");

		// Aktualisierung aller Daten vom Coprozessor
		copro_update();

		for (int i = 0; i < 5; i++) {
			current_distance = copro_distance[i] / 256;
			showDistance(current_distance, i);

			// Ausgabe
			sprintf(output, "%3i", current_distance);
			gfx_move(23 * i, 10);
			gfx_print_text(output);
		}

	delay(200);

	}

}


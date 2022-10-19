/*
 ============================================================================
 Name        : helloFloor.c
 Author      : Daniel Wittekind
 Version     : 1.0
 Description : Auslesen der Bodensensoren des Nibo2
 ============================================================================
 */
// Standard Includes fuer das Funktionieren des Nibo2
#include <nibo/niboconfig.h>
#include <nibo/iodefs.h>
#include <nibo/bot.h>

// Bibliothek zum Ansteuern des Display
#include <nibo/display.h>

// Bibliothek mit Grafikfunktionen
#include <nibo/gfx.h>

// Bibliothek fuer Bodensensoren
#include <nibo/floor.h>

// Wartefunktionen
#include <nibo/delay.h>

// Ein- und Ausgabefunktionen
#include <stdio.h>

#include <stdbool.h>

// Coprozessorfunktionen einbinden, da dieser die Motoren steuert
#include <nibo/copro.h>

// Kommunikationsfunktionen fuer die SPI Schnittstelle zum Coprozessor
#include <nibo/spi.h>

#define WHITE(floor) floor > 1000

int main() {

	// Initialisierung des Roboters (immer noetig)
	bot_init();

	// initialisiert das Display und die Grafikfunktionen
	display_init(DISPLAY_TYPE_TXT);
	gfx_init();

	// initialisiert die Bodensensorfunktionen
	floor_init();

	// Initialisierung der SPI Schnittstelle
	spi_init();

	// Variable fuer Ausgabetext
	char output[10] = "";

	// speichert die Sensorwerte
	unsigned int front_left_floor = 0;
	unsigned int front_right_floor = 0;

	// Display leeren
	gfx_fill(0);

	// Endlosschleife
	while (1 == 1) {

		// fragt die aktuellen Werte der Bodensensoren ab
		floor_update();

		gfx_move(0, 36);

		// beschreibende Ausgabe
		gfx_print_text("Front");
		gfx_move(0, 45);

		front_right_floor = floor_relative[FLOOR_RIGHT];

		// Ausgabe
		sprintf(output, "rel R %4u ", front_right_floor);
		gfx_print_text(output);

		// linken Sensor vorn abfragen
		front_left_floor = floor_relative[FLOOR_LEFT];

		sprintf(output, "rel L %4u ", front_left_floor);
		gfx_move(64, 45);
		gfx_print_text(output);

		if(WHITE(front_left_floor) && WHITE(front_right_floor)){
			copro_stop();
		} else {
			copro_setSpeed(-12, -12);
		}

		delay(300);
	}

}


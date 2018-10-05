/********************************************************************
Autor/en		:	T. Vandrey
Datum			:
Version			:	1
Datei			:	latex_eingabe_colorschemes.h
Dateifunktion	:	Escapesequenzen zur Vereinfachung als Strings speichern und bereitstellen

Kurzbeschreibung:
n.A.
********************************************************************/
// Für einmaliges Verlinken der Datei
#pragma once

// Farben- Escapesequenzen
#define ANSI_COLOR_RED     "\x1b[31m"	// ROT
#define ANSI_COLOR_GREEN   "\x1b[32m"	// GRÜN
#define ANSI_COLOR_YELLOW  "\x1b[33m"	// GELB
#define ANSI_COLOR_BLUE    "\x1b[34m"	// BLAU
#define ANSI_COLOR_MAGENTA "\x1b[35m"	// MAGENTA
#define ANSI_COLOR_CYAN    "\x1b[36m"	// CYAN

// Reset der Nutzung der Farbpalette
#define ANSI_COLOR_RESET   "\x1b[0m"

// Beipiel in der Nutzung:
/*
	Code:
	printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_RESET "\n");

	Folgen: Der Text wird Rot angezeigt
*/
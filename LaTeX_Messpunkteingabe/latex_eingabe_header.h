/********************************************************************
Autor/en		:	T. Vandrey
Datum			:
Version			:	1
Datei			:	latex_eingabe_header.h
Dateifunktion	:	Prototypen, Symb. Konstanten, etc. vordefiniert

Kurzbeschreibung:
n.A.
********************************************************************/
// F�r einmaliges Verlinken der Datei
#pragma once

//	148 = �
//	129 = �
//	132 = �
//	196 = Durchgehender Strich aber in der Mitte ( _ )
//	248 = Durchgehender Doppelstrich [...] ( = )

//===[ Symbolische Konstanten ]=======================================================================================================
#define _CRT_SECURE_NO_WARNINGS					// Keine Fehlermeldung bei Nichtnutzung von scanf_s(), etc.
#define PI 3.14159265358979						// Pee
#define E 2.718281828459045						// Euler'sche Zahl
#define CONSOLE_HEIGHT 25						// Konsolenh�he Standard: 25
#define CONSOLE_WIDTH 80						// Konsolenbreite Standard: 80

#define MAX_MEASUREMENTS 100					// Maximale Anzahl an Messwerten/-punkten
#define STD_STRLEN 50							// Hier Standardl�nge f�r Strings (f�r die Labels/Bezeichnungen der Tabelle)

#define FILENAME_FORM_DATA "user_data.txt"				// Name f�r Datei (formatierte Daten) // Variabel
#define FILENAME_BIN_DATA "bin_data.vledat"				// Name f�r Datei (gespeicherte Daten) // Variabel // Datenpunkte- und werte
#define FILENAME_SET_CONFIG "bin_config.vleset"			// Name f�r Datei (Gespeicherte Einstellungen)
#define FILENAME_LATEX_CODE "latex_code.txt"			// Name f�r Datei (LaTeX- Code)
#define FOLDERNAME "VLE - Eingegebene Daten"				// Name f�r den Ordner, in dem die Dateien abgespeichert werden

#define STOPP stopp();							// Stoppt das Programm mit bestimmter Ausgabe auf der Konsole (um es anschaulicher zu machen)
#define NEWLINE printf("\n");					// Setzt den Cursor auf die n�chste Linie in der Konsole
#define HEADER disp_header(0);
#define HEADER_HELP disp_header(1);

#define TITLE_V "VLE - Vereinfachte LaTeX- Tabelleneingabe (v 1.4)"	// Titel mit Versionsnummer
#define TITLE "VLE - Vereinfachte LaTeX- Tabelleneingabe"			// Titel
#define VERSIONNUM "v 1.4"						// Versionsnummer

//===[ Enumerationen, Typdefinitionen, etc. ]=========================================================================================
typedef int bool;			// Anlegen des bool'schen Datentyps
enum { false, true };		// Dazugeh�rige false-/true- Enumerationen

enum { decpts_both, decpts_dataval_only, decpts_datapts_only, decpts_none };	// Enumeration f�r decpts_status- Einstellung

//===[ Strukturen ]===================================================================================================================
struct paireddata
{
	double data_point;
	double data_value;
};

struct config_container
{
	int data_nb;					// Anzahl der Datens�tze

	int decpts_nb;					// Dezimalstellen nach dem Komma
	int decpts_status;				// Dezimalstellenanzeige
	
	int column_nb;					// Anzahl der Spaltenpaare
	int column_lim;					// Grenze der Reihen, bis wohin ein Spaltenpaar gehen soll

	bool has_label;					// Ob die LaTeX- Tabelle eine Bezeichnung hat


	// LaTeX- Bezeichnungen und Namen
	char label1[STD_STRLEN];		// Label linke Spalte
	char label2[STD_STRLEN];		// Label rechte Spalte
	char label_tabular[STD_STRLEN];	// Label der gesamten Tabelle

};

typedef struct paireddata datenpaar;
typedef struct config_container config;

//===[ Einzubindende Bibliotheken ]===================================================================================================
#include <stdlib.h>			// Standard Lib
#include <stdio.h>			// Standard Input/Output
#include <stdarg.h>			// Funktionen f�r main()- function- Argumente
#include <string.h>			// String- Funktionen
#include <math.h>			// Mathematische Funktionen
#include <windows.h>		// Windowsspezifische Funktionen (z.B. System(), Sleep(), etc.)
#include <conio.h>			// Advanced Input/Output
#include <time.h>			// F�r (Pseudo-)Zufallszahlen, Zeiten kontrollieren, etc.		--> Zur Nutzung am Anfang der main()- Funktion einmal "srand((unsigned)time(NULL));" aufrufen

// ???
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <ResourceIndexer.h>
#include <wincon.h>

// Eigener Header f�r Farbcodes
#include "latex_eingabe_colorschemes.h"

//===[ Funktionsprototypen ]==========================================================================================================

//--<Standardfunktionen>-------------------------------------------------------------------------------------
void flashStandardInput(void);			// Leert den Eingabepuffer
void stopp(void);						// Vereinfachtes Anhalten des Programms (zwecks Debugging)

//--<Kosmetische Funktionen>---------------------------------------------------------------------------------
int drawLineCustom_adv(char, char, int);			// Linie �ber die Konsole ziehen, erweiterte Funktionen
void drawLineCustom(char);							// Linie �ber die Konsole ziehen
void setConsoleColor(void);							// Ver�ndert Farbe(n) der Konsole // Hier: Voreingestellt auf Graue Schrift, Schwarzer Hintergrund !!
void disp_header(bool showHelp);					// Gibt den "Header" des Programms aus
void disp_header_custom(char custom_string[39]);	// Gibt den "Header" des Programms mit dem eingegebenen Parameterstring als Zusatz am Ende der Zeile aus


//--<Eingabefunktionen>--------------------------------------------------------------------------------------
int menu_safe_input(int lower_boundary, int upper_boundary);	// Sichere Eingabe von Men�punkten bzw. Nummern von 0-9
int menu_safe_input_2(int lower_boundary, int upper_boundary);	// Sichere Eingabe von Men�punkten bzw. Nummern von 0-9

int menu_main(void);											// Hauptmen�
int menu_input(void);											// Men� f�r den Eingabemodus der Eingabe

void data_input_prime(double measurements[MAX_MEASUREMENTS][2], char* currDir, config* user_config_pt);		// Hauptfunktion Dateneingabe
int data_input_mode1(double measurements[100][2], int* data_nb_p);															// Dateneingabe: Modus 1
int data_input_mode2(double measurements[100][2], int* data_nb_p);															// Dateneingabe: Modus 2

bool data_change(double[MAX_MEASUREMENTS][2], int decpts, int decpts_status, int* data_nb_p);	// Daten ver�ndern (Eingegebene Messdaten)

void data_recreate(double measurements[MAX_MEASUREMENTS][2], config user_config, char* currDir, bool* data_changed_pt);

int decpts_input(int dec_ima);	// Eingabefunktion f�r Dezimalstellen nach dem Komma

void label_input(char* label1_buffer, char* label2_buffer, char* label_tabular_buffer);
void label_input_fract_tabular(char* label_tabular_buffer);
void label_input_fract_columns(char* label1_buffer, char* label2_buffer);
void toggle_decpts(int* decpts_pointer);

//--<Ausgabefunktionen>--------------------------------------------------------------------------------------
void disp_help(void);																								// Hilfe anzeigen
void disp_help_settings(void);																						// Hilfemen� f�r Einstellungen
void disp_settings_main(config user_config);																		// Eingestellte Einstellungen anzeigen, als eigenst�ndige Anzeige
void disp_settings_funct(config user_config);																		// (" - - "), Innerhalb einer anderen Funktion

void data_output_main(double[MAX_MEASUREMENTS][2], int decimalpoints, int decpts_status, int* data_nb_p);							// Datenausgabe im Hauptmen�
void data_output_funct(double[MAX_MEASUREMENTS][2], int decimalpoints, int decpts_status, int* data_nb_p);							// Datenausgabe aus Programmspeicher (in Funktionen)
void data_rearrange(double measurements[MAX_MEASUREMENTS][2], int decpts, int decpts_status, bool* data_changed, int* data_nb_p);	// Daten neu ordnen

//--<Dateifunktionen>----------------------------------------------------------------------------------------
void data_save_formatted(double arrayToSave[MAX_MEASUREMENTS][2], char* currDir, int decpts, int decpts_status, int* data_nb_p);	// Speichert die eingegebenen Messdaten in eine *.txt- Datei in der Art und Weise, wie sie zusammengeh�ren
int data_save_bin(double arrayToSave[MAX_MEASUREMENTS][2], char* currDir, int decpts, int* data_nb);								// Speichert die eingegebenen Daten bin�r ein um sie sp�ter wieder einlesen zu k�nnen
void data_save_latex(double measurements[MAX_MEASUREMENTS][2], char* currDir, config config_container);				// Erstellt eine LaTeX- Datei mit den eingegebenen (sich im Speicher befindenden) Daten
config data_load(double arrayToSave[MAX_MEASUREMENTS][2], char* currDir, config config_container);					// L�dt die entsprechenden Daten, falls vorhanden
void data_save_config(char* currentDirectory, config config_container);

//--<Weitere>------------------------------------------------------------------------------------------------
int getCountNumb(double measurements[MAX_MEASUREMENTS][2]);					// Ermittelt die Anzahl der eingegebenen Messdaten
void remove_newline(char string[50]);										// Entfernt das '\n' und/oder '\0' aus einem String (am Ende) (Praktisch f�r fputs())

double safe_input_double(void);			// Eine sichere Eingabe einer Zahl + M�glichkeit, ein Komma (',') anstatt eines Punktes f�r die Eingabe einer Zahl zu nutzen (praktisch f�r deutsche Tastaturen (QWERTZ) // Gibt bei Fehler eine Fehlermeldung aus und return 0 // Normale Version, nur mit Fehlerausgabe falls keine Zahl eingegeben wurde

//--<Zwielichtige Funktionen usw. aus dem Internet>----------------------------------------------------------

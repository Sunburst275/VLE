/********************************************************************
Autor/en		:	T. Vandrey
Datum			:
Version			:	1
Datei			:	latex_eingabe_header.c
Dateifunktion	:	Funktionen und weiteres für Header- Datei (latex_eingabe_header.h)

Kurzbeschreibung:
n.A.
********************************************************************/

//===[ Einzubindende Bibliotheken ]===================================================================================================
#include "latex_eingabe_header.h"

//===[ Funktionsdeklarierung ]========================================================================================================

//--<Standardfunktionen>-------------------------------------------------------------------------------------
void flashStandardInput(void)
{
	int intCharacter;
	while ((intCharacter = fgetc(stdin)) != '\n' && intCharacter != EOF);

	// Wenn nichts im Eingabepuffer ist, und diese Funktion aufgerufen wird, krüppelt sie, hält das Programm an und verlangt nach einer Eingabe. Also Achtung!
}

void stopp(void)
{
	printf("\n");
	drawLineCustom(196);
	system("pause");
}

//--<Kosmetische Funktionen>---------------------------------------------------------------------------------
int drawLineCustom_adv(char input, char input_2, int length)
{
	const int stdlength = 80;



	// Zweites Zeichen != 0 -> Es wird mit ausgegeben:
	//	- Mit angegebener Länge (= Länge * 2)
	//	- Ohne angegebene Länge (= Standardlänge)
	if ((int)input_2 == 0)
	{

		// Wenn spez. Länge nicht angegeben (== 0) -> Ziehe Linie mit Standardlänge
		if (length == 0)
		{
			for (int i = 0; i < stdlength; i++)
			{
				printf("%c", input);
			}
		}

		// Wenn spez. Länge angegeben -> Nutze angegebene Länge (int length)
		if (length != 0)
		{
			for (int i = 0; i < length; i++)
			{
				printf("%c", input);
			}
		}
	}


	// Zweites Zeichen == 0 -> Es wird nicht mit ausgegeben:
	//	- Mit angegebener Länge (= Länge)
	//	- Ohne angegebene Länge (= Standardlänge)
	if ((int)input_2 != 0)
	{
		// Wenn spez. Länge nicht angegeben (== 0) -> Ziehe Linie mit Standardlänge
		if (length == 0)
		{
			for (int i = 0; i < stdlength; i++)
			{
				printf("%c", input);
				printf("%c", input_2);
			}
		}

		// Wenn spez. Länge angegeben -> Nutze angegebene Länge (int length)
		if (length != 0)
		{
			for (int i = 0; i < length; i++)
			{
				printf("%c", input);
				printf("%c", input_2);
			}
		}
	}

	// Sonst Fehlerwert ausgeben (-1)
	else
	{
		return -1;
	}

	// Alles gut verlaufen = Nullwert zurückgeben
	return 0;

}

void drawLineCustom(char symb)
{
	int length = 80;

	for (int i = 0; i < length; i++)
	{
		printf("%c", symb);
	}
	NEWLINE
}

void setConsoleColor(void)
{
	/*
	Erstes Bit: Hintergrund
	Zweites Bit: Schrift

	0 = Black
	1 = Blue
	2 = Green
	3 = Aqua
	4 = Red
	5 = Purple
	6 = Yellow
	7 = White
	8 = Gray
	9 = Light Blue
	A = Light Green
	B = Light Aqua
	C = Light Red
	D = Light Purple
	E = Light Yellow
	F = Bright White
	*/

	system("color 08");
	return;

}

void disp_header(bool showHelp)
{
	char headerLine[CONSOLE_WIDTH] = { 0 },
		headerLineHelp[CONSOLE_WIDTH] = { 0 };

	//printf("VLE - Vereinfachte LaTeX- Tabelleneingabe\n");

	strcpy(headerLine, "VLE - Vereinfachte LaTeX- Tabelleneingabe");
	strcpy(headerLineHelp, "VLE - Vereinfachte LaTeX- Tabelleneingabe");

	// fputs gibt nur den String bis zum Endezeichen ("\0" bzw. "\n") aus, deswegen müssen alle Zeichen vor dem "Hilfe" zu Leerzeichen konvertiert werden.
	for (int i = 41; i < 74; i++)
	{
		headerLineHelp[i] = 32;
	}

	// "Hilfe" wird eingespeist
	headerLineHelp[CONSOLE_WIDTH - 1 - 5] = 'H';
	headerLineHelp[CONSOLE_WIDTH - 1 - 4] = 'i';
	headerLineHelp[CONSOLE_WIDTH - 1 - 3] = 'l';
	headerLineHelp[CONSOLE_WIDTH - 1 - 2] = 'f';
	headerLineHelp[CONSOLE_WIDTH - 1 - 1] = 'e';

	// Ausgabe
	system("cls");

	if (!showHelp)
	{
		fputs(headerLine, stdout);
		printf("\n");
	}
	else
	{
		fputs(headerLineHelp, stdout);
		printf("\n");
	}

	drawLineCustom(196);
}

void disp_header_custom(char custom_string[39])
{
	char headerLineCustom[CONSOLE_WIDTH] = { 0 };

	int headerStringLength = 0,
		z = 0;

	//printf("VLE - Vereinfachte LaTeX- Tabelleneingabe\n");

	strcpy(headerLineCustom, "VLE - Vereinfachte LaTeX- Tabelleneingabe");

	headerStringLength = (int)strlen(custom_string);


	// fputs gibt nur den String bis zum Endezeichen ("\0" bzw. "\n") aus, deswegen müssen alle Zeichen vor dem "Custom String" zu Leerzeichen konvertiert werden.
	for (int i = 41; i < 80; i++)
	{
		headerLineCustom[i] = 32;
	}


	// "Custom String" wird eingespeist
	for (int i = CONSOLE_WIDTH - (headerStringLength + 2); i < CONSOLE_WIDTH; i++)
	{
		headerLineCustom[i] = custom_string[z];
		z++;
	}

	// Ausgabe
	system("cls");


	fputs(headerLineCustom, stdout);
	printf("\n");


	drawLineCustom(196);
}

void disp_cat(char displine[79])
{
	system("cls");

	// Ausgabe
	fputs(displine, stdout);
	printf("\n");

	drawLineCustom(196);
}

//--<Eingabe-/Ausgabefunktionen>-----------------------------------------------------------------------------
int menu_safe_input(int lower_boundary, int upper_boundary)
{
	char input[3] = { 0 };
	char input_processed = 0;

	int output = 0;
	bool check = false;

	do
	{
		do
		{

			fflush(stdin);

			fgets(input, 2, stdin);			// Als String einlesen

			input_processed = input[0];		// Erstes Zeichen auswerten

			switch (input_processed)
			{
			default:				check = 0; break;
			case (48): output = 0;	check = 1; break;
			case (49): output = 1;	check = 1; break;
			case (50): output = 2;	check = 1; break;
			case (51): output = 3;	check = 1; break;
			case (52): output = 4;	check = 1; break;
			case (53): output = 5;	check = 1; break;
			case (54): output = 6;	check = 1; break;
			case (55): output = 7;	check = 1; break;
			case (56): output = 8;	check = 1; break;
			case (57): output = 9;	check = 1; break;
			case(0):   output = 0;	check = 1; break;
			}

			flashStandardInput();		// Rest aus dem stdin in den Müll // Wenn er nochmal fgets() machen muss, hält er an, und liest nicht einfach ein, weil der stdin dann leer ist

		} while (!check);
	} while (output < lower_boundary || output > upper_boundary);

	return output;
}

int menu_safe_input_2(int lower_boundary, int upper_boundary)
{
	char input = 0;
	int output = 0;
	bool check = false,
		check_already = false;

	do
	{
		do
		{

			fflush(stdin);

			while (!_kbhit())
			{
				//scanf("%c", &input);
				//check_already = 1;

				input = (char)_getch();

				switch (input)
				{
				default:				check = 0; break;
				case (48): output = 0;	check = 1; break;
				case (49): output = 1;	check = 1; break;
				case (50): output = 2;	check = 1; break;
				case (51): output = 3;	check = 1; break;
				case (52): output = 4;	check = 1; break;
				case (53): output = 5;	check = 1; break;
				case (54): output = 6;	check = 1; break;
				case (55): output = 7;	check = 1; break;
				case (56): output = 8;	check = 1; break;
				case (57): output = 9;	check = 1; break;
				case(0):   output = 0;	check = 1; break;
				}
			}

		} while (!check);
	} while (output < lower_boundary || output > upper_boundary);

	return output;
}

int menu_main(void)
{
	int userInput = -1; // Indiziert, dass noch nichts eingegeben wurde

	disp_cat(CAT_MAIN);

	printf("Was m%cchten Sie tun?\n\n", 148);
	printf("<1>\tDaten eingeben\n");
	printf("<2>\tDaten ausgeben\n");
	printf("<3>\tDaten ver%cndern\n", 132);
	printf("<4>\tDaten ordnen\n");
	printf("<5>\tDateien (neu) erstellen\n");
	NEWLINE

		printf("<8>\tHilfe\n");
	printf("<9>\tEinstellungen\n");
	printf("<0>\tProgramm beenden\n\n");
	printf("Ihre Eingabe:\t");

	userInput = menu_safe_input(0, 9);

	return userInput;
}

int menu_input(void)
{
	int userInput = -1;

	printf("Wie m%cchten Sie die Daten eingeben?\n\n", 148);
	printf("<1>\tDatenpunkt + Datenwert\n");
	printf("<2>\tAlle Datenpunkte, dann alle Datenwerte\n");
	printf("<0>\tAbbruch\n\n");
	printf("Ihre Eingabe:\t");

	userInput = menu_safe_input(0, 2);

	/*do
	{
		printf("Ihre Eingabe:\t");
		scanf("%i", &userInput);
	} while (userInput == -1 && userInput != 0 && userInput != 1 && userInput != 2);*/

	return userInput;
}

void disp_help(void)
{

	int userInput = -1; // Noch nichts eingegeben

	do
	{

		disp_cat(CAT_MAIN_HELP);

		printf("Welchen Punkt w%crden Sie gerne erkl%crt haben?\n\n", 129, 132);

		printf("<1>\tDaten eingeben\n");
		printf("<2>\tDaten ausgeben\n");
		printf("<3>\tDaten ver%cndern\n", 132);
		printf("<4>\tDaten ordnen\n");
		printf("<5>\tDateien (neu) erstellen\n");
		printf("<8>\t%cber das Programm\n", 154);
		printf("<9>\tEinstellungen\n");

		printf("\n<0>\tZur%cck\n\n", 129);

		printf("Ihre Wahl:\t");

		userInput = menu_safe_input(0, 9);

		// HILFE: Daten einlesen
		if (userInput == 1)
		{
			disp_cat(CAT_MAIN_HELP_DATAINPUT);

			printf("Daten eingeben:\n\n");
			printf("Daten k%cnnen direkt eingegeben und eingespeichert werden.\nDabei kann man aus zwei Modi w%chlen:\n\n- Datenwerteingabe direkt folgend auf Datenpunkteingabe\n- Erst alle Datenpunkte eingeben, dann alle entsprechenden Datenwerte\n", 148, 132);
			STOPP
		}

		// HILFE: Daten ausgeben
		if (userInput == 2)
		{
			disp_cat(CAT_MAIN_HELP_DATAOUTPUT);

			printf("Daten ausgeben:\n\n");
			printf("Stellt die eingegebenen Datenpunkte/-werte formatiert in der Konsole dar.\nWenn noch keine Werte eingegeben wurden oder keine Datei existiert, wird dies\nangezeigt.\n");
			STOPP
		}

		// HILFE: Daten ändern
		if (userInput == 3)
		{
			disp_cat(CAT_MAIN_HELP_DATACHANGE);

			printf("Daten %cndern:\n\n", 132);
			printf("Hier kann man die Daten (die man eingegeben\noder aus einer Datei geladen hat) %cndern.\n", 132);
			STOPP
		}

		// HILFE: Daten ordnen
		if (userInput == 4)
		{
			disp_cat(CAT_MAIN_HELP_DATAREARRANGE);

			printf("Daten ordnen:\n\n");
			printf("Sie k%cnnen Ihre eingegebenen Daten ordnen lassen. Es gibt vier M%cglichkeiten:\n\n", 148, 148);
			printf("1)\tNach Datenpunkten in aufsteigender Reihenfolge ordnen\n");
			printf("2)\tNach Datenpunkten in absteigender Reihenfolge ordnen\n");
			printf("3)\tNach Datenwerten in aufsteigender Reihenfolge ordnen\n");
			printf("4)\tNach Datenwerten in absteigender Reihenfolge ordnen\n");
			NEWLINE
				STOPP
		}

		// HILFE: Dateien (neu) erstellen
		if (userInput == 5)
		{
			disp_cat(CAT_MAIN_HELP_REBUILD);

			printf("Dateien (neu) erstellen:\n\n");
			printf("Die Dateien \""FILENAME_FORM_DATA"\" und \""FILENAME_LATEX_CODE"\" k%cnnen hier\nseparat generiert werden. Vor Erstellung wird nocheinmal nachgefragt,\nob die Einstellungen und die eingegebenen Daten stimmen.\n", 148);
			STOPP
		}

		// HILFE: Über das Programm
		if (userInput == 8)
		{
			disp_cat(CAT_MAIN_HELP_ABOUT);

			printf("%cber das Programm:\n\n", 154);
			//printf("In dieses Programm k%cnnen Sie Ihre Datenwerte eingeben.\nEs wird ein Ordner mit zwei Dateien erstellt:\n- measured_data.txt\n- latex_table_code.txt\n\nIm ersten sind die eingegebenen Dateien formatiert abgespeichert.\n\nIm zweiten finden Sie den entsprechenden LaTeX- Code f%cr eine Tabelle.\n\nDas Programm ist auf Windows- Systeme ausgelegt.\n", 148, 129);
			printf("In dieses Programm k%cnnen Sie Ihre Daten (z.B. Messdaten) eingeben\num dann daraus eine LaTeX- Tabelle generieren zu lassen.\n\nEs wird ein Ordner mit dem Namen \""FOLDERNAME"\" erstellt.\nEr wird sich in dem Ordner, in dem das Programm (*.exe) ist, befinden.\n\nIn diesem Ordner werden vier Dateien erstellt:", 148);
			printf("\n - "FILENAME_FORM_DATA"\n - "FILENAME_LATEX_CODE"\n - "FILENAME_BIN_DATA"\n - "FILENAME_SET_CONFIG"\n");
			printf("\nErste\tDatei:\tEingegebene Daten formatiert.");
			printf("\nZweite\tDatei:\tGenerierter LaTeX- Code f%cr eine Tabelle.", 129);
			printf("\nDritte\tDatei:\tIhre Daten zum Lesen f%cr das Programm.", 129);
			printf("\nVierte\tDatei:\tIhre Konfiguration zum Lesen f%cr das Programm.\n", 129);
			printf("\n\nHINWEISE:\n");
			printf("- Das Programm ist auf Windows- Systeme ausgelegt.\n- Beenden Sie das Programm immer mit dem \"Programm beenden\"- Befehl im\n  Hauptmen%c, da erst danach die Daten in die \""FILENAME_BIN_DATA"\"- Datei\n  abgespeichert werden.\n", 129);
			NEWLINE

				// Erstellerinformationen
				drawLineCustom(196);
			printf("Ersteller:\tTimo Vandrey\t(Kontakt: timo.vandrey%chaw-hamburg.de)", 64);
			// printf("\nIdee:\t\tJonas Buuck");
			NEWLINE
				STOPP
		}

		//HILFE: Einstellungen
		if (userInput == 9)
		{
			disp_cat(CAT_MAIN_HELP_SETTINGS);

			printf("9) Einstellungen:\n\n");
			printf("Hier k%cnnen verschiedene Attribute der Dateien ver%cndert und angepasst werden.\nEin separater Hilfebildschirm f%cr die einzelnen Unterpunkte\nexistiert im Einstellungsmen%c.\n", 148, 132, 129, 129);
			STOPP
		}

	} while (userInput);
}

void disp_help_settings(void)
{
	bool menuState = true;
	int userInput = -1;

	do
	{

		disp_cat(CAT_MAIN_SETTINGS_HELP);

		printf("Welchen Unterpunkt w%crden Sie gerne erkl%crt haben?\n\n", 129, 132);
		printf("<1>\tDezimalstellen nach dem Komma\n");
		//printf("<2>\tLaTeX- Code: Anzahl der Spaltenpaare\n");
		printf("<3>\tLaTeX- Code: Ob die Tabelle eine Bezeichnung besitzt\n");
		printf("<4>\tLaTeX- Code: Bezeichnung der Tabelle\n");
		printf("<5>\tLaTeX- Code: Spaltenbezeichnungen\n");
		printf("<6>\tNachkommastellenanzeige\n");
		printf("<9>\tEinstellungen anzeigen\n\n");

		printf("<0>\tZur%cck\n\n", 129);

		printf("Ihre Eingabe:\t");
		userInput = menu_safe_input(0, 9);

		// Hilfemenü verlassen
		if (userInput == 0)
		{
			menuState = false;
		}

		// HILFE: Dezimalstellen nach dem Komma
		if (userInput == 1)
		{
			disp_cat(CAT_MAIN_SETTINGS_HELP_DECPOINTS);

			printf("Dezimalstellen nach dem Komma:\n\nHier k%cnnen Sie die Anzahl der Dezimalstellen nach dem Komma einstellen.\nSie wird global angewendet. Eingaben, die %cber die Kommastellenanzahl\nhinausgehen, werden abgekappt. Sie bleiben jedoch bis zum Beenden\ndes Programms im Programmspeicher erhalten.\n", 148, 129);
			STOPP
		}

		// Hilfe: Spaltenpaaranzahl
		//if (userInput == 2)
		//{
		//	HEADER
		//		printf("");
		//	STOPP
		//}

		// HILFE: LaTeX- Code: Ob die Tabelle eine Bezeichnung besitzt
		if (userInput == 3)
		{
			disp_cat(CAT_MAIN_SETTINGS_HELP_WHETHER);

			printf("LaTeX- Code: Ob die Tabelle eine Bezeichnung besitzt:\n\nIn LaTeX kann die Tabelle in ein Tabellenregister aufgenommen\nund betitelt werden. Wenn Sie das w%cnschen, m%cssen Sie hier \"Ja\" w%chlen.\nAndererseits w%chlen Sie bitte \"Nein\".\nEin Indikator am Ende der Zeile \"(Derzeit: X)\"\nzeigt Ihnen den derzeitigen Status der Variable an.\n", 129, 129, 132, 132);
			STOPP
		}

		// HILFE: LaTeX- Code: Bezeichnung der Tabelle
		if (userInput == 4)
		{
			disp_cat(CAT_MAIN_SETTINGS_HELP_LABELTABULAR);

			printf("LaTeX- Code: Bezeichnung der Tabelle:\n\nIn LaTeX kann die Tabelle in ein Tabellenregister aufgenommen\nund betitelt werden. Hier k%cnnen Sie den Titel bestimmen.\nDer Titel wird global verwendet.\n\nHinweis:\tEs k%cnnen auch LaTeX- Befehle bereits mit eingegeben werden\n\t\twie z.B. \"Impedanz [$\\Omega$]\".\n\t\tUmlaute werden jedoch nicht erkannt.\n", 148, 148);
			STOPP
		}

		// HILFE: LaTeX- Code: Spaltenbezeichnungen
		if (userInput == 5)
		{
			disp_cat(CAT_MAIN_SETTINGS_HELP_LABELCOLOUMN);

			printf("LaTeX- Code: Spaltenbezeichnungen:\n\nIn der generierten LaTeX- Tabelle gibt es zwei Spalten.\nHier bestimmen Sie die Bezeichnungen der beiden.\n\nErste Spaltenbezeichnung\t=\tLinke Spalte\nZweite Spaltenbezeichnung\t=\tRechte Spalte\n\nHinweis:\tEs k%cnnen auch LaTeX- Befehle bereits mit eingegeben werden\n\t\twie z.B. \"Impedanz [$\\Omega$]\".\n\t\tUmlaute werden jedoch nicht erkannt.\n", 148);
			STOPP
		}

		// HILFE: Nachkommastellenanzeige
		if (userInput == 6)
		{
			disp_cat(CAT_MAIN_SETTINGS_HELP_DECDISP);

			printf("Nachkommastellenanzeige:\n\nHier k%cnnen Sie einstellen, bei welchen Werten die Nachkommastellen angezeigt\nwerden. Der Standard ist, dass bei allen Daten die Nachkommastellen angezeigt\nwerden. Mit dem Ausw%chlen des Men%cpunktes wechseln Sie durch die Optionen.\nDiese Anzeige wird auch auf die Dateien angewendet.\nDie eingegebenen Nachkommastellen bleiben auch nach Beenden\ndes Programmes erhalten\n", 148, 132, 129);
			STOPP
		}

		// HILFE: Einstellungen anzeigen
		if (userInput == 9)
		{
			disp_cat(CAT_MAIN_SETTINGS_HELP_DISPLAY);

			printf("Einstellungen anzeigen:\n\nHier werden alle Einstellungen und Titel einmal aufgelistet.\n");
			STOPP
		}



	} while (menuState);
}

void disp_settings_main(config user_config)
{
	disp_cat(CAT_MAIN_SETTINGS_DISPLAY);

	// Dezimalstellen nach dem Komma
	printf("Dezimalstellen nach dem Komma:\t\t%i\n", user_config.decpts_nb);

	// Dezimalstellenanzeige
	printf("Dezimalstellen werden angezeigt bei:\t");
	if (user_config.decpts_status == decpts_both)
	{
		printf("Datenpunkte-/und werte\n");
	}
	else if (user_config.decpts_status == decpts_dataval_only)
	{
		printf("Nur Datenwerte\n");
	}
	else if (user_config.decpts_status == decpts_datapts_only)
	{
		printf("Nur Datenpunkte\n");
	}
	else if (user_config.decpts_status == decpts_none)
	{
		printf("Keine\n");
	}

	// Ob die Tabelle eine Bezeichnung hat
	printf("Tabelle hat eine Bezeichnung:\t\t");
	if (user_config.has_label) { printf("Wahr\n"); }
	else { printf("Falsch\n"); }

	// Bezeichnung der Tabelle
	printf("Bezeichnung der Tabelle:\t\t");
	if (user_config.has_label) { fputs(user_config.label_tabular, stdout); NEWLINE }
	else { printf("n.A.\n"); }

	// Bezeichnung der ersten Tabellenspalte
	printf("Bezeichnung erste Tabellenspalte:\t");
	fputs(user_config.label1, stdout);
	NEWLINE

		// Bezeichnung der ersten Tabellenspalte
		printf("Bezeichnung zweite Tabellenspalte:\t");
	fputs(user_config.label2, stdout);
	NEWLINE

		// Anzahl der Tabellenspaltenpaare
		/*printf("Anzahl der Tabellenspaltenpaare:\t%i");*/

		STOPP

}

void disp_settings_funct(config user_config)
{
	// Dezimalstellen nach dem Komma
	printf("Dezimalstellen nach dem Komma:\t\t%i\n", user_config.decpts_nb);

	// Dezimalstellenanzeige
	printf("Dezimalstellen werden angezeigt bei:\t");
	if (user_config.decpts_status == decpts_both)
	{
		printf("Datenpunkte-/und werte\n");
	}
	else if (user_config.decpts_status == decpts_dataval_only)
	{
		printf("Nur Datenwerte\n");
	}
	else if (user_config.decpts_status == decpts_datapts_only)
	{
		printf("Nur Datenpunkte\n");
	}
	else if (user_config.decpts_status == decpts_none)
	{
		printf("Keine\n");
	}

	// Ob die Tabelle eine Bezeichnung hat
	printf("Tabelle hat eine Bezeichnung:\t\t");
	if (user_config.has_label) { printf("Wahr\n"); }
	else { printf("Falsch\n"); }

	// Bezeichnung der Tabelle
	printf("Bezeichnung der Tabelle:\t\t");
	if (user_config.has_label) { fputs(user_config.label_tabular, stdout); NEWLINE }
	else { printf("n.A.\n"); }

	// Bezeichnung der ersten Tabellenspalte
	printf("Bezeichnung erste Tabellenspalte:\t");
	fputs(user_config.label1, stdout);
	NEWLINE

		// Bezeichnung der ersten Tabellenspalte
		printf("Bezeichnung zweite Tabellenspalte:\t");
	fputs(user_config.label2, stdout);
	NEWLINE

		// Anzahl der Tabellenspaltenpaare
		/*printf("Anzahl der Tabellenspaltenpaare:\t%i");*/
}


void data_input_prime(double measurements[MAX_MEASUREMENTS][2], char* currDir, config* user_config_pt)
{
	// HIER NOCH PROBLEME IM HEADER (MENÜFÜHRUNG) UND DIE ENTSPRECHENDEN SCHRITTE WERDEN NICHT ANGEZEIGT -->>> FIXXXXEN!!!

	int userInput = -1;					// Abspeicherung der Eingabe des Nutzers; "-1" zur Signalisierung, dass kein Wert eingegeben wurde
	// decpts							// Dezimalstellen die genutzt werden
	bool functionState = true;			// Für Aufrechterhaltung der Funktionsschleife
	bool latex_create_now = false;		// Für Abfrage ob die LaTeX- Datei jetzt erstellt werden soll
	// bool latex_has_label = false;	// Ob die Tabelle (LaTeX) eine Bezeichnung hat 
	bool latex_name_now = false;		// Ob die Tabellenspalten- und bezeichnung jetzt eingegeben werden soll
	bool userAgree = false;				// Sicherheitsabfrage: Neue Datei wird erstellt und alte Dateien überschrieben
	bool userInputState = false;
	// Für LaTeX- Code
	// char label1_buffer[50] = { 0 };			// Label linke Spalte
	// char label2_buffer[50] = { 0 };			// Label rechte Spalte
	// char label_tabular_buffer[50] = { 0 };	// Label der gesamten Tabelle


	do
	{
		disp_cat(CAT_MAIN_DATAINPUT);

		printf("Es wird eine neue Datei angelegt und m%cglicherweise\nvorhandene Daten %cberschrieben.\nTrotzdem fortfahren?\n\n<1>\tJa\n<0>\tNein\n\nIhre Eingabe:\t", 148, 129);
		//scanf("%i", &userAgree);
		userAgree = menu_safe_input(0, 1);

		if (!userAgree)
		{
			return;
		}

		else
		{
			disp_cat(CAT_MAIN_DATAINPUT_DECPTS);

			//printf("Auf wieviele Kommastellen genau m%cchten Sie die Daten eingeben?\n(min. 0 | max. 9 | Standard: 3)\n\nIhre Eingabe:\t", 148);
			printf("Auf wieviele Kommastellen genau m%cchten Sie die Daten eingeben?\n(min. 0 %c max. 9 %c Standard: 3 %c Jetzt: %i)\n\nIhre Eingabe:\t", 148, 179, 179, 179, user_config_pt->decpts_nb);
			user_config_pt->decpts_nb = menu_safe_input(0, 9);

			// Eingabemodus wählen
			disp_cat(CAT_MAIN_DATAINPUT_DECPTS_INPUTMODE);
			userInput = menu_input();

			if (userInput != 0)
			{

				// Feld auf Null zurücksetzen
				for (int i = 0; i < MAX_MEASUREMENTS; i++)
				{
					measurements[i][0] = 0;
					measurements[i][1] = 0;
				}


				disp_cat(CAT_MAIN_DATAINPUT_DECPTS_INPUTMODE_AMOUNT);

				// Der Benutzer will beides jeweils entsprechend eingeben
				if (userInput == 1)
				{
					userInputState = data_input_mode1(measurements, &(user_config_pt->data_nb));
					if (!userInputState)
					{
						return;
					}
					functionState = false;
				}

				// Der Benutzer will erst die Datenpunkte (x- Achse), und dann die zugehörenden Werte (y- Achse) eingeben
				if (userInput == 2)
				{
					userInputState = data_input_mode2(measurements, &(user_config_pt->data_nb));
					if (!userInputState)
					{
						return;
					}
					functionState = false;
				}

				data_save_formatted(measurements, currDir, user_config_pt->decpts_nb, user_config_pt->decpts_status, &(user_config_pt->data_nb));
				
				disp_cat(CAT_MAIN_DATAINPUT_DECPTS_INPUTMODE_AMOUNT_INPUT);

				printf("Ihre eingegebenen Datenwerte:\n\n");
				data_output_funct(measurements, user_config_pt->decpts_nb, user_config_pt->decpts_status, &(user_config_pt->data_nb));

				STOPP

					// Abfrage, ob der Code jetzt eingegeben werden soll
					disp_cat(CAT_MAIN_DATAINPUT_DECPTS_INPUTMODE_AMOUNT_INPUT_LATEX);

				printf("M%cchten Sie jetzt Ihren LaTeX- Code erstellen lassen?\n\n<1>\tJa\n<0>\tNein\n\nIhre Eingabe:\t", 148);
				//scanf("%i", &latex_create_now);
				latex_create_now = menu_safe_input(0, 1);

				// LaTeX- Code erstellen
				if (latex_create_now)
				{
					disp_cat(CAT_MAIN_DATAINPUT_DECPTS_INPUTMODE_AMOUNT_INPUT_LATEX);

					printf("Soll Ihre Tabelle eine Bezeichnung haben und im Verzeichnis aufgenommen werden?\n\n<1>\tJa\n<0>\tNein\n\nIhre Eingabe:\t");
					user_config_pt->has_label = menu_safe_input(0, 1);

					disp_cat(CAT_MAIN_DATAINPUT_DECPTS_INPUTMODE_AMOUNT_INPUT_LATEX);

					printf("Wollen Sie die Spalten- und Tabellenbezeichnungen jetzt eingeben/ver%cndern?\n\n<1>\tJa\n<0>\tNein\n\nIhre Eingabe:\t", 132);
					latex_name_now = menu_safe_input(0, 1);


					// HIER NOCH PROBLEME IM HEADER (MENÜFÜHRUNG)
					if (latex_name_now)
					{
						if (user_config_pt->has_label)
						{
							label_input_fract_tabular(user_config_pt->label_tabular, 1);
						}
						label_input_fract_columns(user_config_pt->label1, user_config_pt->label2, 1);
					}

					// LaTeX- Code erstellen
					NEWLINE

						data_save_latex(measurements, currDir, *user_config_pt);
					drawLineCustom(196);
					printf("LaTeX- Code erfolgreich erstellt.\n");

				}

				STOPP

			}
		}

	} while (functionState && userInput != 0);

}

int data_input_mode1(double measurements_inFunc[MAX_MEASUREMENTS][2], int* data_nb)
{

	int measureCount = *data_nb;

	printf("Wie viele Datenpunkte m%cchten Sie eingeben?\nIhre Wahl:\t", 148);
	measureCount = (int)safe_input_double();
	*data_nb = measureCount;

	/*scanf("%i", &measureCount);*/
	//measureCount = menu_safe_input(0, 1);

	if (measureCount <= 0)
	{
		return 0;
	}

	disp_cat(CAT_MAIN_DATAINPUT_DECPTS_INPUTMODE_AMOUNT_INPUT);

	printf("Geben Sie nun bitte Ihre Daten ein:\n\n");

	for (int i = 0; i < measureCount; i++)
	{
		// Datenpunkteingabe (Punkte auf der x- Achse)
		printf("Datenpunkt %i:\t", i + 1);
		measurements_inFunc[i][0] = safe_input_double();

		//scanf("%lf", &measurements_inFunc[i][0]);

		// Datenwerteingabe (Punkte auf der y- Achse)
		printf("Datenwert %i:\t", i + 1);
		measurements_inFunc[i][1] = safe_input_double();
		//scanf("%lf", &measurements_inFunc[i][1]);

		printf("\n");
	}

	return 1;

}

int data_input_mode2(double measurements_inFunc[MAX_MEASUREMENTS][2], int* data_nb)
{

	int measureCount = 0;

	printf("Wie viele Datenpunkte m%cchten Sie eingeben?\nIhre Wahl:\t", 148);
	//scanf("%i", &measureCount);
	measureCount = (int)safe_input_double();
	*data_nb = measureCount;

	if (measureCount <= 0)
	{
		return 0;
	}

	disp_cat(CAT_MAIN_DATAINPUT_DECPTS_INPUTMODE_AMOUNT_INPUT);

	printf("Geben Sie nun bitte Ihre Daten ein:\n\n");

	// Datenpunkteingabe (Punkte auf der x- Achse)
	for (int i = 0; i < measureCount; i++)
	{
		printf("Datenpunkt %i:\t", i + 1);
		//scanf("%lf", &measurements_inFunc[i][0]);
		measurements_inFunc[i][0] = safe_input_double();
	}
	printf("\n");
	// Datenwerteingabe (Punkte auf der y- Achse)
	for (int i = 0; i < measureCount; i++)
	{
		printf("Datenwert %i:\t", i + 1);
		//scanf("%lf", &measurements_inFunc[i][1]);
		measurements_inFunc[i][1] = safe_input_double();
	}

	return 1;
}

void data_output_main(double measurements[MAX_MEASUREMENTS][2], int decimalpts, int decpts_status, int* data_nb)
{
	int measureCount = 0;
	double check_content = 0;

	// Länge des
	measureCount = *data_nb;

	disp_cat(CAT_MAIN_DATAOUTPUT);

	// Keine Daten gefunden
	if (measureCount == 0)
	{
		printf("Keine Daten gefunden.\n");
	}

	// Eingegebene Daten ausgeben
	else
	{
		printf("Ihre Daten:\n\n");
		printf("###\tDatenpunkt\t\tDatenwert\n");

		if (decpts_status == decpts_both)
		{
			for (int i = 0; i < measureCount; i++)
			{
				printf("%03i\t%6.*lf\t\t\t%6.*lf\n", i + 1, decimalpts, measurements[i][0], decimalpts, measurements[i][1]);
			}
		}
		else if (decpts_status == decpts_dataval_only)
		{
			for (int i = 0; i < measureCount; i++)
			{
				printf("%03i\t%6.*lf\t\t\t%6.*lf\n", i + 1, 0, measurements[i][0], decimalpts, measurements[i][1]);
			}
		}
		else if (decpts_status == decpts_datapts_only)
		{
			for (int i = 0; i < measureCount; i++)
			{
				printf("%03i\t%6.*lf\t\t\t%6.*lf\n", i + 1, decimalpts, measurements[i][0], 0, measurements[i][1]);
			}
		}
		else if (decpts_status == decpts_none)
		{
			for (int i = 0; i < measureCount; i++)
			{
				printf("%03i\t%6.*lf\t\t\t%6.*lf\n", i + 1, 0, measurements[i][0], 0, measurements[i][1]);
			}
		}

		//// HAUPTDURCHFÜHRUNG DER FUNKTION ALS BACKUP
		//for (int i = 0; i < measureCount; i++)
		//{
		//	printf("%03i\t%6.*lf\t\t\t%6.*lf\n", i + 1, decimalpts, measurements[i][0], decimalpts, measurements[i][1]);
		//}

	}

	// Stoppen damit der Benutzer sich die Daten anschauen kann
	stopp();

}

void data_output_funct(double measurements[MAX_MEASUREMENTS][2], int decimalpts, int decpts_status, int* data_nb)
{

	int measureCount = *data_nb;

	//printf("Ihre Daten:\n\n");
	printf("###\tDatenpunkt\t\tDatenwert\n");

	if (decpts_status == decpts_both)
	{
		for (int i = 0; i < measureCount; i++)
		{
			printf("%03i\t%6.*lf\t\t\t%6.*lf\n", i + 1, decimalpts, measurements[i][0], decimalpts, measurements[i][1]);
		}
	}
	else if (decpts_status == decpts_dataval_only)
	{
		for (int i = 0; i < measureCount; i++)
		{
			printf("%03i\t%6.*lf\t\t\t%6.*lf\n", i + 1, 0, measurements[i][0], decimalpts, measurements[i][1]);
		}
	}
	else if (decpts_status == decpts_datapts_only)
	{
		for (int i = 0; i < measureCount; i++)
		{
			printf("%03i\t%6.*lf\t\t\t%6.*lf\n", i + 1, decimalpts, measurements[i][0], 0, measurements[i][1]);
		}
	}
	else if (decpts_status == decpts_none)
	{
		for (int i = 0; i < measureCount; i++)
		{
			printf("%03i\t%6.*lf\t\t\t%6.*lf\n", i + 1, 0, measurements[i][0], 0, measurements[i][1]);
		}
	}

}

bool data_change(double measurements[MAX_MEASUREMENTS][2], int decpts, int decpts_status, int* data_nb)
{
	int measurementCount = 0;
	int userInput_Nb = 0;
	int userInput_Choice = 0;
	double userInput_value = 0;
	bool input_already = false;
	bool change_done = false;

	measurementCount = *data_nb;

	disp_cat(CAT_MAIN_DATACHANGE);

	// Keine Daten gefunden
	if (measurementCount == 0)
	{
		printf("Keine Daten gefunden.\n");
		STOPP
			return 0;
	}

	// Eingegebene Daten ausgeben
	else
	{
		do
		{
			if (input_already)
			{
				disp_cat(CAT_MAIN_DATACHANGE);
			}

			printf("Ihre Daten:\n\n");
			data_output_funct(measurements, decpts, decpts_status, data_nb);
			NEWLINE

				drawLineCustom(196);

			if (userInput_Nb > measurementCount && input_already)
			{
				printf("Der Datenwert %i existiert nicht.\nBitte geben Sie einen existierenden Datenwert ein.\n\n", userInput_Nb);
				drawLineCustom(196);
			}
			printf("Welchen Datenwert m%cchten Sie ver%cndern?\nBitte geben Sie die Nummer an. (0 %c Abbruch)\nIhre Eingabe:\t", 148, 132, 26);
			userInput_Nb = (int)safe_input_double();
			input_already = true;

			NEWLINE

				if (userInput_Nb == 0)
				{
					return false;
				}
			if (!(userInput_Nb > measurementCount))
			{
				disp_cat(CAT_MAIN_DATACHANGE);

				printf("Ihre Daten:\n\n");
				data_output_funct(measurements, decpts, decpts_status, data_nb);
				NEWLINE
					drawLineCustom(196);

				printf("Welchen Wert m%cchten Sie ver%cndern?\n\n<1>\tDatenpunkt\n<2>\tDatenwert\n\nIhre Eingabe:\t", 148, 132);
				userInput_Choice = menu_safe_input(1, 2);
				NEWLINE
					drawLineCustom(196);
				if (userInput_Choice == 1)
				{
					printf("Geben Sie den neuen Datenpunkt ein:\t");
					userInput_value = safe_input_double();
					measurements[userInput_Nb - 1][0] = userInput_value;
				}
				if (userInput_Choice == 2)
				{
					printf("Geben Sie den neuen Datenwert ein:\t");
					userInput_value = safe_input_double();
					measurements[userInput_Nb - 1][1] = userInput_value;
				}
				NEWLINE

					disp_cat(CAT_MAIN_DATACHANGE);

				printf("Ihre neuen Daten:\n\n");
				data_output_funct(measurements, decpts, decpts_status, data_nb);
				change_done = true;
			}


		} while (!change_done);
	}

	STOPP

		return true;

}

void data_rearrange(double measurements[MAX_MEASUREMENTS][2], int decpts, int decpts_status, bool* data_changed, int* data_nb)
{
	double data_buffer[MAX_MEASUREMENTS][2] = { 0 };

	datenpaar pairsOfData[MAX_MEASUREMENTS] = { 0, 0 };
	datenpaar pair_buffer = { 0, 0 };

	int measureCount = 0;		// Anzahl der genutzten Speicherplätze für die Daten
	int increment = 0;			// Inkrementvariable für die Ordnungsprozesse
	int userInput = -1;			// Noch nichts eingegeben

								// Anzahl der Daten ermitteln
	measureCount = *data_nb;

	// Keine Daten gefunden
	if (measureCount <= 0)
	{
		disp_cat(CAT_MAIN_DATAREARRANGE);

		printf("Keine Daten gefunden.\n");
		STOPP
			return;
	}

	// Übertragen der Daten aus dem Array in das Konstrukt zum vereinfachten Ordnen
	for (int i = 0; i < measureCount; i++)
	{
		pairsOfData[i].data_point = measurements[i][0];
		pairsOfData[i].data_value = measurements[i][1];
	}

	disp_cat(CAT_MAIN_DATAREARRANGE);

	printf("Wonach m%cchten Sie Ihre Daten ordnen?\n\n", 148);
	printf("<1>\tDatenpunkte aufsteigend\n");
	printf("<2>\tDatenpunkte absteigend\n");
	printf("<3>\tDatenwerte aufsteigend\n");
	printf("<4>\tDatenwerte absteigend\n");

	printf("\n<0>\tZur%cck\n", 129);

	printf("\nIhre Wahl:\t");

	userInput = menu_safe_input(0, 4);

	if (!userInput)
	{
		return;
	}
	else
	{
		disp_cat(CAT_MAIN_DATAREARRANGE);

		printf("Ihre Daten vor dem Sortieren:\n\n");
		data_output_funct(measurements, decpts, decpts_status, data_nb);
		drawLineCustom(196);

		// Datenpunkte: Größe aufsteigend ordnen
		if (userInput == 1)
		{
			for (int i = 0; i < measureCount; i++)
			{

				// Ordnungsprozess
				while (increment < measureCount)
				{
					if (pairsOfData[increment].data_point > pairsOfData[increment + 1].data_point)
					{
						if (increment + 1 < measureCount)
						{
							pair_buffer = pairsOfData[increment];					// Höherer Wert in den Puffer schieben
							pairsOfData[increment] = pairsOfData[increment + 1];	// Niedrigeren Wert auf den Punkt des höheren Werts schieben
							pairsOfData[increment + 1] = pair_buffer;				// Höheren Wert auf den Punkt des niedrigeren Werts schieben
						}

						pair_buffer.data_point = 0;
						pair_buffer.data_value = 0;

					}
					increment++;
				}

				increment = 0;
			}
		}

		// Datenpunkte: Größe absteigend ordnen
		if (userInput == 2)
		{
			for (int i = 0; i < measureCount; i++)
			{

				// Ordnungsprozess
				while (increment < measureCount)
				{
					if (pairsOfData[increment].data_point < pairsOfData[increment + 1].data_point)
					{
						if (increment + 1 < measureCount)
						{
							pair_buffer = pairsOfData[increment];					// Niedrigerer Wert in den Puffer schieben
							pairsOfData[increment] = pairsOfData[increment + 1];	// Höheren Wert auf den Punkt des niedrigeren Werts schieben
							pairsOfData[increment + 1] = pair_buffer;				// Niedrigeren Wert auf den Punkt des höheren Werts schieben
						}

						pair_buffer.data_point = 0;
						pair_buffer.data_value = 0;

					}
					increment++;
				}

				increment = 0;
			}
		}

		// Datenwerte: Größe aufsteigend ordnen
		if (userInput == 3)
		{
			for (int i = 0; i < measureCount; i++)
			{

				// Ordnungsprozess
				while (increment < measureCount)
				{
					if (pairsOfData[increment].data_value > pairsOfData[increment + 1].data_value)
					{
						if (increment + 1 < measureCount)
						{
							pair_buffer = pairsOfData[increment];					// Höherer Wert in den Puffer schieben
							pairsOfData[increment] = pairsOfData[increment + 1];	// Niedrigeren Wert auf den Punkt des höheren Werts schieben
							pairsOfData[increment + 1] = pair_buffer;				// Höheren Wert auf den Punkt des niedrigeren Werts schieben
						}

						pair_buffer.data_point = 0;
						pair_buffer.data_value = 0;

					}
					increment++;
				}

				increment = 0;
			}
		}

		// Datenwerte: Größe absteigend ordnen
		if (userInput == 4)
		{
			for (int i = 0; i < measureCount; i++)
			{

				// Ordnungsprozess
				while (increment < measureCount)
				{
					if (pairsOfData[increment].data_value < pairsOfData[increment + 1].data_value)
					{
						if (increment + 1 < measureCount)
						{
							pair_buffer = pairsOfData[increment];					// Niedrigerer Wert in den Puffer schieben
							pairsOfData[increment] = pairsOfData[increment + 1];	// Höheren Wert auf den Punkt des niedrigeren Werts schieben
							pairsOfData[increment + 1] = pair_buffer;				// Niedrigeren Wert auf den Punkt des höheren Werts schieben
						}

						pair_buffer.data_point = 0;
						pair_buffer.data_value = 0;

					}
					increment++;
				}

				increment = 0;
			}
		}

		// Übertragen der Daten aus dem Konstrukt zurück ins Array
		while (increment < measureCount)
		{
			measurements[increment][0] = pairsOfData[increment].data_point;
			measurements[increment][1] = pairsOfData[increment].data_value;
			increment++;
		}

		printf("Ihre Daten nach dem Sortieren:\n\n");
		data_output_funct(measurements, decpts, decpts_status, data_nb);

		*data_changed = true;

		STOPP

			return;
	}

}


int decpts_input(int dec_ima)
{
	int dec_inp = 0;

	disp_cat(CAT_MAIN_SETTINGS_DECPOINTS);

	printf("Auf wieviele Kommastellen genau m%cchten Sie die Daten eingeben?\n(min. 0 %c max. 9 %c Standard: 3 %c Jetzt: %i)\n\nIhre Eingabe:\t", 148, 179, 179, 179, dec_ima);
	dec_inp = menu_safe_input(0, 9);

	return dec_inp;
}

void label_input(char* label1_buffer, char* label2_buffer, char* label_tabular_buffer)
{
	bool has_label = false;

	bool userAgree = false;

	char processBar_0[5] = { 0 };
	char processBar_1[5] = { 0 };
	char processBar_2[5] = { 0 };
	char processBar_3[5] = { 0 };
	char processBar_4[5] = { 0 };

	processBar_0[0] = 176;
	processBar_0[1] = 176;
	processBar_0[2] = 176;
	processBar_0[3] = 176;

	processBar_1[0] = 219;
	processBar_1[1] = 176;
	processBar_1[2] = 176;
	processBar_1[3] = 176;

	processBar_2[0] = 219;
	processBar_2[1] = 219;
	processBar_2[2] = 176;
	processBar_2[3] = 176;

	processBar_3[0] = 219;
	processBar_3[1] = 219;
	processBar_3[2] = 219;
	processBar_3[3] = 176;

	processBar_4[0] = 219;
	processBar_4[1] = 219;
	processBar_4[2] = 219;
	processBar_4[3] = 219;

	// Prozessstreifen:

	do
	{

		disp_header_custom(processBar_1);

		// Labels abfragen
		printf("Wie ist die Bezeichnung der ersten Spalte?\nIhre Eingabe:\t");
		fgets(label1_buffer, 49, stdin);

		disp_header_custom(processBar_2);

		printf("Wie ist die Bezeichnung der zweiten Spalte?\nIhre Eingabe:\t");
		fgets(label2_buffer, 49, stdin);

		disp_header_custom(processBar_3);

		printf("Soll Ihre Tabelle eine Bezeichnung haben und im Verzeichnis aufgenommen werden?\n\n<1>\tJa\n<0>\tNein\n\nIhre Eingabe:\t");
		has_label = menu_safe_input(0, 1);

		if (has_label)
		{
			disp_header_custom(processBar_4);

			flashStandardInput();
			NEWLINE
				printf("Wie ist die Bezeichnung der Tabelle?\nIhre Eingabe:\t");
			fgets(label_tabular_buffer, 49, stdin);
		}

		disp_header_custom(processBar_4);

		printf("Ist das richtig so?\n\n<1>\tJa\n<0>\tErneut eingeben\n\nIhre Wahl:\t");
		userAgree = menu_safe_input(0, 1);

	} while (!userAgree);

	remove_newline(label1_buffer);
	remove_newline(label2_buffer);
	remove_newline(label_tabular_buffer);

	return;
}

void label_input_fract_tabular(char* label_tabular_buffer, int headermode)
{
	bool userAgree = false;

	do
	{

		// Header
		if (headermode)
		{
			disp_cat(CAT_MAIN_DATAINPUT_DECPTS_INPUTMODE_AMOUNT_INPUT_LATEX_LABELTABULAR);
		}
		else
		{
			disp_cat(CAT_MAIN_SETTINGS_LABELTABULAR);
		}
		

		// Label abfragen
		printf("Wie ist die Bezeichnung der Tabelle? (0 %c Keine Bezeichnung)\nIhre Eingabe:\t", 26);
		fgets(label_tabular_buffer, 49, stdin);

		drawLineCustom(196);

		printf("Ist das richtig so?\n\n<1>\tJa\n<0>\tErneut eingeben\n\nIhre Wahl:\t");
		userAgree = menu_safe_input(0, 1);

	} while (!userAgree);

	remove_newline(label_tabular_buffer);

	return;
}

void label_input_fract_columns(char* label1_buffer, char* label2_buffer, int headermode)
{
	bool userAgree = false;

	do
	{

		// Header
		if (headermode)
		{
			disp_cat(CAT_MAIN_DATAINPUT_DECPTS_INPUTMODE_AMOUNT_INPUT_LATEX_LABELTABULAR_LABELCOLOUMN);
		}
		else
		{
			disp_cat(CAT_MAIN_SETTINGS_LABELTABULAR);
		}

		// Labels abfragen
		printf("Wie ist die Bezeichnung der ersten Spalte? (0 %c Keine Bezeichnung)\nIhre Eingabe:\t", 26);
		fgets(label1_buffer, 49, stdin);

		drawLineCustom(196);

		printf("Wie ist die Bezeichnung der zweiten Spalte? (0 %c Keine Bezeichnung)\nIhre Eingabe:\t", 26);
		fgets(label2_buffer, 49, stdin);

		drawLineCustom(196);

		printf("Ist das richtig so?\n\n<1>\tJa\n<0>\tErneut eingeben\n\nIhre Wahl:\t");
		userAgree = menu_safe_input(0, 1);

	} while (!userAgree);

	remove_newline(label1_buffer);
	remove_newline(label2_buffer);

	return;

}

void toggle_decpts(int* decpts_pointer)
{
	(*decpts_pointer)++;

	if (*decpts_pointer > 3)
	{
		*decpts_pointer = 0;
	}

	return;
}

//--<Dateifunktionen>----------------------------------------------------------------------------------------

void data_save_formatted(double arrayToSave[MAX_MEASUREMENTS][2], char* currDir, int decpts, int decpts_status, int* data_nb)
{
	bool fileStatus = true;

	int measureCount = 0; // Anzahl der Daten

	FILE* filept = NULL;

	char currDir_filename[200] = { 0 };	// Aktueller Pfad + Ordner | + Dateiname

										// Dateiname + Dateipfad am aktuellen Ort erstellen
	strcpy(currDir_filename, currDir);
	strcat(currDir_filename, "\\");
	strcat(currDir_filename, FILENAME_FORM_DATA);

	// Datei öffnen
	filept = fopen(currDir_filename, "w+");

	// Wenn die Datei nicht geöffnet werden konnte
	if (filept == NULL)
	{
		drawLineCustom(196);
		printf("Die Datei konnte aufgrund eines Fehlers nicht geöffnet werden.");
		drawLineCustom(196);
		return;
	}

	else
	{
		// Anzahl der Daten ermitteln
		measureCount = *data_nb;
		if (decpts_status == decpts_both)
		{
			for (int i = 0; i < measureCount; i++)
			{
				fprintf(filept, "%.*lf\t%.*lf\n", decpts, arrayToSave[i][0], decpts, arrayToSave[i][1]);
			}
		}
		if (decpts_status == decpts_none)
		{
			for (int i = 0; i < measureCount; i++)
			{
				fprintf(filept, "%.*lf\t%.*lf\n", 0, arrayToSave[i][0], 0, arrayToSave[i][1]);
			}
		}
		if (decpts_status == decpts_dataval_only)
		{
			for (int i = 0; i < measureCount; i++)
			{
				fprintf(filept, "%.*lf\t%.*lf\n", 0, arrayToSave[i][0], decpts, arrayToSave[i][1]);
			}
		}
		if (decpts_status == decpts_datapts_only)
		{
			for (int i = 0; i < measureCount; i++)
			{
				fprintf(filept, "%.*lf\t%.*lf\n", decpts, arrayToSave[i][0], 0, arrayToSave[i][1]);
			}
		}


		/*for (int i = 0; i < measureCount; i++)
		{
			fprintf(filept, "%.*lf\t%.*lf\n", decpts, arrayToSave[i][0], decpts, arrayToSave[i][1]);
		}*/
	}

	fclose(filept);
}

int data_save_bin(double arrayToSave[MAX_MEASUREMENTS][2], char* currDir, int decpts, int* data_nb)
{

	//-- Variablendeklaration --------------------------------------------------------->>>>
	FILE* filept_bin = NULL;

	char currDir_filename_bin[200] = { 0 };

	int saveCount = 0;
	int tryCount = 0;
	int measureCount = 0;
	measureCount = *data_nb;

	datenpaar pairsOfData[MAX_MEASUREMENTS] = { 0, 0 };

	datenpaar* pairsOfData_pt[MAX_MEASUREMENTS] = { 0 };	// Wird für Speicherfunktion fwrite() benötigt.

	for (int i = 0; i < measureCount; i++)
	{
		pairsOfData_pt[i] = &pairsOfData[i];
	}


	//-- Dateioperationen ------------------------------------------------------------->>>>
	// Durchgeben des Pfades
	strcpy(currDir_filename_bin, currDir);
	strcat(currDir_filename_bin, "\\");
	strcat(currDir_filename_bin, FILENAME_BIN_DATA);

	filept_bin = fopen(currDir_filename_bin, "r");

	// Wenn Datei existiert: Abfrage ob überschrieben werden soll
	//if (!filept_bin)
	//{
	//	drawLineCustom(196);
	//	printf("Speichervorgang fehlgeschlagen.\nDatei konnte nicht ge%cffnet werden.\n", 148);
	//	return -1; // -1 = Fehlerfall
	//}

	// Wenn Datei nicht existiert/geöffnet werden kann: Neue Datei wird erstellt
	filept_bin = fopen(currDir_filename_bin, "w");

	// Alle Datensätze aus dem Datenarray in Struct- Daten umwandeln damit binär gespeichert werden kann
	for (int i = 0; i < measureCount; i++)
	{
		pairsOfData[i].data_point = arrayToSave[i][0];
		pairsOfData[i].data_value = arrayToSave[i][1];
	}

	// Abspeichern der Daten
	for (int i = 0; i < measureCount; i++)
	{
		saveCount += (int)fwrite(pairsOfData_pt[i], sizeof(datenpaar), 1, filept_bin);
		tryCount++;
	}

	drawLineCustom(196);
	printf("Speichervorgang Datens%ctze:\n", 132);
	printf("- Schreibversuche Insgesamt:\t%i\n", tryCount);
	printf("- Schreibversuche Erfolgreich:\t%i\n", saveCount);

	//fclose(filept_bin);
	return 0;
}

void data_save_latex(double measurements[MAX_MEASUREMENTS][2], char* currDir, config config_container)
{
	FILE* file_latex_pt = NULL;

	// label1				// Label linke Spalte
	// label2				// Label rechte Spalte
	// label_tabular[50] 	// Label der gesamten Tabelle

	int measureCount = 0;			// Anzahl der eingetragenen Daten

	//--------------------------------------------------------------------------

	char currDir_filename[200] = { 0 };			// Aktueller Ordner + Pfad | + Dateiname

	measureCount = config_container.data_nb;	// Anzahl der eingetragenen Daten ermitteln

	// Dateiname + Dateipfad am aktuellen Ort erstellen
	strcpy(currDir_filename, currDir);
	strcat(currDir_filename, "\\");
	strcat(currDir_filename, FILENAME_LATEX_CODE);

	// Datei öffnen
	file_latex_pt = fopen(currDir_filename, "w+");

	// Fehlerfall:
	if (file_latex_pt == NULL)
	{
		printf("Datei konnte nicht ge%cffnet werden.", 148);
		return;
	}
	//--------------------------------------------------------------------------

	// LATEX- Code erstellen
	else
	{

		// Tabellengrundgerüst
		fprintf(file_latex_pt, "\\begin{table}[H]\n");

		if (config_container.column_nb == 1)
		{
			fprintf(file_latex_pt, "\t\\begin{tabular}{|l|l|}\\hline\n");

			// Überschriften bzw. Bezeichnungen in den Spalten
			fprintf(file_latex_pt, "\t\\textbf{");
			fputs(config_container.label1, file_latex_pt);
			fprintf(file_latex_pt, "}&\\textbf{");
			fputs(config_container.label2, file_latex_pt);
			fprintf(file_latex_pt, "} \\\\ \\hline \\hline\n");

			// Daten für die Tabelle ausgeben

			if (config_container.decpts_status == decpts_both)
			{
				for (int i = 0; i < measureCount; i++)
				{
					fprintf(file_latex_pt, "\t$ %.*lf $ \t & \t $ %.*lf $ \\\\ \\hline \n", config_container.decpts_nb, measurements[i][0], config_container.decpts_nb, measurements[i][1]);
				}
			}

			if (config_container.decpts_status == decpts_none)
			{
				for (int i = 0; i < measureCount; i++)
				{
					fprintf(file_latex_pt, "\t$ %.*lf $ \t & \t $ %.*lf $ \\\\ \\hline \n", 0, measurements[i][0], 0, measurements[i][1]);
				}
			}

			if (config_container.decpts_status == decpts_dataval_only)
			{
				for (int i = 0; i < measureCount; i++)
				{
					fprintf(file_latex_pt, "\t$ %.*lf $ \t & \t $ %.*lf $ \\\\ \\hline \n", 0, measurements[i][0], config_container.decpts_nb, measurements[i][1]);
				}
			}

			if (config_container.decpts_status == decpts_datapts_only)
			{
				for (int i = 0; i < measureCount; i++)
				{
					fprintf(file_latex_pt, "\t$ %.*lf $ \t & \t $ %.*lf $ \\\\ \\hline \n", config_container.decpts_nb, measurements[i][0], 0, measurements[i][1]);
				}
			}

			////ORIGINAL AUSGABE LATEX- CODE WERTE/PUNKTE
			//for (int i = 0; i < measureCount; i++)
			//{
			//	fprintf(file_latex_pt, "\t$ %.*lf $ \t & \t $ %.*lf $ \\\\ \\hline \n", decpts, measurements[i][0], decpts, measurements[i][1]);
			//}
			//fprintf(file_latex_pt, "\n");
		}

		//if (config_container.column_nb == 2)
		//{
		//	fprintf(file_latex_pt, "\t\\begin{tabular}{|l|l|l|l|}\\hline\n");
		//	// Überschriften bzw. Bezeichnungen in den Spalten
		//	// Erstes Spaltenpaar
		//	fprintf(file_latex_pt, "\t\\textbf{");
		//	fputs(config_container.label1, file_latex_pt);
		//	fprintf(file_latex_pt, "}&\\textbf{");
		//	fputs(config_container.label2, file_latex_pt);
		//	// Zweites Spaltenpaar
		//	fprintf(file_latex_pt, "}&\\textbf{");
		//	fputs(config_container.label1, file_latex_pt);
		//	fprintf(file_latex_pt, "}&\\textbf{");
		//	fputs(config_container.label2, file_latex_pt);
		//	fprintf(file_latex_pt, "} \\\\ \\hline \\hline\n");
		//}

		// Ende der Tabelle
		fprintf(file_latex_pt, "\t\\end{tabular}\n");

		// Bezeichnung der Tabellenstruktur
		if (config_container.has_label)
		{
			fprintf(file_latex_pt, "\\caption{");
			fputs(config_container.label_tabular, file_latex_pt);
			fprintf(file_latex_pt, "}\n");
		}
		fprintf(file_latex_pt, "\\end{table");
		fprintf(file_latex_pt, "}\n");


	}

	fclose(file_latex_pt);


	//\begin{table*} [...] ist nicht "kein Eintrag im Verzeichnis" sondern "Tabelle versteckt" !!!!!!!!!!!!!!!!!!!!!!



}

void data_save_config(char* currentDirectory, config config_to_save)
{
	FILE* filept_config = NULL;

	char currDir_filename[200] = { 0 };	// Aktueller Ordner + Pfad | + Dateiname

	config* config_pt = &config_to_save;

	bool config_success = 0;

	strcpy(currDir_filename, currentDirectory);
	strcat(currDir_filename, "\\");
	strcat(currDir_filename, FILENAME_SET_CONFIG);

	// Datei öffnen
	filept_config = fopen(currDir_filename, "w+");

	// Fehlerfall:
	if (filept_config == NULL)
	{
		printf("Datei konnte nicht ge%cffnet werden.", 148);
		return;
	}
	//--------------------------------------------------------------------------

	// Konfiguration speichern
	else
	{
		config_success = (int)fwrite(config_pt, sizeof(config), 1, filept_config);
	}

	printf("\n");
	printf("Speichervorgang Einstellungen:\n");
	if (config_success == 0)
	{
		printf("- Konfiguration konnte nicht gespeichert werden\n");
	}
	else
	{
		printf("- Konfiguration erfolgreich abgespeichert\n");
	}

	fclose(filept_config);

}

config data_load(double dat_array[MAX_MEASUREMENTS][2], char* currDir, config config_container)
{
	// Ordnerpfadnamen- etc. deklarieren
	char currDir_filename_format[200] = { 0 },	// Aktueller Pfad + Ordner | + Dateiname (Formatierte Daten)
		currDir_filename_latex[200] = { 0 },	// Aktueller Pfad + Ordner | + Dateiname (LaTeX- Datei)
		currDir_filename_bin[200] = { 0 },	// Aktueller Pfad + Ordner | + Dateiname (Binär- Datei)
		currDir_filename_config[200] = { 0 };	// Aktueller Pfad + Ordner | + Dateiname (Binär- Datei)

	int loadCount = 0;
	int tryCount = 0;
	int measureCount = 0;
	int i = 0;

	bool userChoice = false,
		config_success = 0;

	datenpaar pairsOfData[MAX_MEASUREMENTS] = { 0, 0 };
	datenpaar* pairsOfData_pt[MAX_MEASUREMENTS] = { NULL };

	config* pointerToConfig = NULL;
	pointerToConfig = &config_container;

	for (int i = 0; i < MAX_MEASUREMENTS; i++)
	{
		pairsOfData_pt[i] = &pairsOfData[i];
	}

	// Dateizeiger deklarieren
	FILE* filept_format = NULL;
	FILE* filept_latex = NULL;
	FILE* filept_bin = NULL;
	FILE* filept_config = NULL;

	// Dateinamen mit gesamten Pfad erstellen
	strcpy(currDir_filename_format, currDir);
	strcpy(currDir_filename_latex, currDir);
	strcpy(currDir_filename_bin, currDir);
	strcpy(currDir_filename_config, currDir);

	// Formatierte *.txt- Datei
	strcat(currDir_filename_format, "\\");
	strcat(currDir_filename_format, FILENAME_FORM_DATA);

	// Latex- *.txt- Datei
	strcat(currDir_filename_latex, "\\");
	strcat(currDir_filename_latex, FILENAME_LATEX_CODE);

	// Speicherstand- *.dat- Datei
	strcat(currDir_filename_bin, "\\");
	strcat(currDir_filename_bin, FILENAME_BIN_DATA);

	// Konfigurations- *.dat- Datei
	strcat(currDir_filename_config, "\\");
	strcat(currDir_filename_config, FILENAME_SET_CONFIG);

	// Testen ob sie existieren
	filept_format = fopen(currDir_filename_format, "r");
	filept_latex = fopen(currDir_filename_latex, "r");
	filept_bin = fopen(currDir_filename_bin, "rb");
	filept_config = fopen(currDir_filename_config, "rb");

	// Durchführung

	//Obsolet:		 // Hier wird der HEADER mit Versionsnummer angezeigt, da der Bildschirm sich noch vor dem Hauptmenü befindet. Konsistenz ist wichtig. -> Andererseits: Normal "HEADER".
	system("cls");
	//printf("VLE - Vereinfachte LaTeX- Tabelleneingabe\t\t\t\t"VERSIONNUM"\n");
	//drawLineCustom(196);
	disp_cat(CAT_DATALOAD);

	// Anzeige der gefundenen Dateien
	if (filept_format || filept_latex || filept_bin)
	{
		printf("Gefundene Dateien:\n\n");

		if (filept_format)
		{
			printf("\t- "FILENAME_FORM_DATA"\n");
		}
		if (filept_latex)
		{
			printf("\t- "FILENAME_LATEX_CODE"\n");
		}
		if (filept_bin)
		{
			printf("\t- "FILENAME_BIN_DATA"\n");
		}
		if (filept_config)
		{
			printf("\t- "FILENAME_SET_CONFIG"\n");
		}
		NEWLINE
	}
	// Wenn keine Dateien gefunden wurden
	else
	{
		printf("Keine Dateien gefunden. Dateien werden neu erstellt.\n\n");
		return config_container;
	}



	// Schließen der Dateipointer
	if (filept_latex)
	{
		fclose(filept_latex);
	}
	if (filept_format)
	{
		fclose(filept_format);
	}
	if (filept_bin)
	{
		fclose(filept_bin);
	}
	if (filept_config)
	{
		fclose(filept_config);
	}

	if (filept_bin || filept_config || filept_format || filept_latex)
	{
		drawLineCustom(196);
		printf("Sollen die gefundenen Daten geladen werden?\n\n<1>\tJa\n<0>\tNein\n\nIhre Wahl:\t");
		userChoice = menu_safe_input(0, 1);
	}

	if (userChoice)
	{


		// Daten Laden
		filept_bin = fopen(currDir_filename_bin, "rb");
		filept_config = fopen(currDir_filename_config, "rb");

		if (filept_bin)
		{
			while (!(feof(filept_bin)))
			{
				loadCount += (int)fread(pairsOfData_pt[i], sizeof(datenpaar), 1, filept_bin);
				tryCount++;
				i++;
			}
			tryCount--;	// Weil er für "Ende finden" einen "Versuch" benötigt


			// Laden der Strukturdaten ins Array
			for (int i = 0; i < loadCount; i++)
			{
				dat_array[i][0] = pairsOfData[i].data_point;
				dat_array[i][1] = pairsOfData[i].data_value;
			}
		}

		if (filept_config)
		{
			while (!(feof(filept_config)))
			{
				config_success += (int)fread(pointerToConfig, sizeof(config), 1, filept_config);
			}
		}

		drawLineCustom(196);
		printf("Ladevorgang Datens%ctze:\n", 132);
		printf("- Leseversuche Insgesamt:\t%i\n", tryCount);
		printf("- Leseversuche Erfolgreich:\t%i\n", loadCount);

		printf("\n");
		printf("Ladevorgang Einstellungen:\n");
		if (config_success == 0)
		{
			printf("- Konfiguration konnte nicht %cbernommen werden\n", 129);
		}
		else
		{
			printf("- Konfiguration erfolgreich %cbernommen\n", 129);
		}

		//fclose(filept_bin); //<--- DER HAT GROßEN ÄRGER GEMACHT. WARUM? Keine Ahnung...
	}

	else
	{
		disp_cat(CAT_DATALOAD);

		printf("Es werden neue Dateien angelegt.\n");
	}

	STOPP

		return config_container;

}

void data_recreate(double measurements[MAX_MEASUREMENTS][2], config user_config, char* currDir, bool* data_changed_pt)
{
	bool userAgree_1 = false;
	bool userAgree_2 = false;
	int measureCount = 0;

	// Abfrage, ob Daten vorhanden sind
	measureCount = user_config.data_nb;

	disp_cat(CAT_MAIN_REBUILD);

	// Wenn Daten vorhanden sind
	if (measureCount == 0)
	{
		printf("Keine Daten gefunden. Erstellung der Dateien nicht m%cglich.\n", 148);
		STOPP
			return;
	}
	else
	{
		printf("Es werden die Dateien (LaTeX- Code & formatierte Daten)\nmit folgenden Einstellungen generiert:\n\n");

		disp_settings_funct(user_config);
		NEWLINE
			drawLineCustom(196);

		printf("Sind die Einstellungen so O.K.?\n\n<1>\tJa\n<0>\tAbbrechen\n\nIhre Eingabe:\t");
		userAgree_1 = menu_safe_input(0, 1);
	}

	// Fragen, ob die Daten, die eingegeben wurden, ok sind.
	if (userAgree_1)
	{
		disp_cat(CAT_MAIN_REBUILD);

		printf("Dies sind Ihre eingegebenen Datenwerte:\n\n");

		data_output_funct(measurements, user_config.decpts_nb, user_config.decpts_status, &(user_config.data_nb));
		NEWLINE
			drawLineCustom(196);

		printf("Sind die Daten so O.K.?\n\n<1>\tJa\n<0>\tAbbrechen\n\nIhre Eingabe:\t");
		userAgree_2 = menu_safe_input(0, 1);
	}
	else
	{
		//HEADER
		//	printf("Neuerstellung der Dateien abgebrochen.\n");
		//STOPP
		return;
	}

	// Erstellen der Dateien
	if (userAgree_2)
	{

		data_save_formatted(measurements, currDir, user_config.decpts_nb, user_config.decpts_status, &(user_config.data_nb));
		data_save_latex(measurements, currDir, user_config);
		*data_changed_pt = 0;
		disp_cat(CAT_MAIN_REBUILD);

		printf("Dateien erfolgreich erstellt\n");
		STOPP
	}
	else
	{
		//HEADER
		//	printf("Neuerstellung der Dateien abgebrochen.\n");
		//STOPP
		return;
	}
}

//--<Weitere>------------------------------------------------------------------------------------------------

int getCountNumb(double measurements[MAX_MEASUREMENTS][2])
{
	int numb = 0;	// 1 weil der erste Datenpunkt möglicherweise "0", also der "Ursprung", ist

	if (measurements[0][0] == 0)
	{
		return numb = 0;
	}

	else
	{
		for (int i = 0; i < MAX_MEASUREMENTS; i++)
		{
			if (measurements[i][0] == 0)
			{
				numb = i;
				break;
			}
		}
	}

	return numb;
}

void remove_newline(char string[50])
{
	int incr = 0;

	do
	{
		if (string[incr] == '\0' || string[incr] == '\n')
		{
			string[incr] = 0;
			break;
		}
		incr++;
	} while (true);

	return;
}

double safe_input_double(void)
{
	int callBuff = 0;

	char input_str[51] = { 0 };				// Eingabe vom Nutzer
	char corrected_str[50] = { 0 };			// Eingabe- String ohne '\n', ',' zu '.' korrigiert
	char buffer_str[50] = { 0 };			// Eingabe- String ohne '\n'

	char before_comma[25] = { 0 };			// String (Nummer) vor dem Komma
	char after_comma[25] = { 0 };			// String (Nummer) nach dem Komma
	int before_comma_length = 0;			// Länge des Strings (Nummer) vor dem Komma
	int after_comma_length = 0;				// Länge des Strings (Nummer) nach dem Komma


	int strlength = 0;						// Länge des Strings, hier die Länge des "buffer_str"
	int i = 0;								// Inkrementvariable, mehrmals benutzt

	int before_comma_number = 0;			// Nummer vor dem Komma (int)
	int after_comma_number = 0;				// Nummer nach dem Komma (int)

	double before_comma_double = 0;
	double after_comma_double = 0;
	double output_number = 0;				// Letztendlich auszugebende Nummer

	bool charDetected = false;				// Ob ein Char detektiert wurde -> Wenn ja, gibt es eine Fehlermeldung und wird beendet (Da keine Zahl ausgelesen werden kann)

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	fgets(input_str, 50, stdin);	// Eingabe einlesen

	strcpy(buffer_str, input_str);	// Puffer- String beladen

	remove_newline(buffer_str);		// '\n' bzw. '\0' entfernen

	// Länge des Eingegebenen ermitteln
	strlength = (int)strlen(buffer_str);

	// Prüfen, ob Char vorhanden ist
	for (int i = 0; i < strlength; i++)
	{
		switch (buffer_str[i])
		{
		default: charDetected = true;		break;
		case '0': corrected_str[i] = 48;		break;
		case '1': corrected_str[i] = 49;		break;
		case '2': corrected_str[i] = 50;		break;
		case '3': corrected_str[i] = 51;		break;
		case '4': corrected_str[i] = 52;		break;
		case '5': corrected_str[i] = 53;		break;
		case '6': corrected_str[i] = 54;		break;
		case '7': corrected_str[i] = 55;		break;
		case '8': corrected_str[i] = 56;		break;
		case '9': corrected_str[i] = 57;		break;
		case ',': corrected_str[i] = 46;		break;
		case '.':	corrected_str[i] = 46;		break;
		}

		if (charDetected)
		{
			printf("\nFehler: Die Eingabe ist keine Zahl.\n");
			return 0;
		}
	}

	// Vorkomma- und Nachkommastellenanzahl ermitteln und in Strings aufteilen
	if (!charDetected)
	{
		// Solange before_comma_length erhöhen bis ein Komma kommt oder Ende des Strings erreicht ist
		while (input_str[i] != '.' && input_str[i] != ',' && input_str[i] != '\0' && input_str[i] != '\n')
		{
			before_comma[i] = input_str[i];
			before_comma_length++;
			i++;
		}

		// Wenn ein Komma gefunden/erreicht wurde: i++ um Komma zu überspringen und die nachfolgenden Stellen zählen und einspeichern
		if (input_str[i] == '.' || input_str[i] == ',')
		{
			i++;

			while (input_str[i] != '\0' && input_str[i] != '\n')
			{
				after_comma[i - (before_comma_length + 1)] = input_str[i];	// hier wird after_komma[i] -> i - (before_comma_length + 1, damit das Komma übersprungen (+1) wird und das Char- Array von Anfang an beschrieben wird (und nicht bei i = 15 -> after_comma[15]))
				after_comma_length++;
				i++;
			}
		}
	}

	// double erstellen
	before_comma_double = atoi(before_comma);								// char -> int, int -> double 
	after_comma_double = atoi(after_comma) * pow(0.1, after_comma_length);	// char -> int, int -> double // Aber der Wert muss noch durch 10 * die Länge der Nachkommazahl dividiert werden (also *0,1), damit die Zahl auch wirklich der Nachkommastellenzahl entspricht

	output_number = after_comma_double + before_comma_double;				// Beide Zahlen addieren und damit die Endzahl erschaffen

	// Eingabepuffer entleeren
	//flashStandardInput();

	return output_number;

}





/********************************************************************
Autor/en		:	T. Vandrey
Datum			:
Version			:	1.0
Datei			:	latex_eingabe_main.c
Dateifunktion	:	Hauptdatei für das Programm

Kurzbeschreibung:
n.A.
********************************************************************/
// LEGENDE TODO:
// - Ausstehende Aufgabe
// + Erledigte Aufgabe
// x Abgebrochene Aufgabe (Wird doch nicht umgesetzt
// ? Fragliche Aufgabe (Ob sie durchgeführt wird oder nicht, steht noch aus)

// TODO (v1.0):
// + Nachkommastellendarstellung
// + LaTeX- File sofort  erstellen / später erstellen
// + Daten ausgeben
// + Warnungen wenn Dateien bereits vorhanden sind und überschrieben werden
// + Sichere Eingabe/n (Zahlen 0 - 9 | Buchstaben werden abgefangen)
// + Datei woanders speichern?
// + Richtiges Schreiben (Nachkommastellen) in die Datei mit formatierten Messdaten
// x Sichere Eingabe bei Zahleneingaben > 9 und < 0 !!!

// TODO (v1.1)
// + Wenn Messdaten verändert wurden: LaTeX- Code und formatierte Daten neu abspeichern!!! (mit Merker machen?)
// + Daten verändern
// + Einstellungsmenü: Dezimalstellen, LaTeX- Einstellungen // -> (1 || zwei Zeilen, etc.) <- Wurde nicht übernommen, wird aber vielleicht noch gemacht
// + Hilfebildschirm überarbeiten
// x LaTeX- Einstellung: 1, 2 oder 3 Spaltenpaare -> Togglen (und vllt. Bsp.- Anzeige)
// + Dezimalstellenabfrage in data_input_prime() und mit Zeiger in der main() verändern?
// + Extra Menüpunkt zum generieren der Dateien erstellen
// + data_changed() überarbeiten: Soll nur 1 zurückgeben, wenn Daten wirklich verändert wurden.
// + Problem mit erstellen der Dateien bei Beenden des Programms: Sie werden außerhalb des Verzeichnisses erstellt!!!
// - Zeilenpaaranzahl der Tabelle veränderlich machen (1, 2 oder 3 Zeilenpaare?)
// - Zeilenpaaranzahl der Tabelle in LaTeX- Code schreiben lassen 
// ? Zeilenpaaranzahl- Beispielanzeige
// x Sichere Eingabe bei Zahleneingaben > 9 und < 0 !!!

// TODO (v1.2)
// + Daten aus vorhandener Datei auslesen 
// + Daten in Datei speichern
// ? Bei Ordner- und Dateinamen Datum hinzufügen
// + Daten sortieren
// x MATLAB- Plotcode als Option hinzufügen
// + Messpunkt-/wert Notation zu Datenpunkt/-wert verändern
// x In data_change() auch *.dat- Datei mit einbinden
// + Wenn data_change = true und dann data_recreate() gestartet wird -> data_changed muss zurückgesetzt werden
// + Wenn Daten geladen wurden und weniger Daten "neu" eingegeben werden, als bereits vorhanden: Es bleiben Rückstände vom vorherigen Datensatz übrig. ---> Feld neu Nullsetzen!
// ? Nur eine Warnung in data_input_prime() geben, wenn alte Daten überschrieben werden würden
// + Hilfebildschirm überarbeiten
// + Icon überarbeiten
// + Nullen hinter dem Komma ein-/ausschaltbar machen (Datenpunkte/-werte) (Togglen?)
// + GROßES PROBLEM: Programm läuft in VS17 aber nicht auf dem Desktop/außerhalb der Dev.- Umgebung!!! VERMUTUNG: data_load() oder vielleicht irgendwo ein fclose(X) nicht funktionsfähig?
// x "HINWEISE"- Unterpunkt im Hilfemenü überarbeiten und auffälliger machen
// + "Neuer" Name für das Programm
// + Name an Dateien und an den Ordner anhängen (z.B. Ordner: "VLE - Eingegebene Daten" oder so)
// + Neuer Name für "measured_data.txt" -> Das "measured" muss weg
// + Ein-/ausschaltbare Nullen: In LaTeX- Funktion mit einbauen
// + Hilfemenü überarbeiten: Wie beim Einstellungshilfemenü modular aufbauen? (Keine Informationsflut)
// + data_changed()- Endansage verändern (Nur LaTeX- und Formatierte Daten- Dateien werden erstellt)
// + Ausgabename des Programms zu "VLE" ändern 

// TODO (v1.3)
// + Einstellungen werden mit abgespeichert und übernommen wenn geladen wird
// x Ausgabename des Programms zu "VLE" mit Versionsnummer ändern  
// - LaTeX - Einstellung: 1, 2 oder 3 Spaltenpaare-> Togglen (und vllt.Bsp.- Anzeige, Endreihe eingeben lassen)
// - Icons (Alle Größen) bearbeiten
// + Wenn im Hilfebildschirm (Haupt- und Einstellungshilfebildschirm) -> Oben rechts in der Ecke anzeigen
// + Sichere Eingabe bei Zahleneingaben > 9 und < 0 !!!
// ? MATLAB- Plotcode als Option hinzufügen
// + Eingabe der Dezimalstellen mittels Komma möglich machen (Nicht Punkt, sondern Komma (,) !) -> Als String einlesen und umwandeln?
// + Abfrage ob geladen werden soll in data_load()
// + "HINWEISE"- Unterpunkt im Hilfemenü überarbeiten und auffälliger machen
// + Funktionen aufräumen: Anstatt tausend Werte wird nurnoch "Config- Struktur" übernommen und verwertet
// + GROßES PROBLEM: stdin lässt sich nicht leeren -> safe_input_double() spackt rum... -> LÖSUNG: Kein scanf() benutzen, immer fgets() und fgetc benutzen, um im Eingabepuffer nicht immer Müll zu lassen, und am Ende der Funktion Eingabepuffer leeren. 

// TODO (v1.4)
// + Nummer an Datensätzen nun ins Einstellungs- Struct speichern
// + Alle enstprechenden Funktionen an obiges Anpassen
// + Dateiendungen an "*.vledat" und "*.vleset" anpassen
// - Im Einstellungs- Menü oben rechts "Einstellungen" (wie im Hilfemenü) anzeigen lassen
// - Versionsnummer im Header entsprechend wie "Hilfe" und "Einstellungen" oben rechts anzeigen lassen
// + PROBLEM: Sofort nach dem Starten gibt es Probleme beim Abspeichern wenn man direkt beendet (Config wird nicht richtig geladen?)
// - Change- Function krüppelt
// - Change -> Löschen- Funktion einbauen
// - 


//===[ Einzubindende Bibliotheken ]====================================================================================================
#include "latex_eingabe_header.h"

//===[ Hauptfunktion ]=================================================================================================================

int main(int argc, char* argv[])
{
	//--< Variablendeklarationen >---------------------------------------------------------------------------------------------------->>>>	

	//----- Programmablaufrelevante Variablen
	int userInput = -1,					// Eingabespeicher für Hauptmenü		(-1 = Benutzer hat noch nichts eingegeben)
		userInput_sub = -1,				// Eingabespeicher für Einstellungsmenü (" - - ")
		userInput_end = -1;				// Eingabespeicher für Endabfrage (wenn Daten verändert wurden)

	bool data_changed = false,				// Ob die Daten verändert wurden
		programState = true;				// Programmschleife: An

	// Datei-/Verzeichnispfade
	char currDir[100] = { 0 },					// Aktueller Pfad
		currDir_addDir[110] = { 0 },			// Aktueller Pfad + Ordner
		currDir_filename_format[200] = { 0 },	// Aktueller Pfad + Ordner | + Dateiname (Formatierte Daten)
		currDir_filename_latex[200] = { 0 };	// Aktueller Pfad + Ordner | + Dateiname (LaTeX- Datei)

	//----- Nutzerrelevante Variablen
	config user_config = { 1, 3, 0, 0, 0, 0, 0 };

	config* user_config_pt = &user_config;

	double measurements[MAX_MEASUREMENTS][2] = { 0 };	// Array zur Abspeicherung der Daten

	// Pointer
	int* decpts_nb_pt = NULL;
	decpts_nb_pt = &(user_config.decpts_nb);		// Zur vereinfachten, globalen Wertänderung dieser Variable

	int* decpts_status_pt = NULL;
	decpts_status_pt = &user_config.decpts_status;	// Zur vereinfachten, globalen Wertänderung dieser Variable

	bool* has_label_pt = &user_config.has_label;	// Pointer für vereinfachte veränderung: Bezeichnung LaTeX- Tabelle
	bool* data_changed_pt = &data_changed;			// Pointer für vereinfachte veränderung: Daten wurden verändert

	//--< Konsolen-/Programmvoreinstellungen >---------------------------------------------------------------------------------------->>>>

	// Aktuellen Ordner(pfad) ermitteln
	GetCurrentDirectory(100, currDir);

	// String mit Namen vom absoluten Pfad und Name des Ordners erstellen
	strcpy(currDir_addDir, currDir);
	strcat(currDir_addDir, "\\");
	strcat(currDir_addDir, FOLDERNAME);

	// Ordner am aktuellen Ordnerpfad erstellen
	CreateDirectory(currDir_addDir, NULL);

	// Konsoleneinstellungen
	SetConsoleTitle(TITLE_V);
	setConsoleColor();

	//--< Durchführung >-------------------------------------------------------------------------------------------------------------->>>>

	user_config = data_load(measurements, currDir_addDir, user_config);

	user_config.column_nb = 0;	// Standard um Probleme während des Bearbeitens zu vermeiden

	do
	{
		do
		{

			system("cls");
			userInput = menu_main();

			// Durchführung der gewählten Tätigkeit
			switch (userInput)
			{
			default:	/*Loop neu starten*/																							break;
			case 0:		programState = false;																							break;		// Programm beenden
			case 1:		data_input_prime(measurements, currDir_addDir, user_config_pt);													break;		// Messdaten eingeben
			case 2:		data_output_main(measurements, user_config.decpts_nb, user_config.decpts_status, &(user_config.data_nb));								break;		// Messdaten ausgeben
			case 3:		data_changed = data_change(measurements, user_config.decpts_nb, user_config.decpts_status, &(user_config.data_nb));						break;		// Messdaten verändern (Messpunkt oder Messwert)
			case 4:		data_rearrange(measurements, user_config.decpts_nb, user_config.decpts_status, data_changed_pt, &(user_config.data_nb));				break;		// Daten ordnen
			case 5:		data_recreate(measurements, user_config, currDir_addDir, data_changed_pt);										break;		// Dateien (neu) erstellen
			//case 6:		label_input(user_config.label1, user_config.label2, user_config.label_tabular);	break;

			case 8:		disp_help();																									break;		// Hilfetext ausgeben
			case 9:		/*Einstellungen*/

				do
				{
					// Header
					HEADER

						// Optionen darlegen
						printf("Was m%cchten Sie einstellen?\n\n", 148);
					printf("<1>\tDezimalstellen nach dem Komma\n");
					//printf("<2>\tLaTeX- Code: Anzahl der Spaltenpaare\n");
					printf("<3>\tLaTeX- Code: Ob die Tabelle eine Bezeichnung besitzt (Derzeit: ");
					if (user_config.has_label)
					{
						fputs("Ja", stdout);
					}
					else
					{
						fputs("Nein", stdout);
					}
					printf(")\n");
					printf("<4>\tLaTeX- Code: Bezeichnung der Tabelle\n");
					printf("<5>\tLaTeX- Code: Spaltenbezeichnungen\n");
					printf("<6>\tNachkommastellen anzeigen bei (derzeit): ");	// Nachkommastellenanzeige togglen
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

					printf("\n<8>\tHilfe\n");
					printf("<9>\tEinstellungen anzeigen\n");
					printf("<0>\tZur%cck\n\n", 129);
					printf("Ihre Eingabe:\t");
					userInput_sub = menu_safe_input(0, 9);

					// Einstellungen
					switch (userInput_sub)
					{
					default: break;
					case 1:	user_config.decpts_nb = decpts_input(*decpts_nb_pt);										break;	// Dezimalstellen nach dem Komma
					case 2:	/*LaTeX - Code : Anzahl der Spaltenpaare*/													break;	// LaTeX - Code : Anzahl der Spaltenpaare
					case 3: user_config.has_label = !user_config.has_label;												break;	// LaTeX- Code: Ob die Tabelle eine Bezeichnung besitzt
					case 4:	label_input_fract_tabular(user_config.label_tabular);										break;	// LaTeX - Code: Bezeichnung der Tabelle
					case 5:	label_input_fract_columns(user_config.label1, user_config.label2);							break;	// LaTeX - Code : Spaltenbezeichnungen
					case 6: toggle_decpts(decpts_status_pt);															break;	// In welcher Spalte Dezimalstellen angezeigt werden
					case 8: disp_help_settings();																		break;	// Hilfe
					case 9: disp_settings_main(user_config);															break;	// Einstellungen anzeigen
					case 0:	userInput_sub = 0;																			break;	// Eine Menüstruktur zurück (Zum Hauptmenü)
					}

				} while (userInput_sub);
				break;

			}

		} while (userInput != 0);

		//--< Ende des Programms >-------------------------------------------------------------------------------------------------------->>>>
		if (data_changed)
		{
			HEADER
				printf("ACHTUNG!\n\nSie haben Ihre Daten ver%cndert, jedoch nicht abgespeichert.\nWollen Sie die Dateien jetzt neu erstellen lassen?\n\nEs werden die Dateien \""FILENAME_FORM_DATA"\" und \""FILENAME_LATEX_CODE"\" erstellt.\nDie jetzigen Einstellungen werden genutzt.\n\n<1>\tNeu erstellen\n<2>\tAbbruch\n<0>\tBeenden\n\nIhre Eingabe:\t", 132);
			userInput_end = menu_safe_input(0, 2);

			if (userInput_end == 1)
			{
				data_save_formatted(measurements, currDir_addDir, user_config.decpts_nb, user_config.decpts_status, &(user_config.data_nb));
				data_save_latex(measurements, currDir_addDir, user_config);
				drawLineCustom(196);
				printf("Dateien erfolgreich erstellt.\n\n");
			}
			if (userInput_end == 2)
			{
				programState = true;
			}
			if (userInput_end == 0)
			{
				programState = false;
			}

		}
	} while (programState);

	//--< Wahres Ende des Programms >------------------------------------------------------------------------------------------------->>>>

	data_save_bin(measurements, currDir_addDir, user_config.decpts_nb, &(user_config.data_nb));
	data_save_config(currDir_addDir, user_config);

	NEWLINE
		drawLineCustom(205);
	printf("Das Programm wird jetzt beendet.\n\n");
	system("pause");

	exit(EXIT_SUCCESS);

	return 0;
}
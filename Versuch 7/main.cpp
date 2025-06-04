/** @mainpage
 *
 * Praktikum Informatik 1 MMXXV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include "Student.h"


/**
 * @brief Überladener Ausgabestream-Operator für die Klasse Student.
 *
 * Ermöglicht die Ausgabe eines Studentenobjekts mit std::cout oder in eine Datei.
 *
 * @param out Der Ausgabestrom.
 * @param student Das Studentenobjekt, das ausgegeben werden soll.
 * @return Der Ausgabestrom.
 */
std::ostream& operator << (std::ostream& out, const Student& student)
{
	student.ausgabe(out);
    return out;
}

/**
 * @brief Haupteinstiegspunkt des Programms.
 *
 * Bietet ein textbasiertes Menü zur Interaktion mit der Liste von Studenten.
 * Der Benutzer kann Studenten hinzufügen, die Liste anzeigen, Einträge löschen usw.
 *
 * @return int Rückgabewert des Programms (0 bei regulärem Ende).
 */
int main()
{
    std::vector <Student> studentenListe;
    Student student;

    char abfrage;

    // Menüschleife
    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
				  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
				  << "(5): Datenelement loeschen" << std::endl
				  << "(6): Datenelement vorne hinzufuegen" << std::endl
				  << "(7): Daten aus einer Datei einlesen" << std::endl
				  << "(8): Daten in eine Datei sichern" << std::endl
				  << "(9): Liste sortieren" << std::endl
                  << "(0): Beenden" << std::endl;

        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
        	case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n'); //ignoriert Restzeichen der Eingabe

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        student = studentenListe.front();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        std::cout << student;
                        studentenListe.erase(studentenListe.begin());
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    for (auto it= studentenListe.begin(); it != studentenListe.end(); it++)
                    {
                    	std::cout << *it;
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;

            // Datenbank rueckwaerts ausgeben
            case '4':
            	if (!studentenListe.empty())
            	{
            		std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:" << std::endl;
            		for (auto it= studentenListe.rbegin(); it != studentenListe.rend(); it++)
                    {
            			std::cout << *it;
                    }
            	}
            	else
            	{
            		std::cout << "Die Liste ist leer!\n\n";
            	}
            	break;

            // Student loeschen nach Matrikelnummer
            case '5':
            	{
            		unsigned int mat;
            		std::cout << "Matrikelnummer: " << std::endl;
            		std::cin >> mat;

            		student = Student(mat, " ", " ", " ");

            		// studentenListe.end() is not the last element but a non-existing element after the last one (cant be dereferenced)
            		// find(iterator marking the beginning, iterator marking the end, object to be searched
            		// find() do comparison via 'if (element == value)', since == is overloaded, find() works
            		auto it = std::find(studentenListe.begin(),studentenListe.end(), student);

            		if (it != studentenListe.end())
            		{
            			std::cout << "Der folgende Student wird geloescht:\n";
            			std::cout << *it;
            		    studentenListe.erase(it);
            		    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
            		    for (auto it= studentenListe.begin(); it != studentenListe.end(); it++)
            		    {
            		    	std::cout << *it;
            		    }
            		}
            	    else
            	    {
           		        std::cout << "Student mit dieser Matrikelnummer wurde nicht gefunden.\n";
           		    }
            	}
            	break;

            // Datenelement vorne hinzufuegen
            case '6':
            	{
            		unsigned int matNr = 0;
            		std::string name = "";
            		std::string geburtstag = "";
            		std::string adresse = "";

            		std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
            		getline(std::cin, name); // ganze Zeile einlesen inklusive aller Leerzeichen

            		std::cout << "Geburtsdatum: ";
            		getline(std::cin, geburtstag);

            		std::cout << "Adresse: ";
            		getline(std::cin, adresse);

            		std::cout << "Matrikelnummer: ";
            		std::cin >> matNr;
            		std::cin.ignore(10, '\n'); // ignore 10 characters or a newline, whichever comes first

            		student = Student(matNr, name, geburtstag, adresse);

            		studentenListe.insert(studentenListe.begin(), student);
            	}
            	break;

            //Daten aus einer Datei einlesen
            case '7':
            {
            	std::string dateiname;
            	std::cout << "Geben Sie den Dateinamen ein: " << std::endl;
            	std::cin >> dateiname;

            	std::ifstream datei(dateiname);

            	if (!datei.is_open())
            	{
            		std::cout << "Datei konnte nicht geoeffnet werden." << std::endl;
            		break;
            	}

            	studentenListe.clear();

            	unsigned int matNr;
            	std::string name, geburtstag, adresse ;

            	while (datei >> matNr)
            	{
            		datei.ignore();
            		getline(datei, name);
            		getline(datei, geburtstag);
            		getline(datei, adresse);

            		student = Student(matNr, name, geburtstag, adresse);

            		studentenListe.push_back(student);
            	}
            }
			break;

			//Datei sichern
            case '8':
            {
            	std::string dateiname;
            	std::cout << "Geben Sie den Dateinamen ein: " << std::endl;
            	std::cin >> dateiname;

            	std::ofstream dateisichern (dateiname);

            	if (!dateisichern.is_open())
            	{
            		std::cout << "Datei konnte nicht geoeffnet werden." << std::endl;
            	    break;
            	}

            	if(!studentenListe.empty())
            	{
            		for (auto it= studentenListe.begin(); it != studentenListe.end(); it++)
            	    {
            	    	dateisichern << it->getMatNr() << "\n";
            	    	dateisichern << it->getName() << "\n";
            	    	dateisichern << it->getGeburtstag() << "\n";
            	    	dateisichern << it->getAdresse() << "\n";
            	    }
            		std::cout << "Daten wurden erfolgreich in die Datei gespeichert." << std::endl;
            	}
            	else
            	{
            		std::cout << "Die Liste ist leer!\n\n";
            	}
            }
            break;

            // Liste sortieren
            case '9':
            	{
            		if(!studentenListe.empty())
            		{
            			std::sort(studentenListe.begin(), studentenListe.end());
            			std::cout << "Inhalt der Liste in fortlaufender Reihenfolge (sortiert nach Matrikelnummer):" << std::endl;
            		    for (auto it= studentenListe.begin(); it != studentenListe.end(); it++)
            		    {
            		    	std::cout << *it;
            		    }
            		}
            		else
            		{
            			std::cout << "Die Liste ist leer!\n\n";
            	    }
            	}
            	break;

            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}


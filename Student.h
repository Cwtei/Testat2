//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

/**
 * @class Student
 * @brief Repräsentiert einen Studenten mit persönlichen Daten.
 *
 * Diese Klasse speichert die Matrikelnummer, den Namen, das Geburtsdatum
 * und die Adresse eines Studenten. Sie stellt Zugriffsmethoden bereit
 * sowie eine Methode zur Ausgabe der Daten auf der Konsole.
 */
class Student
{
public:
	/**
	 * @brief Standardkonstruktor, der einen leeren Studenten erstellt
	 */
    Student();

    /**
     * @brief Konstruktor, der einen neuen Studenten mit allen Werten erstellt
     *
     * @param matNr Matrikelnummer
     * @param name Name
     * @param geburtstag Geburtstag
     * @param adresse Adresse
     */
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse);

    /**
     * @brief Gibt die Matrikelnummer des Studenten zurueck
     *
     * @return Matrikelnummer
     */
    unsigned int getMatNr() const;

    /**
     * @brief Gibt den Namen des Studenten zurueck
     *
     * @return Name
     */
    std::string getName() const;

    /**
     * @brief Gibt den Geburtstag des Studenten zurueck
     *
     * @return Geburtstag
     */
    std::string getGeburtstag() const;


    /**
     * @brief Gibt die Adresse des Studenten zurueck
     *
     * @return Adresse
     */
    std::string getAdresse() const;


    /**
     * @brief Gibt alle Daten des Studenten in einer Zeile aus
     */
    void ausgabe() const;

private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

#endif

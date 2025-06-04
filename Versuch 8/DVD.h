/*
 * DVD.h
 *
 *  Created on: 17 May 2025
 *      Author: CWTei
 */

/**
 * @file DVD.h
 * @brief Deklaration der Klasse DVD zur Abbildung von DVDs in der Bibliothek.
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"
#include <string>

/**
 * @class DVD
 * @brief Repräsentiert eine DVD in der Bibliothek.
 *
 * Die Klasse DVD erbt von Medium und ergänzt dieses um die Altersfreigabe
 * und das Genre der DVD.
 */
class DVD: public Medium
{
public:

	/**
	 * @brief Konstruktor für ein DVD-Objekt.
	 * @param initTitel            Der Titel der DVD.
	 * @param initAltersfreigabe   Mindestalter in Jahren zur Ausleihe.
	 * @param initGenre            Genre oder Kategorie der DVD.
	 *
	 * Initialisiert das Medium mit dem übergebenen Titel und
	 * speichert die Altersfreigabe sowie das Genre als eigene Attribute.
	 */
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);

	/**
	 * @brief Destruktor.
	 *
	 * Gibt alle Ressourcen des DVD-Objekts frei.
	 */
	virtual ~DVD();

	/**
	 * @brief Gibt die DVD-Informationen auf der Konsole aus.
	 *
	 * Ruft zunächst Medium::ausgabe() auf (ID, Titel, Status)
	 * und ergänzt die Ausgabe um Altersfreigabe und Genre.
	 */
	void ausgabe(std::ostream& out) const override;

    /**
     * @brief Leihe prüfen und Ausleihe durchführen.
     *
     * Überschreibt Medium::ausleihen().
     * Prüft das Alter des Entleihers anhand der Altersfreigabe.
     * Bei ausreichendem Alter ruft es Medium::ausleihen() auf, sonst wird die Ausleihe abgelehnt.
     *
     * @param person       Entleiher
     * @param ausleihdatum Ausleihdatum
     * @return true  Bei erfolgreicher Ausleihe
     * @return false Bei zu jungem Entleiher oder bereits verliehen
     */
	bool ausleihen(Person person,Datum ausleihdatum) override;


private:
	/**
	 * @brief Mindestalter für die Ausleihe (in Jahren).
	 */
	int altersfreigabe;

	/**
	 * @brief Genre oder Kategorie der DVD.
	 */
	std::string genre;
};

#endif /* DVD_H_ */

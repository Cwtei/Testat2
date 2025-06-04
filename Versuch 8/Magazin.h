/*
 * Magazin.h
 *
 *  Created on: 17 May 2025
 *      Author: CWTei
 */

/**
 * @file Magazin.h
 * @brief Deklaration der Klasse Magazin zur Abbildung von Magazin-Ausgaben in der Bibliothek.
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"
#include <string>

/**
 * @class Magazin
 * @brief Repräsentiert eine Zeitschriften-Ausgabe in der Bibliothek.
 *
 * Die Klasse Magazin erbt von Medium und ergänzt dieses um das Ausgabedatum
 * (Erscheinungsdatum der Ausgabe) sowie die Sparte (Themenschwerpunkt).
 */
class Magazin: public Medium
{
public:

	/**
	 * @brief Konstruktor für ein Magazin-Objekt.
	 * @param initTitel        Der Titel der Zeitschrift.
	 * @param initDatumAusgabe Das Erscheinungsdatum dieser Ausgabe.
	 * @param initSparte       Thematische Sparte oder Genre der Zeitschrift.
	 *
	 * Initialisiert das Medium mit dem übergebenen Titel und
	 * speichert das Ausgabedatum und die Sparte als eigene Attribute.
	 */
	Magazin(std::string initTitel, Datum initDatumAusgabe,
			std::string initSparte);

	/**
	 * @brief Destruktor.
	 *
	 * Gibt alle Ressourcen des Magazin-Objekts frei.
	 */
	virtual ~Magazin();

	/**
	 * @brief Gibt die Magazin-Informationen auf der Konsole aus.
	 *
	 * Ruft zunächst Medium::ausgabe() auf (ID, Titel, Status)
	 * und ergänzt die Ausgabe um das Erscheinungsdatum und die Sparte.
	 */
	void ausgabe(std::ostream& out) const override;

	/**
	 * @brief Versucht, die Magazin-Ausgabe auszuleihen unter Berücksichtigung der Ausgabedatum-Beschränkung.
	 *
	 * Überschreibt Medium::ausleihen().
	 * Prüft zunächst, ob das Ausleihdatum vor dem Erscheinungsdatum dieser Ausgabe liegt.
	 * Ist dies der Fall, wird die aktuelle Ausgabe als „zu neu“ abgelehnt.
	 * Andernfalls wird die Basisklassen-Logik aufgerufen, um Standard-Ausleihbedingungen zu prüfen.
	 *
	 * @param person       Die Person, die das Magazin entleihen möchte.
	 * @param ausleihdatum Das Datum, an dem die Ausleihe erfolgen soll.
	 * @return true  Wenn das Magazin nicht die neueste Ausgabe ist und noch nicht verliehen war.
	 * @return false Wenn es sich um die neueste Ausgabe handelt oder das Medium bereits verliehen ist.
	 */
	bool ausleihen(Person person,Datum ausleihdatum) override;

private:
	/**
	 * @brief Erscheinungsdatum dieser Magazin-Ausgabe.
	 */
	Datum datumAusgabe;

	/**
	 * @brief Thematische Sparte oder Genre der Zeitschrift.
	 */
	std::string sparte;
};

#endif /* MAGAZIN_H_ */

/*
 * Buch.h
 *
 *  Created on: 17 May 2025
 *      Author: CWTei
 */

/**
 * @file Buch.h
 * @brief Deklaration der Klasse Buch, abgeleitet von Medium, zur Abbildung von Büchern.
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"
#include <string>

/**
 * @class Buch
 * @brief Repräsentiert ein Buch in der Bibliothek.
 *
 * Die Klasse Buch erbt von Medium und ergänzt dieses um den Autor bzw. die Autorin.
 */
class Buch: public Medium
{
public:
	/**
	 * @brief Konstruktor für ein Buch-Objekt.
	 * @param initTitel  Der Titel des Buches.
	 * @param initAutor  Der Name des Autors oder der Autorin.
	 *
	 * Initialisiert das Medium mit dem übergebenen Titel und
	 * speichert den Autor in einem eigenen Attribut.
	 */
	Buch(std::string initTitel, std::string initAutor);

	/**
	 * @brief Destruktor.
	 *
	 * Gibt alle Ressourcen des Buch-Objekts frei.
	 */
	virtual ~Buch();

	/**
	 * @brief Gibt die Buch-Informationen auf der Konsole aus.
	 *
	 * Ruft zunächst Medium::ausgabe()
	 * und ergänzt die Ausgabe um den Autor bzw. die Autorin.
	 */
	void ausgabe(std::ostream& out) const override;

private:
	/**
	 * @brief Name des Autors bzw. der Autorin des Buches.
	 */
	std::string autor;

};


#endif /* BUCH_H_ */

/*
 * Magazin.cpp
 *
 *  Created on: 17 May 2025
 *      Author: CWTei
 */

#include "Magazin.h"
# include <iostream>

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
: Medium (initTitel), datumAusgabe (initDatumAusgabe), sparte (initSparte)
{}

Magazin::~Magazin()
{}

void Magazin::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out); // print out the original output first
	out << "Ausgabe: " << datumAusgabe << std::endl;
	out << "Sparte: " << sparte << std::endl;
}

bool Magazin::ausleihen(Person person,Datum ausleihdatum)
{
	if (ausleihdatum - datumAusgabe < 0)
	{
		std::cout << "Neueste Ausgabe kann nicht verliehen werden." << std::endl;
		return false;
	}
	return Medium::ausleihen(person,ausleihdatum);
}

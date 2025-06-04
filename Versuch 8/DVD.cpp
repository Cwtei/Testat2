/*
 * DVD.cpp
 *
 *  Created on: 17 May 2025
 *      Author: CWTei
 */

#include "DVD.h"
#include <iostream>

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
: Medium (initTitel), altersfreigabe (initAltersfreigabe), genre (initGenre)
{}

DVD::~DVD()
{}

void DVD::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out); // print out the original output first
	out << "FSK: ab " << altersfreigabe << " Jahre" << std::endl;
	out << "Genre: " << genre << std::endl;

}

bool DVD::ausleihen(Person person,Datum ausleihdatum)
{
	if (ausleihdatum - person.getGeburtsdatum() >= altersfreigabe * 12)
	{
		return Medium::ausleihen(person,ausleihdatum);
	}
	std::cout << "Entleiher ist zu jung." << std::endl;
	return false;
}


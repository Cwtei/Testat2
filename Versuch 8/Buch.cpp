/*
 * Buch.cpp
 *
 *  Created on: 17 May 2025
 *      Author: CWTei
 */

#include "Buch.h"
#include  <iostream>

Buch::Buch(std::string initTitel, std::string initAutor)
: Medium (initTitel), // 'titel' is assigned to Medium, so Medium = initTitel
  autor (initAutor)
{}

Buch::~Buch()
{}


// if I have a variable under the class Buch name buch1, when i type buch1.ausgabe(),
// it will do buch1.ausgabe() which the ausgabe() is the one defined under Medium,
// printing out the status, name and id, then print out the author of buch1
void Buch::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out); // print out the original output first
	out << "Autor: " << autor << std::endl;

}

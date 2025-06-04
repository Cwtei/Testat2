/*!
 * Praktikum Informatik 1 
 * 
 *
 * @file Medium.cpp
 */
 
#include "Medium.h"

#include <string>
#include <iostream>

unsigned int Medium::currentID = 1;

Medium::Medium(std::string initTitel)
: titel(initTitel)
, status(false)
{
    ID = currentID++;
}

Medium::~Medium(void)
{
}


void Medium::ausgabe(std::ostream& out) const
{
    out << "ID: " << ID << std::endl;
    out << "Titel: " << titel << std::endl;

    if (status)
    {
        out << "Status : Das Medium ist seit dem " << datumAusgeliehen << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
    }
    else
    {
        out << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
    }
}

bool Medium::ausleihen(Person person,Datum ausleihdatum)
{
    if (status)
    {
        std::cout << "Das Medium \"" << titel << "\" ist bereits verliehen!" << std::endl;
        return false;
    }
    else
    {
        status = true;
        personAusgeliehen = person;
        datumAusgeliehen = ausleihdatum;
        std::cout << "Das Medium \"" << titel << "\" wird an " << person.getName() << " verliehen." << std::endl;
        return true;
    }
}

void Medium::zurueckgeben()
{
    if (status)
    {
        status = false;
        std::cout << "Das Medium \"" << titel << "\" wurde zur�ckgegeben." << std::endl;
    }
    else
    {
        std::cout << "Das Medium \"" << titel << "\" ist nicht verliehen!" << std::endl;
    }
}

unsigned int Medium::getID()
{
    return ID;
}

// the & at Medium& titel is saying "inside this function, the name 'titel' refers directly to the same
// object the caller passed in
// if I don't include const, it can only deal with variable which are not const,
// but if I do, it can deal with both const and not const variable

// overloading the operator << does not happens only in the class Medium, i can also write it anywhere
// in any file in this project and it will still work, and when i for example do std::cout << somemedium,
// it will do somemedium.ausgabe(), then depends on the type of medium it can be Buch, Magazin or DVD,
// it will access different ausgabe function to print different output, is my understanding correct now
std::ostream& operator << (std::ostream& out, const Medium& titel)
{
	titel.ausgabe(out);
	return out;
}

bool Medium::getStatus()
{
	return status;
}

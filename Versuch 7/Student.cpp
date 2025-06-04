//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.h"


Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }


unsigned int Student::getMatNr() const
{
    return matNr;
}

std::string Student::getName() const
{
    return name;
}


std::string Student::getGeburtstag() const
{
    return geburtstag;
}


std::string Student::getAdresse() const
{
    return adresse;
}


void Student::ausgabe(std::ostream& out) const
{
    out << name << ", MatNr. " << matNr << ", geb. am "
    		<< geburtstag << ", wohnhaft in " << adresse << std::endl;
}

// example if (student1 == student2), student1 is the 'this', student2 is the parameter student
bool Student::operator == (const Student& student) const
{
	return(this->matNr == student.matNr);
}

bool Student::operator < (const Student& student) const
{
	return (this->matNr < student.matNr);
}

bool Student::operator > (const Student& student) const
{
	return (this->matNr > student.matNr);
}

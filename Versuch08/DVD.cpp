/*
 * DVD.cpp
 *
 *  Created on: 15.05.2023
 *      Author: aliihsangungoren
 */

#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string
		initGenre):Medium(initTitel),initAltersfreigabe(initAltersfreigabe),initGenre(initGenre)
{
	// TODO Auto-generated constructor stub

}

DVD::~DVD()
{
	// TODO Auto-generated destructor stub
}

/*!
 *  @brief Gibt die Eigenschaften Raus
 */
void DVD::ausgabe() const
{
Medium::ausgabe();
std::cout<<"FSK: "<<initAltersfreigabe<<"\n"
"Genre: "<<initGenre<<"\n";

}

/**
 * @brief gibt die medium aus wenn es moeglich ist
 */

bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
	if(ausleihdatum-person.getGeburtsdatum()<initAltersfreigabe*12)
	{
	std::cout<<"Kann nicht ausgeliehen werden wegen Altersfreigabe";

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

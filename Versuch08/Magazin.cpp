/*
 * Magazin.cpp
 *
 *  Created on: 15.05.2023
 *      Author: aliihsangungoren
 */

#include "Magazin.h"

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte): Medium(initTitel),initDatumAusgabe(initDatumAusgabe),initSparte(initSparte)
{
	// TODO Auto-generated constructor stub

}

Magazin::~Magazin()
{
	// TODO Auto-generated destructor stub
}
/**
 * @brief gibt die eigenschaften fur die media aus
 */
void Magazin::ausgabe() const
{
Medium::ausgabe();
std::cout<<"Ausagbe: "<<initDatumAusgabe<<"\n"<<"Sparte: "<<initSparte<<"\n";
}

/**
 * @brief ausleiht die objekt
 */

bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
if(ausleihdatum-initDatumAusgabe<1)
{
std::cout<<"Kann nicht ausgeliehen werden es ist die neusete Ausgabe";
return false;
}
else
{
Medium::ausleihen(person, ausleihdatum);
return true;
}

}

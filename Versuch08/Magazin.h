/*
 * Magazin.h
 *
 *  Created on: 15.05.2023
 *      Author: aliihsangungoren
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_
#include "Datum.h"
#include "Medium.h"

class Magazin: public Medium
{
public:
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
	virtual ~Magazin();


private:
	Datum initDatumAusgabe;
	std::string initSparte;
     void ausgabe() const;
	 bool ausleihen(Person person, Datum ausleihdatum);

};

#endif /* MAGAZIN_H_ */

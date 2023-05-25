/*
 * DVD.h
 *
 *  Created on: 15.05.2023
 *      Author: aliihsangungoren
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"

class DVD: public Medium
{
public:
	DVD(std::string initTitel, int initAltersfreigabe, std::string
			initGenre);
	virtual ~DVD();
    void ausgabe() const;

private:
	int initAltersfreigabe;
	std::string initGenre;
    bool ausleihen(Person person, Datum ausleihdatum);

};

#endif /* DVD_H_ */

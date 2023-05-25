/*
 * Buch.h
 *
 *  Created on: 12.05.2023
 *      Author: aliihsangungoren
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"

class Buch: public Medium
{
public:
	Buch(std::string initTitel, std::string initAutor);
	virtual ~Buch();
    void ausgabe() const;
private:
std::string initAutor;


};

#endif /* BUCH_H_ */

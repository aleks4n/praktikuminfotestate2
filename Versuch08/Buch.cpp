/*
 * Buch.cpp
 *
 *  Created on: 12.05.2023
 *      Author: aliihsangungoren
 */

#include "Buch.h"

Buch::Buch(std::string initTitel, std::string initAutor):Medium(initTitel),initAutor(initAutor)
{
	// TODO Auto-generated constructor stub

}

Buch::~Buch()
{
	// TODO Auto-generated destructor stub
}

void Buch::ausgabe() const
{
Medium::ausgabe();
std::cout<<"Autor: "<<initAutor<<"\n";
}


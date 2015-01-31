/*
 * rgb.h
 *
 *  Created on: 05-nov-2014
 *      Author: Juan Antonio Echeverrias Aranda
 */


#ifndef RGB_H_
#define RGB_H_

#include <iostream>


class Rgb {

public:

	Rgb();
	Rgb(unsigned int r, unsigned int v, unsigned int a);
	Rgb(const Rgb& color);

	~Rgb();

	unsigned int getRojo()const;
	unsigned int getVerde()const;
	unsigned int getAzul()const;

	void setColores (unsigned int r, unsigned int v, unsigned int a);

	Rgb& operator=(const Rgb& color);

	friend std::ostream& operator<< (std::ostream& os,  const Rgb& rgb);
	friend std::istream& operator>> (std::istream& is,  Rgb& rgb);


private:

	unsigned int _rojo;
	unsigned int _verde;
	unsigned int _azul;

	// Comprueba si alguno de los colores que recibe excede del valor 255.
	bool esColorCorrecto(unsigned int r, unsigned int v, unsigned int a);

};


#endif /* RGB_H_ */

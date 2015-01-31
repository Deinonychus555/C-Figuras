/*
 * punto.h
 *
 *  Created on: 05-nov-2014
 *      Author: Juan Antonio Echeverrias Aranda
 */

#ifndef PUNTO_H_
#define PUNTO_H_

#include "rgb.h"
#include "matriz.h"


class Punto{

public:

	Punto();
	Punto (double x, double y);
	Punto (const Punto& p);

	~Punto();

	double getX() const;
	double getY() const;

	void setX(double x);
	void setY(double y);
	void setCoordenadas(double x, double y);

	void trasladar(double x, double y);

	// Calcula la distancia al punto que recibe como argumento.
	double distancia (const Punto& p) const;

	// Cambia el color de la posición de la matriz que coincide con sus coordenadas.
	void pintar(const Rgb& color, Matriz& lienzo) const;

	Punto& operator=(const Punto& p);

	bool operator== (const Punto& p) const;

	friend std::ostream& operator<< (std::ostream& os, const Punto& punto);
	friend std::istream& operator>> (std::istream& is, Punto& punto);


private:

	double _x;
	double _y;

	// Indica si el punto se encuentra en el lienzo que recibe.
	bool estaEnLienzo (Matriz& lienzo) const;

};


#endif /* PUNTO_H_ */

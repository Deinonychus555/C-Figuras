/*
 * area.h
 *
 *  Created on: 05-nov-2014
 *      Author: Juan Antonio Echeverrias Aranda
 */

#ifndef AREA_H_
#define AREA_H_

#include "punto.h"


class Area {

public:

	Area();
	Area(double minX, double minY, double maxX, double maxY);
	Area(Punto supIzq, Punto infDch);

	~Area();

	Punto getVertice1() const;
	Punto getVertice2() const;
	Punto getVertice3() const;
	Punto getVertice4() const;

	void setArea(double minX, double minY, double maxX, double maxY);

	// En el caso que una figura se traslade su área de selección
	// también se trasladará.
	void trasladar(double x, double y);

	// Función para comprobar si un punto está dentro del área de selección.
	bool estaDentro(const Punto& p) const;
	bool estaDentro(double x, double y) const;

	Area& operator=(const Area& area);


private:

	// No es necesario declarar 4 puntos, con 2 hubiera sido suficiente.
	Punto _p1;
	Punto _p2;
	Punto _p3;
	Punto _p4;

};


#endif /* AREA_H_ */

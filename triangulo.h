/*
 * segmento.h
 *
 *  Created on: 05-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */


#ifndef TRIANGULO_H_
#define TRIANGULO_H_

#include "figura.h"


class Triangulo:public Figura{

public:

	Triangulo();
    Triangulo(const Punto& p1, const Punto& p2, const Punto& p3, const Rgb& color);

    ~Triangulo();

    Punto getVertice1() const;
	Punto getVertice2() const;
	Punto getVertice3() const;

	void setVertice1(double x, double y);
	void setVertice1(const Punto& punto);
	void setVertice2(double x, double y);
	void setVertice2(const Punto& punto);
	void setVertice3(double x, double y);
	void setVertice3(const Punto& punto);

	Punto calcularCentroide() const;

	void trasladar(double x, double y);

	void pintar(Matriz& lienzo)const;

	std::string toString()const;
	std::istream& leerEntrada(std::istream& is);

	friend std::ostream& operator<<(std::ostream& os,  const Triangulo& figura);
	friend std::istream& operator>>(std::istream& is,  Triangulo& figura);


private:

	Punto _p1;
	Punto _p2;
	Punto _p3;

	// Funciones utilizadas para calcular las coordenadas máximas y mínimas
	// de la figura, necesarias para calcular el área de selección.
	double getXMin() const;
	double getYMin() const;
	double getXMax() const;
	double getYMax() const;

	void calcularArea();

};


#endif /* TRIANGULO_H_ */

/*
 * segmento.h
 *
 *  Created on: 05-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */


#ifndef RECTANGULO_H_
#define RECTANGULO_H_

#include "figura.h"


class Rectangulo:public Figura{

public:


    Rectangulo();
    Rectangulo(const Punto& p1, unsigned int anchura, unsigned int altura, const Rgb& color);

	~Rectangulo();

	Punto getVertice1() const;
	Punto getVertice2() const;
	Punto getVertice3() const;
	Punto getVertice4() const;

	void setVertice1(double x, double y);
	void setVertice1(const Punto& punto);
	void setVertice2(double x, double y);
	void setVertice2(const Punto& punto);
	void setVertice3(double x, double y);
	void setVertice3(const Punto& punto);
	void setVertice4(double x, double y);
	void setVertice4(const Punto& punto);

	Punto calcularCentroide() const;

	void trasladar(double x, double y);

	void pintar(Matriz& lienzo)const;

	std::string toString()const;
	std::istream& leerEntrada (std::istream& is);

	friend std::ostream& operator<< (std::ostream& os,  const Rectangulo& figura);
	friend std::istream& operator>> (std::istream& is,  Rectangulo& figura);


private:

	Punto _p1;
	Punto _p2;
	Punto _p3;
	Punto _p4;

	void calcularArea();

};


#endif /* RECTANGULO_H_ */

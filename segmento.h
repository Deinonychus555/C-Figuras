/*
 * segmento.h
 *
 *  Created on: 05-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */



#ifndef SEGMENTO_H_
#define SEGMENTO_H_

#include "figura.h"


class Segmento:public Figura{

public:

    Segmento();
    Segmento(const Punto& p1, const Punto& p2, const Rgb& color);

    ~Segmento();

	Punto getExtremo1() const;
	Punto getExtremo2() const;

	void setExtremo1(const Punto& punto);
	void setExtremo1(double x, double y);
	void setExtremo2(const Punto& punto);
	void setExtremo2(double x, double y);

	Punto calcularCentroide() const;

	void trasladar(double x, double y);

	void pintar(Matriz& lienzo) const;

	std::string toString()const;
	std::istream& leerEntrada (std::istream& is);

	friend std::ostream& operator<< (std::ostream& os,  const Segmento& figura);
	friend std::istream& operator>> (std::istream& is,  Segmento& figura);


private:

	Punto _p1;
	Punto _p2;

	// Funciones utilizadas para calcular las coordenadas máximas y mínimas
	// de la figura, necesarias para calcular el área de selección.
	double getXMin() const;
	double getYMin() const;
	double getXMax() const;
	double getYMax() const;

	void calcularArea();

};


#endif /* SEGMENTO_H_ */

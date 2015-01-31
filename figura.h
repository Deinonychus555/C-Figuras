/*
 * figura.h
 *
 *  Created on: 05-nov-2014
 *      Author: Juan Antonio Echeverrias Aranda
 */


#ifndef FIGURA_H_
#define FIGURA_H_


#include "punto.h"
#include "rgb.h"
#include "area.h"
#include <string>
#include <iostream>


class Figura{

protected:

	Figura();
	Figura(const Rgb& color);

	void Bresenham (const Punto& p1,const Punto& p2, const Rgb& color, Matriz& lienzo) const;
	void Bresenham (int x1, int y1, int x2, int y2, const Rgb& color, Matriz& lienzo) const;

	virtual void calcularArea()=0;

	Area _areaSeleccion;


public:

	virtual ~Figura();

	int getId() const;
	Rgb getColor() const;
	Area getAreaSeleccion() const;

	void setColor(const Rgb& color);
	void setColor(unsigned int r, unsigned int v, unsigned int a);
	void setAreaSeleccion(const Area& area);

	// Función para comprobar si  un punto se encuentra en el área de
	// selección de la figura.
	virtual bool seleccionar(const Punto& punto) const;

	virtual Punto calcularCentroide() const=0;


	// Esta función calcula la distancia entre el punto que recibe como argumento
	// y su centroide.
	virtual double distancia(const Punto& punto) const;

	virtual void trasladar(double x, double y)=0;

	// Función para pintar la figura en el lienzo, utiliza la función 'Bresenham'.
	virtual void pintar(Matriz& lienzo) const=0;

	virtual std::string toString() const=0;

	// Está función es para garantizar el polimorfismo al leer una figura,
	// ya que la sobrecarga de 'operator>>' no la podemos hacer virtual al
	// tratarse de una función amiga, por lo que desde dicha función se llamará
	// a 'leerEntrada', que si es virtual, por lo que garantiza el polimorfismo
	// y se leera la figura por la entrada estándar.
	virtual std::istream& leerEntrada (std::istream& is)=0;

	// Dos figuras son iguales si poseen el mismo identificador (atributo '_id').
	bool operator==(const Figura& p) const;

	friend std::ostream& operator<< (std::ostream& os,  const Figura& figura);
	friend std::istream& operator>> (std::istream& is,  Figura& figura);


private:

	// Atributo que se comporta como un contador que se incrementa cada vez
	// que se crea una figura. Se utiliza para dar valor único al
	// atributo '_id' de cada figura, que será su identificador.
	static int _genid;

	// Este atributo se utiliza para saber si dos figuras son o  no la misma.
	int _id;
	Rgb _color;

};


#endif /* FIGURA_H_ */

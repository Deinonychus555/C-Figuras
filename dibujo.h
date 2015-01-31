/*
 * dibujo.h
 *
 *  Created on: 05-nov-2014
 *      Author: Juan Antonio echeverr�as Aranda
 */


#ifndef DIBUJO_H_
#define DIBUJO_H_


#include <list>
#include "figura.h"
#include "matriz.h"
#include "factoriaFigura.h"
#include <boost/shared_ptr.hpp>

// Nombre del fichero por defecto d�nde se va a guardar la informaci�n del dibujo
// en caso de no introducir ning�n nombre.
#define FICHERO_SALIDA "dibujo.ppm"


class Dibujo {

public:

    Dibujo();
	Dibujo (unsigned int ancho, unsigned int alto, const Rgb& color);

	~Dibujo();

	unsigned int getAncho() const;
	unsigned int getAlto() const;
	Rgb getColorFondo() const;
	std::list < boost::shared_ptr<Figura> > getFiguras() const;

	void setColorFondo(unsigned int r, unsigned int v, unsigned int a);

	// Con esta funci�n recalculamos el tama�o del dibujo,
	// el atributo _lienzo se borrar� y se crear� de nuevo,
	// las figuras seguir�n estando en la lista '_figuras'.
	void setDimension(unsigned int ancho, unsigned int alto);


	void insertarFigura(boost::shared_ptr<Figura> figura);

	void agregarSeleccion(const Punto& p);
	void agregarSeleccion(double x, double y);

	void seleccionar(const Punto& p);
	void seleccionar(double x, double y);

	void deseleccionar();

	void moverSeleccion (double x, double y);

	void borrarSeleccion();

	void agruparSeleccion();

	void desagruparSeleccion();

	// Funci�n para guardar la informaci�n del dibujo en un archivo que
	// por defecto se llamar� 'dibujo.ppm'
	void guardarEnFichero(std::string defaultValue=FICHERO_SALIDA);

	friend std::ostream& operator<< (std::ostream& os,  const Dibujo& dibujo);
	friend std::istream& operator>> (std::istream& is,  Dibujo& dibujo);


private:

	Punto _supIzq; // Por defecto ser� el punto (0,0)
	Punto _infDch;
	Rgb _colorFondo;
	std::list < boost::shared_ptr<Figura> > _figuras;
	std::list < boost::shared_ptr<Figura> > _seleccion;
	Matriz* _lienzo;

	// Factor�a para crear las figuras.
	boost::shared_ptr<FactoriaFigura> _factoria;

	// Esta funci�n leera operaciones de la entrada estandar y las ejecutar�.
	void realizarOperacion(std::istream& is);

	// Esta funci�n recibe el nombre del tipo de una figura y actualiza
	// el atributo '_factor�a' a la factor�a adecuada para fabricar dicha figura.
	void setFactoria(std::string claseFigura);

};


#endif /* DIBUJO_H_ */

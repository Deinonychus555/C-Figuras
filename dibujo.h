/*
 * dibujo.h
 *
 *  Created on: 05-nov-2014
 *      Author: Juan Antonio echeverrías Aranda
 */


#ifndef DIBUJO_H_
#define DIBUJO_H_


#include <list>
#include "figura.h"
#include "matriz.h"
#include "factoriaFigura.h"
#include <boost/shared_ptr.hpp>

// Nombre del fichero por defecto dónde se va a guardar la información del dibujo
// en caso de no introducir ningún nombre.
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

	// Con esta función recalculamos el tamaño del dibujo,
	// el atributo _lienzo se borrará y se creará de nuevo,
	// las figuras seguirán estando en la lista '_figuras'.
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

	// Función para guardar la información del dibujo en un archivo que
	// por defecto se llamará 'dibujo.ppm'
	void guardarEnFichero(std::string defaultValue=FICHERO_SALIDA);

	friend std::ostream& operator<< (std::ostream& os,  const Dibujo& dibujo);
	friend std::istream& operator>> (std::istream& is,  Dibujo& dibujo);


private:

	Punto _supIzq; // Por defecto será el punto (0,0)
	Punto _infDch;
	Rgb _colorFondo;
	std::list < boost::shared_ptr<Figura> > _figuras;
	std::list < boost::shared_ptr<Figura> > _seleccion;
	Matriz* _lienzo;

	// Factoría para crear las figuras.
	boost::shared_ptr<FactoriaFigura> _factoria;

	// Esta función leera operaciones de la entrada estandar y las ejecutará.
	void realizarOperacion(std::istream& is);

	// Esta función recibe el nombre del tipo de una figura y actualiza
	// el atributo '_factoría' a la factoría adecuada para fabricar dicha figura.
	void setFactoria(std::string claseFigura);

};


#endif /* DIBUJO_H_ */

/*
 * grupo.h
 *
 *  Created on: 13-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */

#ifndef GRUPO_H_
#define GRUPO_H_

#include "figura.h"
#include <list>
#include <boost/shared_ptr.hpp>



// Esta clase se basa en el patrón 'Composite',
// ya que hereda de la clase Figura y además
// contiene un atributo lista de Figuras.

class Grupo:public Figura{

public:

	Grupo();

	~Grupo();

	void insertarFigura(boost::shared_ptr<Figura> figura);

	std::list < boost::shared_ptr<Figura> > getFiguras()const;

	// Si el punto que recibe la función, está dentro del área de selección de
	// alguna de las figuras que contiene el grupo, el grupo quedará seleccionado.
	bool seleccionar(const Punto& punto) const;

	Punto calcularCentroide() const;

	// Esta función calcula la distancia mínima entre el punto que recibe como
	// argumento y el centroide de una de las figuras que contiene.
	double distancia(const Punto& punto) const;

	// Traslada todas las figuras que contiene el grupo.
	void trasladar(double x, double y);

	void pintar(Matriz& lienzo)const;

	std::string toString()const;
	std::istream& leerEntrada (std::istream& is);

	Figura& operator=(const Figura& figura);

	friend std::ostream& operator<<(std::ostream& os, const Grupo& figura);


private:

	std::list < boost::shared_ptr<Figura> > _figuras;

	void calcularArea();

};

#endif /* GRUPO_H_ */

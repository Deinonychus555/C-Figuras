/*
 * factoriaFigura.h
 *
 *  Created on: 06-nov-2014
 *      Author: Juan Antonio Echeverr�as Aranda
 */


#ifndef FACTORIAFIGURA_H_
#define FACTORIAFIGURA_H_

#include "figura.h"
#include <map>
#include <string>
#include <iostream>
#include <boost/shared_ptr.hpp>


// Esta clase implementa el patr�n 'Factory'. De esta clase heredan las clases
// 'FactoriaSegmento', 'FactoriaTriangulo' y 'FactoriaRectangulo'. Consta de una
// funci�n virtual pura, 'fabricar', que implementan sus clases hijas, creando �stas
// las figuras correspondientes.
// Posee un atributo 'static' de tipo 'map' cuya clave es una clase de figura y su
// valor es una instancia a la factor�a correspondiente a la clave.
// Declaro las clases 'Dibujo' y 'FactoriaFiguraInicializacion' "amigas", para que
// tengan acceso a dicho atributo, esta �ltima ser� la encargada de inicializar
// '_factorias' creando las instancias de las diferentes factor�as, por otro lado
// la calse 'Dibujo' acceder� al atributo para obtener la factor�a adecuada para
// crear las distintas figuras.

class FactoriaFigura{

public:

	friend class FactoriaFiguraInicializacion;
	friend class Dibujo;

	// Recibe como argumento un 'istream' ya que las figuras se van a leer
	// de la entrada estandar.
	virtual boost::shared_ptr<Figura> fabricar(std::istream& is)=0;

protected:

	FactoriaFigura();

	virtual ~FactoriaFigura();


private:

	static std::map< std::string, boost::shared_ptr<FactoriaFigura> > _factorias;

};


#endif /* FACTORIAFIGURA_H_ */

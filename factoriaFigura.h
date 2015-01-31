/*
 * factoriaFigura.h
 *
 *  Created on: 06-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */


#ifndef FACTORIAFIGURA_H_
#define FACTORIAFIGURA_H_

#include "figura.h"
#include <map>
#include <string>
#include <iostream>
#include <boost/shared_ptr.hpp>


// Esta clase implementa el patrón 'Factory'. De esta clase heredan las clases
// 'FactoriaSegmento', 'FactoriaTriangulo' y 'FactoriaRectangulo'. Consta de una
// función virtual pura, 'fabricar', que implementan sus clases hijas, creando éstas
// las figuras correspondientes.
// Posee un atributo 'static' de tipo 'map' cuya clave es una clase de figura y su
// valor es una instancia a la factoría correspondiente a la clave.
// Declaro las clases 'Dibujo' y 'FactoriaFiguraInicializacion' "amigas", para que
// tengan acceso a dicho atributo, esta última será la encargada de inicializar
// '_factorias' creando las instancias de las diferentes factorías, por otro lado
// la calse 'Dibujo' accederá al atributo para obtener la factoría adecuada para
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

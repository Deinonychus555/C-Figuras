/*
 * factoriaFiguraInicializacion.h
 *
 *  Created on: 07-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */

#ifndef FACTORIAFIGURAINICIALIZACION_H_
#define FACTORIAFIGURAINICIALIZACION_H_

// Esta clase se basa en el patrón 'Singleton',
// ya que posee un atributo 'static' que consiste
// en una instancia de la misma clase.
// Con esto nos aseguramos que solo hay una instancia
// de esta clase.

#include <boost/shared_ptr.hpp>

class FactoriaFiguraInicializacion{


	static FactoriaFiguraInicializacion* ffi;

	FactoriaFiguraInicializacion();

	~FactoriaFiguraInicializacion();

};


#endif /* FACTORIAFIGURAINICIALIZACION_H_ */

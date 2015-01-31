/*
 * factoriaSegmento.cpp
 *
 *  Created on: 06-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */

#include "factoriaRectangulo.h"

using namespace std;


FactoriaRectangulo::FactoriaRectangulo(){}


FactoriaRectangulo::~FactoriaRectangulo(){}

boost::shared_ptr<Figura> FactoriaRectangulo::fabricar(istream& is){

	boost::shared_ptr< Rectangulo > rectangulo(new Rectangulo());
	// Leemos la figura de la entrada estandar.
	is >> *rectangulo;

	return rectangulo;
}


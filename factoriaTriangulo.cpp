/*
 * factoriaSegmento.cpp
 *
 *  Created on: 06-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */

#include "factoriaTriangulo.h"

using namespace std;


FactoriaTriangulo::FactoriaTriangulo(){}


FactoriaTriangulo::~FactoriaTriangulo(){}


boost::shared_ptr<Figura> FactoriaTriangulo::fabricar(istream& is){

	boost::shared_ptr<Triangulo> triangulo(new Triangulo());
	// Leemos la figura de la entrada estandar.
	is >> *triangulo;

	return triangulo;
}

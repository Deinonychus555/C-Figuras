/*
 * factoriaSegmento.cpp
 *
 *  Created on: 06-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */

#include "factoriaSegmento.h"

using namespace std;


FactoriaSegmento::FactoriaSegmento(){}


FactoriaSegmento::~FactoriaSegmento(){}


boost::shared_ptr<Figura> FactoriaSegmento::fabricar(istream& is){

	boost::shared_ptr<Segmento> segmento(new Segmento());
	// Leemos la figura de la entrada estandar.
	is >> *segmento;

	return segmento;
}


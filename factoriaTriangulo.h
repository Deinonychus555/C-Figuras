/*
 * factoriaSegmento.h
 *
 *  Created on: 06-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */

#ifndef FACTORIATRIANGULO_H_
#define FACTORIATRIANGULO_H_

#include "factoriaFigura.h"
#include "triangulo.h"


class FactoriaTriangulo:public FactoriaFigura{

public:

	FactoriaTriangulo();

	~FactoriaTriangulo();

	boost::shared_ptr<Figura> fabricar(std::istream& is);

};


#endif /* FACTORIATRIANGULO_H_ */

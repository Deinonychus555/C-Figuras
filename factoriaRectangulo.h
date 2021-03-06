/*
 * factoriaSegmento.h
 *
 *  Created on: 06-nov-2014
 *      Author: Juan Antonio Echeverrķas Aranda
 */

#ifndef FACTORIARECTANGULO_H_
#define FACTORIARECTANGULO_H_

#include "factoriaFigura.h"
#include "rectangulo.h"


class FactoriaRectangulo:public FactoriaFigura{

public:

	FactoriaRectangulo();

	~FactoriaRectangulo();

	boost::shared_ptr<Figura> fabricar(std::istream& is);

};


#endif /* FACTORIARECTANGULO_H_ */

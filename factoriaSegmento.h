/*
 * factoriaSegmento.h
 *
 *  Created on: 06-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */

#ifndef FACTORIASEGMENTO_H_
#define FACTORIASEGMENTO_H_

#include "factoriaFigura.h"
#include "segmento.h"


class FactoriaSegmento:public FactoriaFigura{

public:

	FactoriaSegmento();

	~FactoriaSegmento();

	boost::shared_ptr<Figura> fabricar(std::istream& is);

};


#endif /* FACTORIASEGMENTO_H_ */

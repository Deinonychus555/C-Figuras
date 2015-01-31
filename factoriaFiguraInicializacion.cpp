/*
 * factoriaFiguraInicializacion.cpp
 *
 *  Created on: 07-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */

#include "factoriaFiguraInicializacion.h"
#include "factoriaFigura.h"
#include "factoriaSegmento.h"
#include "factoriaTriangulo.h"
#include "factoriaRectangulo.h"

using namespace std;

// Declaramos el nombre de las figuras según
// aparecerá por la entrada.

#define SEGMENTO "Seg"
#define TRIANGULO "Tri"
#define RECTANGULO "Rec"


FactoriaFiguraInicializacion* FactoriaFiguraInicializacion::ffi=new FactoriaFiguraInicializacion();

// El constructor inicializa el atributo '_factorias' de la clase 'FactoriaFiguras',
// creando instancias de las diferentes factorías.
FactoriaFiguraInicializacion::FactoriaFiguraInicializacion(){

	boost::shared_ptr<FactoriaSegmento>fs (new FactoriaSegmento());
	boost::shared_ptr<FactoriaTriangulo>ft (new FactoriaTriangulo());
	boost::shared_ptr<FactoriaRectangulo>fr (new FactoriaRectangulo());
	// Ahora asociamos la clave a su factoría correspondiente.
	FactoriaFigura::_factorias[SEGMENTO]=fs;
	FactoriaFigura::_factorias[TRIANGULO]=ft;
	FactoriaFigura::_factorias[RECTANGULO]=fr;
}


FactoriaFiguraInicializacion::~FactoriaFiguraInicializacion(){

	FactoriaFigura::_factorias.clear();
}

/*
 * grupo.cpp
 *
 *  Created on: 13-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */

#include "grupo.h"
#include <sstream>


// Defino un valor auxiliar utilizado en la función 'distancia'.
// Como tengo que hallar la distancia mínima entre un punto y
// el centroide de varias figuras, inicializo una
// variable auxiliar a ese valor, que es muy alto, para asegurar
// que cualquier distancia calculada será menor a dicho valor.
#define VALOR 10000


using namespace std;

Grupo::Grupo(){}


Grupo::~Grupo(){

	_figuras.clear();
}


void Grupo::calcularArea(){
	// Sin implementación ya que un grupo carece de área de selección.
}


void Grupo::insertarFigura(boost::shared_ptr<Figura> figura){

	_figuras.push_back(figura);
}


list < boost::shared_ptr<Figura> > Grupo::getFiguras()const{

	return _figuras;
}


bool Grupo::seleccionar (const Punto& punto) const{

	list< boost::shared_ptr<Figura> > figuras;
	list< boost::shared_ptr<Figura> >::const_iterator it;
	bool estaSeleccionado=false;
	it=_figuras.begin();
	while (!estaSeleccionado && it!=_figuras.end()){
		if ((*it)->seleccionar(punto)){
			estaSeleccionado=true;
		}
		it++;
	}

	return estaSeleccionado;
}


Punto Grupo::calcularCentroide() const{
	// Sin implementación ya que el grupo carece de centroide.
}


double Grupo::distancia (const Punto& punto) const{

	double aux;
	double distancia=VALOR;
	list< boost::shared_ptr<Figura> >::const_iterator it;
	for(it=_figuras.begin();it!=_figuras.end();++it){
		aux=(*it)->distancia(punto);
		if (aux < distancia){
			distancia=aux;
		}
	}

	return distancia;
}


void Grupo::trasladar(double x, double y){

	list< boost::shared_ptr<Figura> >::const_iterator it;
		for(it=_figuras.begin();it!=_figuras.end();++it){
			(*it)->trasladar(x,y);
		}
}


void Grupo::pintar(Matriz& lienzo)const{

	list< boost::shared_ptr<Figura> >::const_iterator it;
	for(it=_figuras.begin();it!=_figuras.end();++it){
		(*it)->pintar(lienzo);
	}
}


string Grupo::toString() const{

	stringstream ss ;
	ss << *this;

	return ss.str();
}


istream& Grupo::leerEntrada (istream& is){

	// sin implementación
	return is;
}


Figura& Grupo::operator=(const Figura& figura){

	return *this;
}


ostream& operator<<(ostream& os,  const Grupo& figura){

	os << "Grupo " << figura.getId() << ": " << endl;
	list < boost::shared_ptr<Figura> >::const_iterator it;
		for(it=figura._figuras.begin();it!=figura._figuras.end();++it){
			os << **it << endl;
		}

	return os;
}




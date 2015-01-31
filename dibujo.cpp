/*
 * dibujo.cpp
 *
 *  Created on: 10-nov-2014
 *      Author: Juanan
 */


#include "dibujo.h"
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <math.h>  // trunc
#include "grupo.h"
#include "exceptionRgb.h"

// Es un valor auxiliar utilizado en la función 'agregarSeleccion';
// como tengo que seleccionar la figura con distancia menor de
// su centroide al punto de selección, inicializo una
// variable auxiliar a ese valor, que es muy alto, para asegurar
// que será mayor a cualquier distancia entre el punto de selección y
// el centroide de las figura.
#define VALOR 10000
// Nombre del tipo de la clase Grupo que utilizo en la función 'desagruparSelección'.
#define GRUPO "5Grupo"
// Defino el nombre de las operaciones a leer de la entrada estandar.
#define SELECCIONAR "Seleccionar"
#define AGREGAR_SELECCION "AgregarSel"
#define DESELECCIONAR "Deseleccionar"
#define MOVER_SELECCION "MoverSel"
#define BORRAR_SELECCION "BorrarSel"
#define AGRUPAR_SELECCION "AgruparSel"
#define DESAGRUPAR_SELECCION "DesagruparSel"

using namespace std;


class SeEncuentra{

// Esta clase la utilizo de functor para la función 'count_if',
// que uso en la función 'agregarSelección" para comprobar
// si una figura ya había sido seleccionada.

public:

	SeEncuentra(boost::shared_ptr<Figura> punt):puntero(punt){};

	bool operator()(boost::shared_ptr<Figura> p){
		return *p==*puntero; // compara el identificador de las figuras
	}

private:

	boost::shared_ptr<Figura> puntero;
};


Dibujo::Dibujo(){

	_lienzo=NULL;

}


Dibujo::Dibujo (unsigned int ancho, unsigned int alto, const Rgb& color):_colorFondo(color){

	_infDch.setCoordenadas(static_cast<double>(ancho-1),static_cast<double>(alto-1));
	_lienzo= new Matriz(ancho,alto,color);
}


Dibujo::~Dibujo(){

	_figuras.clear();
	_seleccion.clear();
	delete _lienzo;
}


unsigned int Dibujo::getAncho() const{

	return static_cast <unsigned int>(trunc(_infDch.getX())+1);
}


unsigned int Dibujo::getAlto() const{

	return static_cast <unsigned int>(trunc(_infDch.getY())+1);
}


Rgb Dibujo::getColorFondo() const{

	return _colorFondo;
}


list < boost::shared_ptr<Figura> > Dibujo::getFiguras()const{

	return _figuras;
}


void Dibujo::setColorFondo(unsigned int r, unsigned int v, unsigned int a){

	_colorFondo.setColores(r,v,a);
}


void Dibujo::setDimension(unsigned int ancho, unsigned int alto){

	_infDch.setCoordenadas(static_cast<double>(ancho-1),static_cast<double>(alto-1));
	if(_lienzo!=NULL){
		delete _lienzo;
	}
	_lienzo=new Matriz(ancho,alto,_colorFondo);
}


void Dibujo::insertarFigura(boost::shared_ptr<Figura> figura){

	_figuras.push_back(figura);
}


void Dibujo::agregarSeleccion(const Punto& punto){

	boost::shared_ptr<Figura> vacia;
	boost::shared_ptr<Figura> seleccion=vacia;
	double aux;
	double distancia=VALOR; // VALOR=10000
	list< boost::shared_ptr<Figura> >::const_iterator it;
	for(it=_figuras.begin();it!=_figuras.end();++it){
		if ((*it)->seleccionar(punto)){
		// El punto se encuentra en el área de selección de la figura.
		// Calculamos la distancia de ese punto al centroide de la figura.
			aux=(*it)->distancia(punto);
			if (aux < distancia){
			// si la distancia es menor a cualquiera de las anteriores
			// seleccionaremos dicha figura.
				distancia=aux;
				seleccion=*it;
			}
		}
	}
	if (seleccion!=vacia){
	// Comprobamos que la figura no se encuentra ya seleccionada;
	// si la figura se encuentra seleccionada seguirá seleccionada.
		// Utilizo la función 'count_if' para contar las veces que esta la figura
		// seleccionada en la lista de figuras seleccionadas '_seleccion'.
		if (count_if(_seleccion.begin(),_seleccion.end(),SeEncuentra(seleccion))==0){
			// El functor 'SeEncuentra' ira comparando las figuras previamente
			// seleccionadas con la actual seleccionada, comparando sus identificadores.
			// Si la función 'count_if' devuelve 0 significa que la figura seleccionada
			// no se encontraba, por lo que la añadimos a la lista.
			_seleccion.push_back(seleccion);
		}
	}
}


void Dibujo::agregarSeleccion(double x, double y){

	boost::shared_ptr<Punto> punto(new Punto(x,y));
	agregarSeleccion(*punto);
}


void Dibujo::seleccionar(const Punto& punto){

	_seleccion.clear();
	agregarSeleccion(punto);
}


void Dibujo::seleccionar(double x, double y){

	boost::shared_ptr<Punto> punto(new Punto(x,y));
	seleccionar (*punto);
}


void Dibujo::deseleccionar(){

	_seleccion.clear();
}


void Dibujo::moverSeleccion (double x,double y){

	list< boost::shared_ptr<Figura> >::iterator it;
	for(it=_seleccion.begin();it!=_seleccion.end();++it){
		(*it)->trasladar(x,y);
	}
}


void Dibujo::borrarSeleccion(){

	list< boost::shared_ptr<Figura> >::iterator it;
	for(it=_seleccion.begin();it!=_seleccion.end();++it){
		_figuras.remove(*it);
	}
	_seleccion.clear();
}


void Dibujo::agruparSeleccion(){

	if (_seleccion.size()>1){
		boost::shared_ptr<Grupo> grupo(new Grupo());
		list< boost::shared_ptr<Figura> >::iterator it;
		for(it=_seleccion.begin();it!=_seleccion.end();++it){
			grupo->insertarFigura(*it);
			_figuras.remove(*it);
		}
		_figuras.push_back(grupo);
		_seleccion.clear();
		_seleccion.push_front(grupo);
	}
}


void Dibujo::desagruparSeleccion(){

	// Aquí no tengo más remedio que preguntar el tipo de la figura para comprobar
	// si se trata de un grupo o  no para desagruparlo, ya que tengo que acceder a
	// su método 'getFiguras' que solo posee la clase 'Grupo'.
	if( (_seleccion.size()==1)&& ((string)typeid(*_seleccion.front()).name()==GRUPO)){// GRUPO="5Grupo"
		boost::shared_ptr<Grupo> grupo = boost::dynamic_pointer_cast<Grupo>(_seleccion.front());
		list < boost::shared_ptr<Figura> > figuras=grupo->getFiguras();
		list < boost::shared_ptr<Figura> >::iterator it;
		for(it=figuras.begin();it!=figuras.end();++it){
			_figuras.push_back(*it);
			_seleccion.push_back(*it);
		}
		_figuras.remove(grupo);
		_seleccion.remove(grupo);
	}

}


void Dibujo::guardarEnFichero(string defaultValue){

	ofstream fout (defaultValue.c_str());
	if (fout){
		fout<<"P3"<<endl;
		fout<<_lienzo->getColumns()<<" "<<_lienzo->getRows()<<endl;
		fout << "255" << endl;
		fout << *_lienzo;
	}
}


void Dibujo::realizarOperacion(istream& is){

	double x,y;
	string operacion;
	is >> operacion;
	if (operacion.compare(SELECCIONAR)==0){
		is >> x >> y;
		seleccionar(x,y);
	}
	else if (operacion.compare(AGREGAR_SELECCION)==0){
		is >> x >> y;
		agregarSeleccion(x,y);
	}
	else if (operacion.compare(DESELECCIONAR)==0){
		deseleccionar();
	}
	else if (operacion.compare(MOVER_SELECCION)==0){
		is >> x >> y;
		moverSeleccion(x,y);
	}
	else if (operacion.compare(BORRAR_SELECCION)==0){
		borrarSeleccion();
	}
	else if (operacion.compare(AGRUPAR_SELECCION)==0){
		agruparSeleccion();
	}
	else if (operacion.compare(DESAGRUPAR_SELECCION)==0){
		desagruparSeleccion();
	}
}


void Dibujo::setFactoria(string claseFigura){

	// Se accede al atributo 'static' de tipo 'map' de la clase 'FactoriaFigura'
	// que devuelve una instancía de la factoría que se necesita para fabricar
	// la clase de figura requerida.
	_factoria=FactoriaFigura::_factorias.find(claseFigura)->second;

}


ostream& operator<< (ostream& os,  const Dibujo& dibujo){

	os<<"P3"<<endl;
	os<<dibujo._lienzo->getColumns()<<" "<<dibujo._lienzo->getRows()<<endl;
	os << "255" << endl;

	return os<<*(dibujo._lienzo);
}


istream& operator>> (istream& is,  Dibujo& dibujo){

	// Empezamos estableciendo el tamaño del dibujo y creando el lienzo.
	double anchura,altura,rojo,verde,azul;
	// Leemos las dimensiones del dibujo.
	cin >> anchura >> altura;
	anchura=fabs(trunc(anchura));
	altura=fabs(trunc(altura));
	// Leemos el color de fondo del dibujo.
	cin >> rojo >> verde >> azul;
	rojo=fabs(trunc(rojo));
	verde=fabs(trunc(verde));
	azul=fabs(trunc(azul));
	try{
		dibujo.setColorFondo(static_cast<unsigned int>(rojo),static_cast<unsigned int>(verde),static_cast<unsigned int>(azul));
	}
	catch (ExceptionRgb& e){
		cout<<e.what()<<endl;
		dibujo.setColorFondo(255,255,255);
	}
	dibujo.setDimension(static_cast<unsigned int>(anchura),static_cast<unsigned int>(altura));

	// A continuación pasamos a leer las figuras.
	int numeroFiguras, numeroOperaciones;
	string claseFigura;
	boost::shared_ptr<Figura> figura;
	numeroFiguras=0;
	// Leemos el número de figuras.
	is >> numeroFiguras;
	unsigned int i;
	for (i=0; i<numeroFiguras;i++){
		// Leemos el tipo de figura.
		is >> claseFigura;
		// Devolvemos la instancia de la factoría concreta, necesaria
		// para construir el tipo de figura leído, accediendo
		// al atributo de tipo 'map' de la clase 'FactoriaFigura'.
		dibujo.setFactoria(claseFigura);
		// La factoría devuelve una instancia de la figura adecuada.
		figura =dibujo._factoria->fabricar(is);
		dibujo._figuras.push_back(figura);
	}
	// por último procedemos a leer las distintas operaciones a realizar
	// en el caso de que se haya leido alguna figura
	if(numeroFiguras!=0){
		numeroOperaciones=0;
		is >> numeroOperaciones;
		for (i=0; i<numeroOperaciones;i++){
			dibujo.realizarOperacion(is);
		}
	}
	list < boost::shared_ptr<Figura> >::iterator it;
	for(it=dibujo._figuras.begin();it!=dibujo._figuras.end();++it){
		(*it)->pintar(*(dibujo._lienzo));
	}
}


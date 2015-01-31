/*
 * punto.cpp
 *
 *  Created on: 06-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */

#include "punto.h"
#include <math.h>  // trunc

using namespace std;


Punto::Punto(){

	_x=0;
	_y=0;
}


Punto::Punto (double x, double y){

	_x=x;
	_y=y;
}


Punto::Punto (const Punto& p){

	_x=p._x;
	_y=p._y;
}


Punto::~Punto(){}


bool Punto::estaEnLienzo (Matriz& lienzo) const{

	return (_x>=0 && _y>=0 ) && (trunc(_x)<lienzo.getColumns()&& trunc(_y)<lienzo.getRows());
}


double Punto::getX() const{

	return _x;
}


double Punto::getY() const{

	return _y;
}


void Punto::setX(double x){

	_x=x;
}


void Punto::setY(double y){

	_y=y;
}


void Punto::setCoordenadas(double x, double y){

	_x=x;
	_y=y;
}


void Punto::trasladar(double x, double y){

	_x=_x+x;
	_y=_y+y;
}


double Punto::distancia (const Punto& p) const{

	return sqrt(pow(_x - p._x, 2) + pow(_y - p._y , 2));
}


void Punto::pintar(const Rgb& color, Matriz& lienzo) const{

	 if (estaEnLienzo(lienzo)){
		 unsigned int x= static_cast <unsigned int>(trunc(_x));
		 unsigned int y= static_cast <unsigned int>(trunc(_y));
		 lienzo.setCelda(y,x,color);
	 }
}


Punto& Punto::operator=(const Punto& p) {
	if (this != &p) {
		_x=p._x;
		_y=p._y;
	}

	return *this;
}


bool Punto::operator== (const Punto& p) const{

	return (_x==p._x) && (_y==p._y);
}


ostream& operator<< (ostream& os, const Punto& punto){

    return os<< "(" << punto.getX() << "," << punto.getY() << ")";
}


istream& operator>> (istream& is, Punto& punto){

	double x,y;
	is >> x >> y;
	punto.setCoordenadas(x,y);

    return is;
}


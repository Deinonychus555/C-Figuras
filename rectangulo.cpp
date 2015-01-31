/*
 * segmento.cpp
 *
 *  Created on: 08-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */

#include "rectangulo.h"
#include <sstream>
#include <math.h>
#include "exceptionRgb.h"
#include <cmath>


using namespace std;


void Rectangulo::calcularArea(){

	_areaSeleccion.setArea(_p1.getX(), _p1.getY(), _p4.getX(), _p4.getY());
}


Rectangulo::Rectangulo(){}


Rectangulo::Rectangulo(const Punto& p1, unsigned int anchura, unsigned int altura, const Rgb& color):Figura(color),_p1(p1){

	double x2,y2,x3,y3;
	x3=p1.getX();
	x2=x3+anchura;
	y2=p1.getY();
	y3=y2+altura;
	_p2.setCoordenadas(x2,y2);
	_p3.setCoordenadas(x3,y3);
	_p4.setCoordenadas(x2,y3);
	calcularArea();
}


Rectangulo::~Rectangulo(){}


Punto Rectangulo::getVertice1() const{

	return _p1;
}


Punto Rectangulo::getVertice2() const{

	return _p2;
}


Punto Rectangulo::getVertice3() const{

	return _p3;
}


Punto Rectangulo::getVertice4() const{

	return _p4;
}


void Rectangulo::setVertice1(double x, double y){

	_p1.setCoordenadas(x,y);
	calcularArea();
}


void Rectangulo::setVertice1(const Punto& punto){

	_p1=punto;
	calcularArea();
}


void Rectangulo::setVertice2(double x, double y){

	_p2.setCoordenadas(x,y);
	calcularArea();
}


void Rectangulo::setVertice2(const Punto& punto){

	_p2=punto;
	calcularArea();
}


void Rectangulo::setVertice3(double x, double y){

	_p3.setCoordenadas(x,y);
	calcularArea();
}


void Rectangulo::setVertice3(const Punto& punto){

	_p3=punto;
	calcularArea();
}


void Rectangulo::setVertice4(double x, double y){

	_p4.setCoordenadas(x,y);
	calcularArea();
}


void Rectangulo::setVertice4(const Punto& punto){

	_p4=punto;
	calcularArea();
}


Punto Rectangulo::calcularCentroide() const{

	double x,y;
    x = (_p1.getX() + _p2.getX() + _p3.getX() + _p4.getX()) / 4;
    y = (_p1.getY() + _p3.getY() + _p3.getY() + _p4.getY()) / 4 ;

    return Punto(x,y);
}


void Rectangulo::trasladar(double x, double y){

	_p1.trasladar(x,y);
	_p2.trasladar(x,y);
	_p3.trasladar(x,y);
	_p4.trasladar(x,y);
	_areaSeleccion.trasladar(x,y);
}


void Rectangulo::pintar(Matriz& lienzo)const{

	Bresenham(_p1,_p2,getColor(),lienzo);
	Bresenham(_p1,_p3,getColor(),lienzo);
	Bresenham(_p2,_p4,getColor(),lienzo);
	Bresenham(_p3,_p4,getColor(),lienzo);
}


string Rectangulo::toString()const{

	stringstream ss;
	ss << *this << " "<< getColor();

    return ss.str();
}


istream& Rectangulo::leerEntrada (istream& is){

	return is >> *this;
}


ostream& operator<< (ostream& os,  const Rectangulo& figura){

	return os <<"Rectangulo "<< figura.getId() << ": " << figura._p1 << " " << figura._p2 << " " << figura._p3 << " " << figura._p4;
}


istream& operator>> (istream& is, Rectangulo& figura){

	double x,y,anchura,altura,r,v,a;
	is >> x >> y >> anchura >> altura >> r >> v >> a;
	figura.setVertice1(x,y);
	figura.setVertice2(x+fabs(anchura-1),y);
	figura.setVertice3(x,y+fabs(altura-1));
	figura.setVertice4(x+fabs(anchura-1),y+fabs(altura-1));
	r=fabs(trunc(r));
	v=fabs(trunc(v));
	a=fabs(trunc(a));
	try{
		figura.setColor(static_cast<unsigned int>(r),static_cast<unsigned int>(v),static_cast<unsigned int>(a));
	}
	catch (ExceptionRgb& e){
		cout<<e.what()<<endl;
		figura.setColor(125,125,125);
	}

    return is;
}



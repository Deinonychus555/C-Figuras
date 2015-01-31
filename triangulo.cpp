/*
 * segmento.cpp
 *
 *  Created on: 08-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */

#include "triangulo.h"
#include <sstream>
#include <math.h>
#include "exceptionRgb.h"

using namespace std;


double Triangulo::getXMin() const{

	double xMin;
	(_p1.getX()<_p2.getX())?
			((_p1.getX()<_p3.getX())? xMin=_p1.getX():xMin=_p3.getX()):
			((_p2.getX()<_p3.getX())? xMin=_p2.getX():xMin=_p3.getX());

	return xMin;
}


double Triangulo::getYMin() const{

	double yMin;
	(_p1.getY()<_p2.getY())?
			((_p1.getY()<_p3.getY())? yMin=_p1.getY():yMin=_p3.getY()):
			((_p2.getY()<_p3.getY())? yMin=_p2.getY():yMin=_p3.getY());

	return yMin;
}


double Triangulo::getXMax() const{

	double xMax;
	(_p1.getX()>_p2.getX())?
			((_p1.getX()>_p3.getX())? xMax=_p1.getX():xMax=_p3.getX()):
			((_p2.getX()>_p3.getX())? xMax=_p2.getX():xMax=_p3.getX());

	return xMax;
}


double Triangulo::getYMax() const{

	double yMax;
	(_p1.getY()>_p2.getY())?
			((_p1.getY()>_p3.getY())? yMax=_p1.getY():yMax=_p3.getY()):
			((_p2.getY()>_p3.getY())? yMax=_p2.getY():yMax=_p3.getY());

	return yMax;
}


void Triangulo::calcularArea(){

	double xMin, yMin, xMax, yMax;
	xMin=getXMin();
	yMin=getYMin();
	xMax=getXMax();
	yMax=getYMax();
	_areaSeleccion.setArea(xMin, yMin, xMax, yMax);
}


Triangulo::Triangulo(){}


Triangulo::Triangulo(const Punto& p1, const Punto& p2, const Punto& p3, const Rgb& color):Figura(color),_p1(p1),_p2(p2),_p3(p3){

	calcularArea();
}


Triangulo::~Triangulo(){}


Punto Triangulo::getVertice1() const{

	return _p1;
}


Punto Triangulo::getVertice2() const{

	return _p2;
}


Punto Triangulo::getVertice3() const{

	return _p3;
}


void Triangulo::setVertice1(double x, double y){

	_p1.setCoordenadas(x,y);
	calcularArea();
}


void Triangulo::setVertice1(const Punto& punto){

	_p1=punto;
	calcularArea();
}


void Triangulo::setVertice2(double x, double y){

	_p2.setCoordenadas(x,y);
	calcularArea();
}


void Triangulo::setVertice2(const Punto& punto){

	_p2=punto;
	calcularArea();
}


void Triangulo::setVertice3(double x, double y){

	_p3.setCoordenadas(x,y);
	calcularArea();
}


void Triangulo::setVertice3(const Punto& punto){

	_p3=punto;
	calcularArea();
}


Punto Triangulo::calcularCentroide() const{

	double x,y;
    x = ( _p1.getX() + _p2.getX() + _p3.getX() ) / 3;
    y = ( _p1.getY() + _p2.getY() + _p3.getY() ) / 3;

    return Punto(x,y);
}


void Triangulo::trasladar(double x, double y){

	_p1.trasladar(x,y);
	_p2.trasladar(x,y);
	_p3.trasladar(x,y);
	_areaSeleccion.trasladar(x,y);
}


void Triangulo::pintar(Matriz& lienzo)const{

	Bresenham(_p1,_p2,getColor(),lienzo);
	Bresenham(_p1,_p3,getColor(),lienzo);
	Bresenham(_p2,_p3,getColor(),lienzo);
}


string Triangulo::toString()const{

	stringstream ss;
	ss << *this<< " " << getColor();

	return ss.str();
}


istream& Triangulo::leerEntrada (istream& is){

	return is >> *this;
}


ostream& operator<<(ostream& os,  const Triangulo& figura){

	return os << "Triangulo " << figura.getId() << ": " <<figura._p1 << " " << figura._p2 << " " << figura._p3;
}

istream& operator>>(istream& is, Triangulo& figura){

	double x1,y1,x2,y2,x3,y3,r,v,a;
	is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r >> v >> a;
	figura.setVertice1(x1,y1);
	figura.setVertice2(x2,y2);
	figura.setVertice3(x3,y3);
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



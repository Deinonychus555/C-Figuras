/*
 * segmento.cpp
 *
 *  Created on: 08-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */

#include "segmento.h"
#include <sstream>
#include <math.h>
#include "exceptionRgb.h"


using namespace std;


double Segmento::getXMin() const{

	double xMin;
	(_p1.getX()<_p2.getX())? xMin=_p1.getX():xMin=_p2.getX();

	return xMin;
}


double Segmento::getYMin() const{

	double yMin;
	(_p1.getY()<_p2.getY())? yMin=_p1.getY():yMin=_p2.getY();

	return yMin;
}


double Segmento::getXMax() const{

	double xMax;
	(_p1.getX()>_p2.getX())? xMax=_p1.getX():xMax=_p2.getX();

	return xMax;
}


double Segmento::getYMax() const{

	double yMax;
	(_p1.getY()>_p2.getY())? yMax=_p1.getY():yMax=_p2.getY();

	return yMax;
}


void Segmento::calcularArea(){

	double xMin, yMin, xMax, yMax;
	xMin=getXMin();
	yMin=getYMin();
	xMax=getXMax();
	yMax=getYMax();
	_areaSeleccion.setArea(xMin, yMin, xMax, yMax);
}


Segmento::Segmento(){}


Segmento::Segmento(const Punto& p1, const Punto& p2, const Rgb& color):Figura(color),_p1(p1),_p2(p2){

	calcularArea();
}


Segmento::~Segmento(){}


Punto Segmento::getExtremo1() const{

	return _p1;
}


Punto Segmento::getExtremo2() const{

	return _p2;
}


void Segmento::setExtremo1(const Punto& punto){

	_p1=punto;
	calcularArea();
}


void Segmento::setExtremo1(double x, double y){

	_p1.setCoordenadas(x,y);
	calcularArea();
}


void Segmento::setExtremo2(const Punto& punto){

	_p2=punto;
	calcularArea();
}


void Segmento::setExtremo2(double x, double y){

	_p2.setCoordenadas(x,y);
	calcularArea();
}


Punto Segmento::calcularCentroide() const{

	double x,y;
	x = (_p1.getX() + _p2.getX()) / 2 ;
	y = (_p1.getY() + _p2.getY()) / 2 ;

	return Punto(x,y);
}


void Segmento::trasladar(double x, double y){

    _p1.trasladar(x,y);
	_p2.trasladar(x,y);
	_areaSeleccion.trasladar(x,y);
}


void Segmento::pintar(Matriz& lienzo)const{

	Bresenham(_p1,_p2,getColor(),lienzo);
}


string Segmento::toString()const{

    stringstream ss;
	ss << *this << " " << getColor();

    return ss.str();
}


istream& Segmento::leerEntrada (istream& is){

	return is >> *this;
}


ostream& operator<<(ostream& os,  const Segmento& figura){

	return os << "Segmento " << figura.getId() << ": " << figura._p1 << " " <<figura._p2;
}


istream& operator>>(istream& is, Segmento& figura){

	double x1,y1,x2,y2,r,v,a;
	is >> x1 >> y1 >> x2 >> y2 >> r >> v >> a;
	figura.setExtremo1(x1,y1);
	figura.setExtremo2(x2,y2);
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



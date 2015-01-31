/*
 * area.cpp
 *
 *  Created on: 18-nov-2014
 *      Author: Juanan
 */

#include "area.h"
#include <iostream>


using namespace std;


Area::Area(){}


Area::Area (double minX, double minY, double maxX, double maxY){

	_p1.setCoordenadas(minX,minY);
	_p2.setCoordenadas(maxX,minY);
	_p3.setCoordenadas(minX,maxY);
	_p4.setCoordenadas(maxX,maxY);
}


Area::Area(Punto supIzq, Punto infDch):_p1(supIzq),_p4(infDch){

	_p2.setCoordenadas(infDch.getX(),supIzq.getY());
	_p3.setCoordenadas(supIzq.getX(),infDch.getY());
}

Area::~Area(){}


Punto Area::getVertice1() const{

	return _p1;
}


Punto Area::getVertice2() const{

	return _p2;
}


Punto Area::getVertice3() const{

	return _p3;
}


Punto Area::getVertice4() const{

	return _p4;
}


void Area::setArea (double xMin, double yMin, double xMax, double yMax){

	_p1.setCoordenadas(xMin,yMin);
	_p2.setCoordenadas(xMax,yMin);
	_p3.setCoordenadas(xMin,yMax);
	_p4.setCoordenadas(xMax,yMax);
}


void Area::trasladar (double x, double y){

	_p1.trasladar(x,y);
	_p2.trasladar(x,y);
	_p3.trasladar(x,y);
	_p4.trasladar(x,y);
}


bool Area::estaDentro (const Punto& p)const{

	return (p.getX()>=_p1.getX() && p.getX()<=_p2.getX())
				&& (p.getY()>=_p1.getY() && p.getY()<=_p3.getY());
}


bool Area::estaDentro (double x, double y)const{

	return (x>=_p1.getX() && x<=_p2.getX()) && (y>=_p1.getY() && y<=_p3.getY());
}


Area& Area::operator=(const Area& area) {

	if (this != &area) {
		_p1=area._p1;
		_p2=area._p2;
		_p3=area._p3;
		_p4=area._p4;
	}

	return *this;
}

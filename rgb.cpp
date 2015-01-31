/*
 * rgb.cpp
 *
 *  Created on: 05-nov-2014
 *      Author: Juan Antonio Echeverrias Aranda
 */


#include "rgb.h"
#include "exceptionRgb.h"

// Defino el valor máximo de un color.
#define TONOMAX 255

using namespace std;


bool Rgb::esColorCorrecto(unsigned int r, unsigned int v, unsigned int a){
	// Función para comprobar que los colores no superan
	// el tono máximo de TONOMAX=255.

	return (r<=TONOMAX) && (v<=TONOMAX) && (a<=TONOMAX);
}


Rgb::Rgb(){

	_rojo=0;
	_verde=0;
	_azul=0;
}


Rgb::Rgb(const Rgb& color){

	_rojo=color._rojo;
	_verde=color._verde;
	_azul=color._azul;
}


Rgb::Rgb(unsigned int r, unsigned int v, unsigned int a){

	if (esColorCorrecto(r,v,a)){
		_rojo=r;
		_verde=v;
		_azul=a;
	}
	else{
		throw ExceptionRgb();
	}
}


Rgb::~Rgb(){};


unsigned int Rgb::getRojo()const{

	return _rojo;
}


unsigned int Rgb::getVerde()const{

	return _verde;
}


unsigned int Rgb::getAzul()const{

	return _azul;
}


void Rgb::setColores (unsigned int r, unsigned int v, unsigned int a){

	if (esColorCorrecto(r,v,a)){
		_rojo=r;
		_verde=v;
		_azul=a;
	}
	else{
		throw ExceptionRgb();
	}
}


Rgb& Rgb::operator=(const Rgb& color) {

	if (this != &color) {
		_rojo=color._rojo;
		_verde=color._verde;
		_azul=color._azul;
	}
	return *this;
}


ostream& operator<< (ostream& os,  const Rgb& rgb){

	return os << rgb._rojo << " " << rgb._verde << " " << rgb._azul;
}


istream& operator>>(istream& is, Rgb& rgb){

	unsigned int rojo;
	unsigned int verde;
	unsigned int azul;
	is >> rojo >> verde >> azul;
	rgb.setColores(rojo,verde,azul);

	return is;
}



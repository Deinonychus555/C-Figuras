/*
 * figura.cpp
 *
 *  Created on: 07-nov-2014
 *      Author: Juan Antonio Echeverrias Aranda
 */

#include "figura.h"
#include <sstream>
#include <math.h>
#include <boost/shared_ptr.hpp>


using namespace std;


int Figura::_genid=0;


Figura::Figura(){

	_genid++; // Se incrementa el "contador".
	_id=_genid;
}


Figura::Figura(const Rgb& color):_color(color){

	_genid++; // Se incrementa el "contador".
	_id=_genid;
}


Figura::~Figura(){}


void Figura::Bresenham (int x1, int y1, int x2, int y2, const Rgb& color, Matriz& lienzo) const{
	// ----------------- Bresenham algorithm -----------------------

	boost::shared_ptr<Punto> punto(new Punto()); // punto auxiliar

	int delta_x = (x2 - x1);

	  // if x1 == x2, then it does not matter what we set here
	  // indica el sentido
	  // devuelve 1 (+) si x1<x2
	  // devuelve -1 (-) si x2<x1
	  // devuelve 0 si x1==x2
	  int const ix = ((delta_x > 0) - (delta_x < 0));
	  // el operador << lo que hace es multiplicar por dos tantas veces como indique
	  delta_x = abs(delta_x) << 1;

	  int delta_y = (y2 - y1);

	  // if y1 == y2, then it does not matter what we set here
	  int const iy = ((delta_y > 0) - (delta_y < 0));
	  delta_y = abs(delta_y) << 1;

	  // Draw the pixel
	  punto.get()->setCoordenadas(static_cast<double>(x1),static_cast<double>(y1));
	  punto->pintar(color,lienzo);

	  if (delta_x >= delta_y)
	  {
	    // error may go below zero
	    int error = (delta_y - (delta_x >> 1));

	    while (x1 != x2)
	    {
	      if ((error >= 0) && (error || (ix > 0)))
	      {
	        error -= delta_x;
	        y1 += iy;
	      }
	      // else do nothing

	      error += delta_y;
	      x1 += ix;

	      // Draw the pixel
	      punto.get()->setCoordenadas(static_cast<double>(x1),static_cast<double>(y1));
	      punto->pintar(color,lienzo);
	    }
	  }
	  else
	  {
	    // error may go below zero
	    int error = (delta_x - (delta_y >> 1));

	    while (y1 != y2)
	    {
	      if ((error >= 0) && (error || (iy > 0)))
	      {
	        error -= delta_y;
	        x1 += ix;
	      }
	      // else do nothing

	      error += delta_x;
	      y1 += iy;

	      // Draw the pixel.
	     punto.get()->setCoordenadas(static_cast<double>(x1),static_cast<double>(y1));
	     punto->pintar(color,lienzo);
	    }
	  }
// ------------ End of Bresenham algorithm -----------------------
}



void Figura::Bresenham (const Punto& p1,const Punto& p2, const Rgb& color, Matriz& lienzo) const{
	int x1=static_cast<int>(trunc(p1.getX()));
	int y1=static_cast<int>(trunc(p1.getY()));
	int x2=static_cast<int>(trunc(p2.getX()));
	int y2=static_cast<int>(trunc(p2.getY()));
	Bresenham (x1,y1,x2,y2, color, lienzo);
}


int Figura::getId()const{

		return _id;
}


Rgb Figura::getColor()const{

		return _color;
}


Area Figura::getAreaSeleccion() const{

	return _areaSeleccion;
}


void Figura::setColor(const Rgb& color){

	_color.setColores(color.getRojo(),color.getVerde(),color.getAzul());
}


void Figura::setColor(unsigned int r, unsigned int v, unsigned int a){

	_color.setColores(r,v,a);
}


void Figura::setAreaSeleccion(const Area& area){

	_areaSeleccion=area;
}


bool Figura::seleccionar (const Punto& punto) const{

	return _areaSeleccion.estaDentro(punto);
}


double Figura::distancia (const Punto& punto) const{
    // Se halla el centroide de la figura y luego se calcula la distancia
	// entre dicho punto y el punto que recibe como argumento.
	return calcularCentroide().distancia(punto);

}


bool Figura::operator==(const Figura& figura) const{

	return _id==figura._id;
}


ostream& operator<< (ostream& os,  const Figura& figura){

	return os<<figura.toString();
}


istream& operator>> (istream& is,  Figura& figura){
    // La función 'leerEntrada' es virtual, por lo que se cumple el polimorfismo.
	return figura.leerEntrada(is);
}

/*
 * matriz.h
 *  Created on: 17/01/2012
 *      Author: rcabido
 *  Modified on: 30/09/14
 *      Author: jmbuenaposada
 *  Modified on: 06-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */

#include "matriz.h"
#include <sstream>

using namespace std;


Rgb** Matriz::createStructure(unsigned int cols, unsigned rows){

	Rgb** new_data;
	new_data = new Rgb*[rows];
	for (unsigned i = 0; i < rows; i++) {
  	  new_data[i] = new Rgb[cols];
	}

	return new_data;
}


void Matriz::deleteStructure(){

	for (unsigned int i = 0; i < _rows; i++) {
		delete[] _celdas[i];
	}
	delete[] _celdas;
	_celdas = NULL;
	_rows = 0;
	_cols = 0;
}


Matriz::Matriz(){
	_celdas = NULL;
	_rows = 0;
	_cols = 0;
};


Matriz::Matriz(unsigned int cols, unsigned rows, const Rgb& color) {
	// Habría que crear una clase 'ExcepcionMatriz' que se lanzará
	// si el valor que recibe de las columnas o filas es 0.
	_cols = cols;
	_rows = rows;
	_celdas = createStructure(cols, rows);
	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++) {
			_celdas[i][j] = color;
		}
	}
}


Matriz::~Matriz() {

  deleteStructure();
}


unsigned int Matriz::getRows() const{

	return _rows;
}


unsigned int Matriz::getColumns() const{

	return _cols;
}


Rgb** Matriz::getCeldas() const{

	return _celdas;
}


void Matriz::setCelda (unsigned int row, unsigned int col, const Rgb& color){

	_celdas[row][col].setColores(color.getRojo(),color.getVerde(),color.getAzul());
}


bool Matriz::sizeMatrix(const Matriz & matriz)const{

		return ((this->_rows==matriz._rows)&&(this->_cols==matriz._cols));
	}


ostream& operator<<(ostream& os, const Matriz& m){

	for (unsigned int i = 0; i < m._rows; i++) {
		for (unsigned int j = 0; j < m._cols; j++) {
			os << m._celdas[i][j]<<" ";
		}
		os << endl;
	}
	return os;
}


istream& operator>>(istream& is, Matriz& m)
{
	unsigned new_rows;
	unsigned new_cols;

	is >> new_rows >> new_cols;

	if ((new_rows != m._rows) || (new_cols != m._cols)) {
		m.deleteStructure();
		m._celdas = m.createStructure(new_cols, new_rows);
		m._rows = new_rows;
		m._cols = new_cols;
	}

	for (unsigned int i = 0; i < m._rows; i++) {
		for (unsigned int j = 0; j < m._cols; j++) {
			is >> m._celdas[i][j];
		}
	}
	return is;
}






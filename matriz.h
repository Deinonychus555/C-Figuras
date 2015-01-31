/*
 * matriz.h
 *  Created on: 17/01/2012
 *      Author: rcabido
 *  Modified on: 30/09/14
 *      Author: jmbuenaposada
 *  Modified on: 06-nov-2014
 *      Author: Juan Antonio Echeverrías Aranda
 */


#ifndef MATRIZ_H_
#define MATRIZ_H_

#include <iostream>
#include "rgb.h"



class Matriz {

public:

	Matriz();
	Matriz(unsigned cols, unsigned rows, const Rgb& color=Rgb(100,100,100));

	virtual ~Matriz();

	unsigned int getRows() const;
	unsigned int getColumns() const;
	Rgb** getCeldas() const;

	void setCelda (unsigned int row, unsigned int col, const Rgb& color);

	friend std::ostream& operator<<(std::ostream& os, const Matriz& m);

	friend std::istream& operator>>(std::istream& os, Matriz& m);


private:

	Rgb** _celdas;
	unsigned _rows;
	unsigned  _cols;

	Rgb** createStructure(unsigned int cols, unsigned rows);
	void deleteStructure();
	bool sizeMatrix(const Matriz & matriz) const ;

};

#endif /* MATRIZ_H_ */

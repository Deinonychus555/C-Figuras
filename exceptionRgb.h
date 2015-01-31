/*
 * exceptionRgb.h
 *
 *  Created on: 05-nov-2014
 *      Author: Juan Antonio Echeverrias Aranda
 */

#ifndef EXCEPTIONRGB_H_
#define EXCEPTIONRGB_H_

#include <exception>

// Excepción que se lanzará cuando al crear un color o modificarlo, alguno de sus
// subcolores sea mayor al valor 255.

class ExceptionRgb : public std::exception{

public:

	virtual const char* what() const throw();

};

#endif /* EXCEPTIONRGB_H_ */

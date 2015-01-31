/*
 * exceptionRgb.cpp
 *
 *  Created on: 05-nov-2014
 *      Author: Juan Antonio Echeverrias Aranda
 */

#include "exceptionRgb.h"
#include <exception>


const char* ExceptionRgb::what() const throw() {

       return "Color incorrecto";
}

# C++Figuras

A continuación citaré algunas de las cosas que he utilizado.

He utilizado el patrón Factoría que implementan las clases FactoriaFiguras y sus hijas FactoriaSegmento,
FactoriaTriangulo y FactoriaRectangulo, para fabricar las figuras utilizando el polimorfismo.

He utilizado el Patrón Singleton en la clase FactoriaFiguraInicializacion, para inicializar un atributo de la
clase FactoriaFiguras que contendrá instancias a las diferentes factorías.

He implementado un functor 'SeEncuentra' que se utiliza en la clase Dibujo en el método 'agregarSeleccion'
que comprueba si dos figuras son iguales comparando sus identificadores.

El utilizado el polimorfismo en el método fabricar de la clase FactoriaFigura y en los metodos trasladar,
leerEntrada, calcularCentroide,CalcularArea y Pintar de la clase Figura.

He utilizado smart pointers ('shared_ptr') para las listas de figuras de la clase Dibujo ('_figuras' y
'_seleccion') y de la clase Grupo ('_figuras') y otros punteros en general exceptuando la clase Matriz.

Decir que me he dado cuenta que la clase Area utilizada para establecer el área de selección de la figura
debería de haber constado solo de dos puntos como atributos en vez de cuatro como aparecen, no lo he
podido cambiar por falta de tiempo.

Esta práctica está valorada con un 10.

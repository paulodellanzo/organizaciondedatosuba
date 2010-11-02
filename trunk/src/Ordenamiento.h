/*
 * Ordenamiento.h
 *
 *  Created on: Oct 22, 2010
 *      Author: santiago
 */

#ifndef ORDENAMIENTO_H_
#define ORDENAMIENTO_H_

#include <iostream>
#include <fstream>
#include <sstream>



using namespace std;


typedef enum {vacio,congelado,ocupado} estado;


class replac_selection {

	typedef struct{
		void* elem;
		estado est;
	}T_elem;


	private:
		int dataTam;//para saber de que tamaño es el stream
		int buffTam;

		/*Recibe un stream, retorna un puntero al elemento*/
		void* (*constructor)(char*);

		/*Destruye el elemento*/
		void (*destructor) (void*);

		/* para comparar las claves, debe retornar -1 si el 1° parametro es mayor,
		 * 0 si son iguales, 1 si el segundo es mayor*/
		int (*comp) (void*,void*);

		void (*persistencia) (ofstream&,void*);

		T_elem* v_elem;


	public:
		/* Param:
		 * -- int:tamaño de los datos y tamaño del buffer a usar
		 * */
		replac_selection(int buffTam, int dataTam,void* (*constructor)(char*),
				void (*destructor) (void*),int (*comp) (void*,void*),
				void (*persistencia) (ofstream&,void*));

		~replac_selection() {
			delete [] v_elem;
		}

		/* Param:
		 * --string: nombre archivo entrada
		 * */
		void ordenar (const string&);



	private:
		int completarArray(ifstream&);
		int elemMasPequenio(int);
		void descongelarElem(int);
};


#endif /* ORDENAMIENTO_H_ */
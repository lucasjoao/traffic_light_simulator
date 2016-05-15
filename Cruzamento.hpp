#ifndef CRUZAMENTO_HPP
#define CRUZAMENTO_HPP

#include "estruturas/ListaCirc.hpp"
#include "estruturas/Lista.hpp"
#include "Semaforo.hpp"

class Cruzamento : ListaCirc<Semaforo> {
	public:
		Cruzamento() {}

		int proximoEvento() {

		}
	private:
		Lista *pistas;
};
#endif
#ifndef CRUZAMENTO_HPP
#define CRUZAMENTO_HPP

#include "estruturas/ListaCirc.hpp"
#include "estruturas/Lista.hpp"
#include "Semaforo.hpp"

class Cruzamento : ListaCirc<Semaforo*> {
	public:
		Cruzamento() {}

		void adiciona(Semaforo *semaforo) {
			ListaCirc<Semaforo*>::adiciona(semaforo);
		}

		int getSize() {
			return ListaCirc<Semaforo*>::getSize();
		}

		Semaforo *getSem(int posicao) {
			return ListaCirc<Semaforo*>::mostra(posicao);
		}

};
#endif
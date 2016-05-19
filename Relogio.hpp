#ifndef RELOGIO_HPP
#define RELOGIO_HPP

#include "estruturas/ListaEnc.hpp"
#include "Evento.hpp"

class Relogio : public ListaEnc<Evento*> {
	public:
		Relogio() {}

		// void adicionaEmOrdem(Evento *evento) {
		// 	ListaEnc<Evento*>::adicionaEmOrdem(evento);
		// }

		bool maior(Evento *evento0, Evento *evento1) const {
			return evento0->getTempo() > evento1->getTempo();
		}

		int getTamanho() {
			return ListaEnc<Evento*>::getSize();
		}

		Evento *getEvento(int posicao) {
			return ListaEnc<Evento*>::mostra(posicao);
		}
};

#endif
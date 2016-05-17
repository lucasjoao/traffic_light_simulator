#ifndef RELOGIO_HPP
#define RELOGIO_HPP

#include "estruturas/ListaEnc.hpp"
#include "Evento.hpp"

class Relogio : public ListaEnc<Evento*> {
	public:
		Relogio() {}

		void adicionaEmOrdem(Evento *evento) {
			ListaEnc<Evento*>::adicionaEmOrdem(evento);
		}

		int getTamanho() {
			return ListaEnc<Evento*>::getSize();
		}

		Evento getEvento(int posicao) {
			return *ListaEnc<Evento*>::mostra(posicao);
		}
};

#endif
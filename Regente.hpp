#ifndef REGENTE_HPP
#define REGENTE_HPP

#include "estruturas/Lista.hpp"
#include "Pista.hpp"
#include "Relogio.hpp"
#include "Cruzamento.hpp"

class Regente {
	public:
		Regente(int tE, int tS) {
			tempoExecucao = tE;
			tempoSemaforo = tS;
			pistas = new Lista<Pista*>(14);
			cruzamentos = new Lista<Cruzamento*>(2);
			eventos = Relogio();
		}

	private:
		Lista<Pista*> pistas;
		Lista<Cruzamento> cruzamentos;
		Relogio eventos;
		int tempoExecucao;
		int tempoSemaforo;
};

#endif
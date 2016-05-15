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

		void start() {
			/* só se precisar de uma var com nome
			 *
			Pista *o1oeste = new Pista(80, 2000, 0, 0);
			Pista *o1leste = new Pista(80, 2000, 10, 2);
			Pista *c1oeste = new Pista(60, 300, 0, 0);
			Pista *c1leste = new Pista(60, 300, 0, 0);
			Pista *l1oeste = new Pista(30, 400, 10, 2);
			Pista *l1leste = new Pista(30, 400, 0, 0);
			Pista *n1sul = new Pista(60, 500, 20, 5);
			Pista *n1norte = new Pista(60, 500, 0, 0);
			Pista *n2sul = new Pista(40, 500, 20, 5);
			Pista *n2norte = new Pista(40, 500, 0, 0);
			Pista *s1sul = new Pista(60, 500, 0, 0);
			Pista *s1norte = new Pista(60, 500, 30, 7);
			Pista *s2sul = new Pista(40, 500, 0, 0);
			Pista *s2norte = new Pista(40, 500, 60, 15);*/

			pistas->adiciona(new Pista(80, 2000, 0, 0));
			pistas->adiciona(new Pista(80, 2000, 10, 2));
			pistas->adiciona(new Pista(60, 300, 0, 42));
			pistas->adiciona(new Pista(60, 300, 0, 42));
			pistas->adiciona(new Pista(30, 400, 10, 2));
			pistas->adiciona(new Pista(30, 400, 0, 0));
			pistas->adiciona(new Pista(60, 500, 20, 5));
			pistas->adiciona(new Pista(60, 500, 0, 0));
			pistas->adiciona(new Pista(40, 500, 20, 5));
			pistas->adiciona(new Pista(40, 500, 0, 0));
			pistas->adiciona(new Pista(60, 500, 0, 0));
			pistas->adiciona(new Pista(60, 500, 30, 7));
			pistas->adiciona(new Pista(40, 500, 0, 0));
			pistas->adiciona(new Pista(40, 500, 60, 15));

		}

	private:
		Lista<Pista*> *pistas;
		Lista<Cruzamento*> *cruzamentos;
		Relogio eventos;
		int tempoExecucao;
		int tempoSemaforo;
};

#endif
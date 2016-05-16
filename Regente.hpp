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
			eventos = new Relogio();
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

			/* só de precisar de uma var com nome
			 *
			Semaforo *s1norte = new Semaforo(false, tempoSemaforo);
			Semaforo *s2norte = new Semaforo(false, tempoSemaforo);
			Semaforo *s1leste = new Semaforo(false, tempoSemaforo);
			Semaforo *s2leste = new Semaforo(false, tempoSemaforo);
			Semaforo *s1sul = new Semaforo(false, tempoSemaforo);
			Semaforo *s2sul = new Semaforo(false, tempoSemaforo);
			Semaforo *s1oeste = new Semaforo(false, tempoSemaforo);
			Semaforo *s2oeste = new Semaforo(false, tempoSemaforo);*/

			Cruzamento *c1 = new Cruzamento();
			c1->adiciona(new Semaforo(false, tempoSemaforo));
			c1->adiciona(new Semaforo(false, tempoSemaforo));
			c1->adiciona(new Semaforo(false, tempoSemaforo));
			c1->adiciona(new Semaforo(false, tempoSemaforo));
			cruzamentos->adiciona(c1);

			Cruzamento *c2 = new Cruzamento();
			c2->adiciona(new Semaforo(false, tempoSemaforo));
			c2->adiciona(new Semaforo(false, tempoSemaforo));
			c2->adiciona(new Semaforo(false, tempoSemaforo));
			c2->adiciona(new Semaforo(false, tempoSemaforo));
			cruzamentos->adiciona(c2);
		}

		void eventosCriarCarro() {
			Pista *pista;
    		Evento *evento;
    		int tempo;
    		// int tempoEvento;

			for(int i = 0; i < pistas->getMaxLista(); i++) {
				pista = pistas->getDados()[i];
				if (pista->getFonte()) {
					tempo = 0;
					while(tempo < tempoExecucao) {
						/*tempoEvento = pista->proximaCriacaoCarro(tempo);
						if (tempoEvento < tempoExecucao) {
							evento = new Evento(tempoEvento, 0);
                    		eventos->adicionaEmOrdem(evento);
							tempo = tempoEvento;
						}*/

						tempo = pista->proximaCriacaoCarro(tempo);
						if (tempo < tempoExecucao) {
							evento = new Evento(tempo, 0);
                    		eventos->adicionaEmOrdem(evento);
						}
					}
				}
			}
		}

		/*void eventosChegadaSemaforo() {
			Pista* atual;
			Semaforo* semaforo;
			Evento* evento;
			int tChegada, tNextEvent;
			int tOriginal = eventos->getTamanho(); //não tenho certeza se pode acessar isso desse geito, acho que sim já que eventos é do tipo relógio e relógio tem uma lista de eventos
			for (int pos = 0; pos < tOriginal; i++) {
				if (eventos->retornaDado(pos)->getTipo() == 0) { //supondo que zero é o tipo que queremos
					tChegada = eventos->retornaDado(pos)->getTempo();
					//travei aqui
					//estava tentando adaptar ao nosso até pq a partir daqui ele meche com semaforo
					//e o semaforo dele tem mais atributos que o nosso, logo mais usos dai fiquei meio confuso, inclusive com aquele relacionado rs
					//pretendo pegar novamente amanhã, para entender melhor e possívelmente implementar
				}
			}
		}*/

	private:
		Lista<Pista*> *pistas;
		Lista<Cruzamento*> *cruzamentos;
		Relogio *eventos;
		int tempoExecucao;
		int tempoSemaforo;
};

#endif

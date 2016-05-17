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
			Pista *s2norte = new Pista(40, 500, 60, 15);

			pistas->adiciona(o1oeste);
			pistas->adiciona(o1leste);
			pistas->adiciona(c1oeste);
			pistas->adiciona(c1leste);
			pistas->adiciona(l1oeste);
			pistas->adiciona(l1leste);
			pistas->adiciona(n1sul);
			pistas->adiciona(n1norte);
			pistas->adiciona(n2sul);
			pistas->adiciona(n2norte);
			pistas->adiciona(s1sul);
			pistas->adiciona(s1norte);
			pistas->adiciona(s2sul);
			pistas->adiciona(s2norte);

			int prob0[2] = {80, 90};
			int prob1[2] = {40, 70};
			Cruzamento *c1 = new Cruzamento();
			Pista *pistaSaida0[3] = {c1leste, o1oeste, s1sul};
			c1->adiciona(new Semaforo(false, tempoSemaforo, prob0, n1sul, pistaSaida0));
			Pista *pistaSaida1[3] = {o1oeste, n1norte, s1sul};
			c1->adiciona(new Semaforo(false, tempoSemaforo, prob1, c1oeste, pistaSaida1));
			Pista *pistaSaida2[3] = {c1leste, n1norte, o1oeste};
			c1->adiciona(new Semaforo(false, tempoSemaforo, prob0, s1norte, pistaSaida2));
			Pista *pistaSaida3[3] = {c1leste, n1norte, s1sul};
			c1->adiciona(new Semaforo(false, tempoSemaforo, prob0, o1leste, pistaSaida3));
			cruzamentos->adiciona(c1);

			Cruzamento *c2 = new Cruzamento();
			Pista *pistaSaida4[3] = {l1leste, c1oeste, s2sul};
			c2->adiciona(new Semaforo(false, tempoSemaforo, prob1, n2sul, pistaSaida4));
			Pista *pistaSaida5[3] = {n2norte, c1leste, s2sul};
			c2->adiciona(new Semaforo(false, tempoSemaforo, prob1, l1oeste, pistaSaida5));
			Pista *pistaSaida6[3] = {l1leste, s2sul, c1oeste};
			c2->adiciona(new Semaforo(false, tempoSemaforo, prob1, s2norte, pistaSaida6));
			Pista *pistaSaida7[3] = {l1leste, n2norte, s2sul};
			c2->adiciona(new Semaforo(false, tempoSemaforo, prob1, c1leste, pistaSaida7));
			cruzamentos->adiciona(c2);
		}

		void eventosCriarCarro() {
			Pista *pista;
    		Evento *evento;
    		int tempo;

			for(int i = 0; i < pistas->getMaxLista(); i++) {
				pista = pistas->getDados()[i];
				if (pista->getFonte()) {
					tempo = 0;
					while(tempo < tempoExecucao) {
						tempo = pista->proximaCriacaoCarro(tempo);
						if (tempo <= tempoExecucao) {
							evento = new Evento(tempo, 0, pista);
                    		eventos->adicionaEmOrdem(evento);
						}
					}
				}
			}
		}

		void eventosChegadaSemaforo() {
			Pista *pista;
			Evento *evento;
			int tempo;
			for (int i = 0; i < eventos->getTamanho(); i++) {
				if (eventos->getEvento(i).getTipo() == 0) {
					tempo = eventos->getEvento(i).getTempo();
					pista = (Pista *) eventos->getEvento(i).getElemento();
					tempo += pista->getTempoPercorrer();
					if (tempo <= tempoExecucao) {
						evento = new Evento(tempo, 1, 0);
						eventos->adicionaEmOrdem(evento);
					}
				}
			}
		}

		void eventosCarroNoSemaforo(Evento tmpEvento) {
			Evento *evento;
			Semaforo *semaforo = (Semaforo *) tmpEvento.getElemento();
			int tempo = tmpEvento.getTempo();
			Pista *pistaDestino = semaforo->defineDestino();
			bool conseguiu = semaforo->trocaDePista(pistaDestino);

			if (semaforo->getStatusAberto()) {
				if (conseguiu) {
					tempo += pistaDestino->getTempoPercorrer();
					if (pistaDestino->getSumidouro())
						evento = new Evento(tempo, 3, pistaDestino);
					else
						evento = new Evento(tempo, 1, 0);
				} else {
					tempo += 1;
					evento = new Evento(tempo, 1, 0);
				}
			} else {
				tempo = semaforo->proximaTrocaSinal(tempo);
				evento = new Evento(tempo, 1, 0);
			}

			eventos->adicionaEmOrdem(evento);
		}

		void eventosMudancaSemaforo() {
			Semaforo *semaforo;
			Semaforo *proxSemaforo;
			Evento *evento;
			Evento *proxEvento;
			Cruzamento *tmpCruzamento;
			int tempo;
			for (int i = 0; i < cruzamentos->getMaxLista(); i++) {
				tmpCruzamento = cruzamentos->getDados()[i];
				for (int j = 0; j < tmpCruzamento->getSize(); j++) {
					tempo = 0;
					while (tempo <= tempoExecucao) {
						semaforo = (Semaforo *) tmpCruzamento->getSem(j);
						proxSemaforo = (Semaforo *) tmpCruzamento->getSem(j+1);
						tempo = semaforo->proximaTrocaSinal(tempo);
						if (tempo <= tempoExecucao) {
							evento = new Evento(tempo, 2, semaforo);
							proxEvento = new Evento(tempo, 2, semaforo);
							eventos->adicionaEmOrdem(evento);
							eventos->adicionaEmOrdem(proxEvento);
						}
					}
				}
			}
		}

		void executorDeEventos() {
 			int tempo = 0;
 			for(int i = 0; i < eventos->getTamanho(); i++) {
 				Evento evento = eventos->getEvento(i);
 				if (tempo > tempoExecucao) {
 					break;
 				} else if (evento.getTipo() == 0) {  // adiciona carro
 					Pista *pista = (Pista *) evento.getElemento();
 					pista->adicionaCarro(new Carro());
 					tempo = evento.getTempo();
 				} else if (evento.getTipo() == 1) { // carro chega semáforo
 					eventosCarroNoSemaforo(evento);
 					tempo = evento.getTempo();
 				} else if (evento.getTipo() == 2) { // muda semaforo
 					Semaforo *semaforo = (Semaforo *) evento.getElemento();
 					semaforo->mudaEstado();
 					tempo = evento.getTempo();
 				} else if (evento.getTipo() == 3) {  // remove carro
 					Pista *pista = (Pista *) evento.getElemento();
 					pista->retiraCarro();
 					tempo = evento.getTempo();
 				} else {
 					std::cout << "problema no código! \n";
 				}
 			}

 		}

		void terminaTrabalho() {
			int entraram;
			int sairam;
			Pista *pista;

			for(int i = 0; i < pistas->getMaxLista(); i++) {
				pista = pistas->getDados()[i];

				if (pista->getFonte())
					entraram += pista->getCarrosEntraram();

				if (pista->getSumidouro())
					sairam += pista->getCarrosSairam();
			}

			std::cout << entraram << " carros entraram em nossa simulação. \n";
			std::cout << sairam << " carros saíram em nossa simulação. \n";
		}

	private:
		Lista<Pista*> *pistas;
		Lista<Cruzamento*> *cruzamentos;
		Relogio *eventos;
		int tempoExecucao;
		int tempoSemaforo;
};

#endif

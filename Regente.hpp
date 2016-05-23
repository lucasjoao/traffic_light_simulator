#ifndef REGENTE_HPP
#define REGENTE_HPP

#include "estruturas/Lista.hpp"
#include "Pista.hpp"
#include "Relogio.hpp"
#include "Cruzamento.hpp"
/**
*@brief    Implementação da classe Regente;
*
*@details
*@param    *pistas       		Ponteiro para uma lista de vetor de Pistas.
*@param    *cruzamentos	 		Ponteiro para uma lista de vetor de Cruzamentos.
*@param    *eventos 	 		Ponteiro para um Relogio, que é uma lista encadeada de Eventos.
*@param    _vaiTerPrint			Inteiro que indica se haverão prints de andamento da execução ou não.
*@param    _tempoExecucao		Inteiro que recebe o tempo de execução total da simulação.
*@param    _tempoSemaforo   	Inteiro que recebe o tempo em que um semáforo deve permanecer aberto no sistema.
**/
class Regente {
	public:
		Regente() {}
/*
 *Construtor com parâmetros, com inicialização de tempoExecucao, tempoSemaforo, pistas, cruzamentos e eventos
 @params     tE, tS
 *O atributo tempoExecucao é inicializado com o int tE recebido do argumento do método construtor.
 *O atributo tempoSemaforo é inicializado com o int tS recebido do argumento do método construtor.
 *O atributo pistas é inicializado com uma nova instanciação de lista de vetor de pistas com 14 pistas.
 *O atributo vai ter print é inicializado com o inteiro vaiTerPrint recebido no arguemento do método construtor.
 *O atributo cruzamentos é inicializado com uma nova instanciação de lista de vetor de cruzamentos com 2 cruzamentos.
 *O atributo eventos é inicializado com uma nova instanciação da classe Relogio.
*/
		Regente(int tempoExecucao, int tempoSemaforo, int vaiTerPrint) {
			_tempoExecucao = tempoExecucao;
			_tempoSemaforo = tempoSemaforo;
			_vaiTerPrint = vaiTerPrint;
			pistas = new Lista<Pista*>(14);
			cruzamentos = new Lista<Cruzamento*>(2);
			eventos = new Relogio();
		}
/*
*Destrutor sem parâmetros, são chamados os métodos destroiCarros(), e destroiRegente().
*/
		~Regente() {
			destroiCarros();
			destroiRegente();
		}
/*
*@brief Método responsável por destruir os carros criados.
*@details Para cada pista que não esteja vazia, todos os carros são deletados.
*/
		void destroiCarros() {
			for (int i = 0; i < pistas->getMaxLista(); i++) {
				Pista *tmpPista = pistas->getDados()[i];
				if (!tmpPista->pistaVazia()) {
					for (int j = 0; j < tmpPista->getTamanho(); j++)
						delete tmpPista->getCarro(j);
				}
			}
		}
/*
*@brief Método responsável por deletar os eventos, cruzamentos e pistas.
*Ou seja, deleta os principais componentes do sistema regente de modo geral.
*@details Para cada evento, para cada cruzamento, para cada pista, são deletados
*os eventos, os cruzamentos e as pistas respectivamente.
*/
		void destroiRegente() {
			for (int i = 0; i < eventos->getTamanho(); i++)
				delete eventos->getEvento(i);

			for (int j = 0; j < cruzamentos->getMaxLista(); j++) {
				for (int k = 0; k < cruzamentos->getDados()[j]->getSize(); k++)
					delete cruzamentos->getDados()[j]->getSem(k);

				delete cruzamentos->getDados()[j];
			}

			for (int l = 0; l < pistas->getMaxLista(); l++)
				delete pistas->getDados()[l];

			delete eventos;
			delete cruzamentos;
			delete pistas;
		}
/*
*@brief    Instancia/cria as estruturas do sistema.
*@details  São criadas estruturas tais como as pistas, semáforos.
*/
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

			int prob0[2] = {80, 90};
			int prob1[2] = {40, 70};

			Cruzamento *c1 = new Cruzamento();
			Cruzamento *c2 = new Cruzamento();

			Pista *pistaSaida0[3] = {c1leste, o1oeste, s1sul};
			Pista *pistaSaida1[3] = {o1oeste, n1norte, s1sul};
			Pista *pistaSaida2[3] = {c1leste, n1norte, o1oeste};
			Pista *pistaSaida3[3] = {c1leste, n1norte, s1sul};
			Pista *pistaSaida4[3] = {l1leste, c1oeste, s2sul};
			Pista *pistaSaida5[3] = {n2norte, c1leste, s2sul};
			Pista *pistaSaida6[3] = {l1leste, s2sul, c1oeste};
			Pista *pistaSaida7[3] = {l1leste, n2norte, s2sul};

			Semaforo *sn1sul = new Semaforo(true, _tempoSemaforo, prob0, n1sul, pistaSaida0);
			Semaforo *sc1oeste = new Semaforo(false, _tempoSemaforo, prob1, c1oeste, pistaSaida1);
			Semaforo *ss1norte = new Semaforo(false, _tempoSemaforo, prob0, s1norte, pistaSaida2);
			Semaforo *so1leste = new Semaforo(false, _tempoSemaforo, prob0, o1leste, pistaSaida3);
			Semaforo *sn2sul = new Semaforo(true, _tempoSemaforo, prob1, n2sul, pistaSaida4);
			Semaforo *sl1oeste = new Semaforo(false, _tempoSemaforo, prob1, l1oeste, pistaSaida5);
			Semaforo *ss2norte = new Semaforo(false, _tempoSemaforo, prob1, s2norte, pistaSaida6);
			Semaforo *sc1leste = new Semaforo(false, _tempoSemaforo, prob1, c1leste, pistaSaida7);

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

			c1->adiciona(sn1sul);
			c1->adiciona(sc1oeste);
			c1->adiciona(ss1norte);
			c1->adiciona(so1leste);

			c2->adiciona(sn2sul);
			c2->adiciona(sl1oeste);
			c2->adiciona(ss2norte);
			c2->adiciona(sc1leste);

			cruzamentos->adiciona(c1);
			cruzamentos->adiciona(c2);
		}
/*
*@brief    Método que gera os eventos respectivos a criação de carros
*@details  Para cada pista, enquanto o tempo for menor que o tempo
*de execução do sistema, serão criados eventos do tipo 0, que correspondem
*ao tipo de criação de carros em um determinado tempo.
*/
		void eventosCriarCarro() {
			Pista *pista;
    		Evento *evento;
    		int tempo;

			for(int i = 0; i < pistas->getMaxLista(); i++) {
				pista = pistas->getDados()[i];
				if (pista->getFonte()) {
					tempo = 0;
					while(tempo < _tempoExecucao) {
						tempo = pista->proximaCriacaoCarro(tempo);
						if (tempo <= _tempoExecucao) {
							evento = new Evento(tempo, 0, pista);
                    		eventos->adicionaEmOrdem(evento);
						}
					}
				}
			}
		}
/*
*@brief Busca o semáforo correto da pista.
*@param Ponteiro para uma pista que deseja se buscar o semaforo da pista que é aferente.
*@return Retorna o semáforo desejado.
*/
		Semaforo *semaforoDaPista(Pista *pista) {
			Semaforo *semaforo;
			Cruzamento *tmpCruzamento;
			for (int i = 0; i < cruzamentos->getMaxLista(); i++) {
				tmpCruzamento = cruzamentos->getDados()[i];
				for (int j = 0; j < tmpCruzamento->getSize(); j++) {
					semaforo = (Semaforo *) tmpCruzamento->getSem(j);
					if (pista == semaforo->getPistaAferente())
						return semaforo;
				}
			}

			return nullptr;
		}
/*
*@brief    Método que gera os eventos respectivos a chegada no semáforo
*@details  Para cada evento já adicionado, é verificado se o evento é de
*um tipo específico, então são criados eventos de chegada ao semáforo.
*/
		void eventosChegadaSemaforo() {
			Pista *pista;
			Evento *evento;
			Semaforo *semaforo;
			Relogio *tmpEventos = new Relogio();
			int tempo;
			int nroEventosPrincipal = eventos->getTamanho();

			for (int i = 0; i < nroEventosPrincipal; i++) {
				tempo = eventos->getEvento(i)->getTempo();
				pista = (Pista *) eventos->getEvento(i)->getElemento();
				semaforo = semaforoDaPista(pista);
				tempo += pista->getTempoPercorrer();
				if (tempo <= _tempoExecucao) {
					evento = new Evento(tempo, 1, semaforo);
					tmpEventos->adicionaEmOrdem(evento);
				}
			}

			for (int j = 0; j < tmpEventos->getTamanho(); j++)
				eventos->adicionaEmOrdem(tmpEventos->getEvento(j));
		}
/*
*@brief    Método que gera os eventos respectivos a mudança de semáforo.
*@details  Enquanto o tempo de execução for válido, são criados dois eventos
*de troca de sinal, em que um se fecha para o seguinte abrir respectivamente.
*De modo que um semáforo de cada cruzamento fica aberto por vez.
*/
		void eventosMudancaSemaforo() {
			Semaforo *semaforo;
			Semaforo *proxSem;
			Evento *evento;
			Evento *proxEvento;
			Cruzamento *tmpCruzamento;
			int tempo;

			for (int i = 0; i < cruzamentos->getMaxLista(); i++) {
				tmpCruzamento = cruzamentos->getDados()[i];
				for (int j = 0; j < tmpCruzamento->getSize(); j++) {
					tempo = 0;
					while (tempo <= _tempoExecucao) {
						semaforo = (Semaforo *) tmpCruzamento->getSem(j);

						if (j == 3)
							proxSem = (Semaforo *) tmpCruzamento->getSem(0);
						else
							proxSem = (Semaforo *) tmpCruzamento->getSem(j+1);

						tempo = semaforo->proximaTrocaSinal(tempo);
						if (tempo <= _tempoExecucao) {
							evento = new Evento(tempo, 2, semaforo);
							proxEvento = new Evento(tempo, 2, proxSem);
							eventos->adicionaEmOrdem(evento);
							eventos->adicionaEmOrdem(proxEvento);
						}
					}
				}
			}
		}
/*
*@brief    Método que gera os eventos respectivos a abertura do sinal
*@details  Se o semáforo encontra-se aberto, e foi possivel trocar de pista,
*é criado novo evento de chegada ao sumidouro ou a uma pista comum, caso não seja
*possível trocar de pista, tenta-se novamente. Caso o semáforo esteja fechado,
*espera-se a próxima troca de sinal.
*/
		void eventosCarroNoSemaforo(Evento *tmpEvento) {
			Evento *evento;
			Semaforo *semaforo = (Semaforo *) tmpEvento->getElemento();
			int tempo = tmpEvento->getTempo();
			Pista *pistaDestino = semaforo->defineDestino();
			bool conseguiu = semaforo->trocaDePista(pistaDestino);

			if (semaforo->getStatusAberto()) {
				if (conseguiu) {
					tempo += pistaDestino->getTempoPercorrer();
					if (pistaDestino->getSumidouro()) {
						evento = new Evento(tempo, 3, pistaDestino);
					} else {
						semaforo = semaforoDaPista(pistaDestino);
						evento = new Evento(tempo, 1, semaforo);
					}
					printa(_vaiTerPrint, 4, tmpEvento->getTempo());
				} else {
					tempo += 1;
					evento = new Evento(tempo, 1, semaforo);
					printa(_vaiTerPrint, 5, tmpEvento->getTempo());
				}
			} else {
				tempo = semaforo->proximaTrocaSinal(tempo);
				evento = new Evento(tempo, 1, semaforo);
				printa(_vaiTerPrint, 6, tmpEvento->getTempo());
			}

			eventos->adicionaEmOrdem(evento);
		}
/*
*@brief    Método responsável por executar todos os tipos de eventos do sistema.
*@details  Para cada evento no sistema, enquanto o tempo de execução pré-estabelecido
*for válido, conforme o tipo do evento (0,1,2,3), estes serão executados.
*/
		void executorDeEventos() {
 			int tempo = 0;
 			for(int i = 0; i < eventos->getTamanho(); i++) {
 				Evento *evento = eventos->getEvento(i);

				if (tempo > _tempoExecucao)
 					break;

				Pista *pista = (Pista *) evento->getElemento();
				Semaforo *semaforo = (Semaforo *) evento->getElemento();

				switch (evento->getTipo()) {
					case 0: // add carro
						pista->adicionaCarro(new Carro());
						tempo = evento->getTempo();
						break;
					case 1: // carro chega no semaforo
						eventosCarroNoSemaforo(evento);
						tempo = evento->getTempo();
						break;
					case 2: // muda semaforo
						semaforo->mudaEstado();
						tempo = evento->getTempo();
						break;
					case 3: // retira carro
						pista->retiraCarro(1);
						tempo = evento->getTempo();
						break;
					default:
						std::cout << "Problema no código! \n";
				}

				printa(_vaiTerPrint, evento->getTipo(), evento->getTempo());
			}
		}
/*
*@brief    Método que termina a execução do programa, retornando as saídas.
*@details  Para cada pista conforme fonte ou sumidouro, são recolhidos seus
*valores de carros que entraram e/ou sairam, para serem armazenados em
*variáveis que servirão de saída para o usuário verificar os resultados
*de toda a simulação de tráfego.
*/
		void terminaTrabalho() {
			int entraram = 0;
			int sairam = 0;
			Pista *pista;

			for(int i = 0; i < pistas->getMaxLista(); i++) {
				pista = pistas->getDados()[i];

				if (pista->getFonte())
					entraram += pista->getCarrosEntraram();

				if (pista->getSumidouro())
					sairam += pista->getCarrosSairam();
			}

			std::cout << "-------------------------------------------------\n";
			std::cout << "RESULTADO:\n";
			std::cout << entraram << " carros entraram em nossa simulação. \n";
			std::cout << sairam << " carros saíram em nossa simulação. \n";
		}
/*
*@brief Método responsável por printar as mensagens dos acontecimentos do sistema.
*@param Inteiro que indica se tais prints devem ser mostrados ou não, e inteiro que
*corresponde ao tempo de cada evento a ser printado.
*/
		void printa(int vaiTerPrint, int tipo, int tempo) {
			if (vaiTerPrint) {
				switch (tipo) {
					case 0:
						std::cout << "Carro chegou em uma pista fonte aos "		  << tempo << " segundos. \n";
						break;
					case 1:
						break;
					case 2:
						break;
					case 3:
						std::cout << "Carro saiu de uma pista sumidoruo aos "	   << tempo << " segundos. \n";
						break;
					case 4:
						std::cout << "Carro mudou a pista após um semáforo aos"	     << " " << tempo << " segundos. \n";
						break;
					case 5:
						std::cout << "Carro não conseguiu mudar de pista após"      << " um semáforo aos "  << tempo             	   << " segundos. \n";
						break;
					case 6:
						std::cout << "Carro encontrou um semáforo fechado aos "      << tempo << " segundos. \n";
						break;
					default:
						std::cout << "Problema no código! \n";
				}
			}
		}

	private:
		Lista<Pista*> *pistas;
		Lista<Cruzamento*> *cruzamentos;
		Relogio *eventos;
		int _tempoExecucao;
		int _tempoSemaforo;
		int _vaiTerPrint;
};

#endif

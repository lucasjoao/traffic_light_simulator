#ifndef SEMAFORO_HPP
#define SEMAFORO_HPP

#include "Pista.hpp"
/**
*@brief    Implementação da classe Semaforo;
*
*@param  _status          Dado por um boolean, que determina se está aberto ou fechado o semáforo.
*@param  tempoAberto      Dado por um inteiro, que descreve o tempo que o semaforo deve permanecer aberto.
*@param  _probabilidades  Dado por ponteiro para um inteiro, que indica a primeira posição da memória do vetor de prob.
*@param  _pistaAferente	  Dado por um ponteiro para objeto do tipo pista, que indica a pista atual do semáforo
*@param  _pistaSaida 	  Atributo dado por um vetor de Pista com 4 posições, que indica as possíveis saídas.
**/
class Semaforo {
	public:
/*
 *Construtor com parâmetros, com inicialização de _status, _probabilidades,  _pistaAferente, tempoAberto e pistaSaida[].
 @params      sts, tmp, *prob, *pista e *pistas[].
 *O atributo _status é inicializado com o bool sts recebido como argumento.
 *O atributo tempoAberto é inicializado com o tempo tmp recebido como argumento.
 *O atributo _probabilidades é inicializado com o int prob recebido como argumento.
 *O atributo _pistaAferente é inicializado com o ponteiro pista recebido como argumento.
 *O atributo _pistaSaida[] é inicializado através de um for, que preenche cada posicao
 *de seu vetor com as informações contidas nas respectivas posições do argumento recebido *pistas[].
 */
		Semaforo(bool sts, int tmp, int *prob, Pista *pista, Pista *pistas[]) {
			_status = sts;
			tempoAberto = tmp;
			_probabilidades = prob;
			_pistaAferente = pista;

			for (int i = 0; i < 3; i++)
				_pistaSaida[i] = pistas[i];
		}
/*
*Construtor sem parâmetros, vazio.
*/
		Semaforo() {}
/*
*Destrutor sem parâmetros, vazio.
*/
		~Semaforo() {}
/*
*@brief     Muda estado do semáforo.
*@details   Nega o estado atual contido no atributo bool _status.
*/
		void mudaEstado() {
			_status = !_status;
		}
/*
*@brief   Calcula o tempo para próxima troca de sinal.
*@return  Retorna um inteiro que é o tempo solicitado.
*/
		int proximaTrocaSinal(int tempo) {
			return tempo + tempoAberto;
		}
/*
*@brief   Método que define destino que determinado carro irá tomar.
*@return  Retorna uma determinada pista contida no vetor de pistas de saida, que fora
*escolhida através das probabilidades de tomada de decisão e que é o destino do carro.
*/
		Pista *defineDestino() {
			Carro *carro = _pistaAferente->getCarroNoSemaforo();
			int probabilidadeCarro = carro->getChanceDeVirar();

			if (probabilidadeCarro <= _probabilidades[0]) {
				return _pistaSaida[0];
			} else if (_probabilidades[1] <= probabilidadeCarro) {
				return _pistaSaida[2];
			} else {
				return _pistaSaida[1];
			}
		}
/*
*@brief   Verifica a disponibilidade da troca de pista por um determinado carro.
*@return  Retorna false caso a pista destino esteja cheia ou o status do semáforo
*dela não esteja aberto, e true caso seja possível realizar a troca de pista.
*/
		bool trocaDePista(Pista *pistaDestino) {
			if (pistaDestino->pistaCheia() || !getStatusAberto())
				return false;

			Carro *carro = _pistaAferente->getCarroNoSemaforo();
			pistaDestino->adicionaCarro(carro);
			_pistaAferente->retiraCarro(0);
			return true;
		}
/*
*@brief   Busca o tempo que permanece aberto determinado semaforo.
*@return  Retorna um inteiro correspondente a tal tempo.
*/
		int getTempoAberto() {
			return tempoAberto;
		}
/*
*@brief   Busca o atual status do semaforo.
*@return  Retorna true caso aberto, e false caso não esteja.
*/
		bool getStatusAberto() {
			return _status;
		}
/*
*@brief   Busca a pista aferente.
*@return  Retorna a pista afererente do semáforo.
*/
		Pista *getPistaAferente() {
			return _pistaAferente;
		}

	private:
		bool _status;
		int tempoAberto;
		int *_probabilidades;
		Pista *_pistaAferente;
		Pista *_pistaSaida[3];
};
#endif
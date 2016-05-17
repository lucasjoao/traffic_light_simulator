#ifndef SEMAFORO_HPP
#define SEMAFORO_HPP

#include "Pista.hpp"

class Semaforo {
	public:
		Semaforo(bool sts, int tmp, int *prob, Pista *pista, Pista *pistas[]) {
			_status = sts;
			tempoAberto = tmp;
			_probabilidades = prob;
			_pistaAferente = pista;

			for (int i = 0; i < 3; i++)
				_pistaSaida->inclui(pistas[i]);
		}

		int getTempoParaAbrir() {
			return tempoParaAbrir;
		}

		int getTempoAberto() {
			return tempoAberto;
		}

		bool getStatusAberto() {
			return _status;
		}

		int proximaTrocaSinal(int tempo) {
			return tempo + tempoAberto;
		}

		Pista *defineDestino() {
			Carro *carro = _pistaAferente->getCarroNoSemaforo();
			int probabilidadeCarro = carro->calculaProbDeVirar();

			if (probabilidadeCarro < _probabilidades[0]) {
				return _pistaSaida->getDados()[0];
			} else if (_probabilidades[1] < probabilidadeCarro) {
				return _pistaSaida->getDados()[2];
			} else {
				return _pistaSaida->getDados()[1];
			}
		}

		bool trocaDePista(Pista *pistaDestino) {
			if (pistaDestino->pistaCheia() || !getStatusAberto())
				return false;

			Carro *carro = _pistaAferente->getCarroNoSemaforo();
			pistaDestino->adicionaCarro(carro);
			_pistaAferente->retiraCarro();
			return true;
		}

	private:
		bool _status;
		int tempoParaAbrir;
		int tempoAberto;
		int *_probabilidades;
		Pista *_pistaAferente;
		Fila<Pista*> *_pistaSaida;
};
#endif
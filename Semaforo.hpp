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
				_pistaSaida[i] = pistas[i];
		}

		void mudaEstado() {
			_status = !_status;
		}

		int proximaTrocaSinal(int tempo) {
			return tempo + tempoAberto;
		}

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

		bool trocaDePista(Pista *pistaDestino) {
			if (pistaDestino->pistaCheia() || !getStatusAberto())
				return false;

			Carro *carro = _pistaAferente->getCarroNoSemaforo();
			pistaDestino->adicionaCarro(carro);
			_pistaAferente->retiraCarro(0);
			return true;
		}

		int getTempoAberto() {
			return tempoAberto;
		}

		bool getStatusAberto() {
			return _status;
		}

	private:
		bool _status;
		int tempoAberto;
		int *_probabilidades;
		Pista *_pistaAferente;
		Pista *_pistaSaida[3];
};
#endif
#ifndef PISTA_HPP
#define PISTA_HPP

#include "estruturas/Fila.hpp"
#include "estruturas/Lista.hpp"
#include "Carro.hpp"

class Pista : Fila<Carro*> {
	public:
		Pista(int vel, int tam, int freq, int varFreq) {
			velocidade = vel;
			tamanho = tam;
			frequencia = freq;
			variacaoFrequencia = varFreq;

			tempoPercorrer = tamanho / velocidade;

			if (freq != 0) {
				fonte = true;
				sumidouro = false;
			} else {
				fonte = false;
				if (varFreq == 42)
					sumidouro = false;
				else
					sumidouro = true;
			}
		}

		void adicionaCarro() {

		}

		void retiraCarro() {

		}

		int proximaCriacaoCarro(int tempo) {
			int limiteInferior = frequencia - variacaoFrequencia;
			int nroValores = 2 * variacaoFrequencia + 1;
			return (limiteInferior + (rand() % nroValores)) + tempo;
		}

		int getTempoPercorrer() {
			return tempoPercorrer;
		}

		bool getFonte() {
			return fonte;
		}

		bool getSumidouro() {
			return sumidouro;
		}

		Carro *getCarroNoSemaforo() {
			return Fila<Carro*>::getDados()[0];
		}

		bool pistaCheia() {
			return Fila<Carro*>::filaCheia();
		}

	private:
		int velocidade;
		int tamanho;
		int frequencia;
		int variacaoFrequencia;
		int espacoLivre;
		int tempoPercorrer;
		bool fonte;
		bool sumidouro;
		// Lista *pistasDeSaidas;
};

#endif

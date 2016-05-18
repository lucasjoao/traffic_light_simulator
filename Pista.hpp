#ifndef PISTA_HPP
#define PISTA_HPP

#include "estruturas/Fila.hpp"
#include "estruturas/Lista.hpp"
#include "Carro.hpp"

class Pista : Fila<Carro*> {
	public:
		Pista(int vel, int tam, int freq, int varFreq) :       									Fila<Carro*>::Fila<Carro*>(tam) {
			velocidade = vel;
			tamanho = tam;
			frequencia = freq;
			variacaoFrequencia = varFreq;
			espacoLivre = tam;
			tempoPercorrer = (int) (tamanho / velocidade);

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

		void adicionaCarro(Carro *carro) {
			int tamCar = carro->getTamanho();
			if (tamCar <= espacoLivre) {
				Fila<Carro*>::inclui(carro);
				carrosEntraram += 1;
				espacoLivre -= tamCar;
			}
		}

		void retiraCarro(int tipo) {
			Carro *carro = Fila<Carro*>::retira();
			int tamCar = carro->getTamanho();
			espacoLivre += tamCar;
			if (tipo == 1)
				carrosSairam += 1;
		}

		int proximaCriacaoCarro(int tempo) {
			int limiteInferior = frequencia - variacaoFrequencia;
			int nroValores = 2 * variacaoFrequencia + 1;
			return (limiteInferior + (rand() % nroValores)) + tempo;
		}

		Carro *getCarroNoSemaforo() {
			return Fila<Carro*>::getDados()[0];
		}

		bool pistaCheia() {
			return Fila<Carro*>::filaCheia();
		}

		int getTempoPercorrer() {
			return tempoPercorrer;
		}

		int getCarrosEntraram() {
			return carrosEntraram;
		}

		int getCarrosSairam() {
			return carrosSairam;
		}

		bool getFonte() {
			return fonte;
		}

		bool getSumidouro() {
			return sumidouro;
		}

		// Semaforo *getSemaforoDaPista() {
		// 	return semaforoDaPista;
		// }

		// void setSemaforoDaPista(Semaforo *semaforo) {
		// 	semaforoDaPista = semaforo;
		// }

	private:
		int velocidade;
		int tamanho;
		int frequencia;
		int variacaoFrequencia;
		int espacoLivre;
		int tempoPercorrer;
		int carrosEntraram;
		int carrosSairam;
		// Semaforo *semaforoDaPista;
		bool fonte;
		bool sumidouro;
};

#endif

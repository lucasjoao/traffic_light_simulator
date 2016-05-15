#ifndef PISTA_HPP
#define PISTA_HPP

#include "estruturas/Fila.hpp"
#include "estruturas/Lista.hpp"
#include "Carro.hpp"

class Pista : Fila<Carro> {
	public:
		Pista(int vel, int tam, int freq) : velocidade(vel), tamanho(tam), 								 	frequencia(freq) {}

		void adicionaCarro() {

		}

		void retiraCarro() {

		}

		int proximoEvento() {

		}

	private:
		int velocidade;
		int tamanho;
		int frequencia;
		int espacoLivre;
		int tempoPercorrer;
		bool fonte;
		bool sumidouro;
		Lista *pistasDeSaidas;
};

#endif

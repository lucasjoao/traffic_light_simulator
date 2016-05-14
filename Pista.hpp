#ifndef PISTA_HPP
#define PISTA_HPP

#include "estruturas/Fila.hpp"
#include "estruturas/Lista.hpp"
#include "Carro.hpp"

class Pista : Fila<Carro> {
	public:
	private:
		int _velocidade, _tamanho, _espacoLivre;
		Lista *pistasDeSaidas;
};

#endif

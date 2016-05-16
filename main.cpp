#include <iostream>
#include <stdlib.h>
#include "Regente.hpp"

int main() {
	srand((unsigned)time(NULL));

	int tempoExecucao;
	std::cout << "Insira o tempo, em segundos, de execução da simulação: \n"      << "> ";
	std::cin >> tempoExecucao;

	int tempoSemaforo;
	std::cout << "Insira o tempo, em segundos, que o semáforo fica aberto: \n" 		 << "> ";
	std::cin >> tempoSemaforo;

	Regente *regente = new Regente(tempoExecucao, tempoSemaforo);
	regente->start();
	regente->eventosCriarCarro();
	regente->eventosChegadaSemaforo();
	// aqui deve-se instanciar o regente, chamar métodos que calculam os eventos, metodo que executa todos os eventos e finalizar execução com print do resultado final

	return 0;
}
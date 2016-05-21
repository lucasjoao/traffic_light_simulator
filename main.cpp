#include <iostream>
#include <stdlib.h>
#include "Regente.hpp"

int main() {
	srand((unsigned)time(NULL));

	int vaiTerPrint;
	std::cout << "Insira 1 se você quiser que a simulação imprima informações " 	 << "na tela durante a execução ou 0 se você quiser apenas "      		<< "receber o resultado final: \n"									  << "> ";
	std::cin >> vaiTerPrint;

	int tempoExecucao;
	std::cout << "Insira o tempo, em segundos, de execução da simulação: \n"      << "> ";
	std::cin >> tempoExecucao;

	int tempoSemaforo;
	std::cout << "Insira o tempo, em segundos, que o semáforo fica aberto: \n" 		 << "> ";
	std::cin >> tempoSemaforo;

	Regente *regente = new Regente(tempoExecucao, tempoSemaforo, vaiTerPrint);
	regente->start();
	regente->eventosCriarCarro();
	regente->eventosChegadaSemaforo();
	regente->eventosMudancaSemaforo();
	regente->executorDeEventos();
	regente->terminaTrabalho();
	delete regente;

	return 0;
}
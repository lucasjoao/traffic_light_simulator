#include <iostream>
#include <stdlib.h>
#include "Regente.hpp"
/**
*@brief    Implementação da classe main (Principal);
**/
int main() {
	srand((unsigned)time(NULL));
/*@details Entradas do usuário são recebidas, que denotam o tempo total em segundos
*que a simulação deve acontecer. De mesmo modo com o tempo que os semáforos devem
*permanecer abertos. Além de solicitar a escolha do usuário se deseja que as informações
*detalhadas de tráfego nas vias sejam imprimidas na tela ou não */
	int vaiTerPrint;
	std::cout << "Insira 1 se você quiser que a simulação imprima informações " 	 << "na tela durante a execução ou 0 se você quiser apenas "      		<< "receber o resultado final: \n"									  << "> ";
	std::cin >> vaiTerPrint;
	int tempoExecucao;
	std::cout << "Insira o tempo, em segundos, de execução da simulação: \n"      << "> ";
	std::cin >> tempoExecucao;
	int tempoSemaforo;
	std::cout << "Insira o tempo, em segundos, que o semáforo fica aberto: \n" 		 << "> ";
	std::cin >> tempoSemaforo;

/*@details   Classe regente "Regente" de todo o sistema é instanciada,
*e iniciada "start()" */
	Regente *regente = new Regente(tempoExecucao, tempoSemaforo, vaiTerPrint);
	regente->start();

/*@details   Os métodos geradores dos eventos são executados.*/
	regente->eventosCriarCarro();
	regente->eventosChegadaSemaforo();
	regente->eventosMudancaSemaforo();
	regente->executorDeEventos();

/*Por fim, o método "terminaTrabalho()" de finalização da execução do sistema é
*executado, mostrando as respectivas saídas do sistema.*/
	regente->terminaTrabalho();
	delete regente;

	return 0;
}
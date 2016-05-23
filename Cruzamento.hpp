#ifndef CRUZAMENTO_HPP
#define CRUZAMENTO_HPP

#include "estruturas/ListaCirc.hpp"
#include "estruturas/Lista.hpp"
#include "Semaforo.hpp"
/**
*@brief    Implementação da classe Cruzamento;
*
*@details  Cruzamento é uma lista circular de Semaforo com herança privada, e não tem atributos próprios.
**/
class Cruzamento : private ListaCirc<Semaforo*> {
	public:
/*
*Construtor sem parâmetros, vazio.
*/
		Cruzamento() {}
/*
*Destrutor, que chama o método destroi lista da superclasse.
*/
		~Cruzamento() {
			ListaCirc<Semaforo*>::destroiLista();
		}
/*
*@brief   Adiciona um semaforo na circular.
*@param   Ponteiro para um Semaforo que será adicionado na lista circular.
*/
		void adiciona(Semaforo *semaforo) {
			ListaCirc<Semaforo*>::adiciona(semaforo);
		}
/*
*@brief   Busca a informação que denota o atual tamanho da lista circular.
*@return  Retorna um inteiro que é o tamanho atual da lista circular.
*/
		int getSize() {
			return ListaCirc<Semaforo*>::getSize();
		}
/*
*@brief   Busca um objeto Semaforo a partir de sua posiçao na lista circular.
*@param   Recebe como parâmetro a posição de determinado semaforo na lista.
*@return  Retorna o Semaforo que fora encontrado na posição posicao, através
*do método mostra da superclasse.
*/
		Semaforo *getSem(int posicao) {
			return ListaCirc<Semaforo*>::mostra(posicao);
		}

};
#endif
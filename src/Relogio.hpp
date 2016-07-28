#ifndef RELOGIO_HPP
#define RELOGIO_HPP

#include "estruturas/ListaEnc.hpp"
#include "Evento.hpp"
/**
*@brief    Implementação da classe Relogio;
*
*@details  Relogio é uma lista encadeada de eventos, e não tem atributos próprios.
**/
class Relogio : public ListaEnc<Evento*> {
	public:
/*
*Construtor sem parâmetros, vazio.
*/
		Relogio() {}
/*
*Destrutor sem parâmetros, utiliza o método destroiLista() da superclasse lista encadeada.
*/
		virtual ~Relogio() {
			ListaEnc<Evento*>::destroiLista();
		}
/*
*@brief   Adiciona um evento em uma determinada ordem na lista encadeada
*@param   Ponteiro para um Evento que será adicionado na lista.
*/
		void adicionaEmOrdem(Evento *evento) {
			ListaEnc<Evento*>::adicionaEmOrdem(evento);
		}
/*
*@brief   Verifica a comparação de tempo entre dois eventos.
*@param   Ponteiros para dois eventos diferentes, a serem comparados.
*@return  True caso o evento0 tenha tempo maior que o evento1, e false caso não tenha.
*/
		bool maior(Evento *evento0, Evento *evento1) {
			return evento0->getTempo() > evento1->getTempo();
		}
/*
*@brief   Busca a informação que denota o atual tamanho da lista encadeada.
*@return  Retorna um inteiro que é o tamanho atual da lista.
*/
		int getTamanho() {
			return ListaEnc<Evento*>::getSize();
		}
/*
*@brief   Busca um evento a partir de sua posiçao na lista encadeada.
*@param   Recebe como parâmetro a posição de determinado evento na lista encadeada.
*@return  Retorna o evento que fora encontrado na posição posicao.
*/
		Evento *getEvento(int posicao) {
			return ListaEnc<Evento*>::mostra(posicao);
		}
};

#endif
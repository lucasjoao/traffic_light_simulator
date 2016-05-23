#ifndef EVENTO_HPP
#define EVENTO_HPP
/**
*@brief    Implementação da classe Evento;
*
*@param  _tempo         Dado por int que representa tempo de acontecimento do evento
*@param  _tipo          Representa o tipo do evento, podendo diferenciar-se em 4 tipos(0 a 3).
*@param  *_elemento     Representa o elemento do evento
**/
class Evento {
    public:
/*
*Construtor sem parâmetros, vazio.
*/
        Evento() {}
/*
 *Construtor com parâmetros, com inicialização de _tempo, _tipo e _elemento.
 @params      tempo, tipo e ponteiro void elemento.
 *O atributo _tempo é inicializado com o tempo recebido como argumento.
 *O atributo _tipo é inicializado com o tipo recebido como argumento.
 *O atributo *_elemento é inicializado com o ponteiro void recebido como argumento.
 */
        Evento(int tempo, int tipo, void *elemento) {
            _tempo = tempo;
            _tipo = tipo;
            _elemento = elemento;
        }
/*
*@brief   Busca a informação que denota o tipo do evento.
*@return  Retorna um inteiro que é um número correspondente ao tipo do evento.
*/
        int getTipo() {
            return _tipo;
        }
/*
*@brief   Busca a informação que denota o tempo de acontecimento do evento.
*@return  Retorna um inteiro que é o tempo do evento.
*/
        int getTempo() {
            return _tempo;
        }
/*
*@brief   Busca um ponteiro tipo void do evento.
*@return  Retorna o ponteiro void do evento.
*/
        void *getElemento() {
            return _elemento;
        }

    private:
        int _tempo;
        int _tipo;
        void *_elemento;
};
#endif

#ifndef PISTA_HPP
#define PISTA_HPP

#include "estruturas/Fila.hpp"
#include "estruturas/Lista.hpp"
#include "Carro.hpp"
/**
*@brief    Implementação da classe Pista;
*
*@details  Pista é uma fila de vetor  de Carro com herança privada, e possui os atributos abaixo.
*@param  velocidade          Inteiro que descreve a velocidade permitida de determinada pista.
*@param  tamanho             Inteiro que descreve o tamanho de determinada pista.
*@param  frequencia      	 Inteiro que descreve a frequencia da pista.
*@param  variacaoFrequencia  Inteiro que descreve a variãção de frequencia.
*@param  espacoLivre         Inteiro que descreve o espaço livre em determinada pista.
*@param  tempoPercorrer      Inteiro que descreve em quanto tempo é possivel percorrer a pista.
*@param	 carrosEntraram      Inteiro que descreve a quantidade de carros que entraram no sistema.
*@param  carrosSairam        Inteiro que descreve a quantidade de carros que sairam do sistema.
*@param  fonte               Boolean que informa se determinada pista é fonte ou não.
*@param  sumidouro           Boolean que informa se determinada pista é sumidouro ou não.
**/
class Pista : private Fila<Carro*> {
	public:
/*
 *Construtor com parâmetros, com inicialização de velocidade, tamanho, frequencia,
 variacaoFrequencia, espacoLivre, tempoPercorrer, sumidouro e fonte.
 @params      vel, tam, freq, varFreq.
 *O atributo velocidade recebe o int vel recebido como argumento.
 *O atributo tamanho recebe o int tam recebido como argumento.
 *O atributo frequencia recebe o int freq recebido como argumento.
 *O atributo variacaoFrequencia recebe o int varFreq recebido como argumento.
 *O atributo espacoLivre recebe tam, int recebido no argumento.
 *O atributo tempoPercorrer recebe a divisão entre o tamanho e velocidade da pista.
 *O atributo fonte recebe true se frequencia for diferente de zero, e false caso não seja.
 *O atributo sumidouro recebe false caso fonte for true, ou caso a variação de frequencia
 *for igual a 42, caso contrário recebe true.
 */
		Pista() {}

		Pista(int vel, int tam, int freq, int varFreq) : Fila<Carro*>::Fila<Carro*>(tam) {
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

		virtual ~Pista() {}
/*
*@brief     Adiciona o carro da pista, se houver espaço.
*@param     Ponteiro para o Carro a ser adicionado.
*@detail    Carro só é adicionado se houver espaço, e ao ser adicionado o
*espaço livre da pista é diminuido, e a contagem de carros que entraram é incrementada.
*/
		void adicionaCarro(Carro *carro) {
			int tamCar = carro->getTamanho();
			if (tamCar <= espacoLivre) {
				Fila<Carro*>::inclui(carro);
				carrosEntraram += 1;
				espacoLivre -= tamCar;
			}
		}
/*
*@brief     Retira o carro da pista.
*@param     int tipo que descreve o tipo da pista.
*@detail    Ao retirar de fato o carro o espaço livre é aumentado e no caso de
*um sumidouro, a quantidade de carros que sairam do sistema é incrementada.
*/
		void retiraCarro(int tipo) {
			Carro *carro = Fila<Carro*>::retira();
			int tamCar = carro->getTamanho();
			espacoLivre += tamCar;
			if (tipo == 1) {
				carrosSairam += 1;
				delete carro;
			}
		}
/*
*@brief   Busca o tempo de criação de proximo carro na pista.
*@return  Retorna um inteiro correspondente a tal valor.
*/
		int proximaCriacaoCarro(int tempo) {
			int limiteInferior = frequencia - variacaoFrequencia;
			int nroValores = 2 * variacaoFrequencia + 1;
			return (limiteInferior + (rand() % nroValores)) + tempo;
		}
/*
*@brief   Busca o carro localizado na posição 0 da fila .
*@return  Retorna o objeto carro contido na posição respectiva da fila.
*/
		Carro *getCarroNoSemaforo() {
			return Fila<Carro*>::getDados()[0];
		}
/*
*@brief   Busca o carro localizado na posição pos da fila .
*@param   Inteiro pos, que é posição que se deseja pegar o carro desejado na fila.
*@return  Retorna o objeto carro contido na posição respectiva desejada da fila.
*/
		Carro *getCarro(int pos) {
			return Fila<Carro*>::getDados()[pos];
		}
/*
*@brief   Verifica se a pista está cheia.
*@return  True caso esteja, e false caso não esteja.
*/
		bool pistaCheia() {
			return Fila<Carro*>::filaCheia();
		}
/*
*@brief   Verifica se a pista está vazia, através do metodo filaVazia() da superclasse.
*@return  True caso esteja, e false caso não esteja.
*/
		bool pistaVazia() {
			return Fila<Carro*>::filaVazia();
		}
/*
*@brief   Busca o tempo necessário para percorrer a pista.
*@return  Retorna um inteiro correspondente a tal tempo.
*/
		int getTempoPercorrer() {
			return tempoPercorrer;
		}
/*
*@brief   Busca a quantidade de carros que entraram no sistema.
*@return  Retorna o inteiro correspondente a tal informação.
*/
		int getCarrosEntraram() {
			return carrosEntraram;
		}
/*
*@brief   Busca a quantidade de carros que sairam do sistema.
*@return  Retorna o inteiro correspondente a tal informação.
*/
		int getCarrosSairam() {
			return carrosSairam;
		}
/*
*@brief   Verifica se a pista é fonte.
*@return  True caso seja, e false caso não seja.
*/
		bool getFonte() {
			return fonte;
		}
/*
*@brief   Verifica se a pista é sumidouro.
*@return  True caso seja, e false caso não seja.
*/
		bool getSumidouro() {
			return sumidouro;
		}
/*
*@brief   Busca o tamanho da pista.
*@return  Retorna o inteiro correspondente a tal informação, através do método getUltimo() da superclasse.
*/
		int getTamanho() {
			return Fila<Carro*>::getUltimo();
		}

	private:
		int velocidade;
		int tamanho;
		int frequencia;
		int variacaoFrequencia;
		int espacoLivre;
		int tempoPercorrer;
		int carrosEntraram;
		int carrosSairam;
		bool fonte;
		bool sumidouro;
};

#endif

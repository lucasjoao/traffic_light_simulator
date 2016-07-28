#ifndef CARRO_HPP
#define CARRO_HPP
/**
*@brief    Implementação da classe Carro;
*
*@param  tamanho         Dado por int que representa tamanho do carro
*@param  chanceDeVirar   Representa a probabilidade int de pista destino para o carro
**/
class Carro {
    public:
/*
 *Construtor sem parâmetros, com inicialização de tamanho e chanceDeVirar.
 *O atributo tamanho é calculado por calculaTam()
 *O atributo chanceDeVirar é calculado por calculaProbDeVirar();
 */
        Carro() {
        	tamanho = calculaTam() + 3;
            chanceDeVirar = calculaProbDeVirar() + 1 ;
        }

        ~Carro() {}
/*
*@brief   Calcula tamanho do carro
*@return  Retorna int obtido através do calculo parcialmente randomico
*/
        int calculaTam() {
            return (int) (rand() % 5) + 2;
        }
/*
*@brief   Calcula probabilidade de direção a ser seguida pelo carro
*@return  Retorna int obtido através do calculo parcialmente randomico
*/
        int calculaProbDeVirar() {
            return (int) (rand() % 100);
        }
/*
*@brief   Busca o tamanho de determinado carro
*@return  Retorna int que descreve o tamanho do carro
*/
        int getTamanho() {
            return tamanho;
        }
/*
*@brief   Busca a probabilidade de direção a ser seguida por determinado carro
*@return  Retorna int que representa a probabilidade de virada do carro
*/
        int getChanceDeVirar() {
            return chanceDeVirar;
        }

    private:
        int tamanho;
        int chanceDeVirar;
};
#endif
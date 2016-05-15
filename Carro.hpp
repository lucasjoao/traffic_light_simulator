#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Carro {
    private:
        int tamanho;
        int chanceDeVirar;

    public:
        Carro() {
        	tamanho = calculaTam() + 3;//somando 3 que é distancia minima trás/frente
            chanceDeVirar = calculaProbDeVirar() + 1 ;// soma 1 para q nao de 0 e em caso de 99 fique 100
        }

        ~Carro() {
            //possivel destrutor
        }

        int calculaTam() {
            int x = 0;
            srand((unsigned)time(NULL));  // inicializando a semente de numero
            //randomico neste caso pegando um tempo diferente
            x = 2 + (rand()%5); // para que x receba um valor de 2 a 6(0-1-2-3-4-5);
            return x;
        }

        int calculaProbDeVirar() {
            int x = (rand() % 100); //num randomico de 0 a  99
            return x;
        }

        int getTamanho() {
            return tamanho;
        }

        int returnChanceDeVirar() {
            return chanceDeVirar;
        }
};
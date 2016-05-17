#ifndef CARRO_HPP
#define CARRO_HPP

class Carro {
    public:
        Carro() {
        	tamanho = calculaTam() + 3;
            chanceDeVirar = calculaProbDeVirar() + 1 ;
        }

        int calculaTam() {
            return (int) (rand() % 5) + 2;
        }

        int calculaProbDeVirar() {
            return (int) (rand() % 100);
        }

        int getTamanho() {
            return tamanho;
        }

        int getChanceDeVirar() {
            return chanceDeVirar;
        }

    private:
        int tamanho;
        int chanceDeVirar;
};
#endif
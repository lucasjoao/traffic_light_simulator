#ifndef EVENTO_HPP
#define EVENTO_HPP

class Evento {
    public:
        Evento(int time, int type) {
            tempo = time;
            tipo = type;
        }

        int getTipo() {
            return tipo;
        }

        int getTempo() {
            return tempo;
        }

    private:
        int tempo;
        int tipo;
};
#endif
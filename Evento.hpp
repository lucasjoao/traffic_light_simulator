#ifndef EVENTO_HPP
#define EVENTO_HPP

class Evento {
    private:
        int tempo;
        var tipo;

    public:
        Evento(int time, var type) {
            tempo = time;
            tipo = type;
        }

        getTipo() {
            return tipo;
        }

        getTempo() {
            return tempo;
        }
};
#endif
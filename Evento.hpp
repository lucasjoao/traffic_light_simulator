#ifndef EVENTO_HPP
#define EVENTO_HPP

class Evento {
    public:
        Evento(int tempo, int tipo) {
            _tempo = tempo;
            _tipo = tipo;
        }

        int getTipo() {
            return _tipo;
        }

        int getTempo() {
            return _tempo;
        }

    private:
        int _tempo;
        int _tipo;
};
#endif

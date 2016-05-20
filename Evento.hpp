#ifndef EVENTO_HPP
#define EVENTO_HPP

class Evento {
    public:
        Evento(int tempo, int tipo, void *elemento) {
            _tempo = tempo;
            _tipo = tipo;
            _elemento = elemento;
        }

        int getTipo() {
            return _tipo;
        }

        int getTempo() {
            return _tempo;
        }

        void *getElemento() {
            return _elemento;
        }

    private:
        int _tempo;
        int _tipo;
        void *_elemento;
};
#endif

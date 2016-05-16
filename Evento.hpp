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
            // 0 = criar carro
            // 1 = carro chega semáforo
            // 2 = muda semáforo
        void *_elemento;
};
#endif

#ifndef EVENTO_HPP
#define EVENTO_HPP

class Evento {
    public:
        Evento(int tempo, int tipo, void *elemPrinc, void *elemSecun) {
            _tempo = tempo;
            _tipo = tipo;
            _elementoPrincipal = elemPrinc;
            _elementoSecundario = elemSecun;

        }

        int getTipo() {
            return _tipo;
        }

        int getTempo() {
            return _tempo;
        }

        void *getElementoPrincipal() {
            return _elementoPrincipal;
        }

        void *getElementoSecundario() {
            return _elementoSecundario;
        }

    private:
        int _tempo;
        int _tipo;
        void *_elementoPrincipal;
        void *_elementoSecundario;

};
#endif

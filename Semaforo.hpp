#ifndef SEMAFORO_HPP
#define SEMAFORO_HPP

class Semaforo {
	public:
		Semaforo(bool status, int tempo) {
			status = status;
			tempoAberto = tempo;
		}

		int getTempoParaAbrir() {
			return tempoParaAbrir;
		}

		int getTempoAberto() {
			return tempoAberto;
		}

		int proximaTrocaSinal(int tempo) {
			return tempo + tempoAberto;
		}

	private:
		bool status;
		int tempoParaAbrir;
		int tempoAberto;
};
#endif
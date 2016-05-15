#ifndef SEMAFORO_HPP
#define SEMAFORO_HPP

class Semaforo {
	public:
		Semaforo(bool status, int tempo) {
			status = status;
			tempo = tempo;
		}

		int getTimeToOpen() {
			return timeToOpen;
		}

		int getTimeOpenned() {
			return timeOpenned;
		}

	private:
		bool status;
		int timeToOpen;
		int timeOpenned;
};
#endif
class Semaforo {
	private:
		bool status;
		int timeToOpen;
		int timeOpenned;

	public:
		Semaforo(bool status, int tempo) {
			status = status;
			tempo = tempo
		}

		int getTimeToOpen () {
			return timeToOpen();
		}

		int getTimeOpenned () {
			return timeOpenned();
		}
};
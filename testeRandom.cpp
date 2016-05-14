#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main() {
	cout << "teste do wesley \n\n";
	int x = 0;
	int tamanho = 0;
	srand((unsigned)time(NULL));  // inicializando a semente de numero randomico, neste caso pegando um tempo diferente
	x = 2 + (rand()%5); // para que x receba um valor de 2 a 6(0-1-2-3-4-5)
	tamanho = x + 3; //somando 3 que é a distancia minima trás-frente
	printf("tamanho é  %d \n\n", tamanho );
	cout << "fim parte do do wesley \n";
	cout << "---------------------- \n\n";

	cout << "seguindo moodle\n\n";

	double random = rand();
	int result = int(random/RAND_MAX * 5 + 2 + 3);
	cout << result << "\n";

	return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include <funcoes.h>


int main(int argc, char* argv[]) {
	if (argc < 3) {
		perror("Quantidade de argumentos inferior ao esperado.\n");
		perror("Necessário informar a quantidade de threads a serem criadas e o número de trapézios desejados.\n");
		perror("Ex.: ./prog 5 7\n");
		exit(1);
	}

	int numero_threads = atoi(argv[1]);
	int numero_trapezios = atoi(argv[2]);

	float resultado = calc_area(numero_threads, numero_trapezios);

	printf("Valor da área: %.2f\n", resultado);

	return 0;
}
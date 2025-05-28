#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_ESPERADO 30
int esteira1 = 0, esteira2 = 0, esteira3 = 0;

int vetor[3];

int calculaPerdaTotal(int valorInicial, int valorFinal) {
    int resultado = ((valorInicial - valorFinal) * 100)  / valorInicial;
    return resultado;
}

int simulaEsteira() {
    int i = 0;
    for(i; i<TOTAL_ESPERADO; i++) {
        esteira1 = i;
    }
}

void simulaPerda(int vetor[3]) {
    for(int i = 0; i < 3; i++) {
        vetor[i] = (rand() % 10) + 1;
    }
}

int main() {
    esteira1 = simulaEsteira();
    esteira2 = simulaEsteira();
    esteira3 = simulaEsteira();
    

    int perda[3];
    simulaPerda(perda);
    simulaPerda(perda);
    simulaPerda(perda);
    esteira1 -= perda[0];
    esteira2 = esteira1 - perda[1];
    esteira3 = esteira2 - perda[2];

    printf("esteira1: %d\nesteira2: %d\nesteira3: %d\n", esteira1, esteira2, esteira3);
    printf("Porcentagem perdida: %d%%\n", calculaPerdaTotal(TOTAL_ESPERADO, esteira3));

    system("pause");
    return 0;
}
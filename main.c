#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_ESPERADO 30
int esteira1 = 0, esteira2 = 0, esteira3 = 0;

int perda[3];

int calculaPerdaTotal(int valorInicial, int valorFinal) {
    int resultado = ((valorInicial - valorFinal) * 100)  / valorInicial;
    return resultado;
}

int simulaEsteira() {
    int esteira = 0;
    for(int i=0; i<TOTAL_ESPERADO; i++) {
        esteira = i;
    }
    return esteira;
}

void simulaPerda(int vetor[3]) {
    srand(time(NULL));
    for(int i = 0; i < 3; i++) {
        vetor[i] = rand() % 10 + 1;
    }
}

void verificaMaiorPerda() {
    if(perda[0] > perda[1] && perda[0] > perda[2]){
        printf("O maior numero de perdas foi na esteira 1\n");
    }
    else if(perda[1] > perda[0] && perda[1] > perda[2]) {
        printf("O maior numero de perdas foi na esteira 2\n");
    }
    else if(perda[2] > perda[0] && perda[2] > perda[1]) {
        printf("O maior numero de perdas foi na esteira 3\n");
    }
}

int main() {
    esteira1 = simulaEsteira();
    esteira2 = simulaEsteira();
    esteira3 = simulaEsteira();
    
    simulaPerda(perda);

    esteira1 -= perda[0];
    esteira2 = esteira1 - perda[1];
    esteira3 = esteira2 - perda[2];

    system("cls");
    printf("\nSensor 1: %d produtos ( %d produtos perdidos )\nSensor 2: %d produtos ( %d produtos perdidos )\nSensor 3: %d produtos ( %d produtos perdidos )\n", esteira1, perda[0], esteira2, perda[1], esteira3, perda[2]);
    verificaMaiorPerda();
    printf("Porcentagem perdida: %d%%\n\n", calculaPerdaTotal(TOTAL_ESPERADO, esteira3));

    system("pause");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_ESPERADO 30
int esteira1 = 0, esteira2 = 0, esteira3 = 0;

int calculaPerdaTotal(int valorInicial, int valorFinal) {
    int resultado = ((valorInicial - valorFinal) * 100)  / valorInicial;
    return resultado;
}

int simulaEsteira() {
    int i = 0;
    for(i; i<TOTAL_ESPERADO; ++i) {
        esteira1 = i;
    }
}

int main() {
    esteira1 = simulaEsteira();
    esteira2 = esteira1;
    esteira3 = esteira2;
    
    srand(time(NULL));
    int valor_perdido = rand() % 10 + 1;
    esteira2 -= valor_perdido;
    esteira3 = esteira2 - valor_perdido;
    printf("esteira1: %d\nesteira2: %d\nesteira3: %d\n", esteira1, esteira2, esteira3);
    printf("Porcentagem perdida: %d%%", calculaPerdaTotal(TOTAL_ESPERADO, esteira3));

    if(esteira1 < esteira2 && esteira1 < esteira3) {
        printf("A maioria dos produtos foram perdidos/danificados na esteira 1");
    }
    else if(esteira2 < esteira1 && esteira2 < esteira3) {
        printf("A maioria dos produtos foram perdidos/danificados na esteira 2");
    }
    else if(esteira3 < esteira1 && esteira3 < esteira2) {
        printf("A maioria dos produtos foram perdidos/danificados na esteira 3");
    }
    else {
        printf("Não houveram perdas! :)");
    }

    return 0;
}
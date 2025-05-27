#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_ESPERADO 30  // Total esperado de produtos

int calculaPerdaTotal(int valorInicial, int valorFinal) {
    int resultado = ((valorInicial - valorFinal) * 100)  / valorInicial;
    return resultado;
}

int main() {
    int esteira1 = 0, esteira2 = 0, esteira3 = 0;

    for(esteira1; esteira1<TOTAL_ESPERADO; esteira1++){
        if(esteira1 > TOTAL_ESPERADO/2){
            for(esteira2; esteira2<=TOTAL_ESPERADO; esteira2++){
                    if(esteira2 > TOTAL_ESPERADO/2){
                        for(esteira3; esteira3<TOTAL_ESPERADO; esteira3++){
                        }
                    }
            }
        }
    }
    
    srand(time(NULL));
    int valor_perdido = rand() % 10 + 1;
    esteira2 -= valor_perdido;
    esteira3 = esteira2 - valor_perdido;
    printf("esteira1: %d\nesteira2: %d\nesteira3: %d\n", esteira1, esteira2, esteira3);
    printf("Porcentagem perdida: %d%%", calculaPerdaTotal(TOTAL_ESPERADO, esteira3));

    return 0;
}


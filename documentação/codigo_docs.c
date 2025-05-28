#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_ESPERADO 30 // Valor inicial esperado para cada esteira

int esteira1 = 0, esteira2 = 0, esteira3 = 0; // Quantidade de itens nas três esteiras
int perda[3]; // Vetor que armazena a perda de cada esteira

// Calcula a perda total em porcentagem com base no valor inicial e final
int calculaPerdaTotal(int valorInicial, int valorFinal) {
    int resultado = ((valorInicial - valorFinal) * 100)  / valorInicial;
    return resultado;
}

// Simula a produção de uma esteira (valor sempre será TOTAL_ESPERADO)
int simulaEsteira() {
    int esteira = 0;
    for(int i = 0; i < TOTAL_ESPERADO; i++) {
        esteira = i; // No final, esteira = 30
    }
    return esteira;
}

// Preenche o vetor de perdas com valores aleatórios entre 1 e 10
void simulaPerda(int vetor[3]) {
    srand(time(NULL)); // Semente para gerar números aleatórios diferentes a cada execução
    for(int i = 0; i < 3; i++) {
        vetor[i] = rand() % 10 + 1;
    }
}

// Verifica qual esteira teve a maior perda
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

// Função principal
int main() {
    // Simula a produção nas esteiras
    esteira1 = simulaEsteira();
    esteira2 = simulaEsteira(); 
    esteira3 = simulaEsteira(); 

    // Gera perdas aleatórias
    simulaPerda(perda);

    // Subtrai perdas da produção de cada esteira
    esteira1 -= perda[0];
    esteira2 = esteira1 - perda[1];
    esteira3 = esteira2 - perda[2];

    // Exibe valores finais das esteiras
    printf("esteira1: %d\nesteira2: %d\nesteira3: %d\n", esteira1, esteira2, esteira3);

    // Calcula e exibe a porcentagem de perda total
    printf("Porcentagem perdida: %d%%\n", calculaPerdaTotal(TOTAL_ESPERADO, esteira3));

    // Verifica qual esteira teve mais perdas
    verificaMaiorPerda();

    system("pause");
    return 0;
}

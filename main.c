#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_ESPERADO 30  // Total esperado de produtos

// Função para verificar se algum produto foi retirado
void verificarProdutos(int esteira1, int esteira2, int esteira3,
                       int ultimoEsteira1, int ultimoEsteira2, int ultimoEsteira3) {
    if (esteira1 < ultimoEsteira1) {
        printf("Produto retirado da Esteira 1!\n");
    }
    if (esteira2 < ultimoEsteira2) {
        printf("Produto retirado da Esteira 2!\n");
    }
    if (esteira3 < ultimoEsteira3) {
        printf("Produto retirado da Esteira 3!\n");
    }
}

int main() {
    int esteira1 = 0, esteira2 = 0, esteira3 = 0;
    int ultimoEsteira1, ultimoEsteira2, ultimoEsteira3;

    srand(time(NULL)); // Inicializa a semente de aleatoriedade
	int i;
	for (i = 1; i <= TOTAL_ESPERADO; i++) {
        // Cada iteração simula a chegada de um produto em uma esteira
        if (i % 3 == 1) {
            esteira1++;
        } else if (i % 3 == 2) {
            esteira2++;
        } else {
            esteira3++;
        }

        // A cada 5 produtos, há chance de remoção e verificação
        if (i % 5 == 0) {
            // Salva os valores antes de qualquer possível alteração
            ultimoEsteira1 = esteira1;
            ultimoEsteira2 = esteira2;
            ultimoEsteira3 = esteira3;

            // Simula chance de produto ser retirado (20%)
            if (rand() % 10 < 2) {
                int escolhaEsteira = rand() % 3;
                if (escolhaEsteira == 0 && esteira1 > 0) {
                    esteira1--;
                } else if (escolhaEsteira == 1 && esteira2 > 0) {
                    esteira2--;
                } else if (escolhaEsteira == 2 && esteira3 > 0) {
                    esteira3--;
                }
            }

            // Verifica se houve retirada
            verificarProdutos(esteira1, esteira2, esteira3,
                              ultimoEsteira1, ultimoEsteira2, ultimoEsteira3);
        }

        // Exibe o estado atual das esteiras
        printf("Esteira 1: %d, Esteira 2: %d, Esteira 3: %d\n", esteira1, esteira2, esteira3);
    }

    return 0;
}


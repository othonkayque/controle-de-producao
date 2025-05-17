#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_ESPERADO 30  // Total esperado de produtos (por exemplo, 30 produtos no total)

// Função para simular a detecção de um produto retirado
void verificarProdutos(int esteira1, int esteira2, int esteira3, int ultimoEsteira1, int ultimoEsteira2, int ultimoEsteira3) {
    // Verificando se a contagem de alguma esteira diminuiu (indicando que um produto foi retirado)
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
    int ultimoEsteira1 = 0, ultimoEsteira2 = 0, ultimoEsteira3 = 0;
    int totalProdutos = 0;
    int produtoRetirado = 0;
    
    srand(time(NULL)); // Para gerar números aleatórios para simular a remoção de produtos

    // Simulação do movimento dos produtos nas esteiras
    for (int i = 1; i <= TOTAL_ESPERADO; i++) {
        // Cada iteração simula a passagem de um produto por uma das esteiras
        if (i % 3 == 1) {
            esteira1++;
        } else if (i % 3 == 2) {
            esteira2++;
        } else {
            esteira3++;
        }

        // Armazenar os valores anteriores para detectar remoções
        ultimoEsteira1 = esteira1;
        ultimoEsteira2 = esteira2;
        ultimoEsteira3 = esteira3;

        // A cada 5 produtos passados, verificamos se algum foi retirado
        if (i % 5 == 0) {
            // Simular que um produto pode ser retirado de forma aleatória
            if (rand() % 10 < 2) { // 20% de chance de um produto ser retirado
                if (rand() % 3 == 0 && esteira1 > 0) {
                    esteira1--; // Remover produto da esteira 1
                } else if (rand() % 3 == 1 && esteira2 > 0) {
                    esteira2--; // Remover produto da esteira 2
                } else if (rand() % 3 == 2 && esteira3 > 0) {
                    esteira3--; // Remover produto da esteira 3
                }
            }
            
            // Verificar se algum produto foi retirado
            verificarProdutos(esteira1, esteira2, esteira3, ultimoEsteira1, ultimoEsteira2, ultimoEsteira3);
        }
        
        // Apenas para fins de visualização, exibindo as contagens
        printf("Esteira 1: %d, Esteira 2: %d, Esteira 3: %d\n", esteira1, esteira2, esteira3);
    }

    return 0;
}

# Controle de Linha de Produção

## IFCE Campus Cedro

### Professor: Victor Sales

**Matéria:** Linguagem de Programação

### Equipe:

[Kayque Othon de Araújo Rolim](https://github.com/othonkayque)

[Jhonatas Ferreira de Matos](https://github.com/jhonatasxp)

<hr>

## Ideia Inicial

Projeto em C que simula uma linha de produção, onde os produtos que são perdidos ou danificados no meio do processo são detectados. Ao fim do algoritmo, é exibido na tela, em porcentagem, quantos produtos foram perdidos e em qual parte da linha de produção ocorreram mais perdas.

![ideia-1](./imagens/ideia.png)

Nosso projeto foi pensado para poder ser replicado em linhas de produção de diferentes tamanhos

![ideia-2](./imagens/exemploGrandeEscala.png)


## Fluxograma da ideia

<iframe frameborder="0" style="width:100%;height:375px;" src="https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&title=#R%3Cmxfile%3E%3Cdiagram%20id%3D%22bKeCniUfdtDQdnIx8u1Z%22%20name%3D%22Page-1%22%3E7ZpNc9owEIZ%2FjWfaQzu2ZQgcw0fSS9sDnbY5CrRgNbZFZZmP%2FvpKQgIbOYEJFJqJL1hayba0r571WsZD%2FXR1z%2FE8%2FswIJF7ok5WHBl4YBqHfkQdlWRtLx1pmnBJj2xlG9A8Yo2%2BsBSWQVzoKxhJB51XjhGUZTETFhjlny2q3KUuqd53jGTiG0QQnrvUHJSLeWDstf2f%2FBHQW2zsHvmlJse1sDHmMCVuWTGjooT5nTGxK6aoPifKe9cvmvLsnWrcD45CJY04wfl%2FgpDBzM%2BMSaztZIHLuppqxTB568uJ8%2FVPWfVt5UJWPLVsdrMqNg7WpcVZkBIip5YKzx60DkbRMaZL0WcK4vjMKxjiAcNuz1OL77eGtnFNPwEqMrA%2FVRRM8hqTHOAFu%2B5tBb1rw5HGmh7HXOmWZsCYCU1wk0n%2B9WKSJNASy6HrWODtnBZ8YXxnvCcxnYHqhjUl5sXSaUeMeWArSQ7IDhwQLuqiuMGwW6mzbb6elLBg566UNHWm%2Fjn%2BBYHoWeY7lMVM%2FkAugHDu6n1%2Bseh%2BfTcJlTAWM5liLsZSh50gBF8DlGJ4Vx7beGGzXe%2FXlLgoEFu24FAHa%2Ful6thtUz4kqclFtXQvVm5dJu6Lip5myKj9YIWV5p6qqrMsSN4vhqMUQXWsxIGcx5OAG55il4yL%2FJ9q8%2BjCNWnthuu2G6U5NlO6cIUrbFLUJ0%2BchM3LJ7F6LzMiRltmMioCQLxrSax66azKpw4hGnSqi3QsmUoGbGTeInoBoy0U0CK7FaOtpRjOvj7xb1OB6Oq5hdEFea%2BLuCby%2BdVq7NbReLdftOsreEjqhLMPcU8upFyhu2aYLUzaCdYVTvNC7imb34ktD8WGK23vbFx%2BCS1LsRuaXUxy8dYrtA%2Fb%2FwNiOpqTt9zpE1Ya8oFmBdTGVvwrtFPK0hHjD8UGOoyrHyL8gx9ELN6temD2%2FRnb3ADwMc81LLupeil03uxrmasfJn3M2gTxXaOo6h7lMm1WDfhL%2FLnAm5J23gOviiuaCclBs668LCc1irDPuzRVJobPwm20u3uB%2BCPcO2tvOCo%2FEffvZ8STem%2B8O591qrknAo6t9eUBuBj6QrpIot%2FXsxpL09kyV3mVFCpxVUBaqowwE2oBlqCi20WGCdaaeQ5Yz%2Fr7B%2FDDmgb%2F3WA8u%2BZIduen5Nyaw6jIHTihRyuuw7tlMvpHzWTnDoHUxOWV1958R3Vb66w0a%2FgU%3D%3C%2Fdiagram%3E%3C%2Fmxfile%3E"></iframe>

## O que o programa faz?

* Simula a passagem de 30 produtos por 3 esteiras.
* Gera uma perda aleatória de produtos em cada esteira (de 1 a 10).
* Mostra quantos produtos restaram após cada esteira.
* Informa qual esteira perdeu mais produtos.
* Calcula a porcentagem total de perda.

## Como rodar?

É necessário ter o MinGW (compilador de C) instalado no seu computador.

### Compilar e executar o código

```bash
gcc main.c -o executavel 
```
```bash
./executavel.exe
```

## Bibliotecas usadas

```c
stdio.h  
stdlib.h  
time.h
```

## Código documentado

### Includes

```c
#include <stdio.h>      // Permite mostrar informações na tela.
#include <stdlib.h>     // Permite usar funções como gerar números aleatórios.
#include <time.h>       // Ajuda a criar números aleatórios diferentes a cada vez.
```

### Variáveis

```c
#define TOTAL_ESPERADO 30 // Define o total inicial de produtos.
int esteira1 = 0, esteira2 = 0, esteira3 = 0; // Guarda a quantidade de produtos que passou em cada esteira.
int perda[3]; // Guarda quantos produtos foram perdidos em cada esteira.
```

### Funções `calculaPerdaTotal()` e `simulaEsteira()`

```c
// Calcula a perda total (em %) dos produtos durante toda a linha de produção
int calculaPerdaTotal(int valorInicial, int valorFinal) {
    int resultado = ((valorInicial - valorFinal) * 100) / valorInicial;
    return resultado;
}

// Simula a esteira recebendo os 30 produtos
int simulaEsteira() {
    int esteira = 0;
    for (int i = 0; i < TOTAL_ESPERADO; i++) {
        esteira = i;
    }
    return esteira;
}
```

### Função `simulaPerda()`

```c
// Gera perdas aleatórias entre 1 e 10 para cada esteira
void simulaPerda(int vetor[3]) {
    srand(time(NULL)); // Garante que os números mudem a cada execução.
    for (int i = 0; i < 3; i++) {
        vetor[i] = rand() % 10 + 1;
    }
}
```

### Função `verificaMaiorPerda()`

```c
// Informa qual esteira teve mais perdas
void verificaMaiorPerda() {
    if (perda[0] > perda[1] && perda[0] > perda[2]) {
        printf("O maior número de perdas foi na esteira 1\n");
    } else if (perda[1] > perda[0] && perda[1] > perda[2]) {
        printf("O maior número de perdas foi na esteira 2\n");
    } else if (perda[2] > perda[0] && perda[2] > perda[1]) {
        printf("O maior número de perdas foi na esteira 3\n");
    }
}
```

### Função principal

```c
// Função principal
int main() {
    esteira1 = simulaEsteira();
    esteira2 = simulaEsteira();
    esteira3 = simulaEsteira();

    simulaPerda(perda);

    esteira1 -= perda[0];           // Subtrai perdas da esteira 1
    esteira2 = esteira1 - perda[1]; // Esteira 2 começa do final da 1 e perde mais
    esteira3 = esteira2 - perda[2]; // Esteira 3 começa do final da 2 e perde mais

    system("cls"); // Limpa a tela (Windows)
    
    printf("\nSensor 1: %d produtos (%d produtos perdidos)\n", esteira1, perda[0]);
    printf("Sensor 2: %d produtos (%d produtos perdidos)\n", esteira2, perda[1]);
    printf("Sensor 3: %d produtos (%d produtos perdidos)\n", esteira3, perda[2]);

    verificaMaiorPerda();

    printf("Porcentagem perdida: %d%%\n\n", calculaPerdaTotal(TOTAL_ESPERADO, esteira3));

    system("pause"); // Espera o usuário apertar algo
    return 0;
}
```
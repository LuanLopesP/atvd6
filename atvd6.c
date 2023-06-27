#include <stdio.h>
#include <stdlib.h>

void inicializarMatriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = i + j; // Exemplo de inicialização
        }
    }
}

void somarMatrizes(int** matrizA, int** matrizB, int** matrizC, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matrizA[i][j] = matrizB[i][j] + matrizC[i][j];
        }
    }
}

void mostrarMatriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int linhas = 3;
    int colunas = 3;

    // Alocar matrizes
    int** matrizA = (int*)malloc(linhas * sizeof(int));
    int** matrizB = (int*)malloc(linhas * sizeof(int));
    int** matrizC = (int*)malloc(linhas * sizeof(int));

    for (int i = 0; i < linhas; i++) {
        matrizA[i] = (int*)malloc(colunas * sizeof(int));
        matrizB[i] = (int*)malloc(colunas * sizeof(int));
        matrizC[i] = (int*)malloc(colunas * sizeof(int));
    }

    // Inicializar matrizes B e C
    inicializarMatriz(matrizB, linhas, colunas);
    inicializarMatriz(matrizC, linhas, colunas);

    // Calcular A = B + C
    somarMatrizes(matrizA, matrizB, matrizC, linhas, colunas);

    // Mostrar matrizes
    printf("Matriz A:\n");
    mostrarMatriz(matrizA, linhas, colunas);

    printf("Matriz B:\n");
    mostrarMatriz(matrizB, linhas, colunas);

    printf("Matriz C:\n");
    mostrarMatriz(matrizC, linhas, colunas);

    // Liberar memória
    for (int i = 0; i < linhas; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizC[i]);
    }
    free(matrizA);
    free(matrizB);
    free(matrizC);

    return 0;
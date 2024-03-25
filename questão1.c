#include <stdio.h>

int buscar(int vetor[], int tamanho, int valor, int *iteracoes) {
    int inicio = 0;
    int fim = tamanho - 1;
    *iteracoes = 0;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        (*iteracoes)++;

        if (vetor[meio] == valor) {
            return meio;
        } else if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int main() {
    int vetor[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valor = 12;

    int iteracoes;
    int posicao = buscar(vetor, tamanho, valor, &iteracoes);

    if (posicao != -1) {
        printf("O valor %d foi encontrado na posição %d\n", valor, posicao);
    } else {
        printf("O valor %d não foi encontrado no vetor.\n", valor);
    }

    printf("Número de iterações realizadas: %d\n", iteracoes);

    return 0;
}

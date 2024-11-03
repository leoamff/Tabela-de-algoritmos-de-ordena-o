#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int v[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < tam; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        int aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

int main() {
    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    int *v = (int *)malloc(tam * sizeof(int));
    if (v == NULL) {
        printf("Falha na alocação de memória!\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < tam; i++) {
        v[i] = rand() % 10000;
    }

    clock_t inicio = clock();
    selectionSort(v, tam);
    clock_t fim = clock();

    double tempo_execucao = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo de execução do Selection Sort: %.2f ms\n", tempo_execucao);

    free(v);
    return 0;
}

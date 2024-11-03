#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int v[], int tam) {
    for (int i = 1; i < tam; ++i) {
        int temp = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > temp) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = temp;
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
    insertionSort(v, tam);
    clock_t fim = clock();

    double tempo_execucao = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo de execução do Insertion Sort: %.2f ms\n", tempo_execucao);

    free(v);
    return 0;
}

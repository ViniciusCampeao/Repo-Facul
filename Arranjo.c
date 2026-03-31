#include <stdio.h>

void maiorMenor(const int a[], int tamanho, int *maior, int *menor) {
    *maior = a[0];
    *menor = a[0];
    for (int i = 1; i < tamanho; i++) {
        if (a[i] > *maior) {
            *maior = a[i];
        }
        if (a[i] < *menor) {
            *menor = a[i];
        }
    }
}

void imprimirMaiorMenor(const int a[], int tamanho) {
    int maior, menor;
    maiorMenor(a, tamanho, &maior, &menor);
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
}

void imprimir(const int a[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void inverter(int a[], int tamanho) {
    for (int i = 0, j = tamanho - 1; i < j; i++, j--) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 2};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    imprimir(arr, tamanho);
    imprimirMaiorMenor(arr, tamanho);

    inverter(arr, tamanho);

    printf("Array invertido: ");
    imprimir(arr, tamanho);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 50

void leer_dimension(int *n);
void leer_matriz(float matriz[][MAX_DIM], int n);
int invertir_matriz(float matriz[][MAX_DIM], int n);
void imprimir_matriz(const float matriz[][MAX_DIM], int n);

int main() {
    float matriz_A[MAX_DIM][MAX_DIM];
    int n;

    printf("\n--- INVERSA DE UNA MATRIZ NxN (METODO GAUSS-JORDAN) ---\n\n");

    leer_dimension(&n);
    leer_matriz(matriz_A, n);

    if (invertir_matriz(matriz_A, n)) {
        imprimir_matriz(matriz_A, n);
    } else {
        printf("\nERROR: La matriz es singular o no se puede invertir con este metodo.\n");
        printf("El calculo se ha detenido.\n");
    }

    return 0;
}

void leer_dimension(int *n) {
    printf("Cual es la dimension de la Matriz? (max %d): ", MAX_DIM);
    scanf("%d", n);

    if (*n <= 0 || *n > MAX_DIM) {
        printf("Error: La dimension debe ser un numero entre 1 y %d.\n", MAX_DIM);
        exit(1);
    }
}

void leer_matriz(float matriz[][MAX_DIM], int n) {
    printf("\nIntroduce los elementos de la matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("  Elemento A[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }
}

int invertir_matriz(float A[][MAX_DIM], int n) {
    float B[MAX_DIM][MAX_DIM];
    float pivote;
    int i, j, k;

    for (i = 0; i < n; i++) {
        pivote = A[i][i];

        if (pivote == 0.0) {
            return 0;
        }

        B[i][i] = 1.0 / pivote;

        for (j = 0; j < n; j++) {
            if (j != i) {
                B[i][j] = A[i][j] / pivote;
            }
        }

        for (j = 0; j < n; j++) {
            if (j != i) {
                B[j][i] = -A[j][i] / pivote;
            }
        }

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (x != i && y != i) {
                    B[x][y] = A[x][y] - (A[i][y] * A[x][i]) / pivote;
                }
            }
        }

        for (k = 0; k < n; k++) {
            for (j = 0; j < n; j++) {
                A[k][j] = B[k][j];
            }
        }
    }

    return 1;
}

void imprimir_matriz(const float matriz[][MAX_DIM], int n) {
    printf("\n\n--- Matriz Inversa Resultante ---\n");
    for (int i = 0; i < n; i++) {
        printf("  ");
        for (int j = 0; j < n; j++) {
            printf("%9.4f ", matriz[i][j]);
        }
        printf("\n");
    }
}

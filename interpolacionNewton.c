#include <stdio.h>
#include <math.h>

float interpolacionNewton(int grado, float *coordenadasX, float *coordenadasY, float valorAInterpolar);

int main() {
    int i, grado = 0;
    float valorAInterpolar;
    float resultado;

    printf("Cual es el grado del polinomio: ");
    scanf("%i", &grado);

    if (grado < 0) {
        printf("Error: El grado del polinomio no puede ser negativo.\n");
        return 1;
    }

    float coordenadasX[grado + 1];
    float coordenadasY[grado + 1];

    printf("\nIngresa los valores de los puntos que componen al polinomio (x y):\n");
    printf("Debes ingresar %d pares de (x, y).\n", grado + 1);

    for (i = 0; i < grado + 1; i++) {
        printf("Punto %d (x y): ", i + 1);
        scanf("%f %f", &coordenadasX[i], &coordenadasY[i]);
    }

    printf("\nIngrese el valor de x que desea interpolar: ");
    scanf("%f", &valorAInterpolar);

    resultado = interpolacionNewton(grado, coordenadasX, coordenadasY, valorAInterpolar);

    printf("\nEl resultado de la interpolacion es: %f\n", resultado);

    return 0;
}

float interpolacionNewton(int grado, float *coordenadasX, float *coordenadasY, float valorAInterpolar) {
    int i, j;

    float tablaDiferencias[grado + 1][grado + 1];
    float terminoProducto;
    float valorInterpolado;

    for (i = 0; i < grado + 1; i++) {
        tablaDiferencias[i][0] = coordenadasY[i];
    }

    for (j = 1; j <= grado; j++) {
        for (i = 0; i <= grado - j; i++) {
            tablaDiferencias[i][j] = (tablaDiferencias[i + 1][j - 1] - tablaDiferencias[i][j - 1]) / (coordenadasX[i + j] - coordenadasX[i]);
            if ((coordenadasX[i + j] - coordenadasX[i]) == 0) {
            }
        }
    }

    valorInterpolado = tablaDiferencias[0][0];
    terminoProducto = 1;

    for (i = 0; i < grado; i++) {
        terminoProducto = terminoProducto * (valorAInterpolar - coordenadasX[i]);
        valorInterpolado = valorInterpolado + tablaDiferencias[0][i + 1] * terminoProducto;
    }

    return valorInterpolado;
}
#include <stdio.h>
#include <math.h>

#define TOLERANCIA 0.01
#define MAX_ECUACIONES 10

int main() {
    int i, j, n, iteracion = 0;
    int max_iteraciones = 100; // Límite de iteraciones
    float a[MAX_ECUACIONES][MAX_ECUACIONES + 1], x[MAX_ECUACIONES];
    float sum, temp, error, max_error;

    printf("Introduce el numero de ecuaciones (max %d): ", MAX_ECUACIONES);
    scanf("%d", &n);

    if (n > MAX_ECUACIONES || n <= 0) {
        printf("Numero de ecuaciones no valido.\n");
        return 1;
    }

    printf("Introduce los coeficientes de la matriz aumentada:\n");
    // Usamos indexación basada en 0 (de 0 a n-1)
    for(i = 0; i < n; i++) {
        for(j = 0; j < n + 1; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    // Verificar que no haya ceros en la diagonal
    for(i = 0; i < n; i++) {
        if (a[i][i] == 0.0) {
            printf("Error: El elemento a[%d][%d] de la diagonal es cero. El metodo no puede continuar.\n", i, i);
            return 1;
        }
    }

    // Inicializar el vector de solución x con ceros
    for(i = 0; i < n; i++) {
        x[i] = 0;
    }

    do {
        max_error = 0;
        for(i = 0; i < n; i++) {
            sum = 0;
            for(j = 0; j < n; j++) {
                if(j != i) {
                    sum = sum + a[i][j] * x[j];
                }
            }
            // La columna n contiene los términos independientes b
            temp = (a[i][n] - sum) / a[i][i];
            error = fabs(x[i] - temp);
            if(error > max_error) {
                max_error = error;
            }
            x[i] = temp;
        }

        iteracion++;
        if (iteracion > max_iteraciones) {
            printf("\nADVERTENCIA: El metodo no converge despues de %d iteraciones.\n", max_iteraciones);
            printf("La solucion podria no ser precisa.\n");
            break; // Salir del bucle
        }

    } while(max_error >= TOLERANCIA);

    printf("\n\nLa solucion final es:\n");
    for(i = 0; i < n; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }

    return 0; // Finalización exitosa
}
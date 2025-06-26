#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 25

int main()
{
    float mat[MAX_SIZE][MAX_SIZE + 1];
    int n, i, j, k;
    float factor, temp;

    printf("\n MÉTODO DE GAUSS-JORDAN\n");
    printf("-------------------------\n");
    printf("Ingrese el número de incógnitas (ecuaciones): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("El número de incógnitas debe estar entre 1 y %d.\n", MAX_SIZE);
        return 1;
    }

    printf("\nIngrese los coeficientes de la matriz aumentada:\n");
    for (i = 0; i < n; i++)
    {
        printf("\nFila %d:\n", i + 1);
        for (j = 0; j < n + 1; j++)
        {
            if (j < n) {
                printf("  Coeficiente de x%d: ", j + 1);
            } else {
                printf("  Término independiente: ");
            }
            scanf("%f", &mat[i][j]);
        }
    }

    for (k = 0; k < n; k++)
    {
        int max_fila = k;
        for (i = k + 1; i < n; i++)
        {
            if (fabs(mat[i][k]) > fabs(mat[max_fila][k]))
            {
                max_fila = i;
            }
        }

        if (max_fila != k)
        {
            for (j = k; j < n + 1; j++)
            {
                temp = mat[k][j];
                mat[k][j] = mat[max_fila][j];
                mat[max_fila][j] = temp;
            }
        }

        if (fabs(mat[k][k]) < 1e-9) {
            printf("\nError: El sistema no tiene solución única (matriz singular).\n");
            exit(0);
        }

        float pivote = mat[k][k];
        for (j = k; j < n + 1; j++)
        {
            mat[k][j] = mat[k][j] / pivote;
        }

        for (i = 0; i < n; i++)
        {
            if (i != k)
            {
                factor = mat[i][k];
                for (j = k; j < n + 1; j++)
                {
                    mat[i][j] = mat[i][j] - factor * mat[k][j];
                }
            }
        }
    }

    printf("\n\nSOLUCIÓN DEL SISTEMA\n");
    printf("---------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("X(%d) = %0.4f\n", i + 1, mat[i][n]);
    }
    printf("\n");

    return 0;
}

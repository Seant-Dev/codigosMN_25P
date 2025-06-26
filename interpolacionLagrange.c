#include<stdio.h>
#include<math.h>
#define MAX 100

int main()
{
    double x[MAX], y[MAX], s, t, k;
    double a, re, er;
    int n, i, j, op;

    do
    {
        k = 0;

        printf("\n¿Cuántos puntos vas a introducir?: ");
        do {
            scanf("%d", &n);
            if (n > MAX || n <= 1) {
                printf("Por favor, introduce un número de puntos entre 2 y %d: ", MAX);
            }
        } while (n > MAX || n <= 1);


        printf("\nTeclea las %d parejas de puntos (x y) separadas por un espacio:\n", n);
        for(i = 0; i < n; i++)
        {
            scanf("%lf %lf", &x[i], &y[i]);
        }

        printf("\nEsta es la tabla de datos que has tecleado:\n\n");
        printf("\t   x\t\t   y\n");
        printf("\t--------------------------\n");
        for(i = 0; i < n; i++){
            printf("\t%lf\t%lf\n", x[i], y[i]);
        }

        printf("\n¿En qué punto \"x\" vas a aproximar con el polinomio?: ");
        scanf("%lf", &a);
        printf("¿Cuál es el valor real de f(x) en ese punto? (para calcular el error): ");
        scanf("%lf", &re);

        for(i = 0; i < n; i++)
        {
            s = 1.0;
            t = 1.0;
            for(j = 0; j < n; j++)
            {
                if(j != i)
                {
                    s = s * (a - x[j]);
                    t = t * (x[i] - x[j]);
                }
            }
            k = k + ((s / t) * y[i]);
        }

        if (re != 0) {
            er = ((re - k) / re) * 100;
        } else {
            er = (re - k) * 100;
        }

        printf("\n------------------------------------------------------\n");
        printf("El valor obtenido en la interpolación para %0.4f es: %lf\n", a, k);
        printf("El porcentaje de error relativo es: %lf %%\n", fabs(er));
        printf("------------------------------------------------------\n\n");

        printf("Para ejecutar de nuevo el programa presiona 1, para terminar presiona cualquier otro número: ");
        scanf("%d", &op);
        printf("\n");

    } while(op == 1);

    return 0;
}
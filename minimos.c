#include <stdio.h>
#include <math.h>

void lectura();
void calculo();
void imprime();

int i, n, grado;
double m, b, x[50], y[50];
double sumax, sumay, sumax2, sumax3, sumax4, sumax5, sumax6, sumaxy, sumax2y, sumax3y;

int main() {
    printf("\n\tPrograma de Minimos Cuadrados");
    printf("\n\tProporciona el numero de datos: ");
    scanf("%d", &n);
    printf("\n\tProporciona el Grado del Polinomio: ");
    scanf("%d", &grado);
    
    lectura();
    calculo();
    imprime();
}

void lectura() {
    for (i = 0; i < n; i++) {
        printf("\n\tX(%d)= ", i + 1);
        scanf("%lf", &x[i]);
    }
    for (i = 0; i < n; i++) {
        printf("\n\tY(%d)= ", i + 1);
        scanf("%lf", &y[i]);
    }
}

void calculo() {
    sumax = 0;
    sumay = 0;
    sumaxy = 0;
    sumax2 = 0;
    sumax3 = 0;
    sumax4 = 0;
    sumax2y = 0;

    if (grado == 2) {
        for (i = 0; i < n; i++) {
            sumax += x[i];
            sumay += y[i];
            sumax2 += pow(x[i], 2);
            sumax3 += pow(x[i], 3);
            sumax4 += pow(x[i], 4);
            sumaxy += x[i] * y[i];
            sumax2y += (pow(x[i], 2)) * y[i];
        }
    }
    
    if (grado == 3) {
        for (i = 0; i < n; i++) {
            sumax += x[i];
            sumay += y[i];
            sumax2 += pow(x[i], 2);
            sumax3 += pow(x[i], 3);
            sumax4 += pow(x[i], 4);
            sumax5 += pow(x[i], 5);
            sumax6 += pow(x[i], 6);
            sumaxy += x[i] * y[i];
            sumax2y += (pow(x[i], 2)) * y[i];
            sumax3y += (pow(x[i], 3)) * y[i];
        }
    }
}

void imprime() {
    if (grado == 2) {
        printf("\t%d\t%lf\t%lf\t%lf\n", n, sumax, sumax2, sumay);
        printf("\t%lf\t%lf\t%lf\t%lf\n", sumax, sumax2, sumax3, sumaxy);
        printf("\t%lf\t%lf\t%lf\t%lf\n", sumax2, sumax3, sumax4, sumax2y);
    }

    if (grado == 3) {
        printf("\t%d\t%lf\t%lf\t%lf\t%lf\n", n, sumax, sumax2, sumax3, sumay);
        printf("\t%lf\t%lf\t%lf\t%lf\t%lf\n", sumax, sumax2, sumax3, sumax4, sumaxy);
        printf("\t%lf\t%lf\t%lf\t%lf\t%lf\n", sumax2, sumax3, sumax4, sumax5, sumax2y);
        printf("\t%lf\t%lf\t%lf\t%lf\t%lf\n", sumax3, sumax4, sumax5, sumax6, sumax3y);
    }
}
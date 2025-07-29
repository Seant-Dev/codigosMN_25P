#include <stdio.h>
#define MAX 32
int main(void) {
    float a, b, delta, sumPares = 0, sumImpares = 0, areaTotal = 0;
    int n = -1, i;
    float x[MAX], y[MAX];
    printf("Ingrese el limite inferior (a): ");
    scanf("%f", &a);
    printf("Ingrese el limite superior (b): ");
    scanf("%f", &b);
    while (!((n >= 2) && (n%2 == 0))) {
        printf("ingreese el numero de flajas (n): ");
        scanf("%d", &n);
    }
    delta = (b - a) / n;
    for (i = 0; i <= n; i++) {
        x[i] = a + (i*delta);
        printf("Ingrese el valor de y( %f ): ", x[i]);
        scanf("%f", &y[i]);
    }

    for (i = 1; i <= n; i = i+2) {
        sumPares = sumPares + y[i];
    }
    //printf("%f\n", sumPares);

    for (i = 2; i < n; i = i+2) {
        sumImpares = sumImpares + y[i];
    }
    //printf("%f\n", sumImpares);

    areaTotal = (delta / 3) * (y[0] + (4*sumPares) + (2*sumImpares) + y[n]);

    printf("La integral entre los intervalos %f, %f es: %f", a, b, areaTotal);

    return 0;
}
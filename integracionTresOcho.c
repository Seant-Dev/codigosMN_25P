#include <stdio.h>
#define MAX 32
int main(void) {
    float a, b, delta, areaTotal = 0, primeros = 0, segundos = 0, terceros = 0;
    int n = -1, i;
    float x[MAX], y[MAX];
    printf("Ingrese el limite inferior (a): ");
    scanf("%f", &a);
    printf("Ingrese el limite superior (b): ");
    scanf("%f", &b);
    while (!((n >= 3) && (n%3 == 0))) {
        printf("ingreese el numero de flajas (n): ");
        scanf("%d", &n);
    }
    delta = (b - a) / n;
    for (i = 0; i <= n; i++) {
        x[i] = a + (i*delta);
        printf("Ingrese el valor de y( %f ): ", x[i]);
        scanf("%f", &y[i]);
    }

    for (i = 1; i < n; i = i+3) {
        primeros = primeros + y[i];
    }
    for (i = 2; i < n; i = i+3) {
        segundos = segundos + y[i];
    }
    for (i = 3; i < n; i = i+3) {
        terceros = terceros + y[i];
    }
    areaTotal = (3 * delta / 8) * (y[0] + (3*primeros) + (3*segundos) + (2*terceros) + y[n]);
    printf("La integral entre los intervalos %f, %f es: %f", a, b, areaTotal);
    return 0;
}

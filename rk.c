/******************************************************************************
Programa para resolver ecuaciones diferenciales de primer orden por Runge-Kutta.
Para cambiar la ecuacion, modifica solo la funcion funcionXY() marcada abajo.

Ejemplos de ecuaciones:
- f(x,y) = x + y              →  resultado = x + y;
- f(x,y) = x*x - y            →  resultado = x*x - y;
- f(x,y) = sin(x) + cos(y)    →  resultado = sin(x) + cos(y);
- f(x,y) = -20y + 7e^(-0.5x)  →  resultado = -20*y + 7*exp(-0.5*x);
- f(x,y) = 0.5(1+x)y²         →  resultado = 0.5*(1+x)*(pow(y,2));
*******************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX 50

double xInicial, yInicial, xf, h;
double x[MAX], y[MAX], k1[MAX], k2[MAX], k3[MAX], k4[MAX];

double funcionXY(double x, double y);

int main()
{
    int i, n;
    
    printf("\nMETODO DE RUNGE-KUTTA DE 4TO ORDEN\n");
    printf("x inicial = "); scanf("%lf", &xInicial);
    printf("y inicial = "); scanf("%lf", &yInicial); 
    printf("x final   = "); scanf("%lf", &xf);
    printf("paso h    = "); scanf("%lf", &h);
    
    n = (int)((xf - xInicial) / h);
    h = (xf - xInicial) / n;
    
    x[0] = xInicial; y[0] = yInicial;
    for(i = 1; i <= n; i++) x[i] = x[i-1] + h;
    x[n] = xf;
    
    // Aplicar metodo de Runge-Kutta
    for(i = 0; i < n; i++)
    {
        k1[i] = funcionXY(x[i], y[i]);
        k2[i] = funcionXY(x[i] + h/2, y[i] + k1[i]*h/2);
        k3[i] = funcionXY(x[i] + h/2, y[i] + k2[i]*h/2);
        k4[i] = funcionXY(x[i] + h, y[i] + k3[i]*h);
        y[i+1] = y[i] + (h/6) * (k1[i] + 2*k2[i] + 2*k3[i] + k4[i]);
    }
    
    // Calcular k's del ultimo punto para mostrar
    k1[n] = funcionXY(x[n], y[n]);
    k2[n] = funcionXY(x[n] + h/2, y[n] + k1[n]*h/2);
    k3[n] = funcionXY(x[n] + h/2, y[n] + k2[n]*h/2);
    k4[n] = funcionXY(x[n] + h, y[n] + k3[n]*h);
    
    // Imprimir resultados
    printf("\n%3s | %10s | %10s | %10s | %10s | %10s | %10s\n", "i", "x", "y", "k1", "k2", "k3", "k4");
    printf("----|------------|------------|------------|------------|------------|------------\n");
    for(i = 0; i <= n; i++)
        printf("%3d | %10.6f | %10.6f | %10.6f | %10.6f | %10.6f | %10.6f\n", 
               i, x[i], y[i], k1[i], k2[i], k3[i], k4[i]);
    
    printf("\nResultado final: y(%.6f) = %.6f\n", x[n], y[n]);
    return 0;
}

/*******************************************************************************
MODIFICA ESTA FUNCION PARA CAMBIAR LA ECUACION DIFERENCIAL dy/dx = f(x,y)
*******************************************************************************/
double funcionXY(double x, double y)
{
    return 0.5*(1+x)*(pow(y,2));  // ← CAMBIA ESTA LINEA
}
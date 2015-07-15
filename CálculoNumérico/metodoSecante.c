#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ep 0.005

float f (float x)
{
    float y=0;
    //colocar y pra receber uma função
    y= (9.8/x)*(1-pow(M_E, -x*6/75))-36;
    return (y);
}

int main()
{

    float x_ant, x_ant1, xk;
    float erro=1, ea;
    int n, continua=1, k=0;

    while(continua==1)
    {
        printf("Insira o valor de X0: ");
        scanf ("\n%f", &x_ant1);

        printf("Insira o valor de X1: ");
        scanf ("\n%f", &x_ant);

        continua=0;

        while (erro>ep && k<20)
        {
            xk=(x_ant1*f(x_ant)-x_ant*f(x_ant1))/(f(x_ant)-f(x_ant1));
            if(xk < 0)
            {
                 xk = xk * -1;
                 ea = x_ant - xk;
                 if (ea < 0)
                 {
                     ea = ea * -1;
                 }
                 erro = ea/xk;
                 xk = xk * -1;
             }
             else
             {
                ea = (x_ant-xk);
                if (ea < 0)
                {
                     ea = ea * -1;
                }
                erro = ea/xk;
             }
             k++;
             printf("\n%2.2d %f          %f                 %f",k, xk, f(xk), erro);

             x_ant=x_ant1;
             x_ant1=xk;
        }
        printf("%d", k);
        printf("\n Quer continuar 1 ou 0? \n");
        scanf("%d", &continua);

        }

    return 0;
}

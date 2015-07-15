#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ep 0.0005

float f (float x)
{
    float y=0;
    //colocar y pra receber uma função
    //y=pow(x,3) - 7*x+3;
    y= 1+(pow((1+x),12))*(-1+7.5*x);
    return (y);
}

int main()
{

    float a,b, x_ant, xk, x0;
    float erro=1, ea=1;
    int n, continua=1, k=0;

    while(continua==1)
    {
        printf("Insira o valor de A: ");
        scanf ("\n%f", &a);

        printf("Insira o valor de B: ");
        scanf ("\n%f", &b);
        continua=0;
        if (f(a)*f(b)<0)
        {
            x0=(a+b)/2;
            xk=x0;
            while (ea>ep)
            {
                if(f(xk)*f(a)<0)
                {
                    b=xk;
                }
                else
                    a=xk;
                x_ant=xk;
                xk=(a+b)/2;

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
                printf("%2.2d       %f          %f        %f",k,xk, f(xk), erro);
                printf("\n");
            }
            printf("%d", k);
    }
    else
    {
        printf("Escolha outro intervalo, a = %f, b = %f", f(a), f(b));
        printf("\n Quer continuar 1 ou 0? \n");
        fflush(stdin);
        scanf("%d", &continua);
    }
    }
    return 0;
}

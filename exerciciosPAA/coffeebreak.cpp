#include "iostream"
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct porcao
{
	double cv; //custo por volume da porcao
	double c; //custo (em reais) por porcao de comida
	double v; //volume de uma porcao de comida

} Porcao;

/*
	Funcao: compare
	Objetivo: definir a regra para ordenacao do vetor de struct.

*/

bool compare(Porcao i, Porcao j)
{
	return (i.cv<j.cv);
}

/*
	Funcao: coffeeGreedy
  	Objetivo: calcular os maiores valores de porções vezes custos para os alunos que desejam comer mais e do mais caro, dependo do tamanho do quanto seu estomago suporta.
*/

void coffeeGreedy(Porcao *coffee, double *e, int n, int a)
{

	int i,k;
	double soma;
	double consumo;

	sort(coffee, coffee+n, compare); //n*log(n)

	for(i=0; i<a; i++) //varia de 0 a quantidade de alunos (a)
	{
	
		soma = 0;
		k = n-1;

		while (e[i] != 0 && k>=0) //varia de quantidade de consumo do aluno (e[i]) 
		{

			if (e[i] >= coffee[k].v)
				consumo = coffee[k].v;
	   		else
				consumo = e[i];

			e[i]=e[i]-consumo;
			soma=soma+(consumo*coffee[k].cv);
			k--;
		}	
		cout << setiosflags (ios::fixed) << setprecision (4) <<  soma <<endl;
	}
}


int main()
{
	Porcao *coffee;
	int i,n,a;
	double *e;

	do
	{
		cin >> n;
		cin >> a;
		coffee = new Porcao[n];
		e = new double[a];

		for(i=0; i<n; i++)
			cin >> coffee[i].c;

		for(i=0; i<n; i++)
		{
			cin >> coffee[i].v;
			coffee[i].cv = coffee[i].c/coffee[i].v;
		}

		for(i=0; i<a; i++)		
			cin >> e[i];
		

		coffeeGreedy(coffee,e,n,a);

		delete[] coffee;
		delete[] e;
	}
	while (n or a);

	return(0);
}

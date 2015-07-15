#include <stdio.h>
#include <stdlib.h>


/*
	Função: definirTabela
	Objetivo: irá definir uma tabela com os custos do Romano (0 a 999), logo depois vai fazer a RSQ (acumulando a soma dos intervalos) para ser usado no custo;

*/

void definirTabela(int *tabelaRomanos, int *i) 
{
	int j;

	tabelaRomanos[0] = 0;
	tabelaRomanos[1] = i[0];
	tabelaRomanos[2] = 2*i[0];
	tabelaRomanos[3] = 3*i[0];
	tabelaRomanos[4] = i[0] + i[1];
	tabelaRomanos[5] = i[1];
	tabelaRomanos[6] = i[0] + i[1];
	tabelaRomanos[7] = i[1] + 2*i[0];
	tabelaRomanos[8] = i[1] + 3*i[0];
	tabelaRomanos[9] = i[2] + i[0];

	for(j=10; j<40; j++)
		tabelaRomanos[j] = tabelaRomanos[j-10]+i[2];

	for(j=40; j<50; j++)
		tabelaRomanos[j] = tabelaRomanos[j-40]+i[3]+i[2];
	
	for(j=50; j<90; j++)
		tabelaRomanos[j] = tabelaRomanos[j-50]+i[3];
	
	for(j=90; j<100; j++)
		tabelaRomanos[j] = tabelaRomanos[j-90]+i[4]+i[2];

	for(j=100; j<400; j++)
		tabelaRomanos[j] = tabelaRomanos[j-100]+i[4];
	
	for(j=400; j<500; j++)
		tabelaRomanos[j] = tabelaRomanos[j-400]+i[4]+i[5];
	
	for(j=500; j<900; j++)
		tabelaRomanos[j] = tabelaRomanos[j-500]+i[5];

	for(j=900; j<1000; j++)
		tabelaRomanos[j] = tabelaRomanos[j-900]+i[4]+i[6];
	
	//Tornando a tabela um acumulador dos custos, ou seja, o tabelaRomanos[j] representa o custo do número romano 0 até j;

	for(j=1; j<1000; j++)
		tabelaRomanos[j] += tabelaRomanos[j-1];
	
}


int definirCusto(int ppaa, int ppbb, int *i, int *tabelaRomanos)
{
	int custo=0;
	int digito = ppaa / 1000;
	int restoAA = ppaa % 1000;
	int restoBB = ppbb % 1000;

//	printf ("digito: %d. restoBB %d - %d restoAA %d - %d\n", digito, restoBB, tabelaRomanos[restoBB] , restoAA-1, tabelaRomanos[restoAA-1] );
	custo = digito*i[6]*(restoBB-restoAA+1) + tabelaRomanos[restoBB] - tabelaRomanos[restoAA-1];
	
	return custo;
}

int main()
{

	int n;
	int i[7];
	int ppaa, ppbb, custo;
	int tabelaRomanos[1000];

	int j;
	
	scanf("%d", &n);

	for(j=0; j<7; j++)
		scanf("%d", &i[j]);

	definirTabela(tabelaRomanos, i);
	
	//for (j=0; j<1000; j++)
	//	printf("\n %d ", tabelaRomanos[j]);

	for(j=0; j<n; j++)
	{
		scanf("%d %d", &ppaa, &ppbb);
		
		custo = definirCusto(ppaa, ppbb, i, tabelaRomanos);
	
		printf("%d\n", custo);			
	}
		
	return(0);
}

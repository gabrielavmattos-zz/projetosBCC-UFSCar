#include <iostream>
#include <iomanip>
#include <cstdio>
#include <sstream>
#include <string>

using namespace std;


int maiorK(int *k, int tamK)
{

	int maior = k[0];
	int i;
	
	for(i=0; i<tamK; i++)
		if(maior < k[i])
			maior = k[i];

	return maior;
}

void menorPreco (float u, int m, int *n, float *p, int *k, int tamK, int caso)
{

	cout << "aqui";	
	float *tabela;	
	int maior, i, j, parte, a;

	maior = maiorK(k, tamK) + m;
		
	tabela = new float[maior];

	tabela[0] = 0;


	for(i=1; i<=maior; i++)
	{
		tabela[i] = tabela[0] + u*i;
		for(j=0; j<=i; j++)
		{	
			parte =	tabela[a] + p[j];
			if(tabela[i] > parte)
				tabela[i] = parte;
		}
	
	}	
	
//	for(i=0; i<=maior; i++)
//		cout << "- "<< i << ":" << tabela[i] << endl;
	
	j=0;	
	float menor = tabela[maior];
	

	cout << "Case " << caso << ": " << endl;
	for(i=maior; i>=k[0]; i++)
	{
	
		if(i >= k[j])
		{
			if(menor > tabela[i])
				menor = tabela[i];
		}
		else
		{
			
			cout << "Buy " << k[j] << " for $" << setiosflags (ios::fixed) << setprecision (2) << menor << endl;
			j++;			
			menor = tabela[maior];	
		}

	}

		
	
	delete[] tabela;

}

int main()
{

	int m, *n;
	float u, *p;
	int k[100];
	int i, j, caso=0;

	
	while (cin >> u)
	{
		caso++;
		j=0;
	//	cin >> u;
		cin >> m;

//		cout << u << endl;
//		cout << m << endl;


		n = new int[m];
		p = new float[m];
		
		for(i=0; i<m; i++)
		{
			cin >> n[i];			
			cin >> p[i];

		}
		//int a;
		//string S;
		//cin.ignore();
		//getline(cin, S);
		//stringstream SS(S);
		cout << "Aqui";
		while (cin >> k[j])
		{	
			j++;
			if(k[j] == 0) //etchar() == '\n')	
				break;	
		}

		menorPreco(u, m, n, p, k, j, caso);

		delete[] n;
		delete[] p;
	}	

	return 0;

}

# -*- coding: utf-8 -*-

import networkx as nx
import numpy as np
import random as random
import matplotlib.pyplot as plt

A = np.loadtxt('wg59distB.txt', dtype='int') 
V = np.loadtxt('wg59_name.txt', dtype='str')
G = nx.from_numpy_matrix(A) #converte a matriz em um grafo


def AlgDijkstra (G,V,S,k):

	#lista com os pesos do Grafo
	W = [int(G[u][v]['weight']) for u, v in G.edges()] 

	#matriz com o custo de cada aresta 
	custo = [float('inf')]*len(V)

	#matriz com os predecessores de cada aresta
	pred = [-1]*len(V)

	#matriz contendo a fila com vertices que não contem o custo do menor caminho 
	Q = G.nodes()

	#zerando o custo das raizes definidas
	for i in range(k):
		custo[int(S[i])] = 0
	

	U = []
	Vizinhos = []

	pos = 0

	while (Q!=[]):

		menor = float('inf')
		for i in range(len(Q)):
			if(custo[Q[i]] < menor):
				menor = custo[Q[i]] #menor custo existente em Q
				u = Q[i] #posicao do vertice que possui o menor custo

		U.append(u)
		Q.remove(u)   #extrai o vertice atual da fila 
		
		Vizinhos = G.neighbors(u)

		for j in range(len(Vizinhos)):
			v = int(Vizinhos[j])
			if(v in Q):
				if(custo[v] > (custo[u] + G[u][v]['weight'])):
					custo[v] = custo[u] + G[u][v]['weight']
					pred[v] = u
	return pred, custo

def DesenharCaminho (pred, custo, k):

	MST = nx.Graph()
	vet = np.zeros(len(V))

	for i in range(len(V)):           
	    vet[i] = int(i)


	vet = np.rint(vet)
	pred = np.rint(pred)
	edges = zip(vet,pred)

	for i in range(k):
		#remoção dos predecessores das raizes (que seria o -1 que inicializamos todos os predecessores)		
		edges.remove((S[i], pred[S[i]]))


	MST.add_edges_from(edges)

	#fixando as posições dos nodes para plotar o grafo
	pos_mst = nx.spring_layout(MST)

	plt.figure()
	nx.draw(MST,dim = 100,  pos=pos_mst, with_labels=True, node_size=500, node_color='gray',font_size=10, edge_width=10, alpha=1, arrows=False)
	plt.savefig('MST_Alg.png')	
	plt.axis('off')
	plt.show()


	    
k = int(input('Entre com o valor de sementes para iniciar o Algoritmo de Dijkstra: '))
S = np.zeros(k)

for i in range(k):
	S[i] = int(input('Entre com a raiz entre 0 e 58: '))

pred, custo = AlgDijkstra(G, V, S,k)
DesenharCaminho(pred, custo, k)


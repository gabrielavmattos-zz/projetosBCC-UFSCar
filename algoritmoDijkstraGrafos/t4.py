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
	print G.edges()
	W = [int(G[u][v]['weight']) for u, v in G.edges()] 
	print W

	#matriz com o custo de cada aresta (onde linha é o grupo e coluna é o custo do vertice nesse grupo) [grupo][vertice]
	custo = [[float('inf')]*len(V)]*k

	#matriz com os predecessores de cada aresta (onde linha é o grupo e coluna é o predecessor do vertice nesse grupo) [grupo][vertice]
	pred = np.zeros((k, len(V)))

	#matriz contendo a fila com vertices que não contem o custo do menor caminho [grupo][vertice]
	Q = [G.nodes()]*k
	print Q
		
	#definir três raizes
	
	print S

	#zerando o custo das raizes -----ERRO AINDA
	for i in range(k):
		print i
		custo[i][int(S[i])] = 0
	
	print custo
	k=0

	U = [[]]
	Vizinhos = [[]]
	raiz2 = 2

	P = []
	Po = []
	k=0
	pos = 0

	while (k < 10):
		k = k+1		
		for i in range(k):
			u = int(S[i]) 
			print "Q, ", Q
			print "U, ", U
			print "Custo: ", custo
			U[i].append(S[i])
                        print "Q::: ", Q[i][int(S[i])]
			del Q[i][int(S[i])]   #extrai o vertice atual da fila 
			
			Vizinhos[i] = G.neighbors(u)
			print Vizinhos[i]
			min = float('inf')

			for j in range(len(Vizinhos[i])):
				v = int(Vizinhos[i][j])
				print "atual1:", v
				print "custo:", custo[i][v]
				print "custo + w!", (custo[i][u] + G[u][v]['weight'])
				
				if(custo[i][v] > (custo[i][u] + G[u][v]['weight'])):
					custo[i][v] = custo[i][u] + G[u][v]['weight']
					pred[i][v] = int(S[i])
					if (min > custo[i][v]):
						min = custo[i][v]
						pos = v
					#P.insert(custo[i][v])
					#Po.insert(u)
				
				print "custo depois:", custo[i][v]
			

			S[i] = pos
			print "S: ", S
		

k = int(input('Entre com o valor de sementes para iniciar o Algoritmo de Dijkstra: '))
S = np.zeros(k)

for i in range(k):
	S[i] = int(input('Entre com a raiz entre 0 e 58: '))

print S
AlgDijkstra(G, V, S,k)


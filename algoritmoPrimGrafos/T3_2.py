# -*- coding: utf-8 -*-


import networkx as nx
import numpy as np
import random as random
import matplotlib.pyplot as plt

A = np.loadtxt('wg59_dist.txt', dtype=int) #leitura da matriz
V = np.loadtxt('wg59_name.txt', dtype='str')

#print G
#print V

def algPrim(G):
    
    
    W = [ int(G[u][v]['weight']) for u, v in G.edges()]
    
    custo = ['inf']*len(V) #custo de cada aresta
    fila = ['inf']*len(V)
    pred = np.zeros (len(V))
    
    vertice_atual = random.randint(0, len(V)) #o vertice inicial sera escolhido aleatoriamente
    
    j=0
    
    custo[vertice_atual] = 0
    a = np.zeros(len(V))
    k=0
    pred[vertice_atual] = 'inf'
    raiz = vertice_atual
    
    while(max(fila)!=0)
    {
    

algPrim(G)

G = nx.from_numpy_matrix(A) #converte a matriz em um grafo
    ]
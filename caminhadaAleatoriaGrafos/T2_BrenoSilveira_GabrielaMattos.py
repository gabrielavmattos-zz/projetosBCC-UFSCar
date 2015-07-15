# -*- coding: utf-8 -*-
"""
Created on Tue Sep 30 19:54:58 2014

@author: Breno
"""

import networkx as nx
import numpy as np
import random as random
G = nx.read_gml('dolphins.gml')

def Parte1(G):
      #Primeiramente, será computada a distribuicao estacionaria obrigatoria

    w_real = []
    
    L = G.degree()

    NE = G.number_of_edges()

       #NE recebe o numero de arestas no grafo. Para podermos utilizar a distribuicao
       #estacionaria obrigatoria, esse valor sera multiplicado por 2

    NE = 2*NE

    i = 0
    while i < len(L):
         j = G.degree(i)
         j = float(j)
         j = j/NE
         w_real.append(j)    
         i = i + 1
    

    print "\n\nPrimeira Parte - W Real: \n"
    print w_real
    print "\n\n\n\n"
       
Parte1(G) 
# Segunda Parte: Gerar a matriz P e a partir de uma linha determinar o 
#vetor w    
    
def Parte2(G, k):  
    
    V = G.number_of_nodes()
    A = nx.adjacency_matrix(G)
    D = np.zeros((V,V))
    
    for i in range(V):
             j = 1 / float(G.degree(i))
             D[i][i] = j
    
    print "\nMatriz Delta-1:\n"
    print D    

    P = D*A
    NP = P
    i = 0
    
    while i < k:
            NP = np.dot(NP, P)
            i = i + 1

    print "\nMatriz P com k = ",k,":\n"
    print NP   
    
    print "\n w_power '",k,"' retirado da matriz P: \n"
    w_power = NP[0]
    print w_power
    X = sum(w_power)
    print "\nSoma do vetor: ", X

print "\n\nPower Method com n=5: "
Parte2(G,5)
print "\n\nPower Method com n=100: "
Parte2(G,100)


def sort_matriz (matriz):
    for j in range(10):
     chave = matriz[0][j]  #chave vai ser o elemento da direita
     chave1 = matriz[1][j]
     i = j - 1             #o índice i vai ser o índice do elemento da esquerda
     while i >= 0 and matriz [1] [j] > chave1:
      matriz [0][i + 1] = matriz [0][i+1]
      matriz [1][i + 1] = matriz [1][i+1]
    
      i = i - 1
      matriz [0] [i + 1] =  chave1
      matriz [1] [i + 1] = chave
        
    return matriz

def CaminhadaAleatoria(G, inicio, tam):
     
    contador =  np.zeros(len(G))
    caminho = []
    caminho += [inicio]
    i = 0
    for i in range(tam):
        ok = 0
        k = 0
        while (ok == 0):
            num = inicio
            j = 0
            while (num == inicio):
                num = random.randint(0, len(G))
            
            vet = G.neighbors(inicio)
            while (j < len(vet)):
                if(num == vet[j]):
                        ok = 1
                        caminho += [num]
                        contador[num] += 1
                        inicio = num
                j = j + 1
                
    top = np.zeros(10)
    top10 = []
    top10 = np.zeros(10)
    tamG = len(G)
    prob = np.zeros(tamG)
    
    for i in range(tamG):
        prob[i] = contador[i]/float(tam)
        minimo = min(top)
        for j in range (10):
            if (top[j] == minimo):
                posMinimo = j
            

        if (contador[i] > minimo):
            top[posMinimo] = contador[i]
            top10[posMinimo] = i
    
    print "\n\nMatriz de Probabilidade: "
    print prob
    print "\n\nTop 10: ", top10
    print "\n\nQtd 10: ", top
        
    

print "\n\nCaminhada de tamanho 100 começando em 5: "
CaminhadaAleatoria(G,5,100)

print "\n\nCaminhada de tamanho 100 começando em 50: "
CaminhadaAleatoria(G,50,100)

    
print "\n\nCaminhada de tamanho 10000 começando em 5: "
CaminhadaAleatoria(G,5,10000)

print "\n\nCaminhada de tamanho 10000 começando em 50: "
CaminhadaAleatoria(G,50,10000)

print "\n\n"
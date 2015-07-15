# -*- coding: utf-8 -*-

import networkx as nx
import numpy as np
import random as random
import matplotlib.pyplot as plt

A = np.loadtxt('wg59_dist.txt', dtype=int) #leitura da matriz
V = np.loadtxt('wg59_name.txt', dtype='str')

def algPrim(A,V):
     
    custo = ['inf']*len(V) #custo de cada aresta
    fila = ['inf']*len(V)
    pred = np.zeros (len(V))
    
    vertice_atual = random.randint(0, len(V)) #o vertice inicial sera escolhido aleatoriamente
    
   
    custo[vertice_atual] = 0
    pred[vertice_atual] = 'inf'
    raiz = vertice_atual

    
    while (max(fila)!=0):
        min = 555555
        fila[vertice_atual]=0
        
        for i in range(len(V)):
            if(fila[i] > A[vertice_atual][i] and fila[i]!= 0):
                fila[i] = int(A[vertice_atual][i])
                pred[i] = int(vertice_atual)
                
        for i in range (len(V)):
            if( min > fila[i] and fila[i]>0):
                pos_min = i
                min = fila[i]
                
        custo[pos_min] = int(fila[pos_min])
        vertice_atual = pos_min    
    
    
    MST = nx.Graph()
    vet = np.zeros(len(V))

    for i in range(len(V)):           
            vet[i] = int(i)
    
    vet = np.rint(vet)
    pred = np.rint(pred)
    edges = zip(vet,pred)
    edges.remove((raiz, pred[raiz]))
    
    
    MST.add_edges_from(edges)
    W_MST = [A[u][v] for u,v in MST.edges()]
    W_MST_Ord = sorted(W_MST) 
    

    #fixando as posições dos nodes para plotar o grafo
    pos_mst = nx.spring_layout(MST)

    plt.figure()
    nx.draw(MST,dim = 100,  pos=pos_mst, with_labels=True, node_size=500, node_color='gray',font_size=10, edge_width=10, alpha=1, arrows=False)
    plt.savefig('MST_Alg.png')	
    
    
    print "\n\n T \n\n"
    print " - Soma dos pesos da MST encontrada a partir do Algoritmo de Prim: ", sum(W_MST)
    print " - Número de vértices da MST encontrada a partir do Algoritmo de Prim: ", len(MST.edges())
    print "\n\n T \n\n"
    
    #nx.draw_networkx_edges(MST, edges)
    plt.axis('off')
    plt.show()

    #obter 3 grupos, vamos remover as duas maiores arestas
    maior = np.zeros(3)
    preds = np.zeros(3)
    
    j=0
    
    for i in range(len(V)-2, len(V)-5, -1):
        m = W_MST_Ord[i]
        maior[j] = W_MST.index(m)
        preds[j] = pred[maior[j]]
        j=j+1
    

    #removendo as duas maiores arestas
    
    MST.remove_edge(maior[0], preds[0])
    MST.remove_edge(maior[1], preds[1])

    plt.figure()		#// Cria figura para desenhar grafo: 15 é a dimensão da imagem
    nx.draw(MST,dim = 100,  pos=pos_mst, with_labels=True, node_size=500, node_color='gray',font_size=10, edge_width=10, alpha=1, arrows=False)
    plt.savefig('elimina2.png')	#// Outros formatos: pdf, svg, ...
    
    plt.axis('off')
    plt.show()
    
    #removendo as três maiores arestas
        
    MST.remove_edge(maior[2], preds[2])

    plt.figure()		#// Cria figura para desenhar grafo: 15 é a dimensão da imagem
    nx.draw(MST,dim = 100,  pos=pos_mst, with_labels=True, node_size=500, node_color='gray',font_size=10, edge_width=10, alpha=1, arrows=False)
    plt.savefig('elimina3.png')	#// Outros formatos: pdf, svg, ...

    plt.axis('off')
    plt.show()

algPrim(A,V)


G = nx.from_numpy_matrix(A) #converte a matriz em um grafo
T = nx.minimum_spanning_tree(G) #faz uma MST automatica

W = [ int(T[u][v]['weight']) for u, v in T.edges()] #lista com os pesos da MST gerada automatico

#imprimir a soma das arestas 
print "\n\n T \n\n"
print " - Soma dos pesos da MST gerada automatico: ", sum(W)
print " - Número de vértices da MST gerada automatico: ", len(T.edges())
print "\n\n T \n\n"

plt.figure()		#// Cria figura para desenhar grafo: 15 é a dimensão da imagem
nx.draw(T,dim = 100, with_labels=True, node_color='gray', node_size=500, font_size=10, edge_width=10, alpha=1, arrows=False)
plt.savefig('MST_geradaAut.png')	#// Outros formatos: pdf, svg, ...


#nx.draw_networkx_edges(MST, edges)
plt.axis('off')
plt.show()
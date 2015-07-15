# raiz (utilizada ao computar dijkstra)
s = 1
# computar os caminhos ótimos
pred, cost = dijkstra(G, s) # chamada da implementação de dijkstra

# verificar algoritmo
for v in G.nodes():
    
    # testar caminho otimo de s-v
    # para isso usar networkx como gabarito 
    Psv = nx.shortest_path_length(G, s, v, 'weight') 
    # obs: 'weight' é o atributo padrão que armazena os pesos do grafo
    
    # obter lambda(v): custo ótimo de s-v computado pelo algoritmo de dijkstra
    myPsv = cost[v] # custo computado pelo "meu" algoritmo
   
    # compara se o custo ótimo é igual ao computado pela networkx
    print 'Caminho ótimo s-v é válido?', '(s=', s, '; v=', v, ')'
    
    # imprimir resposta    
    print Psv == myPsv # (True ou False)
    # obs: se for falso para pelo menos um s-v, implementação está incorreta
    

projetoLabArq2
==============
Projeto Final de Laboratório de Arquitetura de Computadores 2

Produzido por: Gabriela Mattos e Ilgner Vieira

LookupFilter (Modificado)

Na disciplina de Laboratório de Arquitetura de Computadores 2, estudamos a linguagem Assembly Intel x86, com aplicações de programas sequenciais ou aplicando o conceito de paralelização com intruções SIMD (http://pt.wikipedia.org/wiki/SIMD), aplicando o formato MMX ou outros.

Contudo, como projeto final da disciplina objetivamos aplicar os conceitos visto em aula com a implementação sequencial e paralela de um filtro para imagens do tipo PBM, possibilitando a comparação de desempenho entre as aplicações Sequenciais e SIMD da linguagem Assembly Intel x86.

O filtro possibilita alterar a coloração das imagens para uma das opções abaixo, com o auxilio de um ColorMap que nos implementados, para o resultado mais efetivo das imagens é indicado que a imagem seja passada para tons de cinza antes. No nosso projeto temos um programa que faz o filtro de cinza e um outro que a partir da escolha pode deixar nos seguintes tons (o número corresponde ao parâmetro que é necessário passar para falar qual filtro deve ser feito):

     * Vermelho - Filtro 1
     * Amarelo - Filtro 2
     * Verde - Filtro 3
     * Azul - Filtro 4
     * Roxo - Filtro 5
     * Olive - Filtro 6
     * Aqua - Filtro 7


Obs.: o Makefile utilizado permite o teste com todas as imagens presentes na pasta in nas duas versões do programa, mas infelizmente ainda não é o arquivo make mais funcional. Gostaríamos de modificar isso futuramente.

projetoLabArq2
==============
== Projeto Final de Laboratório de Arquitetura de Computadores 2 ==

====Produzido por: Gabriela Mattos e Ilgner Vieira====

===LookupFilter (Modificado)===

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

==== Imagens utilizadas na aplicação do Filtro ====


http://i.picasion.com/pic79/977661ff2e3a8c948500ec78b3bc0ab4.gif

Disponível em: [https://code.google.com/p/arq2asm/source/browse/#svn%2Ftrunk%2Fpbm%2Fin] 


=== Implementação dos procedimentos para alterar a coloração ===

No arquivo [https://code.google.com/p/projetolabarq2/source/browse/trunk/projeto_seq.c projeto_seq.c] temos a implementação com inline assembly. É importante destacar que essa versão assembly não é a da Intel, presente no arquivo [https://code.google.com/p/projetolabarq2/source/browse/trunk/projeto.asm projeto.asm], mas sim a do AT&T, sendo essa compatível com qualquer sistema que possua o gcc como compilador. Por isso algumas diferenças serão notadas.

Como já mencionado, esse filtro permite a escolha de 7 cores do mapa de cores. Usaremos o código das cores Vermelho (filtro 1) e Amarelo (filtro 2) para explicar o funcionamento do código. 

No inline assembly AT&T é utilizado para receber da memória e para retornar uma estrutura de definir nas últimas linhas e depois referenciar com o número correspondente. Sendo que a partir do primeiro *:* contasse do 0 e utiliza com _%num_. Ou seja:

{{{
: "=r"(*G), "=r"(*B) // %0 , %1
: "r"(*G), "r"(*B) // %2 , %3
}}}

Algumas outras diferenças existem, mas são mais intuitivas. Qualquer dúvida é possível resolver nesse artigo [http://www.imada.sdu.dk/Courses/DM18/Litteratur/IntelnATT.htm].

==== Programa implementado na versão Sequencial ====

Nessa versão trabalhamos com byte individualmente. Onde lemos do arquivo de imagem o R, G e B, logo depois é feito o processamento de cada um dos bytes para transformar em outras cores. 

Os procedimentos consistem em receber como parâmetro de referência esses três bytes (R, G e B) mover para os registradores. Esse processo de mover é necessário lembrar de utilizar a instrução que move sem sinal, nesse caso o _movzbl_ que estende os bits com 0. 


 * Converter Vermelho:

Para conversão para o vermelho temos que zerar G e B e manter o R. É isso que o código a seguir faz com uso da instrução _andl_.

{{{
void ConverterVermelho(char *R, char *G, char *B)
{

        asm("movzbl %2, %%eax \n"
            "andl $0, %%eax \n"
            "mov %%al, %0 \n"
            "movzbl %3, %%eax \n"
            "andl $0, %%eax\n"
            "mov %%al, %1"
             : "=r"(*G), "=r"(*B)
             : "r"(*G), "r"(*B)
             : "eax");
        
}
}}}


 * Converter Amarelo:

Nesse filtro é setado o R e o G e mantem o B, para assim transformar em amarelo. O resultado sempre será 255 255 B. 

{{{
void ConverterAmarelo(char *R, char *G, char *B)
{

        asm("movzbl %2, %%eax \n"
            "orl $255, %%eax \n"
            "mov %%al, %0 \n"
            "movzbl %3, %%eax \n"
            "orl $255, %%eax\n"
            "mov %%al, %1"
             : "=r"(*R), "=r"(*G)
             : "r"(*R), "r"(*G)
             : "eax");

}
}}}


==== Programa implementado na versão Paralela ====


Abaixo encontra-se o programa e linguagem C com a paralelização das funções inLine Assembly, utilizando o formato de instruções MMX.

O formato de instrução MMX permite trabalhar com um vetor de 64 bits. Esse vetor armazena 8 char's (como é possível ver nos tamanhos das máscaras utilizadas). Para que não houvesse erro por conta da quantidade de pixels e o tamanho do vetor, preferimos transformar de 6 em 6 bytes, pois não haveria conflito com o tamanho, já que é divisível por 3. 

Outro aspecto importante de mencionar é a utilização do *rax, rbx* para armazenar os endereços da imagem. Foi algo importante da implementação, pois quando era uma imagem grande não era possível armazenar no *eax, ebx* os endereços já que necessitavam de mais de 32 bits. Então foi pesquisado e visto a necessidade de utilizar esses registradores de 64 bits tornando possível a execução dos filtros em todas as imagens testadas.


 * Converter Vermelho:

{{{
void ConverterVermelho(char *ptri, char *ptro, int loop)
{

        char masc[] = {255, 0, 0, 255, 0, 0, 255, 0}; 

        asm("mov %0, %%rax \n"
                "mov %1, %%rbx \n"
                "movl %3, %%ecx \n"
                "movl $0, %%edx \n"
                "movq %2, %%mm1 \n"
                "L1: movq (%%rax), %%mm0 \n"
                "pand %%mm1, %%mm0 \n"
                "movq %%mm0, (%%rbx) \n"
                "add $6, %%rax \n"
                "add $6, %%rbx \n"
                "add $6, %%edx \n"
                "cmp %%edx, %%ecx \n"
                "ja L1\n"
                :
                : "g"(ptri), "g" (ptro), "m" (*(__m64*)masc), "r" (loop)
                : "mm0", "rax", "rbx", "ecx", "edx");
}
}}}

 * Converter Amarelo:

{{{
void ConverterAmarelo(char *ptri, char *ptro, int loop)
{
        char masc[] = {255, 255, 0, 255, 255, 0, 255, 255}; 

        asm("mov %0, %%rax \n"
                "mov %1, %%rbx \n"
                "movl %3, %%ecx \n"
                "movl $0, %%edx \n"
                "movq %2, %%mm1 \n"
                "L2: movq (%%rax), %%mm0 \n"
                "por %%mm1, %%mm0 \n"
                "movq %%mm0, (%%rbx) \n"
                "add $6, %%rax \n"
                "add $6, %%rbx \n"
                "add $6, %%edx \n"
                "cmp %%edx, %%ecx \n"
                "ja L2\n"
                :
                : "g"(ptri), "g" (ptro), "m" (*(__m64*)masc), "r" (loop)
                : "mm0", "rax", "rbx", "ecx", "edx");



}
}}}

É necessário utilizar o * {{{*(__m64*)}}}*, pois para que seja mandando para o mm0 o compilador precisa entender que esse é para ser interpretado como uma variável de 64 bits. Mais informações: [http://msdn.microsoft.com/pt-br/library/08x3t697.aspx]

=== Resultados ===

Com a implementação do Filtro foi possível obter as imagens abaixo. Os gif's consistem em: a primeira imagem é a original, a segunda é a em cinza, e as outras são os filtros que o nosso programa faz.

 * Exempo com a imagem Flower.pnm

http://i.picasion.com/pic79/4ecc2cafa5c966b537bc296337faebfd.gif

 * Exemplo com a imagem Lorikeet.pnm

http://i.picasion.com/pic79/ac3c1b19bcb4dc5a063fabc23973e3fb.gif


=== Conclusões ===

Uma escolha importante tomada no trabalho foi realizar o filtro em tons de cinza em um programa separado, pois para verificar o desempenho do nossos filtros juntamente com esse outro seria bem mais difícil, já que a diferença não ia ser muito grande quando fosse utilizado uma versão paralela. 

Portanto, a implementação em sequencial e paralela da forma que fizemos permitiu observar a melhora no desempenho com a utilização do MMX. Para imagens com mais pixel's a diferença, no tempo de execução que é dado em segundos, é mais considerável, confirmando a vantagem no processamento vetorial.

 * Filtro 1 - Vermelho:

http://projetolabarq2.googlecode.com/svn/filtro1.png

 * Filtro 2 - Amarelo:

http://projetolabarq2.googlecode.com/svn/filtro_2.png

Para verificar a diferença em relação ao desempenho dos outros filtros é simples, já que o make faz a execução do sequencial e logo após do paralelo apresentando os resultados. A visualização é bem simples. Observe abaixo um exemplo de execução. 

http://projetolabarq2.googlecode.com/svn/trunk/exemplo.png

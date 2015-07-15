/*-----------------------TAREFAS A FAZER----------------------

- IMPLEMENTAR FUNÇÕES QUE PERMITE O USUARIO TROCAR ORDEM DAS LETRAS

Desenvolvido por:
Eric Vinicius Reginaldo Rocha - 551538
Gabriela Vanessa Pereira Alves Mattos - 551570

Orientacao: Prof. Ednaldo Brigante Pizzolato.


--------------------------JOGO DOS ANAGRAMAS-------------------------------------------

1.OBJETIVO

Formar o maior número de palavras com as letras disponíveis.

2.INSTRUÇÕES

2.1 Como jogar
Em cada nível do jogo haverá um conjunto de letras que deverão ser organizadas de
modo que formem palavras. Essas palavras devem existir na língua portuguesa
e podem, ou não, utilizar todas as letras disponíveis.
Ex.: Conjunto de letras: AROM
Palavras possíveis: AMOR, ROMA, MAR , MORA, MOR

2.2 Como passar de nível
Todos os níveis possuem um número mínimo de palavras que devem ser formadas.


2.3 Pontuação
A pontuacao inicial é 20 e a cada palavra formada acarreta um acréscimo de X pontos ao escore final e
a cada palavra errada será subtraido Y pontos.

*/

//----------------------------Bibliotecas que serão necessárias-----------------------

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
#define max_caracteres_1 8 //definindo maximo de caracteres no nivel 1
#define max_palavras_1 8 //definindo maximo de palavras no nivel 1
#define max_caracteres_2 9 //definindo maximo de caracteres no nivel 2
#define max_palavras_2 8 //definindo maximo de palavras no nivel 2
#define max_caracteres_3 12 //definindo maximo de caracteres no nivel 3
#define max_palavras_3 11 //definindo maximo de palavras no nivel 3

//------------------Estruturas que serão utilizadas no programa-----------------------

//Estrutura que será utilizada no nível 1
typedef struct
{
    char letra[max_caracteres_1];
    char palavras[max_palavras_1][10];
    int codigo;

}nivel1;

//Estrutura que será utilizada no nível 2
typedef struct
{
    char letra[max_caracteres_2];
    char palavras[max_palavras_2][10];
    int codigo;
}nivel2;

//Estrutura que será utilizada no nível 3
typedef struct
{
    char letra[max_caracteres_3];
    char palavras[max_palavras_3][13];
    int codigo;
}nivel3;

//Estrutura para salvar último jogo
typedef struct
{
    int nivel;
    int pontuacao;

}ultimo_jogo;

//------------------Prototipos das funções e procedimentos-----------------------

int sorteia_indice(int); //Função que sorteará o indice para definir qual o conjunto de palavras que será apresentado ao usuário
int jogar_nivel1(int *);//Função que permitirá o usuário jogar a primeira fase do jogo
int jogar_nivel2(int *);//Função que permitirá o usuário jogar a segunda fase do jogo
int jogar_nivel3(int *);//Função que permitirá o usuário jogar a terceira fase do jogo
int continuar_nivel(int, int);//Função que permitirá o usuário escolher se quer continuar o nível
void apresentar_letras(char *, int); //Apresenta as letras sortidas
void apresentar_pontuacao(int pontuacao); //Apresenta os pontos
void tela_jogo1(char *, char [10][10], int, int); //Apresenta tela nivel 1
void tela_jogo2(char *, char [10][10], int, int); //Apresenta tela nivel 2
void tela_jogo3(char *, char [16][13], int, int); //Apresenta tela nivel 3
void menu(); //menu principal
void perdeu_jogo(); //Quando o usuario perde o jogo
void iniciar_jogo(int *, int); //verifica em que nivel o usuario vai começar por conta do contunuar
void continuar_jogo(); //para continuar o jogo
void instrucoes(); //Apresentara as instruções
void salvar_jogo(ultimo_jogo); //Salvará as informações do ultimo jogo em um arquivo binario
void sair(); //Sai do jogo
void nova_linha(); //Escreve uma nova linha
void nova_linha_pont(); //Escre uma nova linha pontinhada
void nome_jogo();
void trocar_letras(char *, int);
void ganhou_jogo();
void creditos();
//----------------------------Funções-------------------------------------------------


//Função que sorteará o indice para definir qual o conjunto de palavras que será apresentado ao usuário
int sorteia_indice(int maximo)
{
    int num;
    time_t seconds;
    time(&seconds);
    srand((unsigned int)seconds);
    num=rand()% maximo;
    return num; //retorna um numero que foi sorteado

}

//Função que permitirá o usuário jogar a primeira fase do jogo
//Objetivo da fase: montar 3 anagramas com as letras apresentadas (sendo 7)
//A cada palavra acertada nessa fase ganhará 5 pontos x pelo número de caracteres da acerdada
//A cada tentativa errada perde 5 pontos
int jogar_nivel1(int *pontuacao)
{

    nivel1 sorteado; //estrutura que será usado para ler no arquivo e começar o nivel
    char palavra[10];  //variavel que será utilizada para que o usuário entre com as palavras
    char palavra_acertou[10][10]; //vetor que armazenará as palavras que o usuário acertou
    int indice_sorteado, acertou=0, continuar=1, acertou_inicial, i,j=0,indice_acertou=0; //variaveis interias que serão utilizadas

    indice_sorteado=sorteia_indice(5); //sorteia um numero inteiro entre 0 e 8 que corresponderá a um dos conjutos de palavras do nível 1

    FILE *arq1; //Arquivo que estará armazenada as palavras do primeiro nível

    arq1=fopen("Palavras_jogo_nivel_1.bin", "rb"); //leitura do arquivo
    if(arq1==NULL)
    {
        printf("Erro no arquivo!");
        getch();
        exit(1);

    }

    fseek(arq1,indice_sorteado*sizeof(nivel1),SEEK_SET); //posicionamento do arquivo na posicao sorteada pela função sorteia_indice
    fread(&sorteado,sizeof(nivel1),1,arq1); //leitura da estrutura no arquivo
    fclose(arq1); //fechando o arquivo

    strcpy(palavra_acertou[0],"");//inicializa a o vetor na posicao 0 pra na primeira rodada não mostrar nada
    trocar_letras(sorteado.letra, max_caracteres_1); //função que mudara a ordem das letras apresentadas
    do
    {

        tela_jogo1(sorteado.letra,palavra_acertou,indice_acertou,*pontuacao); //função que apresentará as informações para o usuário
        printf("Entre com um anagrama das palavras apresentadas: [        ]\b\b\b\b\b\b\b\b\b");
        fflush(stdin);
        gets(palavra); //leitura das palavras que o usuario entrar
        strlwr(palavra); //deixando todas as letras minusculas da variavel digitada pelo usuario
        i=0;//inicializa oi que será utilizado como indice da palavras da estrutura pra ver se existe
        acertou_inicial=acertou; //coloca o acertou inicial sendo igual ao acertou para ser consição de parada do proximo while
        while(i<8 && acertou_inicial==acertou)
        {
            if(strcmp(palavra,sorteado.palavras[i])==0 && strcmp(palavra, "")) //compara se a palavra digitada é igual a alguma do arquivo
            {
                acertou++; //caso encontre incrementa acertou
                strcpy(palavra_acertou[indice_acertou],palavra); //copia a palavra que o usuario acertou para ser mostrada posteriormente
                indice_acertou++;
                *pontuacao=*pontuacao+5*strlen(palavra); //o valor da pontuacao corresponde a 5*o tamanho da palavra digitada caso acerte
                printf("\n\n\tVoce acertou a palavra '%s'.\n\n\tFaltam formar mais %d palavras.", sorteado.palavras[i], (3-acertou));
                printf("\n\t1 - Continuar");
                continuar=continuar_nivel(1, *pontuacao); //chama a funcao que dara a opção dele sair do jogo ou continuar
                strcpy(sorteado.palavras[i],""); //zera a palavra que o usuario já acertou do arquivo para que ele não escreva de novo
            }
            i++;
        }

        if(acertou_inicial==acertou) //compara o acertou_inicial com o acertou pra ver se o usuario acertou, caso acertou ele será um vez maior
        {                             //quando erra é esse if

            printf("\n\tVoce nao acertou a palavra!");
            *pontuacao-=5; //subtrai 5 pontos na pontuacao total dele
            nova_linha();
            nova_linha();
            printf("\n\t1 - Tentar novamente!");
            continuar=continuar_nivel(1, *pontuacao); //perguntara se ele deseja continuar caso sim retorna 1

        }
        if (continuar==2)
            trocar_letras(sorteado.letra, max_caracteres_1); //função que mudara a ordem das letras apresentadas

    } while(acertou!=3 && continuar!=0 && *pontuacao>0);

    if(acertou==3) //testa se o usuario acertou o suficiente para ir no próximo nível
        return 2; //retorna 2 corresponde ao nivel 2
    else
        return 0;

}

//Função que permitirá o usuário jogar a segunda fase do jogo
//Objetivo da fase: montar 5 anagramas com as letras apresentadas (sendo 9)
//A cada palavra acertada nessa fase ganhará 10 pontos x pelo número de caracteres da acerdada
//A cada tentativa errada perde 10 pontos
int jogar_nivel2(int *pontuacao)
{

    nivel2 sorteado; //estrutura que será usado para ler no arquivo e começar o nivel
    char palavra[10];  //variavel que será utilizada para que o usuário entre com as palavras
    char palavra_acertou[10][10]; //vetor que armazenará as palavras que o usuário acertou
    int indice_sorteado, acertou=0, continuar=1, acertou_inicial, i, j=0,indice_acertou=0;//variaveis interias que serão utilizadas

    indice_sorteado=sorteia_indice(5); //sorteia um numero inteiro entre 0 e 5 que corresponderá a um dos conjutos de palavras do nível 1

    FILE *arq2; //Arquivo que estará armazenada as palavras do primeiro nível

    arq2=fopen("Palavras_jogo_nivel_2.bin", "rb"); //leitura do arquivo
    if(arq2==NULL)
    {
        printf("Erro no arquivo!");
        getch();
        exit(1);

    }

    fseek(arq2,indice_sorteado*sizeof(nivel2),SEEK_SET); //posicionamento do arquivo na posicao sorteada pela função sorteia_indice
    fread(&sorteado,sizeof(nivel2),1,arq2); //leitura da estrutura no arquivo
    fclose(arq2); //fechando o arquivo

    strcpy(palavra_acertou[0],"");//inicializa a o vetor na posicao 0 pra na primeira rodada não mostrar nada
    trocar_letras(sorteado.letra, max_caracteres_2); //função que mudara a ordem das letras apresentadas
    do
    {

        tela_jogo2(sorteado.letra,palavra_acertou,indice_acertou,*pontuacao); //função que apresentará as informações para o usuário
        printf("Entre com um anagrama das palavras apresentadas: [         ]\b\b\b\b\b\b\b\b\b\b");
        fflush(stdin);
        gets(palavra); //leitura das palavras que o usuario entrar
        strlwr(palavra); //deixando todas as letras minusculas da variavel digitada pelo usuario
        i=0;//inicializa oi que será utilizado como indice da palavras da estrutura pra ver se existe
        acertou_inicial=acertou; //coloca o acertou inicial sendo igual ao acertou para ser consição de parada do proximo while
        while(i<max_palavras_2 && acertou_inicial==acertou)
        {
            if(!strcmp(palavra,sorteado.palavras[i]) && strcmp(palavra, "")) //compara se a palavra digitada é igual a alguma do arquivo
            {
                acertou++; //caso encontre incrementa acertou
                strcpy(palavra_acertou[indice_acertou++],palavra); //copia a palavra que o usuario acertou para ser mostrada posteriormente
                *pontuacao=*pontuacao+10*strlen(palavra); //o valor da pontuacao corresponde a 10*o tamanho da palavra digitada caso acerte
                printf("\n\n\tVoce acertou a palavra '%s'.\n\n\tFaltam formar mais %d palavras.", sorteado.palavras[i], (5-acertou));
                nova_linha();
                nova_linha();
                printf("\n\t1 - Continuar");
                continuar=continuar_nivel(2, *pontuacao); //chama a funcao que dara a opção dele sair do jogo ou continuar
                strcpy(sorteado.palavras[i],""); //zera a palavra que o usuario já acertou do arquivo para que ele não escreva de novo
            }
            i++;
        }

        if(acertou_inicial==acertou) //compara o acertou_inicial com o acertou pra ver se o usuario acertou, caso acertou ele será um vez maior
        {                             //quando erra é esse if

            printf("\n\tVoce nao acertou a palavra!");
            *pontuacao-=5; //subtrai 5 pontos na pontuacao total dele
            nova_linha();
            nova_linha();
            printf("\n\t1 - Tentar novamente!");
            continuar=continuar_nivel(2, *pontuacao); //perguntara se ele deseja continuar caso sim retorna 1

        }
        if (continuar==2)
            trocar_letras(sorteado.letra, max_caracteres_2); //função que mudara a ordem das letras apresentadas

    } while(acertou!=5 && continuar!=0 && *pontuacao>0);

    if(acertou==5) //testa se o usuario acertou o suficiente para ir no próximo nível
        return 3; //retorna 3 corresponde ao nivel 3
    else
        return 0;

}

//Função que permitirá o usuário jogar a terceira fase do jogo
//Objetivo da fase: montar 8 anagramas com as letras apresentadas (sendo 12)
//A cada palavra acertada nessa fase ganhará 20 pontos x pelo número de caracteres da acerdada
//A cada tentativa errada perde 20 pontos
int jogar_nivel3(int *pontuacao)
{


    nivel3 sorteado; //estrutura que será usado para ler no arquivo e começar o nivel
    char palavra[14];  //variavel que será utilizada para que o usuário entre com as palavras
    char palavra_acertou[16][13]; //vetor que armazenará as palavras que o usuário acertou
    int indice_sorteado, acertou=0, continuar=1, acertou_inicial, i,j=0,indice_acertou=0; //variaveis interias que serão utilizadas

    indice_sorteado=sorteia_indice(5); //sorteia um numero inteiro entre 0 e 8 que corresponderá a um dos conjutos de palavras do nível 1

    FILE *arq3; //Arquivo que estará armazenada as palavras do primeiro nível

    arq3=fopen("Palavras_jogo_nivel_3.bin", "rb"); //leitura do arquivo
    if(arq3==NULL)
    {
        printf("Erro no arquivo!");
        getch();
        exit(1);

    }

    fseek(arq3,indice_sorteado*sizeof(nivel3),SEEK_SET); //posicionamento do arquivo na posicao sorteada pela função sorteia_indice
    fread(&sorteado,sizeof(nivel3),1,arq3); //leitura da estrutura no arquivo
    fclose(arq3); //fechando o arquivo
    strcpy(palavra_acertou[0],"");//inicializa a o vetor na posicao 0 pra na primeira rodada não mostrar nada

    trocar_letras(sorteado.letra, max_caracteres_3); //função que mudara a ordem das letras apresentadas
    do
    {

        tela_jogo3(sorteado.letra,palavra_acertou,indice_acertou,*pontuacao); //função que apresentará as informações para o usuário
        printf("Entre com um anagrama das palavras apresentadas: [            ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
        fflush(stdin);
        gets(palavra); //leitura das palavras que o usuario entrar
        strlwr(palavra); //deixando todas as letras minusculas da variavel digitada pelo usuario
        i=0;//inicializa oi que será utilizado como indice da palavras da estrutura pra ver se existe
        acertou_inicial=acertou; //coloca o acertou inicial sendo igual ao acertou para ser consição de parada do proximo while
        while(i<max_palavras_3 && acertou_inicial==acertou)
        {
            if(!strcmp(palavra,sorteado.palavras[i]) && strcmp(palavra, "")) //compara se a palavra digitada é igual a alguma do arquivo
            {
                acertou++; //caso encontre incrementa acertou
                strcpy(palavra_acertou[indice_acertou++],palavra); //copia a palavra que o usuario acertou para ser mostrada posteriormente

                *pontuacao=*pontuacao+20*strlen(palavra); //o valor da pontuacao corresponde a 20*o tamanho da palavra digitada caso acerte
                printf("\n\n\tVoce acertou a palavra '%s'.\n\n\tFaltam formar mais %d palavras.", sorteado.palavras[i], (8-acertou));
                nova_linha();
                nova_linha();
                printf("\n\t1 - Continuar");
                continuar=continuar_nivel(3, *pontuacao); //chama a funcao que dara a opção dele sair do jogo ou continuar
                strcpy(sorteado.palavras[i],""); //zera a palavra que o usuario já acertou do arquivo para que ele não escreva de novo
            }
            i++;
        }

        if(acertou_inicial==acertou) //compara o acertou_inicial com o acertou pra ver se o usuario acertou, caso acertou ele será um vez maior
        {                             //quando erra é esse if

            printf("\n\tVoce nao acertou a palavra!");
            *pontuacao-=5; //subtrai 5 pontos na pontuacao total dele
            nova_linha();
            nova_linha();
            printf("\n\t1 - Tentar novamente!");
            continuar=continuar_nivel(1, *pontuacao); //perguntara se ele deseja continuar caso sim retorna 1

        }
        if (continuar==2)
            trocar_letras(sorteado.letra, max_caracteres_3); //função que mudara a ordem das letras apresentadas

    } while(acertou!=8 && continuar!=0 && *pontuacao>0);

    if(acertou==8) //testa se o usuario acertou o suficiente para ir no próximo nível
        return 4; //retorna 4 corresponde ao fim do jogo
    else
        return 0;
}


//Função que permitirá o usuário decidir se quer continuar jogando ou parar
int continuar_nivel(int nivel, int pontuacao)
{

        int opcao; //variavel para receber o que o usuário escolher
        ultimo_jogo salvar; //caso ele decida sair do jogo e salvar

        do
        {
            printf("\n\t2 - Trocar ordem das letras!");
            printf("\n\t3 - Sair do jogo e salvar!");
            printf("\n\t4 - Sair do jogo sem salvar!");
            printf("\n\n\tDigite a opcao desejada: [ ]\b\b");
            scanf("%d", &opcao);

            switch(opcao) //testando qual a opção digitada pelo usuário
            {
                case 1:
                    return opcao;
                    break;
                case 2:
                    printf ("\n\n\r\t\t\t   Trocando a ordem das letras...");
                    Sleep (1200);
                    system("cls");
                    return opcao;
                    break;
                case 3:
                    printf ("\n\n\r\t\t\t   Salvando e saindo do jogo...");
                    Sleep (1200);
                    system("cls");
                    salvar.nivel=nivel;
                    salvar.pontuacao=pontuacao;
                    salvar_jogo(salvar);
                    break;
                case 4:
                    printf ("\n\n\r\t\t\t   Saindo do jogo...");
                    Sleep (1200);
                    system("cls");
                    sair();
                default:
                    nome_jogo();
                    printf("\n\n\tOpcao invalida!\n\n\tPressione enter para voltar. ");
                    getch();
                    return opcao;
                    system("cls");
            }
        } while(opcao!=1 || opcao!=2);

    return 0;
}


//-------------------------------Procedimentos----------------------------------------//

//Procedimento que trocará a ordem das palavras
void trocar_letras(char *letras, int maximo)
{
    int i=0,j;
    char aux;
    time_t seconds;
    time(&seconds);
    srand((unsigned int)seconds); //sorteia numeros sem repeticao

    while(i!=maximo)
    {
        aux=letras[i];
        j=rand() % maximo;
        letras[i]=letras[j];
        letras[j]=aux;
        i++;
    }

}

//Procedimento que apresentará as letras para o usuário jogar
void apresentar_letras(char *letra, int maximo)
{
    int i=0;
    nova_linha();
    nova_linha();
    printf("\tLetras:  ");
    nova_linha();
    nova_linha();
    printf("\t\t" );
    for(i=0; i<maximo; i++)
    {
        printf("%3c", letra[i]);
    }
    nova_linha();

}

//Procedimento que apresentará a pontuação do jogador
void apresentar_pontuacao(int pontuacao)
{
    nova_linha();
    nova_linha();
    printf("\t\t\t\t\t\tPontos:                 ");
    printf("\n\t\t\t\t\t\t.....................");
    printf("\n\t\t\t\t\t\t.                   .");
    printf("\n\t\t\t\t\t\t.   %8d        .%", pontuacao);
    printf("\n\t\t\t\t\t\t.                   .");
    printf("\n\t\t\t\t\t\t.....................");
    nova_linha();
    nova_linha();

}

//Procedimento que escreve o numero do nivel
void tela_nivel(int nivel)
{
    printf("\n                                  NIVEL %d                                  ", nivel);
    nova_linha_pont();

}

//Procedimento que apresentará as informações pro usuário
void tela_jogo1(char *letras, char palavra_acertou[10][10], int i_acertou, int pontuacao)
{

    int i, max_letras;

    system("cls");
    nome_jogo();
    tela_nivel(1);
    max_letras=8;
    apresentar_letras(letras, max_letras);
    nova_linha_pont();
    nova_linha();
    printf("\tAnagramas: ");
    nova_linha();
    printf("\nAcertou: ");
    nova_linha();
    for(i=0; i<i_acertou; i++)
    {
        printf("\n\t%12s", palavra_acertou[i]);
    }
    nova_linha();
    apresentar_pontuacao(pontuacao);
    nova_linha();
}

//Procedimento que apresentará as informações pro usuário
void tela_jogo2(char *letras, char palavra_acertou[10][10], int i_acertou, int pontuacao)
{

    int i, max_letras;

    system("cls");
    nome_jogo();
    tela_nivel(2);
    max_letras=9;
    apresentar_letras(letras, max_letras);
    nova_linha_pont();
    nova_linha();
    printf("\tAnagramas: ");
    nova_linha();
    printf("\nAcertou: ");
    nova_linha();
    for(i=0; i<i_acertou; i++)
    {
        printf("\n\t%12s", palavra_acertou[i]);
    }
    nova_linha();
    apresentar_pontuacao(pontuacao);
    nova_linha();
}

//Procedimento que apresentará as informações pro usuário
void tela_jogo3(char *letras, char palavra_acertou[16][13], int i_acertou,int pontuacao)
{

    int i, max_letras;

    system("cls");
    nome_jogo();
    tela_nivel(3);
    max_letras=12;
    apresentar_letras(letras, max_letras);
    nova_linha_pont();
    nova_linha();
    printf("\tAnagramas: ");
    nova_linha();
    printf("\nAcertou: ");
    nova_linha();
    for(i=0; i<i_acertou; i++)
    {
        printf("\n\t%12s", palavra_acertou[i]);
    }
    nova_linha();
    apresentar_pontuacao(pontuacao);
    nova_linha();
}

//Procedimento que apresentará o menu inicial do jogo
void menu()
{
    int opcao;

    int pontuacao=20;

    do
    {
        nome_jogo();
        nova_linha();
        printf("\n\t1 - Novo jogo");
        printf("\n\t2 - Continuar jogo");
        printf("\n\t3 - Instrucoes");
        printf("\n\t4 - Creditos");
        printf("\n\t5 - Sair");
        nova_linha();
        nova_linha_pont();
        nova_linha();
        printf("\tDigite a opcao desejada: [ ]\b\b");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
            	printf ("\n\n\r\t\t\t   Carregando o jogo...");
                Sleep (1200);
                system("cls");
                iniciar_jogo(&pontuacao, 1);
                break;
            case 2:
            	printf ("\n\n\r\t\t\t   Carregando o jogo...");
                Sleep (1200);
                system("cls");
                continuar_jogo();
                break;
            case 3:
                printf ("\n\n\r\t\t\t   Carregando as instrucoes...");
                Sleep (1200);
                system("cls");
                instrucoes();
                break;
            case 4:
                printf ("\n\n\r\t\t\t   Carregando os creditos...");
                Sleep (1200);
                system("cls");
                creditos();
                break;
            case 5:
                printf ("\n\n\r\t\t\t   Saindo do jogo...");
                Sleep (1200);
                system("cls");
                sair();
                break;
            default:
                nome_jogo();
                printf("\n\n\tOpcao invalida!\n\n\tPressione enter para voltar para o menu. ");
                getch();
                menu();
                system("cls");
        }

    } while (opcao>4 || opcao<1);
}

//Procedimento que será utilizado quando o jogador não passa de nível
void perdeu_jogo()
{
        int opcao;

        do
        {

            nome_jogo();
            printf("\n\tVoce nao passou para o proximo nivel!");
            nova_linha();
            nova_linha();
            printf("\n\t1 - Voltar ao menu principal");
            printf("\n\t2 - Sair do jogo");
            printf("\n\n\tDigite a opcao desejada: [ ]\b\b");
            scanf("%d", &opcao);

            switch(opcao)
            {
                case 1:
                    printf ("\n\n\r\t\t\t   Carregando o menu...");
                    Sleep (1200);
                    system("cls");
                    menu();
                    break;
                case 2:
                    printf ("\n\n\r\t\t\t   Saindo do jogo...");
                    Sleep (1200);
                    system("cls");
                    sair();
                    break;
                default:
                    nome_jogo();
                    printf("\n\n\tOpcao invalida!\n\n\tPressione enter para voltar para o menu. ");
                    getch();
                    menu();
                    system("cls");
            }
        } while(opcao!=1 || opcao!=2);
}


//Procedimento que inicia o jogo e analiza se o jogador esta cumprindo as fases
void iniciar_jogo(int *pontuacao, int continuar)
{
    //testa em que nível deve começar por conta da opção continuar
    if(continuar==1)//nivel1
    {
        tela_nivel(1);
        continuar=jogar_nivel1(pontuacao);
        if(continuar!=2)
                perdeu_jogo();

    }

    if(continuar==2)//nivel2
    {
        continuar=jogar_nivel2(pontuacao);
        if(continuar!=3)
            perdeu_jogo();
    }

    if (continuar==3)//nivel3
    {
        continuar=jogar_nivel3(pontuacao);
    }
    else
        perdeu_jogo();

    if (continuar==4)//ganhou todo o jogo
    {
        ganhou_jogo(*pontuacao);
    }
    else
        perdeu_jogo();


}

//Procedimento que mostra quando o jogador ganhou
void ganhou_jogo(int pontuacao)
{

    int opcao;
    nome_jogo();
    nova_linha();
    nova_linha();
    nova_linha_pont();
    nova_linha();
    printf("\t\t\t\t G A N H O U!");
    nova_linha();
    nova_linha_pont();
    nova_linha();
    apresentar_pontuacao(pontuacao);
    nova_linha();
    nova_linha();
    do
    {

        nova_linha();
        nova_linha();
        printf("\n\t1 - Deseja voltar ao menu principal");
        printf("\n\t2 - Sair do jogo");
        printf("\n\n\tDigite a opcao desejada: [ ]\b\b");
        scanf("%d", &opcao);

        switch(opcao) //teste de opçoes
        {
            case 1:
                    printf ("\n\n\r\t\t\t   Carregando o menu...");
                    Sleep (1200);
                    system("cls");
                    menu();
                    break;
            case 2:
                    printf ("\n\n\r\t\t\t   Saindo do jogo...");
                    Sleep (1200);
                    system("cls");
                    sair();
                    break;
            default:
                    nome_jogo();
                    printf("\n\n\tOpcao invalida!\n\n\tPressione enter para voltar para o menu. ");
                    getch();
                    menu();
                    system("cls");
            }
        } while(opcao!=1 || opcao!=2);

    sair();
}

//Procedimento que fará com que o jogador continue um jogo salvo anteriormente
void continuar_jogo()
{

    int continuar=1, pontos;
    ultimo_jogo salvo;

    nome_jogo();
    nova_linha();
    nova_linha();

    FILE *arquivo_salvar;

    arquivo_salvar=fopen("Salvar_jogo.bin","rb");

    if(arquivo_salvar==NULL)
    {
        printf("Erro na leitura do arquivo que salvou o jogo.!");
        fflush(stdin);
        getch();

        exit(1);
    }
    pontos=0;
    fseek(arquivo_salvar,0*sizeof(ultimo_jogo),SEEK_SET);
    fread(&salvo,sizeof(ultimo_jogo),1,arquivo_salvar);
    pontos=salvo.pontuacao;
    switch(salvo.nivel)
    {
        case 1:
            iniciar_jogo(&pontos,continuar);
            break;
        case 2:
            continuar=2;
            iniciar_jogo(&pontos,continuar);
            break;
        case 3:
            continuar=3;
            iniciar_jogo(&pontos,continuar);
            break;
        default:
            printf("Erro na leitura do nível.");
            sair();
    }
    fclose(arquivo_salvar);
}

//Procedimento que apresenta os creditos do jogo
void creditos()
{
    nome_jogo();
    printf("\n                                  CREDITOS                                  ");
    nova_linha_pont();
    nova_linha();
    nova_linha();
    printf("\tDesenvolvido por: \t\n\nEric Vinicius Reginaldo Rocha - 551538\nGabriela Vanessa Pereira Alves Mattos - 551570 \
            \n\n\tOrientacao: \n\nProf. Ednaldo Brigante Pizzolato.");
    nova_linha();
    nova_linha();
    printf("\n\n\n\tPressione enter para voltar para o menu. ");
    getch();
    menu();
}

//Procedimento que apresenta as instruções do jogo para o jogador
void instrucoes()
{
    nome_jogo();
    printf("\n                                  INSTRUCOES                                  ");
    nova_linha_pont();
    nova_linha();
    nova_linha();
    printf("1.OBJETIVO\n\n\tFormar o maior numero de palavras com as letras disponiveis.");
    nova_linha();
    nova_linha();
    printf("2.INSTRUCOES");
    nova_linha();
    printf("\n2.1 Como jogar\n\n\tEm cada nivel do jogo havera um conjunto de letras que deverao ser organizadas de modo que formem palavras. Essas palavras devem existir na lingua portuguesa e podem, ou não, utilizar todas as letras disponiveis.");
    nova_linha();
    printf("Ex.: Conjunto de letras: AROM\nPalavras possiveis: AMOR, ROMA, MAR , MORA, MOR.");
    nova_linha();
    printf("\n2.2 Como passar de nivel\n\n\tTodos os niveis possuem um numero minimo de palavras que devem ser formadas.");
    nova_linha();
    printf("\n2.3 Pontuacao\n\n\t A pontuacao inicial é 20 e a cada palavra formada acarreta um acrescimo de X pontos ao escore final e a cada palavra errada será subtraido Y pontos.");
    nova_linha();
    printf("\n\n\n\tPressione enter para voltar para o menu. ");
    getch();
    menu();
}

//Procedimento que irá salvar o jogo quando o usuário desejar parar
    //Salvará: o nível que está e a pontuação
void salvar_jogo(ultimo_jogo salvar)
{

    FILE *arquivo_salvar;
    arquivo_salvar=fopen("Salvar_jogo.bin","wb");

    if(arquivo_salvar==NULL)
    {
        printf("Erro ao abrir arquivo Salvar_jogo.");
        exit(1);
    }

    fseek(arquivo_salvar,0*sizeof(ultimo_jogo), SEEK_SET);
    fwrite(&salvar, sizeof(ultimo_jogo),1, arquivo_salvar);

    fclose(arquivo_salvar);
    sair();

}


//Procedimento que sai do jogo
void sair()
{
    nome_jogo();
    nova_linha();
    nova_linha();
    printf("\tObrigado por utilizar o nosso jogo!\n\n");
    exit(1);

}

//Procedimento para pular uma linha
void nova_linha()
{
    printf("\n");
}

//Procedimento para colocar linha pontilhada
void nova_linha_pont()
{

    printf("\n................................................................................");
}
//Procedimento que escreve o nome do jogo
void nome_jogo()
{
        system("cls");
        nova_linha_pont();
        printf("\n                         J O G O  D O S  A N A G R A M A S                    ");
        nova_linha_pont();
}

//---------------------------Função Principal-----------------------------------------
int main ()
{

    nome_jogo();
    nova_linha();
    nova_linha();
    printf("\t\t\t\tBEM VINDO!");
    nova_linha();
    nova_linha();
    nova_linha();
    printf("\t\t\t     Carregando o jogo...");
    Sleep(1200);
    menu();
    return (0);
}

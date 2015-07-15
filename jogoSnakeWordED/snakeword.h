
#include "Lista.h"

#include <string>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#pragma once
#ifndef SNAKEWORD_H
#define SNAKEWORD_H
#define quantMax 10 //quantidade maxima de palavras no arquivo

class SnakeWord
{
    private:
        Lista *cobra;
        string palavra_sorteada;
        int nivel;
        int pontuacao;

    public:

        SnakeWord();

        ~SnakeWord();

        void setNivel(int);

        int getNivel();

        int quantLetras();

        void setPalavra_sorteada(string);

        string getPalavra_sorteada();

        void setPontuacao(int);

        int getPontuacao();

        int iniciarAllegro();

        void mostrarPalavra();

        char LetraPalavra(int);

        void IniciarJogo();

        int Pause();

        void EscolherNivel();

        void InstrucoesJogo();

        void SairJogo(int);

        void menu();

        void SorteiaPalavra();//metodo que vai sortear a palavra a partir do arquivo de cada nivel (o parametro será o nivel)

        char SorteiaLetra();

        Node* SorteiaElementos(char); //metodo que sorteia as letras que deverão aparecer para a cobrinha comer

        void CriarCobrinha();

        bool DesenhaQuadrado(int , int, ALLEGRO_BITMAP* );

        bool colisaoCobra();

        bool colisaoCantos(Node*);

        int ColisaoNode(Lista);

        void AtualizarPontuacao(int );//condições de pontuação

        void AtualizarCobrinha(Lista);

        void EscreveCaminho (char*, char);

        void FinalizarAllegro();
};
#endif

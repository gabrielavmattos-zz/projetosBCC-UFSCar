#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Arvore.h"
#include "Node.h"

#pragma once
#ifndef JOGO_ADIVINHACAO_H
#define JOGO_ADIVINHACAO_H

class Jogo_Adivinhacao
{
    private:

	Arvore *numeros;
	int quantidade;

    public:

        Jogo_Adivinhacao();

        ~Jogo_Adivinhacao();

        void setQuant(int);

        int getQuant();

        int iniciarAllegro();

	    void TelaPensou();

        void IniciarJogo();

        void Resposta(Node*);

        void Tabela1(Node*, Node*);

        void Tabela2(Node*,  Node*);

        void Tabela3(Node*, Node*);

        void Tabela4(Node*, Node*);

        void Tabela5(Node*);

        int Pause();

        void InstrucoesJogo();

        void SairJogo(int);

        void menu();

        void MostrarNumero(Node*);

        void CriarArvore();

        void FinalizarAllegro();



        Node* LogicaJogo(Node*, Node*);   ///i nao tera valores alterados na funçao, mas qtdeposicaoesquerda sera alterado

};



#endif // JOGOADIVINHACAO_H_INCLUDED




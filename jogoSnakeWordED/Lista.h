#include "Node.h"
#pragma once
#ifndef LISTA_H
#define LISTA_H

using namespace std;

class Lista
{
    private:

        Node *Inicio, *Atual, *Final;

    public:
        Lista();
        ~Lista();

        void setInicio(Node*);
        Node* getInicio();
        void setAtual(Node*);
        Node* getAtual();
        void setFinal(Node*);
        Node* getFinal();

        Node* CriaNode(Node&);
        bool Vazia();
        bool Inserir(Node*);
        bool Retirar(Node*);
        bool PegaOPrimeiro(Node*);
        bool PegaOProximo(Node*);
        bool PegaOAnterior(Node*);
        bool PegaOUltimo(Node*);
        bool DestroiLista();
        bool EstaNaLista(char, Node*);
};

#endif



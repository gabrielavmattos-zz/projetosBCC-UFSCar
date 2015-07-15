#include "Node.h"
#pragma once
#ifndef ARVORE_H
#define	ARVORE_H

class Arvore {
    private:

        Node *Inicio, *Atual;
        bool mudouAltura;

    public:
        Arvore();
        ~Arvore();

        void setInicio(Node*);
        Node* getInicio();
        void setAtual(Node*);
        Node* getAtual();
        void setMudouAltura(bool);
        bool getMudouAltura();
        Node* CriaNode(Node&);
        bool Vazia();
        Node* Inserir(Node*, int);
        bool PegaOPrimeiro(Node*);
        bool PegaOEsquerdo(Node*);
        bool PegaODireito(Node*);
        Node* RebalancearEE(Node*);
        Node* RebalancearDD(Node*);
        Node* RebalancearED(Node*);
        Node* RebalancearDE(Node*);
        void RemoverTodos(Node*);
};

#endif	/* ARVORE_H */

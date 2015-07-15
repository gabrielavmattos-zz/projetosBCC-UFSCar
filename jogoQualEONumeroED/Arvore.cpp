#include "Arvore.h"

#include <iostream>

using namespace std;


Arvore::Arvore()
{
    Inicio=NULL;
    Atual=NULL;
    mudouAltura=true;
}

Arvore::~Arvore()
{}

void Arvore::setInicio(Node* Inicio)
{
    this->Inicio=Inicio;
}

Node* Arvore::getInicio()
{
    return(this->Inicio);
}

void Arvore::setAtual(Node* Atual)
{
    this->Atual=Atual;
}

Node* Arvore::getAtual()
{
    return(this->Atual);
}

void Arvore::setMudouAltura(bool mudouAltura)
{
    this->mudouAltura=mudouAltura;
}

bool Arvore::getMudouAltura()
{
    return(this->mudouAltura);
}

bool Arvore::Vazia()
{
    if (this->Inicio==NULL)
        return true;

    return false;
}

Node* Arvore::CriaNode(Node& PAux)
{
	Node *nodePtr;
	nodePtr= new Node(PAux);

	nodePtr->setEsq(NULL);
	nodePtr->setDir(NULL);
        nodePtr->setBal(0);

	return nodePtr;
}

Node* Arvore::Inserir(Node* R, int X){
    Node *Filho, *P;
    P = new Node;

    if(R==NULL)
    {

        P = CriaNode(*P);
        P->setInfo(X);
        R = P;

        if (getInicio() == NULL)
        {
            setInicio(P);
        }
        P = NULL;
        setMudouAltura(true);

        return R;

    }else{
           if(X == R->getInfo())
           {
               setMudouAltura(false);
               return R;
           }else{
                  if(R->getInfo() > X)
                  {
                      Filho = Inserir(R->esq, X);      ///como passa os parametros??
                      R->esq = Filho;
                      if(getMudouAltura())
                      {
                         switch(R->getBal())
                         {
                         case 1:
                            R->setBal(0);
                            setMudouAltura(false);
                         break;

                         case 0:
                             R->setBal(-1);
                         break;

                         case -1:
                            if(Filho->getBal() == 1)   ///Rotacao Dupla ED Insere
                                R = RebalancearED(R);
                            else
                                R = RebalancearEE(R);
                            setMudouAltura(false);
                            break;
                         }
                      }
                  }

                      else{
                        Filho = Inserir(R->dir, X);
			R->dir = Filho;
                        if(getMudouAltura())
                        {
                          switch(R->getBal())
                          {
                          case -1:
                            R->setBal(0);
                            setMudouAltura(false);
                            break;

                          case 0:
                            R->setBal(1);
                            break;

                          case 1:
                            if(Filho->getBal() == -1)   ///Rotacao Dupla DE Insere
                                R = RebalancearDE(R);
                            else
                                R = RebalancearDD(R);
                            setMudouAltura(false);
                            break;
                          }
                      }
                  }
	    	return R;
           	}
    }
}


bool Arvore::PegaOPrimeiro(Node* PAux)
{
    Node Aux;

    if(!Vazia())
    {
        setAtual(getInicio());
        Aux = *getAtual();
        *PAux = Aux;
        return true;
    }

    return false;
}

bool Arvore::PegaOEsquerdo(Node* PAux)
{
    Node aux;

    if(this->Atual!=NULL)
    {
        //if(this->Atual->getDir()!=this->Inicio)
        //{
        setAtual(this->Atual->esq);
        aux=*this->Atual;
        *PAux=aux;
        return true;

        //}

    }
    return false;

}

bool Arvore::PegaODireito(Node* PAux)
{
    Node aux;

    if(this->Atual!=NULL)
    {
        //if(this->Atual->getEsq()!=this->Inicio)
        //{
        setAtual(this->Atual->dir);
        aux=*this->Atual;
        *PAux=aux;
        return true;

        //}

    }

    return false;
}

Node* Arvore::RebalancearEE(Node* R)
{
    Node* Filho;

    Filho = R->getEsq();
    R->setEsq(Filho->getDir());
    Filho->setDir(R);

    R->setBal(0);
    Filho->setBal(0);
    if (this->Inicio == R){
        R = Filho;
        setInicio(R);
    }
    else
        R = Filho;

	return R;
}

Node* Arvore::RebalancearDD(Node* R)
{
    Node* Filho;

    Filho = R->getDir();
    R->setDir(Filho->getEsq());
    Filho->setEsq(R);
    R->setBal(0);
    Filho->setBal(0);
    if (this->Inicio == R)
    {
        R = Filho;
        setInicio(R);
    }
    else
        R = Filho;

	return R;
}

Node* Arvore::RebalancearED(Node* R)
{
    Node* Filho;
    Node* Neto;

    Filho = R->getEsq();
    Neto = Filho->getDir();
    Filho->setDir(Neto->getEsq());
    Neto->setEsq(Filho);
    R->setEsq(Neto->getDir());
    Neto->setDir(R);

    switch(Neto->getBal())
    {
        case -1:
                R->setBal(1);
                Filho->setBal(0);
                Neto->setBal(0);
        break;

        case 1:
                R->setBal(0);
                Filho->setBal(-1);
                Neto->setBal(0);
        break;

        case 0:
                R->setBal(0);
                Filho->setBal(0);
                Neto->setBal(0);
        break;
        }

    if (this->Inicio == R){
        R = Neto;
        setInicio(R);
    }
    else
        R = Neto;

	return R;
}

Node* Arvore::RebalancearDE(Node* R)
{
    Node* Filho;
    Node* Neto;

    Filho = R->getDir();
    Neto = Filho->getEsq();
    Filho->setEsq(Neto->getDir());
    Neto->setDir(Filho);
    R->setDir(Neto->getEsq());
    Neto->setEsq(R);

    switch(Neto->getBal())
    {
        case -1:
                R->setBal(0);
                Filho->setBal(1);
                Neto->setBal(0);
        break;

        case 1:
                R->setBal(-1);
                Filho->setBal(0);
                Neto->setBal(0);
        break;

        case 0:
                R->setBal(0);
                Filho->setBal(0);
                Neto->setBal(0);
        break;
    }

    if (this->Inicio == R){
        R = Neto;
        setInicio(R);
    }
    else
        R = Neto;

	return R;
}

void Arvore::RemoverTodos(Node* R)
{
    if(!Vazia())
    {

        if(R->getEsq()==NULL && R->getDir()==NULL && R!=NULL)
            R=NULL;
        else
        {
                RemoverTodos(R->getEsq());
                RemoverTodos(R->getDir());
        }

    }
}


#include "Lista.h"

#include <iostream>

using namespace std;


Lista::Lista()
{
    Inicio=0;
    Atual=0;
    Final=0;
}

Lista::~Lista()
{}

void Lista::setInicio(Node* inicio)
{
    Node aux;
    aux = *inicio;
    *Inicio = aux;

}

Node* Lista::getInicio()
{
    return(this->Inicio);
}

void Lista::setAtual(Node* atual)
{
    this->Atual=atual;
}

Node* Lista::getAtual()
{
    return(this->Atual);
}

void Lista::setFinal(Node* fim)
{
    Node aux;
    aux = *fim;
    *Final = aux;
}

Node* Lista::getFinal()
{
    return(this->Final);
}

bool Lista::Vazia()
{
    if (this->Inicio==0)
        return true;

    return false;
}

Node* Lista::CriaNode(Node& PAux)
{
	Node *nodePtr;
	nodePtr= new Node(PAux);

	nodePtr->setEsq(NULL);
	nodePtr->setDir(NULL);

	return nodePtr;
}

bool Lista::Inserir(Node* PAux)
{

    Node *nodePtr;

    if(Vazia())
    {
        this->Inicio=CriaNode(*PAux);
        this->Inicio->setEsq(NULL);
        this->Inicio->setDir(NULL);
        this->Final=this->Inicio;

        return true;
    }
    else
    {

        nodePtr = CriaNode(*PAux);
        nodePtr->setEsq(Final);
        nodePtr->setDir(NULL);

        this->Final->setDir(nodePtr);
        this->Final=nodePtr;


       /* if(this->Inicio==this->Final)  //quando tem apenas um elemento
        {
            this->Inicio->setDir(nodePtr);
            this->Final = nodePtr;
            this->Final->setDir(NULL);
        }
        else
        {
            this->Final->setDir(nodePtr);
            this->Final = nodePtr;
            this->Final->setDir(NULL);
       // }*/

        return true;
    }

    return false;
}

bool Lista::Retirar(Node* PAux)
{

    Node *nodePtr, aux;
    nodePtr = new Node();
    aux = *PAux;

    if(Vazia() || PAux==NULL)
        return false;
    else
    {

        if (PegaOPrimeiro(nodePtr))
        {

            if (*nodePtr == aux)
            {
				aux = *nodePtr;
				*PAux = aux;

				nodePtr = this->Inicio;

                if(this->Inicio==this->Final)
                {
                    this->Inicio=NULL;
                    this->Final = NULL;
                    this->Atual =NULL;

                }
                else
                {
                    this->Inicio = this->Inicio->getDir();
                    this->Atual=NULL;
                    this->Final->setDir(NULL);
                    this->Inicio->setEsq(NULL);
                }

				delete nodePtr;
				return true;
            }
            else
            {

                PegaOPrimeiro(nodePtr);
                while (PegaOProximo(nodePtr))
                {

                    if (*nodePtr == aux)
                    {

                        aux = *nodePtr;
                        *PAux = aux;

                        if (Atual->getDir() == NULL) //é o último elemento
                        {

							nodePtr = Atual->getEsq();
                         	nodePtr->setDir(NULL);
                         	Final = nodePtr;

                        }
                        else //está no  meio da lista
                        {
                            nodePtr = Atual->getEsq();
               				nodePtr->setDir(Atual->getDir());
							nodePtr = nodePtr->getDir();
							nodePtr->setEsq(Atual->getEsq());
                        }

						nodePtr = Atual;
						Atual = Inicio;

						delete nodePtr;
						return true;
                    }

                }

            return false;
            }

    }
    }
}


bool Lista::PegaOPrimeiro(Node* PAux)
{
    Node Aux;

    if(!Vazia())
    {
        setAtual(getInicio());
        Aux = *getAtual();
        *PAux = Aux;
        return  true;
    }

    return false;
}

bool Lista::PegaOProximo(Node* PAux)
{
    Node aux;
    if(this->Atual!=NULL)
    {
        if(Atual->getDir() == NULL)
                return false;
        else
        {
           setAtual(this->Atual->getDir());
           aux=*Atual;
           *PAux=aux;
          return true;
        }
    }

    return false;

}

bool Lista::PegaOAnterior(Node* PAux)
{
    Node aux;

    if(this->Atual!=NULL)
    {
        if(Atual->getEsq() == this->Inicio)
            return false;
        else
        {

          setAtual(this->Atual->getEsq());
          aux = *Atual;
          *PAux = aux;
          return true;
        }
    }

    return false;
}

bool Lista::PegaOUltimo(Node* PAux)
{
    Node Aux;

    if(!Vazia())
    {
        setAtual(getFinal());
        Aux = *getAtual();
        *PAux = Aux;
        return  true;
    }

    return false;
}

bool Lista::DestroiLista()
{
    Node *Aux = new Node();

    while (PegaOPrimeiro(Aux))
        Retirar(Aux);

    if(Vazia())
        return true;
    else
        return false;


}
bool Lista::EstaNaLista(char letra, Node* Aux)
{
    Node aux;
    bool continua;
    continua=PegaOPrimeiro(Aux);

    while (Aux->getInfo()!=letra && continua)
    {
        continua=PegaOProximo(Aux);
    }

    if (continua)
        return true;
    else
        return false;
}

#pragma once

#include "Node.h"
#include <iostream>

using namespace std;

Node::Node()
{
    esq = NULL;
    dir = NULL;
}

Node::Node(int _info, int _bal)
{

    setInfo(_info);
    setBal(_bal);

   // esq = NULL;
   // dir = NULL;

}

Node::~Node()
{}

void Node::setInfo(int _info)
{
    this->info = _info;
}

int Node::getInfo()
{
    return (this->info);
}

void Node::setBal(int _bal)
{
    this->bal = _bal;
}

int Node::getBal()
{
    return (this->bal);
}

void Node::setEsq(Node* _esq)
{
    this->esq=_esq;
}

Node* Node::getEsq()
{
    return(this->esq);
}


void Node::setDir(Node* _dir)
{
    this->dir=_dir;
}

Node* Node::getDir()
{
    return(this->dir);
}

Node& Node::operator=(Node& _node)
{
    setInfo(_node.getInfo());
    setBal(_node.getBal());

    setEsq(_node.getEsq());
    setDir(_node.getDir());

	return (*this);
}

bool Node::operator==(Node& _node)
{
    int info = _node.getInfo();
    int bal = _node.getBal();

    if(this->info==info && this->bal==bal)
        return true;
    return false;
}








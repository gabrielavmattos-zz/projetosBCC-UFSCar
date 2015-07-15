#pragma once

#include "Node.h"
#include <iostream>

using namespace std;

Node::Node()
{
    esq = NULL;
    dir = NULL;
}

Node::Node(int _posInicialX, int _posInicialY, int _posFinalX, int _posFinalY, char _info)
{
    setPosInicialX(_posInicialX);
    setPosInicialY(_posInicialY);
    setPosFinalX(_posFinalX);
    setPosFinalY(_posFinalY);
    setInfo(_info);

    esq = NULL;
    dir = NULL;

}

Node::~Node()
{}

void Node::setInfo(char _info)
{
    this->info = _info;
}

char Node::getInfo()
{
    return (this->info);
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

void Node::setPosInicialX(int _posInicialX)
{
    this->posInicialX = _posInicialX;

}

int Node::getPosInicialX()
{
    return (this->posInicialX);
}

void Node::setPosInicialY(int _posInicialY)
{
    this->posInicialY = _posInicialY;
}

int Node::getPosInicialY()
{
    return (this->posInicialY);
}

void Node::setPosFinalX(int _posFinalX)
{
    this->posFinalX = _posFinalX;
}

int Node::getPosFinalX()
{
    return (this->posFinalX);
}

void Node::setPosFinalY(int _posFinalY)
{
    this->posFinalY = _posFinalY;
}

int Node::getPosFinalY()
{
    return (this->posFinalY);
}

Node& Node::operator=(Node& _node)
{

	setPosInicialX(_node.getPosInicialX());
	setPosInicialY(_node.getPosInicialY());
	setPosFinalX(_node.getPosFinalX());
	setPosFinalY(_node.getPosFinalY());
    setInfo(_node.getInfo());

    setEsq(_node.getEsq());
    setDir(_node.getDir());

	return (*this);
}

bool Node::operator==(Node& _node)
{
    int posX=_node.getPosInicialX();
    int posY=_node.getPosInicialY();
    char info= _node.getInfo();

    if(this->posInicialX==posX && this->posInicialY==posY && this->info==info)
        return true;
    return false;
}








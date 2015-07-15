#pragma once

class Node
{

public:

	int posInicialX,posInicialY,posFinalX,posFinalY;
	char info;
	Node *esq, *dir;

public:
	Node();
	Node (int, int, int, int, char);
	~Node();

	void setInfo(char);
	char getInfo();
    void setEsq(Node*);
    Node* getEsq();
    void setDir(Node*);
    Node* getDir();
	void setPosInicialX(int);
    int getPosInicialX();
    void setPosInicialY(int);
    int getPosInicialY();
    void setPosFinalX(int);
    int getPosFinalX();
    void setPosFinalY(int);
    int getPosFinalY();
    Node& operator=(Node&);
    bool operator== (Node&);
};


#pragma once

class Node
{

public:

	int info, bal;
	Node *esq, *dir;

public:
	Node();
	Node (int, int);
	~Node();

    void setInfo(int);
    int getInfo();
    void setBal(int);
    int getBal();
    void setEsq(Node*);
    Node* getEsq();
    void setDir(Node*);
    Node* getDir();
    Node& operator=(Node&);
    bool operator== (Node&);
};


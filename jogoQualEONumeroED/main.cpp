#include "jogo_adivinhacao.h"
#include <iostream>

using namespace std;

int main(void)
{
    int erros=0;

    Jogo_Adivinhacao *jogo = new Jogo_Adivinhacao;

    erros=jogo->iniciarAllegro();

    if(erros!=0)
    {
        cout << "Erro de número: " << erros << endl;
        jogo->FinalizarAllegro();
        return -1;
    }

    jogo->menu();
    jogo->FinalizarAllegro();
    delete jogo;
    return 0;
}

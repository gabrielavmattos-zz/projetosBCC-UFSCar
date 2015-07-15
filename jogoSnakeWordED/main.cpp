#include "snakeword.h"
#include <iostream>

int main(void)
{
    int erros=0;

    SnakeWord *snake = new SnakeWord;

    erros=snake->iniciarAllegro();

    if(erros!=0)
    {
        cout << "Erro de número: " << erros << endl;
        snake->FinalizarAllegro();
        return -1;
    }

    snake->menu();
    snake->FinalizarAllegro();
    delete snake;
    //system("PAUSE");
    return 0;
}

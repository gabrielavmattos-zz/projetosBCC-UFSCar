#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <ctime>

//Cabeçalhos do allegro:

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

//Constantes utilizadas:
#define largura_tela 960
#define altura_tela 720
#define limite_largura_inferior 60
#define limite_largura_superior 910
#define limite_altura_inferior 109
#define limite_altura_superior 558
#define centro_cobraX 390
#define centro_cobraY 300
#define tempo 0.2


#include "snakeword.h"
//INICIO - criação das classes utilizadas do allegro

ALLEGRO_DISPLAY *janela = NULL; //variavel representando a janela principal

ALLEGRO_BITMAP *tela_inicial = NULL, *tela_padrao = NULL, *tela_instrucoes = NULL, *tela_instrucoes2 = NULL, *tela_sair = NULL; //telas

ALLEGRO_BITMAP *tela_pontuacao = NULL, *tela_pontuacao1 = NULL, *tela_pontuacao2 = NULL;

ALLEGRO_BITMAP *tela_nivel = NULL, *tela_nivel1 = NULL, *tela_nivel2 = NULL, *tela_nivel3 = NULL;

ALLEGRO_BITMAP *botao_jogar_press = NULL,  *botao_instrucoes_press = NULL, *botao_sair_press; //variavel para os botões

ALLEGRO_BITMAP *q0 = NULL, *a = NULL , *q1 = NULL;

ALLEGRO_BITMAP *icone = NULL;

ALLEGRO_EVENT_QUEUE *fila_eventos = NULL; // variavel dos eventos

ALLEGRO_EVENT evento;

ALLEGRO_TIMER *timer = NULL, *timerA = NULL;

ALLEGRO_FONT *fonte = NULL;

//FIM

using namespace std;




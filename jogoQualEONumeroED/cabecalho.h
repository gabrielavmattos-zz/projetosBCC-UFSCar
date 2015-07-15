#ifndef CABECALHO_H
#define CABECALHO_H
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Arvore.h"
#include "Node.h"

//Cabeçalhos do allegro:

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

//Constantes utilizadas:
#define largura_tela 1120
#define altura_tela 700
#define limite_largura_inferior 50
#define limite_largura_superior 920
#define limite_altura_inferior 110
#define limite_altura_superior 530
#define tempo 0.5

#include "jogo_adivinhacao.h"
//INICIO - criação das classes utilizadas do allegro

ALLEGRO_DISPLAY *janela = NULL; //variavel representando a janela principal

ALLEGRO_BITMAP *tela_inicial = NULL, *tela_padrao = NULL, *tela_sair = NULL; //telas

ALLEGRO_BITMAP *botao_iniciar_press = NULL,  *botao_instrucoes_press = NULL, *botao_sair_press=NULL; //variavel para os botões

ALLEGRO_BITMAP *tela_instrucoes = NULL, *tela_instrucoesvoltar = NULL, *tela_jogo = NULL, *tela_tabela1 = NULL, *tela_tabela1selsim = NULL, *tela_tabela1selnao = NULL, *tela_tabela2 = NULL, *tela_tabela2selsim = NULL, *tela_tabela2selnao = NULL;

ALLEGRO_BITMAP *tela_tabela3 = NULL, *tela_tabela3selsim = NULL, *tela_tabela3selnao = NULL, *tela_tabela4 = NULL, *tela_tabela4selsim = NULL, *tela_tabela4selnao = NULL;

ALLEGRO_BITMAP *tela_tabela5 = NULL, *tela_tabela5selsim = NULL, *tela_tabela5selnao = NULL, *tela_final = NULL, *tela_finalmenu = NULL, *tela_finalsair = NULL;


ALLEGRO_BITMAP *q0 = NULL, *a = NULL , *q1=NULL, *Desenvolvedores, *fundo, *Pensou, *PensouAvancar;

ALLEGRO_EVENT_QUEUE *fila_eventos = NULL; // variavel dos eventos

ALLEGRO_EVENT evento;

ALLEGRO_FONT *fonte = NULL;

//FIM

using namespace std;








#endif // CABECALHO_H_INCLUDED

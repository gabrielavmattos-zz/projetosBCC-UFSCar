#pragma once
#include <iostream>

#include "cabecalho.h"

//Como nao achei o node e o arvore lá no cabecalho, coloquei aqui
#include "Node.h"
#include "Arvore.h"
#include "string.h"

using namespace std;


         Jogo_Adivinhacao::Jogo_Adivinhacao()
        {
            numeros = new Arvore;
            quantidade = 0;

        }

        Jogo_Adivinhacao::~Jogo_Adivinhacao()
        {
		delete numeros;
        }

        void Jogo_Adivinhacao::setQuant(int quant)
        {
            this->quantidade=quant;
        }

        int Jogo_Adivinhacao::getQuant()
        {
            return this->quantidade;


        }
        int Jogo_Adivinhacao::iniciarAllegro()
        {

            if (!al_init()) //inicializando o allegro
                return 1;

            if (!al_init_image_addon())
                return 2;

            if (!al_install_keyboard())
                return 3;

            janela = al_create_display(largura_tela, altura_tela); //criando a janela
            tela_inicial = al_load_bitmap("imagens/tela_inicial.jpg");
            al_draw_bitmap(tela_inicial, 0, 0, 0);
            al_flip_display();
            //al_rest(10.0);

            if (!janela)
                return 4;

            fila_eventos = al_create_event_queue();

            if (!fila_eventos)
                return 5;

            botao_iniciar_press=al_load_bitmap("imagens/inicial-selecao-iniciar.jpg");
            botao_instrucoes_press=al_load_bitmap("imagens/inicial-selecao-instrucoes.jpg");
            botao_sair_press=al_load_bitmap("imagens/inicial-selecao-sair.jpg");

            tela_instrucoes=al_load_bitmap("imagens/tela-jogo-instrucoes.jpg");
            tela_instrucoesvoltar=al_load_bitmap("imagens/tela-jogo-instrucoes-selvoltar.jpg");
            tela_jogo=al_load_bitmap("imagens/tela-jogo-tabela.jpg");

            tela_tabela1=al_load_bitmap("imagens/tela-jogo-tabela1simnao.jpg");
            tela_tabela1selsim=al_load_bitmap("imagens/tela-jogo-tabela1simnao-selsim.jpg");
            tela_tabela1selnao=al_load_bitmap("imagens/tela-jogo-tabela1simnao-selnao.jpg");

            tela_tabela2=al_load_bitmap("imagens/tela-jogo-tabela2simnao.jpg");
            tela_tabela2selsim=al_load_bitmap("imagens/tela-jogo-tabela2simnao-selsim.jpg");
            tela_tabela2selnao=al_load_bitmap("imagens/tela-jogo-tabela2simnao-selnao.jpg");

            tela_tabela3=al_load_bitmap("imagens/tela-jogo-tabela3simnao.jpg");
            tela_tabela3selsim=al_load_bitmap("imagens/tela-jogo-tabela3simnao-selsim.jpg");
            tela_tabela3selnao=al_load_bitmap("imagens/tela-jogo-tabela3simnao-selnao.jpg");

            tela_tabela4=al_load_bitmap("imagens/tela-jogo-tabela4simnao.jpg");
            tela_tabela4selsim=al_load_bitmap("imagens/tela-jogo-tabela4simnao-selsim.jpg");
            tela_tabela4selnao=al_load_bitmap("imagens/tela-jogo-tabela4simnao-selnao.jpg");

            tela_tabela5=al_load_bitmap("imagens/tela-jogo-tabela5simnao.jpg");
            tela_tabela5selsim=al_load_bitmap("imagens/tela-jogo-tabela5simnao-selsim.jpg");
            tela_tabela5selnao=al_load_bitmap("imagens/tela-jogo-tabela5simnao-selnao.jpg");

            tela_final=al_load_bitmap("imagens/tela-jogo-final.jpg");
            tela_finalmenu=al_load_bitmap("imagens/tela-jogo-final-selmenu.jpg");
            tela_finalsair=al_load_bitmap("imagens/tela-jogo-final-selsair.jpg");

            Desenvolvedores = al_load_bitmap("imagens/tela-jogo-Desenvolvedores.jpg");

            Pensou = al_load_bitmap("imagens/tela-jogo-Pensou.jpg");

            PensouAvancar = al_load_bitmap("imagens/tela-jogo-Pensou-selavancar.jpg");

            fundo = al_load_bitmap("imagens/fundo.png");


            if(!tela_inicial || !botao_instrucoes_press || !botao_iniciar_press || !botao_sair_press || !tela_instrucoes
              || !tela_instrucoesvoltar || !tela_jogo || !tela_tabela1 || !tela_tabela1selsim || !tela_tabela1selnao || !Pensou
              || !tela_tabela2 || !tela_tabela2selsim || !tela_tabela2selnao || !tela_tabela3 || !tela_tabela3selsim || !PensouAvancar ||
              !tela_tabela3selnao || !tela_tabela4 || !tela_tabela4selsim || !tela_tabela4selnao || !tela_tabela5   || !fundo
              || !tela_tabela5selsim || !tela_tabela5selnao || !tela_final || !tela_finalmenu || !tela_finalsair || !Desenvolvedores)
            return 6;





            if(!al_install_mouse())
                return 7;

            if(!al_set_system_mouse_cursor(janela,ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK))
                return 8;

            al_init_font_addon();


            if(!al_init_ttf_addon())
                return 10;

            fonte = al_load_font("comic.ttf", 48,0);

            if(!fonte)
                return 11;


            al_register_event_source(fila_eventos,al_get_mouse_event_source());
            al_register_event_source(fila_eventos, al_get_display_event_source(janela));


            return 0;
        }

        void Jogo_Adivinhacao::MostrarNumero(Node *aux)
        {

                char buffer[3];
                int c;
                if(quantidade==5) //quando aperta não em tudo
                    c=0;
                else
                 {c = aux->getInfo();
                  sprintf(buffer,"%d",c);
                  al_draw_textf(fonte, al_map_rgb(255,255,255),491, 256,ALLEGRO_ALIGN_CENTRE,buffer);
                 }
                if(c==0)
                  {
                    fundo = al_load_bitmap("imagens/fundo.png");
                    al_draw_bitmap(fundo,220,8,0);
                    al_flip_display();

                   //al_draw_textf(fonte, al_map_rgb(255,255,255),168, 50,ALLEGRO_ALIGN_CENTRE,frase);
                  }

        }

        void Jogo_Adivinhacao::InstrucoesJogo()
        {
                bool  sair=false;
                al_draw_bitmap(tela_instrucoes,0,0,0);
                al_flip_display();

                while (!sair) //evento de apertar o botão de sair
                {

                  al_wait_for_event(fila_eventos, &evento);

                  if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                    {
                            SairJogo(0);
                            sair=true;
                    }
                  else
                    if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) //evento de movimentação do mouse
                    {
                                if (evento.mouse.x >= 804 && evento.mouse.x <= 954 && evento.mouse.y >= 541 && evento.mouse.y <= 582)
                          //      pelo botão instruções
                                {

                                    al_draw_bitmap(tela_instrucoesvoltar,0,0,0);
                                    al_flip_display();
                                }
                                else
                                {

                                    al_draw_bitmap(tela_instrucoes,0,0,0);
                                    al_flip_display();

                                }



                    }
                    else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                        {
                            if(evento.mouse.x >= 804 && evento.mouse.x <= 954 && evento.mouse.y >= 541 && evento.mouse.y <= 582)
                       //       botão jogar caso ele clique
                            {
                                al_draw_bitmap(tela_instrucoesvoltar,0,0,0);
                                al_flip_display();
                                menu();
                                sair=true;
                            }
                            else
                            {
                                    al_draw_bitmap(tela_instrucoes,0,0,0);
                                    al_flip_display();

                            }
                        }
                    }


            }



        void Jogo_Adivinhacao::TelaPensou()
         {
            bool sair=false;

            al_draw_bitmap(Pensou,0,0,0);
            al_flip_display();

            while (!sair) //evento de apertar o botão de sair
            {

              al_wait_for_event(fila_eventos, &evento);

              if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                {
                        al_destroy_event_queue(fila_eventos);
                        SairJogo(0);
                        sair=true;
                }
                else
                if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) //evento de movimentação do mouse
                {
				// Verificamos se ele está sobre a região do retângulo central
                        if (evento.mouse.x >= 842 && evento.mouse.x <= 983 && evento.mouse.y >= 555 && evento.mouse.y <= 600)
 				// quando passa pelo botão Avançar
                        {
                            al_draw_bitmap(PensouAvancar,0,0,0);
                            al_flip_display();
                        }
                        else
                        {
                                        al_draw_bitmap(Pensou,0,0,0);
                                        al_flip_display();
                        }
                    }
                    else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                    {
                        if(evento.mouse.x >= 842 && evento.mouse.x <= 983 && evento.mouse.y >= 555 && evento.mouse.y <= 600)
                       //   caso seja detectado clique no botão avançar
                        {
                            al_draw_bitmap(PensouAvancar,0,0,0);
                            al_flip_display();
                            IniciarJogo();
                            sair=true;
                        }
                        else
                        {
                                        al_draw_bitmap(Pensou,0,0,0);
                                        al_flip_display();
                        }

                   }


            }
        }


        void Jogo_Adivinhacao::menu()
        {
            bool sair=false;

            al_draw_bitmap(tela_inicial,0,0,0);
            al_flip_display();

            while (!sair) //evento de apertar o botão de sair
            {

              al_wait_for_event(fila_eventos, &evento);

              if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                {
                        al_destroy_event_queue(fila_eventos);
                        SairJogo(0);
                        sair=true;
                }
                else
                if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) //evento de movimentação do mouse
                {
				// Verificamos se ele está sobre a região do retângulo central
                        if (evento.mouse.x >= 788 && evento.mouse.x <= 962 && evento.mouse.y >= 97 && evento.mouse.y <= 128)
 				// quando passa pelo botão iniciar
                        {
                            al_draw_bitmap(botao_iniciar_press,0,0,0);
                            al_flip_display();
                        }
                        else
                            if (evento.mouse.x >= 788 && evento.mouse.x <= 1050 && evento.mouse.y >= 145 && evento.mouse.y <=185 )
    				    // pelo botão instruções
                            {
                                al_draw_bitmap(botao_instrucoes_press,0,0,0);
                                al_flip_display();
                            }
                            else
                                if (evento.mouse.x >= 788 && evento.mouse.x <= 918 && evento.mouse.y >= 205 && evento.mouse.y <= 235)
                              //  pelo botão sair
                                {
                                    al_draw_bitmap(botao_sair_press,0,0,0);
                                    al_flip_display();
                                }
                                else
                                {
                                        al_draw_bitmap(tela_inicial,0,0,0);
                                        al_flip_display();
                                }
                    }
                    else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                    {
                        if(evento.mouse.x >= 788 && evento.mouse.x <= 962 && evento.mouse.y >= 97 && evento.mouse.y <= 128)
                       //   caso seja detectado clique no botão iniciar
                        {
                            al_draw_bitmap(botao_iniciar_press,0,0,0);
                            al_flip_display();
                            TelaPensou();
                            sair=true;
                        }
                        else
                            if (evento.mouse.x >= 788 && evento.mouse.x <= 1050 && evento.mouse.y >= 145 && evento.mouse.y <= 185)
                         //   pelo botão instruções
                            {
                                al_draw_bitmap(botao_instrucoes_press,0,0,0);
                                al_flip_display();
                                InstrucoesJogo();
                                sair=true;
                            }
                            else
                                if (evento.mouse.x >= 788 && evento.mouse.x <= 918 && evento.mouse.y >= 205 && evento.mouse.y <= 235)
                           //     pelo botão sair
                                {
                                    al_draw_bitmap(botao_sair_press,0,0,0);
                                    al_flip_display();
                                    SairJogo(0);
                                    sair=true;
                                }
                                else
                                {
                                        al_draw_bitmap(tela_inicial,0,0,0);
                                        al_flip_display();
                                }

                   }


            }
        }

        void Jogo_Adivinhacao::Resposta(Node *aux)
        {
            bool sair=false;

                    al_draw_bitmap(tela_final,0,0,0);
                    MostrarNumero(aux);
                    al_flip_display();

                    while (!sair) //evento de apertar o botão de sair
                    {

                      al_wait_for_event(fila_eventos, &evento);

                      if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                        {
                                al_destroy_event_queue(fila_eventos);
                                SairJogo(0);
                                sair=true;
                        }
                        else
                        if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) //evento de movimentação do mouse
                        {
                        // Verificamos se ele está sobre a região do retângulo central
                                if (evento.mouse.x >= 834 && evento.mouse.x <= 970 && evento.mouse.y >= 493 && evento.mouse.y <= 539)
                        // quando passa pelo botão menu
                                {
                                    al_draw_bitmap(tela_finalmenu,0,0,0);
                                    MostrarNumero(aux);
                                    al_flip_display();
                                }
                                else
                                    if (evento.mouse.x >= 834 && evento.mouse.x <= 971 && evento.mouse.y >= 545 && evento.mouse.y <=590 )
                                // pelo botão sair
                                    {
                                        al_draw_bitmap(tela_finalsair,0,0,0);
                                        MostrarNumero(aux);
                                        al_flip_display();
                                    }
                                    else
                                        {
                                                al_draw_bitmap(tela_final,0,0,0);
                                                MostrarNumero(aux);
                                                al_flip_display();

                                        }
                            }else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                            {
                                if(evento.mouse.x >= 834 && evento.mouse.x <= 970 && evento.mouse.y >= 493 && evento.mouse.y <= 539)
                               //   caso seja detectado clique no botão menu
                                {
                                    al_draw_bitmap(tela_finalmenu,0,0,0);
                                    MostrarNumero(aux);
                                    al_flip_display();
                                    menu();
                                    sair=true;
                                }
                                else
                                    if (evento.mouse.x >= 834 && evento.mouse.x <= 971 && evento.mouse.y >= 545 && evento.mouse.y <= 590)
                                 //   pelo botão sair
                                    {
                                        al_draw_bitmap(tela_finalsair,0,0,0);
                                        MostrarNumero(aux);
                                        al_flip_display();
                                        SairJogo(0);
                                        sair=true;
                                    }
                                    else
                                        {
                                                al_draw_bitmap(tela_final,0,0,0);
                                                MostrarNumero(aux);
                                                al_flip_display();
                                        }

                            }

                    }
        }

        void Jogo_Adivinhacao::Tabela1(Node *numeroEscolhido, Node *aux)
        {
            bool sair=false;

                    al_draw_bitmap(tela_tabela1,0,0,0);
                    al_flip_display();

                    while (!sair) //evento de apertar o botão de sair
                    {

                      al_wait_for_event(fila_eventos, &evento);

                      if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                        {
                                al_destroy_event_queue(fila_eventos);
                                SairJogo(0);
                                sair=true;
                        }
                        else
                        if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) //evento de movimentação do mouse
                        {
                        // Verificamos se ele está sobre a região do retângulo central
                                if (evento.mouse.x >= 864 && evento.mouse.x <= 970 && evento.mouse.y >= 484 && evento.mouse.y <= 535)
                        // quando passa pelo botão sim
                                {
                                    al_draw_bitmap(tela_tabela1selsim,0,0,0);
                                    al_flip_display();
                                }
                                else
                                    if (evento.mouse.x >= 863 && evento.mouse.x <= 971 && evento.mouse.y >= 545 && evento.mouse.y <=585 )
                                // pelo botão nao
                                    {
                                        al_draw_bitmap(tela_tabela1selnao,0,0,0);
                                        al_flip_display();
                                    }
                                    else
                                        {
                                                al_draw_bitmap(tela_tabela1 ,0,0,0);
                                                al_flip_display();
                                        }
                            }else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                            {
                                if(evento.mouse.x >= 864 && evento.mouse.x <= 970 && evento.mouse.y >= 484 && evento.mouse.y <= 535)
                               //   caso seja detectado clique no botão sim
                                {
                                    al_draw_bitmap(tela_tabela1selsim,0,0,0);
                                    al_flip_display();
                                    aux=LogicaJogo(numeroEscolhido, aux);
                                    Resposta(aux);
                                    sair=true;
                                }
                                else
                                    if (evento.mouse.x >= 863 && evento.mouse.x <= 971 && evento.mouse.y >= 545 && evento.mouse.y <= 585)
                                 //   pelo botão nao
                                    {
                                        al_draw_bitmap(tela_tabela1selnao,0,0,0);
                                        al_flip_display();
                                        setQuant(getQuant()+1);
                                        Resposta(aux);
                                        sair=true;
                                    }
                                    else
                                        {
                                                al_draw_bitmap(tela_tabela1,0,0,0);
                                                al_flip_display();
                                        }

                            }

                    }
        }

        void Jogo_Adivinhacao::Tabela2(Node *numeroEscolhido,Node *aux)
        {
            bool sair=false;

                    al_draw_bitmap(tela_tabela2,0,0,0);
                    al_flip_display();

                    while (!sair) //evento de apertar o botão de sair
                    {

                      al_wait_for_event(fila_eventos, &evento);

                      if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                        {
                                al_destroy_event_queue(fila_eventos);
                                SairJogo(0);
                                sair=true;
                        }
                        else
                        if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) //evento de movimentação do mouse
                        {
                        // Verificamos se ele está sobre a região do retângulo central
                                if (evento.mouse.x >= 864 && evento.mouse.x <= 970 && evento.mouse.y >= 484 && evento.mouse.y <= 535)
                        // quando passa pelo botão sim
                                {
                                    al_draw_bitmap(tela_tabela2selsim,0,0,0);
                                    al_flip_display();
                                }
                                else
                                    if (evento.mouse.x >= 863 && evento.mouse.x <= 971 && evento.mouse.y >= 545 && evento.mouse.y <=585 )
                                // pelo botão nao
                                    {
                                        al_draw_bitmap(tela_tabela2selnao,0,0,0);
                                        al_flip_display();
                                    }
                                    else
                                        {
                                                al_draw_bitmap(tela_tabela2,0,0,0);
                                                al_flip_display();
                                        }
                            }else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                            {
                                if(evento.mouse.x >= 864 && evento.mouse.x <= 970 && evento.mouse.y >= 484 && evento.mouse.y <= 535)
                               //   caso seja detectado clique no botão sim
                                {
                                    al_draw_bitmap(tela_tabela2selsim,0,0,0);
                                    al_flip_display();
                                    aux=LogicaJogo(numeroEscolhido, aux);
                            ///FIM DA PARTE LOGICA
                                    Tabela1(numeroEscolhido, aux);
                                    sair=true;
                                }
                                else
                                    if (evento.mouse.x >= 863 && evento.mouse.x <= 971 && evento.mouse.y >= 545 && evento.mouse.y <= 585)
                                 //   pelo botão nao
                                    {
                                        al_draw_bitmap(tela_tabela2selnao,0,0,0);
                                        al_flip_display();
                                        setQuant(getQuant()+1);
                                        Tabela1(numeroEscolhido, aux);
                                        sair=true;
                                    }
                                    else
                                        {
                                                al_draw_bitmap(tela_tabela2,0,0,0);
                                                al_flip_display();
                                        }

                            }

                    }
        }

        void Jogo_Adivinhacao::Tabela3(Node *numeroEscolhido, Node *aux)
        {
            bool sair=false;

                    al_draw_bitmap(tela_tabela3,0,0,0);
                    al_flip_display();

                    while (!sair) //evento de apertar o botão de sair
                    {

                      al_wait_for_event(fila_eventos, &evento);

                      if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                        {
                                al_destroy_event_queue(fila_eventos);
                                SairJogo(0);
                                sair=true;
                        }
                        else
                        if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) //evento de movimentação do mouse
                        {
                        // Verificamos se ele está sobre a região do retângulo central
                                if (evento.mouse.x >= 864 && evento.mouse.x <= 970 && evento.mouse.y >= 484 && evento.mouse.y <= 535)
                        // quando passa pelo botão sim
                                {
                                    al_draw_bitmap(tela_tabela3selsim,0,0,0);
                                    al_flip_display();
                                }
                                else
                                    if (evento.mouse.x >= 863 && evento.mouse.x <= 971 && evento.mouse.y >= 545 && evento.mouse.y <=585 )
                            // pelo botão nao
                                    {
                                        al_draw_bitmap(tela_tabela3selnao,0,0,0);
                                        al_flip_display();
                                    }
                                    else
                                        {
                                                al_draw_bitmap(tela_tabela3,0,0,0);
                                                al_flip_display();
                                        }
                            }else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                            {
                                if(evento.mouse.x >= 864 && evento.mouse.x <= 970 && evento.mouse.y >= 484 && evento.mouse.y <= 535)
                               //   caso seja detectado clique no botão sim
                                {
                                    al_draw_bitmap(tela_tabela3selsim,0,0,0);
                                    al_flip_display();

                                    aux=LogicaJogo(numeroEscolhido, aux);
                                    Tabela2(numeroEscolhido, aux);
                                    sair=true;
                                }
                                else
                                    if (evento.mouse.x >= 863 && evento.mouse.x <= 971 && evento.mouse.y >= 545 && evento.mouse.y <= 585)
                                 //   pelo botão nao
                                    {
                                        al_draw_bitmap(tela_tabela3selnao,0,0,0);
                                        al_flip_display();
                                        setQuant(getQuant()+1);
                                        Tabela2(numeroEscolhido, aux);
                                        sair=true;
                                    }
                                    else
                                        {
                                                al_draw_bitmap(tela_tabela3,0,0,0);
                                                al_flip_display();
                                        }

                            }

                    }
        }

        void Jogo_Adivinhacao::Tabela4(Node *numeroEscolhido,  Node *aux)
        {
            bool sair=false;

                    al_draw_bitmap(tela_tabela4,0,0,0);
                    al_flip_display();

                    while (!sair) //evento de apertar o botão de sair
                    {

                      al_wait_for_event(fila_eventos, &evento);

                      if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                        {
                                al_destroy_event_queue(fila_eventos);
                                SairJogo(0);
                                sair=true;
                        }
                        else
                        if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) //evento de movimentação do mouse
                        {
        //                     Verificamos se ele está sobre a região do retângulo central
                                if (evento.mouse.x >= 864 && evento.mouse.x <= 970 && evento.mouse.y >= 484 && evento.mouse.y <= 535)
          //                      quando passa pelo botão sim
                                {
                                    al_draw_bitmap(tela_tabela4selsim,0,0,0);
                                    al_flip_display();
                                }
                                else
                                    if (evento.mouse.x >= 863 && evento.mouse.x <= 971 && evento.mouse.y >= 545 && evento.mouse.y <=585 )
            //                        pelo botão nao
                                    {
                                        al_draw_bitmap(tela_tabela4selnao,0,0,0);
                                        al_flip_display();
                                    }
                                    else
                                        {
                                                al_draw_bitmap(tela_tabela4,0,0,0);
                                                al_flip_display();
                                        }
                            }else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                            {
                                if(evento.mouse.x >= 864 && evento.mouse.x <= 970 && evento.mouse.y >= 484 && evento.mouse.y <= 535)
                               //   caso seja detectado clique no botão sim
                                {
                                    al_draw_bitmap(tela_tabela4selsim,0,0,0);
                                    al_flip_display();
                            /// PARTE LOGICA DO JOGO
                                    aux=LogicaJogo(numeroEscolhido, aux);
                                    Tabela3(numeroEscolhido, aux);
                                    sair=true;
                                }
                                else
                                    if (evento.mouse.x >= 863 && evento.mouse.x <= 971 && evento.mouse.y >= 545 && evento.mouse.y <= 585)
                                 //   pelo botão nao
                                    {
                                        al_draw_bitmap(tela_tabela4selnao,0,0,0);
                                        al_flip_display();
                                        setQuant(getQuant()+1);
                                        Tabela3(numeroEscolhido, aux);
                                        sair=true;
                                    }
                                    else
                                        {
                                                al_draw_bitmap(tela_tabela4,0,0,0);
                                                al_flip_display();
                                        }

                            }

                    }
        }

        void Jogo_Adivinhacao::Tabela5(Node *aux)
        {
            bool sair=false;
            Node *numeroEscolhido = new Node;

            aux = NULL;
            al_draw_bitmap(tela_tabela5,0,0,0);
            al_flip_display();

                    while (!sair) //evento de apertar o botão de sair
                    {

                      al_wait_for_event(fila_eventos, &evento);

                      if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                        {
                                al_destroy_event_queue(fila_eventos);
                                SairJogo(0);
                                sair=true;
                        }
                        else
                        if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) //evento de movimentação do mouse
                        {
                        // Verificamos se ele está sobre a região do retângulo central
                                if (evento.mouse.x >= 864 && evento.mouse.x <= 970 && evento.mouse.y >= 484 && evento.mouse.y <= 535)
                        // quando passa pelo botão sim
                                {
                                    al_draw_bitmap(tela_tabela5selsim,0,0,0);
                                    al_flip_display();
                                }
                                else
                                    if (evento.mouse.x >= 863 && evento.mouse.x <= 971 && evento.mouse.y >= 545 && evento.mouse.y <=585 )
                            // pelo botão nao
                                    {
                                        al_draw_bitmap(tela_tabela5selnao,0,0,0);
                                        al_flip_display();
                                    }
                                    else
                                        {
                                                al_draw_bitmap(tela_tabela5,0,0,0);
                                                al_flip_display();
                                        }
                            }else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                            {
                                if(evento.mouse.x >= 864 && evento.mouse.x <= 970 && evento.mouse.y >= 484 && evento.mouse.y <= 535)
                               //   caso seja detectado clique no botão sim
                                {
                                    al_draw_bitmap(tela_tabela5selsim,0,0,0);
                                    al_flip_display();
                                    aux=LogicaJogo(numeroEscolhido, aux);
                                    Tabela4(numeroEscolhido, aux);
                                    sair=true;
                                }
                                else
                                    if (evento.mouse.x >= 863 && evento.mouse.x <= 971 && evento.mouse.y >= 545 && evento.mouse.y <= 585)
                                 //   pelo botão nao
                                    {
                                        al_draw_bitmap(tela_tabela5selnao,0,0,0);
                                        al_flip_display();
                                        setQuant(getQuant()+1);
                                        Tabela4(numeroEscolhido, aux);
                                        sair=true;
                                    }
                                    else
                                        {
                                                al_draw_bitmap(tela_tabela5,0,0,0);
                                                al_flip_display();
                                        }

                            }

                    }
        }

        void Jogo_Adivinhacao::CriarArvore()
        {

            setQuant(0);

            int i;
            for(i=1; i<32; i++)
            {
                numeros->Inserir(numeros->getInicio(),i);
            }
        }

        void Jogo_Adivinhacao::IniciarJogo()
        {
            numeros->RemoverTodos(numeros->getInicio());
            Node *aux;
            aux = new Node;
            CriarArvore();
            Tabela5(aux);
        }

        void Jogo_Adivinhacao::FinalizarAllegro()
        {
            al_destroy_display(janela);
            al_destroy_event_queue(fila_eventos);
            al_destroy_bitmap(tela_inicial);
            al_destroy_bitmap(botao_iniciar_press);
            al_destroy_bitmap(botao_instrucoes_press);
            al_destroy_bitmap(botao_sair_press);
            al_destroy_bitmap(tela_instrucoes);
            al_destroy_bitmap(tela_instrucoesvoltar);
            al_destroy_bitmap(tela_jogo);
            al_destroy_bitmap(tela_tabela1);
            al_destroy_bitmap(tela_tabela2);
            al_destroy_bitmap(tela_tabela3);
            al_destroy_bitmap(tela_tabela4);
            al_destroy_bitmap(tela_tabela5);
            al_destroy_bitmap(tela_tabela1selsim);
            al_destroy_bitmap(tela_tabela2selsim);
            al_destroy_bitmap(tela_tabela3selsim);
            al_destroy_bitmap(tela_tabela4selsim);
            al_destroy_bitmap(tela_tabela5selsim);
            al_destroy_bitmap(tela_tabela1selnao);
            al_destroy_bitmap(tela_tabela2selnao);
            al_destroy_bitmap(tela_tabela3selnao);
            al_destroy_bitmap(tela_tabela4selnao);
            al_destroy_bitmap(tela_tabela5selnao);
            al_destroy_bitmap(tela_final);
            al_destroy_bitmap(tela_finalmenu);
            al_destroy_bitmap(tela_finalsair);
            al_destroy_bitmap(Desenvolvedores);
            al_destroy_bitmap(fundo);
            al_destroy_bitmap(Pensou);
            al_destroy_bitmap(PensouAvancar);
            al_destroy_font(fonte);
		delete numeros;
        }

        void Jogo_Adivinhacao::SairJogo(int i)
        {
            if (i==0)
            {
                Desenvolvedores = al_load_bitmap("imagens/tela-jogo-Desenvolvedores.jpg");
                al_draw_bitmap(Desenvolvedores,0,0,0);
                al_flip_display();
                al_rest(1.0);
                al_destroy_display(janela);
                exit(0);
            }
        }

        Node* Jogo_Adivinhacao::LogicaJogo(Node *numeroEscolhido, Node *aux)
        {

                            if (aux == NULL)
                            {
                                    numeros->PegaOPrimeiro(numeroEscolhido); // APONTA O numeroEscolhido PARA O NOH DE VALOR 16

                            }

                            else
                            {
                                    numeros->PegaODireito(numeroEscolhido); // MOVE O PONTEIRO PARA O FILHO A DIREITA, COMO SE "SOMANDO" AO VALOR QUE JAH TINHA ANTES
                            }
                            int quant = getQuant();
                            for (quant; quant--; quant>0)
                            { // VERIFICA QUANTOS NAOS FORAM DITOS ENTRE A ULTIMA LISTA QUE O JOGADOR CLICOU NO SIM E A LISTA DE AGORA QUE O JOGADOR CLICOU QUE SIM. ESSA QUANTIA TEM QUE SER O NUMERO DE VEZES QUE O PONTEIRO VAI PARA O SEU FILHO ESQUERDO, ASSIM COMO NA 1ª PARTE

                                numeros->PegaOEsquerdo(numeroEscolhido);

                            }

                            setQuant(quant+1);
                            aux = numeroEscolhido;
                            return (aux);
        }




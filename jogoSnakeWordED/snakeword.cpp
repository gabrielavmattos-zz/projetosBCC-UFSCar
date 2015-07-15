//Allegro 5 ainda com alguns bugs deixou esse jogo lento

#include <iostream>

#include "cabecalho.h"
        SnakeWord::SnakeWord()
        {
            cobra = new Lista();
            setPontuacao(0);
            al_init(); //inicializando o allegro

        }

        SnakeWord::~SnakeWord()
        {
            al_destroy_display(janela);
            delete cobra;
        }

        void SnakeWord::setNivel(int nivel)
        {
            this->nivel=nivel;
        }

        int SnakeWord::getNivel()
        {
            return (this->nivel);
        }

        int SnakeWord::quantLetras()
        {
            switch(getNivel())
            {
                case 1:
                    return 4;
                    break;
                case 2:
                    return 5;
                    break;
                case 3:
                    return 6;
                    break;
            }

        }

        void SnakeWord::setPalavra_sorteada(string palavra_sorteada)
        {
            this->palavra_sorteada=palavra_sorteada;
        }

        string SnakeWord::getPalavra_sorteada()
        {
             return(this->palavra_sorteada);
        }

        void SnakeWord::setPontuacao(int pontuacao)
        {
            this->pontuacao=pontuacao;
        }

        int SnakeWord::getPontuacao()
        {
            return(this->pontuacao);
        }

        int SnakeWord::iniciarAllegro()
        {



            if (!al_init_image_addon())
                return 2;

            if (!al_install_keyboard())
                return 3;

            al_set_new_display_flags(ALLEGRO_RESIZABLE);
            janela = al_create_display(largura_tela, altura_tela); //criando a janela


            icone=al_load_bitmap("im/icone.png");
            al_set_display_icon(janela,icone);



            if(!al_install_mouse())
                return 7;

            if(!al_set_system_mouse_cursor(janela,ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK))
                return 8;

            al_init_font_addon();


            if(!al_init_ttf_addon())
                return 10;

            fonte = al_load_font("arial.ttf", 48,0);

            if(!fonte)
                return 11;


            return 0;
        }

        void SnakeWord::mostrarPalavra()
        {

            q1=al_load_bitmap("im/palavra.png");
            al_draw_bitmap(q1,62,588,0);

            al_flip_display();
            SorteiaPalavra();

            int i;
            char c[10];
            string s=getPalavra_sorteada();
            int j=s.length();

            for(i=0; i<j; i++)
            {
                c[i]=s[i];

            }

            c[i]='\0';
            al_draw_textf(fonte, al_map_rgb(255,255,255),250, 606,ALLEGRO_ALIGN_CENTRE,c);

        }

        char SnakeWord::LetraPalavra(int pos)
        {
            char c[10];
            int i;
            string s=getPalavra_sorteada();

            for(i=0; i<s.length(); i++)
            {
                c[i]=s[i];

            }
            c[i]='\0';
            return (c[pos]);

        }

        void SnakeWord::IniciarJogo()
        {
            fila_eventos = al_create_event_queue();
            cobra->DestroiLista();
            tela_padrao = al_load_bitmap("im/tela_padrao.png");
            Lista *ElementoTela = new Lista;
            Node ElementoCerto;
            al_draw_bitmap(tela_padrao,0,0,0);
            int pos=0; //posição da letra que deseja ser pegada
            bool  sair=false;
            char letraSor;
            int i=1, j=0;
            int tecla=0, ultimaTecla=3;
            int x=-30,y=0;

            //começando o jogo... inicialização

            CriarCobrinha();
            AtualizarPontuacao(0);
            mostrarPalavra();

            letraSor=LetraPalavra(pos);
            ElementoCerto = *SorteiaElementos(letraSor);
            if(ElementoTela->Inserir(&ElementoCerto))
                for (j=0; j<3; j++)
                {
                    letraSor=SorteiaLetra();

                    ElementoCerto= *SorteiaElementos(letraSor);
                    char c = ElementoCerto.getInfo();
                    ElementoCerto.setInfo(c);
                    ElementoTela->Inserir(&ElementoCerto);

                }
            AtualizarCobrinha(*ElementoTela);
            timer = al_create_timer(tempo/getNivel());



            al_register_event_source(fila_eventos,al_get_keyboard_event_source());
            al_register_event_source(fila_eventos, al_get_display_event_source(janela));
            al_register_event_source(fila_eventos, al_get_timer_event_source(timer));
            al_start_timer(timer);


            Node *Primeiro = new Node;
            Node *Ultimo = new Node;
            Node *PAux = new Node;
            Node *Anterior = new Node;
            Node *PAux1 = new Node;
            int posX, posY;
            Node aux;

            while (!sair) //evento de apertar o botão de sair
            {
                al_wait_for_event(fila_eventos, &evento);
                switch(evento.keyboard.keycode)
                        {
                            case ALLEGRO_KEY_UP:
                                if(ultimaTecla!=1 && ultimaTecla!=2 )
                                {
                                    tecla=1;
                                    x=0;
                                    y=-30;

                                }
                                break;
                            case ALLEGRO_KEY_DOWN:
                                if(ultimaTecla!=2 && ultimaTecla!=1)
                                {
                                    tecla=2;
                                    x=0;
                                    y=30;
                                }
                                break;
                            case ALLEGRO_KEY_LEFT:
                                if(ultimaTecla!=3 && ultimaTecla!=4)
                                {
                                    tecla = 3;
                                    x=-30;
                                    y=0;
                                }
                                break;
                            case ALLEGRO_KEY_RIGHT:
                                if(ultimaTecla!=4 && ultimaTecla!=3)
                                {
                                    tecla = 4;
                                    x=30;
                                    y=0;
                                }
                                break;
                            case ALLEGRO_KEY_SPACE:
                                Pause();
                                al_start_timer(timer);
                                break;
                            default:
                                tecla=0;
                                break;
                            }

                            if(tecla!=0)
                            {
                               ultimaTecla=tecla;
                            }



                if(evento.type == ALLEGRO_EVENT_TIMER && evento.type != ALLEGRO_EVENT_KEY_DOWN)
                {


                    cobra->PegaOPrimeiro(Primeiro); //recebe o primeiro para teste de comparação

                    aux=*cobra->getFinal();
                    *Ultimo = aux;
                    posX=Primeiro->getPosInicialX();
                    posY=Primeiro->getPosInicialY();
                        if(tecla!=ultimaTecla)
                        {
                            Primeiro->setPosInicialX(posX+x);
                            Primeiro->setPosInicialY(posY+y);

                            posX=Primeiro->getPosInicialX();
                            posY=Primeiro->getPosInicialY();

                            Primeiro->setPosFinalX(posX+30);
                            Primeiro->setPosFinalY(posY+30);
                            bool teste;
                            teste=cobra->PegaOUltimo(Anterior);
                            while (teste)
                            {
                                aux = *Anterior->getEsq();
                                *Anterior = aux;

                                posX=Anterior->getPosInicialX();
                                posY=Anterior->getPosInicialY();

                                cobra->getAtual()->setPosInicialX(posX);
                                cobra->getAtual()->setPosInicialY(posY);
                                cobra->getAtual()->setPosFinalX(posX+30);
                                cobra->getAtual()->setPosFinalY(posY+30);

                                teste=cobra->PegaOAnterior(Anterior);
                            }

                            cobra->setInicio(Primeiro);
                          /*      Atual = cobra->getInicio();
                                do
                                {
                                    cout << "posAtual : "<< Atual->getPosInicialX() << " - " << Atual->getPosInicialY() << endl;

                                    Atual=Atual->getDir();

                                }
                                while (Atual != NULL);*/
                        }

                        AtualizarCobrinha(*ElementoTela);
                 //    al_flip_display();


                            if(colisaoCantos(cobra->getInicio()))
                            {
                                sair=true;
                                al_destroy_event_queue(fila_eventos);
                                al_destroy_bitmap(tela_padrao);
                                al_destroy_timer(timer);
                                SairJogo(1);
                            }


                           if(colisaoCobra())
                            {
                                sair=true;
                                al_destroy_event_queue(fila_eventos);
                                al_destroy_bitmap(tela_padrao);
                                al_destroy_timer(timer);
                                SairJogo(1);
                            }


                    int tipoColisao = 0;
                    tipoColisao=ColisaoNode(*ElementoTela);

                        if(tipoColisao>0)
                        {

                            if(tipoColisao==1) //quando pegou o elemento certo
                            {
                                    AtualizarPontuacao(1);
                                    pos++;

                                    char palavra1 [quantLetras()];

                                    strcpy(palavra1,palavra_sorteada.c_str());
                                    Node aux;

                                    if(pos == quantLetras())
                                    {
                                        i=0;
                                        while(palavra1[i]!='\0' && i<quantLetras())
                                        {
                                            while(cobra->EstaNaLista(palavra1[i], PAux))
                                                cobra->Retirar(PAux);
                                            i++;


                                           /* do
                                            {
                                                cout <<"cobra : " <<PAux1->getInfo() << endl;
                                                j++;
                                            }
                                            while (cobra->PegaOProximo(PAux1) && j<10);*/


                                            AtualizarCobrinha(*ElementoTela);

                                          //  al_rest(0.2);
                                    }

                                        AtualizarPontuacao(2);
                                        mostrarPalavra();
                                        al_flip_display();
                                        pos=0;
                                    }


                                    letraSor=LetraPalavra(pos);
                                    ElementoTela->DestroiLista();
                                    ElementoCerto=*SorteiaElementos(letraSor);
                                    ElementoTela->Inserir(&ElementoCerto);

                                    for (j=0; j<3; j++)
                                    {
                                        letraSor=SorteiaLetra();
                                        ElementoCerto=*SorteiaElementos(letraSor);
                                        ElementoTela->Inserir(&ElementoCerto);

                                    }

                            }
                            else //quando pegou o elemento errado
                            {

                                AtualizarPontuacao(3);
                                mostrarPalavra();

                                pos=0;
                                ElementoTela->DestroiLista();
                                letraSor=LetraPalavra(pos);
                                ElementoCerto = *SorteiaElementos(letraSor);
                                if(ElementoTela->Inserir(&ElementoCerto))
                                    for (j=0; j<3; j++)
                                    {
                                        letraSor=SorteiaLetra();
                                        ElementoCerto= *SorteiaElementos(letraSor);
                                        char c = ElementoCerto.getInfo();
                                        ElementoCerto.setInfo(c);
                                        ElementoTela->Inserir(&ElementoCerto);

                                    }
                                al_flip_display();

                            }


                        }
                }
                else
                if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                {
                        al_destroy_bitmap(tela_padrao);
                        al_destroy_timer(timer);
                        al_destroy_event_queue(fila_eventos);
                        SairJogo(1);
                        sair=true;
                }

            }

                al_destroy_event_queue(fila_eventos);
                al_destroy_bitmap(tela_padrao);
                delete Primeiro;
                delete Ultimo;
                delete PAux;
                delete Anterior;
                delete PAux1;
                delete ElementoTela;

        }

        int SnakeWord::Pause()
        {
            al_flip_display();
            al_stop_timer(timer);

            if (al_show_native_message_box(NULL, "JOGO PAUSADO",
                "Pergunta:", "Deseja tirar o PAUSE?",
                NULL, ALLEGRO_MESSAGEBOX_QUESTION))
                {
                    return 1;
                }

        }

        void SnakeWord::EscolherNivel()
        {

            fila_eventos = al_create_event_queue();
            cobra->DestroiLista();
            tela_nivel=al_load_bitmap("im/tela_nivel.PNG");
            tela_nivel1=al_load_bitmap("im/tela_nivel1.PNG");
            tela_nivel2=al_load_bitmap("im/tela_nivel2.PNG");
            tela_nivel3=al_load_bitmap("im/tela_nivel3.PNG");

                setPontuacao(0);

            al_register_event_source(fila_eventos,al_get_mouse_event_source());
            al_register_event_source(fila_eventos, al_get_display_event_source(janela));

            bool  sair=false;
            al_draw_bitmap(tela_nivel,0,0,0);
            al_flip_display();
         while (!sair) //evento de apertar o botão de sair
        {

              al_wait_for_event(fila_eventos, &evento);

              if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                {
                    al_destroy_bitmap(tela_nivel1);
                    al_destroy_bitmap(tela_nivel2);
                    al_destroy_bitmap(tela_nivel3);
                    al_destroy_event_queue(fila_eventos);
                    SairJogo(0);
                    sair=true;
                }
                else
                if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) //evento de movimentação do mouse
                {
                        if (evento.mouse.x >= 672 && evento.mouse.x <= 699 && evento.mouse.y >= 520 && evento.mouse.y <= 547)
                    //    quando passa pelo botão jogar
                        {
                            al_draw_bitmap(tela_nivel1,0,0,0);
                            al_flip_display();
                        }
                        else
                            if (evento.mouse.x >= 672 && evento.mouse.x <= 699 && evento.mouse.y >= 587 && evento.mouse.y <= 616)
                      //      pelo botão instruções
                            {
                                al_draw_bitmap(tela_nivel2,0,0,0);
                                al_flip_display();
                            }
                            else
                                if (evento.mouse.x >= 672 && evento.mouse.x <= 699 && evento.mouse.y >= 651 && evento.mouse.y <= 678)
                   //             pelo botão sair
                                {
                                    al_draw_bitmap(tela_nivel3,0,0,0);
                                    al_flip_display();
                                }
                                else
                                {
                                        al_draw_bitmap(tela_nivel,0,0,0);
                                        al_flip_display();
                                }
                    }
                   //  Ou se o evento foi um clique do mouse
                    else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                    {
                        if(evento.mouse.x >= 672 && evento.mouse.x <= 699 && evento.mouse.y >= 520 && evento.mouse.y <= 547)
                   //       botão jogar caso ele clique
                        {
                            al_draw_bitmap(tela_nivel1,648,561,0);
                            al_flip_display();
                            setNivel(1);

                            al_destroy_bitmap(tela_nivel1);
                            al_destroy_bitmap(tela_nivel2);
                            al_destroy_bitmap(tela_nivel3);
                            al_destroy_event_queue(fila_eventos);
                            IniciarJogo();
                            sair=true;
                        }
                        else
                            if (evento.mouse.x >= 672 && evento.mouse.x <= 699 && evento.mouse.y >= 587 && evento.mouse.y <= 616)
                     //       pelo botão instruções
                            {
                                al_draw_bitmap(tela_nivel2,0,0,0);
                                al_flip_display();
                                setNivel(2);

                                al_destroy_bitmap(tela_nivel1);
                                al_destroy_bitmap(tela_nivel2);
                                al_destroy_bitmap(tela_nivel3);
                            al_destroy_event_queue(fila_eventos);
                                IniciarJogo();
                                sair=true;
                            }
                            else
                                if (evento.mouse.x >= 672 && evento.mouse.x <= 699 && evento.mouse.y >= 651 && evento.mouse.y <= 678)
                       //         pelo botão sair
                                {
                                    al_draw_bitmap(tela_nivel3,0,0,0);
                                    al_flip_display();
                                    setNivel(3);

                                    al_destroy_bitmap(tela_nivel1);
                                    al_destroy_bitmap(tela_nivel2);
                                    al_destroy_bitmap(tela_nivel3);
                                    IniciarJogo();
                                    sair=true;
                                }
                                else
                                {
                                        al_draw_bitmap(tela_nivel,0,0,0);
                                        al_flip_display();
                                }

                   }

            }

        }

        void SnakeWord::InstrucoesJogo()
        {
            fila_eventos = al_create_event_queue();
            al_register_event_source(fila_eventos,al_get_mouse_event_source());
            al_register_event_source(fila_eventos, al_get_display_event_source(janela));
            tela_instrucoes=al_load_bitmap("im/instrucoes.png");
            tela_instrucoes2=al_load_bitmap("im/instrucoes1.png");
            bool  sair=false;
            al_draw_bitmap(tela_instrucoes,0,0,0);
            al_flip_display();

            while (!sair) //evento de apertar o botão de sair
            {

              al_wait_for_event(fila_eventos, &evento);

              if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                {
                        al_destroy_bitmap(tela_instrucoes);
                        al_destroy_bitmap(tela_instrucoes2);
                        al_destroy_event_queue(fila_eventos);
                        SairJogo(0);
                        sair=true;
                }
              else
                if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) //evento de movimentação do mouse
                {
                            if (evento.mouse.x >= 672 && evento.mouse.x <= 699 && evento.mouse.y >= 674 && evento.mouse.y <= 698)
                      //      pelo botão instruções
                            {

                                al_draw_bitmap(tela_instrucoes2,0,0,0);
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
                        if(evento.mouse.x >= 672 && evento.mouse.x <= 699 && evento.mouse.y >= 674 && evento.mouse.y <= 698)
                   //       botão jogar caso ele clique
                        {

                            al_draw_bitmap(tela_instrucoes2,648,561,0);
                            al_flip_display();
                            menu();
                            al_destroy_bitmap(tela_instrucoes);
                            al_destroy_bitmap(tela_instrucoes2);
                            al_destroy_event_queue(fila_eventos);
                            sair=true;
                        }
                        else
                        {
                                al_destroy_bitmap(tela_instrucoes);
                                al_destroy_bitmap(tela_instrucoes2);
                                al_draw_bitmap(tela_instrucoes,0,0,0);
                                al_flip_display();

                        }
                    }
                }

        }

        void SnakeWord::SairJogo(int i)
        {
            fila_eventos = al_create_event_queue();
            al_register_event_source(fila_eventos,al_get_mouse_event_source());
            al_register_event_source(fila_eventos, al_get_display_event_source(janela));
            if (i==1)
            {
                tela_pontuacao=al_load_bitmap("im/pontuacao.png");
                tela_pontuacao1=al_load_bitmap("im/pontuacao1.png");
                tela_pontuacao2=al_load_bitmap("im/pontuacao2.png");

                bool sair=false;

                al_draw_bitmap(tela_pontuacao,0,0,0);
                int pont=getPontuacao();
                char c[10];
                sprintf(c,"%d",pont);
                al_draw_textf(fonte, al_map_rgb(255,255,255),500,420,ALLEGRO_ALIGN_CENTRE,c);
                al_flip_display();

                while (!sair) //evento de apertar o botão de sair
                {
                    al_wait_for_event(fila_eventos, &evento);

                    if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                    {
                        al_destroy_bitmap(tela_pontuacao1);
                        al_destroy_bitmap(tela_pontuacao);
                        al_destroy_bitmap(tela_pontuacao2);
                        al_destroy_event_queue(fila_eventos);
                        SairJogo(0);
                        sair=true;
                    }
                    else
                    if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) //evento de movimentação do mouse
                    {
                            if (evento.mouse.x >= 731 && evento.mouse.x <= 758 && evento.mouse.y >= 574 && evento.mouse.y <= 600)
                      //      pelo botão instruções
                            {

                                al_draw_bitmap(tela_pontuacao1,0,0,0);
                                al_draw_textf(fonte, al_map_rgb(255,255,255),500,420,ALLEGRO_ALIGN_CENTRE,c);
                                al_flip_display();
                            }
                            else
                              if (evento.mouse.x >= 731 && evento.mouse.x <= 758 && evento.mouse.y >= 645 && evento.mouse.y <= 673)
                              {

                                al_draw_bitmap(tela_pontuacao2,0,0,0);
                                al_draw_textf(fonte, al_map_rgb(255,255,255),500,420,ALLEGRO_ALIGN_CENTRE,c);
                                al_flip_display();

                             }


                             else
                             {

                                al_draw_bitmap(tela_pontuacao,0,0,0);
                                al_draw_textf(fonte, al_map_rgb(255,255,255),500,420,ALLEGRO_ALIGN_CENTRE,c);
                                al_flip_display();

                            }
                }
                else
                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                    {
                            if (evento.mouse.x >= 731 && evento.mouse.x <= 758 && evento.mouse.y >= 574 && evento.mouse.y <= 599)
                      //      pelo botão instruções
                            {

                                al_draw_bitmap(tela_pontuacao1,0,0,0);
                                al_draw_textf(fonte, al_map_rgb(255,255,255),500,420,ALLEGRO_ALIGN_CENTRE,c);
                                al_flip_display();

                                al_destroy_bitmap(tela_pontuacao1);
                                al_destroy_bitmap(tela_pontuacao);
                                al_destroy_bitmap(tela_pontuacao2);
                                al_destroy_event_queue(fila_eventos);
                                menu();
                                sair=true;
                            }
                            else
                              if (evento.mouse.x >= 731 && evento.mouse.x <= 758 && evento.mouse.y >= 645 && evento.mouse.y <= 673)
                              {
                                al_draw_bitmap(tela_pontuacao2,0,0,0);
                                al_draw_textf(fonte, al_map_rgb(255,255,255),500,420,ALLEGRO_ALIGN_CENTRE,c);
                                al_flip_display();

                                al_destroy_bitmap(tela_pontuacao1);
                                al_destroy_bitmap(tela_pontuacao);
                                al_destroy_bitmap(tela_pontuacao2);
                                al_destroy_event_queue(fila_eventos);
                                SairJogo(0);
                                sair=true;

                             }

                             else
                             {
                                al_draw_bitmap(tela_pontuacao,0,0,0);
                                al_draw_textf(fonte, al_map_rgb(255,255,255),500,420,ALLEGRO_ALIGN_CENTRE,c);
                                al_flip_display();

                            }
                    }

                }
            }

            if(i==0)
            {

                tela_sair=al_load_bitmap("im/sair.png");
                al_draw_bitmap(tela_sair,0,0,0);
                al_flip_display();
                al_rest(1.0);
                al_destroy_bitmap(tela_sair);
                exit(0);

            }
        }

        void SnakeWord::menu()
        {
            fila_eventos = al_create_event_queue();
            al_register_event_source(fila_eventos,al_get_mouse_event_source());
            al_register_event_source(fila_eventos, al_get_display_event_source(janela));
            tela_inicial = al_load_bitmap("im/tela_inicial.png");
            botao_jogar_press=al_load_bitmap("im/tela_inicial_1.png");
            botao_instrucoes_press=al_load_bitmap("im/tela_inicial_2.png");
            botao_sair_press=al_load_bitmap("im/tela_inicial_3.png");

            bool sair=false;;
            cobra->DestroiLista();
            al_draw_bitmap(tela_inicial,0,0,0);
            al_flip_display();

            while (!sair) //evento de apertar o botão de sair
            {

              al_wait_for_event(fila_eventos, &evento);

              if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                {

                        al_destroy_bitmap(tela_inicial);
                        al_destroy_bitmap(botao_jogar_press);
                        al_destroy_bitmap(botao_instrucoes_press);
                        al_destroy_bitmap(botao_sair_press);
                        al_destroy_event_queue(fila_eventos);
                        SairJogo(0);
                        sair=true;
                }
                else
                if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) //evento de movimentação do mouse
                {
//                     Verificamos se ele está sobre a região do retângulo central
                        if (evento.mouse.x >= 672 && evento.mouse.x <= 699 && evento.mouse.y >= 520 && evento.mouse.y <= 547)
  //                      quando passa pelo botão jogar
                        {
                            al_draw_bitmap(botao_jogar_press,0,0,0);
                            al_flip_display();
                        }
                        else
                            if (evento.mouse.x >= 672 && evento.mouse.x <= 699 && evento.mouse.y >= 587 && evento.mouse.y <= 616)
    //                        pelo botão instruções
                            {
                                al_draw_bitmap(botao_instrucoes_press,0,0,0);
                                al_flip_display();
                            }
                            else
                                if (evento.mouse.x >= 672 && evento.mouse.x <= 699 && evento.mouse.y >= 651 && evento.mouse.y <= 678)
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
                     //Ou se o evento foi um clique do mouse
                    else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                    {
                        if(evento.mouse.x >= 672 && evento.mouse.x <= 699 && evento.mouse.y >= 520 && evento.mouse.y <= 547)
                       //   botão jogar caso ele clique
                        {
                            al_draw_bitmap(botao_jogar_press,648,561,0);
                            al_flip_display();
                            al_destroy_bitmap(tela_inicial);
                            al_destroy_bitmap(botao_jogar_press);
                            al_destroy_bitmap(botao_instrucoes_press);
                            al_destroy_bitmap(botao_sair_press);
                            al_destroy_event_queue(fila_eventos);
                            EscolherNivel();
                            sair=true;
                        }
                        else
                            if (evento.mouse.x >= 672 && evento.mouse.x <= 699 && evento.mouse.y >= 587 && evento.mouse.y <= 616)
                         //   pelo botão instruções
                            {
                                al_draw_bitmap(botao_instrucoes_press,0,0,0);
                                al_flip_display();
                                al_destroy_bitmap(tela_inicial);
                                al_destroy_bitmap(botao_jogar_press);
                                al_destroy_bitmap(botao_instrucoes_press);
                                al_destroy_bitmap(botao_sair_press);
            al_destroy_event_queue(fila_eventos);

                                InstrucoesJogo();
                                sair=true;
                            }
                            else
                                if (evento.mouse.x >= 672 && evento.mouse.x <= 699 && evento.mouse.y >= 651 && evento.mouse.y <= 678)
                           //     pelo botão sair
                                {
                                    al_draw_bitmap(botao_sair_press,0,0,0);
                                    al_flip_display();
                                    al_destroy_bitmap(tela_inicial);
                                    al_destroy_bitmap(botao_jogar_press);
                                    al_destroy_bitmap(botao_instrucoes_press);
                                    al_destroy_bitmap(botao_sair_press);
            al_destroy_event_queue(fila_eventos);
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

        void SnakeWord::SorteiaPalavra()//metodo que vai sortear a palavra a partir do arquivo de cada nivel (o parametro será o nivel)
        {
            srand((unsigned)time(0));
            int i=0;
            char palavra[quantLetras()];
            string palavras[quantMax];
            ifstream fin;
            switch(getNivel())
            {
                case 1:
                    fin.open("1.txt");
                    break;
                case 2:
                    fin.open("2.txt");
                    break;
                case 3:
                    fin.open("3.txt");
                    break;
            }

            while(fin && i<quantMax)
            {
                fin.getline(palavra,10);
                string s(palavra);
                palavras[i] = s;
                i++;
            }
            i = rand()%quantMax;
            setPalavra_sorteada(palavras[i]);

        }

        char SnakeWord::SorteiaLetra()
        {
            char c;
            int i;
            do
                i=rand()% 100;
            while (i<=66 || i>=90);

            c=i;
            return c;
        }

        Node* SnakeWord::SorteiaElementos(char c) //metodo que sorteia as letras que deverão aparecer para a cobrinha comer
        {
            Node elemento0;
            int i,i1;
            char letra[30];
            EscreveCaminho(letra,c);
            a=al_load_bitmap(letra);

            do
            {
                i=rand()%910;
                i1=rand()%910;
                while (i%30!=0 || i1%30!=0)
                {
                    i=rand()%910;
                    i1=rand()%910;
                }
            }
            while (colisaoCobra() || !DesenhaQuadrado(i,i1,a));

            elemento0.setPosInicialX(i);
            elemento0.setPosInicialY(i1);
            elemento0.setPosFinalX(i+30);
            elemento0.setPosFinalY(i1+30);
            elemento0.setInfo(c);
            elemento0.setDir(NULL);
            al_destroy_bitmap(a);
            return (&elemento0);

        }

        void SnakeWord::CriarCobrinha()
        {
            int posX, posY;
            posX=centro_cobraX;
            posY=centro_cobraY;
            int i;
            Node *PAux = new Node;


            q0=al_load_bitmap("im/0.png");
            for(i=0; i<quantLetras(); i++)
            {
                PAux->setPosInicialX(posX);
                PAux->setPosInicialY(posY);
                PAux->setPosFinalX(posX+30);
                PAux->setPosFinalY(posY+30);
                PAux->setInfo('0');
                cobra->Inserir(PAux);
                posX+=30;
            }

            al_destroy_bitmap(q0);


        }

        bool SnakeWord::DesenhaQuadrado(int posX, int posY, ALLEGRO_BITMAP *q0)
        {
            if(posX>=limite_largura_inferior && posX+30<=limite_largura_superior
            && posY>=limite_altura_inferior && posY+30<=limite_altura_superior)
             {
                     al_draw_bitmap(q0,posX,posY,0);
                     return true;
             }
             return false;
        }

        bool SnakeWord::colisaoCobra()
        {
            Node *PAux = new Node;
            Node *PAux2 = new Node;
            cobra->PegaOPrimeiro(PAux);
            cobra->PegaOPrimeiro(PAux2);
            while(cobra->PegaOProximo(PAux2))
            {

                if(PAux->getPosInicialX()==PAux2->getPosInicialX() && PAux->getPosInicialY()==PAux2->getPosInicialY())
                {
                        delete PAux;
                        delete PAux2;
                        return true;
                }

            }

            delete PAux;
            delete PAux2;
            return false;
        }

        bool SnakeWord::colisaoCantos(Node* PAux)
        {

            if(PAux->getPosInicialX()+20>=limite_largura_superior || PAux->getPosInicialX()<=limite_largura_inferior-3
                    || PAux->getPosInicialY()>=limite_altura_superior-30 || PAux->getPosInicialY()<=limite_altura_inferior)
                    return true;
            else return false;
        }

        int SnakeWord::ColisaoNode(Lista ElementoTela)
        //detectar as colisões
        {
           Node Ultimo, *aux = new Node;
           Ultimo = *cobra->getInicio();
           ElementoTela.PegaOPrimeiro(aux);
           do
           {
                if(Ultimo.getPosInicialX()==aux->getPosInicialX() && Ultimo.getPosInicialY()==aux->getPosInicialY())
                {


                    Ultimo = *cobra->getFinal();
                    aux->setPosInicialX(Ultimo.getPosInicialX()+30);
                    aux->setPosInicialY(Ultimo.getPosInicialY()+30);
                    aux->setPosFinalX(Ultimo.getPosInicialX()+30);
                    aux->setPosFinalY(Ultimo.getPosInicialY()+30);

                    cobra->Inserir(aux);

                    if(ElementoTela.getInicio()->getInfo()==aux->getInfo())
                    {
                        delete aux;
                        return 1;

                    }
                    else
                    {

                        delete aux;
                        return 2;
                    }
                }

           }
           while (ElementoTela.PegaOProximo(aux));

        delete aux;
        return 0;

        }

        void SnakeWord::AtualizarPontuacao(int tipo)//condições de pontuação
        {

            q1=al_load_bitmap("im/q1.png");
           //BITMAP CRIADOS PARA NÃO APARECER A ÚLTIMA PONTUAÇÃO
            al_draw_bitmap(q1,805,27,0);
            al_draw_bitmap(q1,835,27,0);
            al_draw_bitmap(q1,865,27,0);
            al_draw_bitmap(q1,895,27,0);
            al_draw_bitmap(q1,805,43,0);
            al_draw_bitmap(q1,835,43,0);
            al_draw_bitmap(q1,865,43,0);
            al_draw_bitmap(q1,895,43,0);


            int pont;
            pont=getPontuacao();
            switch(tipo)
            {
                case 1: //caso acertou a letra
                    pont+=10*getNivel();
                    break;
                case 2: //acertou a palavra
                    pont+=100*getNivel();
                    break;
                case 3: //errou
                    pont+=-5*getNivel();
                    break;

            }
            setPontuacao(pont);
            int i=pont;
            char c[10];

             sprintf(c,"%d",i);
            al_draw_textf(fonte, al_map_rgb(255,255,255),864,20,ALLEGRO_ALIGN_CENTRE,c);
            al_destroy_bitmap(q1);

        }

        void SnakeWord::AtualizarCobrinha(Lista ElementoTela)
        {
            Node *PAux = new Node();
            q1=al_load_bitmap("im/quadrado.png");
            al_draw_bitmap(q1,limite_largura_inferior,limite_altura_inferior+10,0);
            char letra[10];
            ElementoTela.PegaOPrimeiro(PAux);
            do
            {

                EscreveCaminho(letra, PAux->getInfo());
                q1=al_load_bitmap(letra);
                DesenhaQuadrado(PAux->getPosInicialX()+2,PAux->getPosInicialY(),q1);
            }
            while (ElementoTela.PegaOProximo(PAux));
            cobra->PegaOPrimeiro(PAux);
            /*
            EscreveCaminho(letra, ElementoCerto->getInfo());
            q1=al_load_bitmap(letra);
            DesenhaQuadrado(->getPosInicialX(),PAux->getPosInicialY(),q1);*/

            do
            {

                EscreveCaminho(letra, PAux->getInfo());
                q1=al_load_bitmap(letra);
                DesenhaQuadrado(PAux->getPosInicialX(),PAux->getPosInicialY(),q1);
            }
            while (cobra->PegaOProximo(PAux));
            al_update_display_region(limite_largura_inferior, limite_altura_inferior, limite_largura_superior, limite_altura_superior);
            delete PAux;
            al_destroy_bitmap(q1);

        }

        void SnakeWord::EscreveCaminho(char* letra, char c)
        {

                letra[0]='i';
                letra[1]='m';
                letra[2]='/';
                letra[3]=c;
                letra[4]='.';
                letra[5]='p';
                letra[6]='n';
                letra[7]='g';
                letra[8]='\0';

        }

        void SnakeWord::FinalizarAllegro()
        {
            al_destroy_event_queue(fila_eventos);
            al_destroy_bitmap(tela_inicial);
            al_destroy_bitmap(botao_jogar_press);
            al_destroy_bitmap(botao_instrucoes_press);
            al_destroy_bitmap(botao_sair_press);
            al_destroy_bitmap(tela_instrucoes);
            al_destroy_bitmap(tela_instrucoes2);
            al_destroy_bitmap(tela_nivel1);
            al_destroy_bitmap(tela_nivel2);
            al_destroy_bitmap(tela_nivel3);
            al_destroy_timer(timer);
            al_destroy_font(fonte);
        }

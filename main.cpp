#include <allegro.h>
#include<iostream>
/*
#include <cstdio>
#include <ctime>
*/
#define MAXFILAS 20
#define MAXCOLS 33
using namespace std;

#include "definiciones.h"
#include "metodos_comida.cpp"
#include "metodos_mapa.cpp"

#include "estado_juego.cpp"
#include "enemigo.h"
#include "movimiento_personaje.cpp"
#include "iniciar_allegro.cpp"

int main(){
    bool fin_menu=false;
    bool lose;
    bool salir=false;
    char c1[10],c2[10];


    iniciar_allegro();

    fondo1 = load_bitmap("menu/FONDO1.bmp", NULL);
    fondo2 = load_bitmap("menu/FONDO2.bmp", NULL);
    fondo3 = load_bitmap("menu/FONDO3.bmp", NULL);
    cursor = load_bitmap("menu/cursor.bmp", NULL);

    roca = load_bitmap ("images/roca.bmp", NULL);
    personajebmp = load_bitmap("images/jugador.bmp", NULL);
    comida = load_bitmap("images/comida.bmp", NULL);
    muertebmp= load_bitmap ("images/muerte.bmp", NULL);
    poke1=load_bitmap("images/poke1.bmp",NULL);
    poke2=load_bitmap("images/poke2.bmp",NULL);

    win=load_bitmap("images/ganaste.bmp",NULL);
    loser=load_bitmap("images/perdiste.bmp",NULL);

    musica1 = load_midi("sounds/fondo.mid");




    /* ------- Implementacion del Menu -----*/
     buffer =create_bitmap(800,530);

     while(!fin_menu){
        if(mouse_x>211 && mouse_x<553 && mouse_y>319 && mouse_y<374)
        {
            blit(fondo2,buffer,0,0,60,0,800,530);
            if(mouse_b&1){
                fin_menu=true;
            }
        } else if(mouse_x>311 && mouse_x<404 && mouse_y>418 && mouse_y<465){
                  blit(fondo3,buffer,0,0,60,0,800,530);
                  if(mouse_b&1){
                    fin_menu=true;
                    return 0;
                  }

    }else blit(fondo1,buffer,0,0,60,0,800,530);

    masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
    blit(buffer,screen,0,0,60,0,880,600);

    }


    clear(buffer);
    clear(cursor);
    clear(fondo1);
    clear(fondo2);
    clear(fondo3);

   //enemigos
    Enemigo<int> A(30*3,30*2);
    Enemigo<int> B(30*7,30*4);
    Enemigo<int> C(30*9,30*7);
    Enemigo<int> D(30*11,30*4);
    Enemigo<int> E(30*13,30*7);
    Enemigo<int> F(30*15,30*5);
    Enemigo<int> G(30*19,30*8);
    Enemigo<int> H(30*21,30*6);
    Enemigo<int> I(30*27,30*2);

    //Personaje<int> P(30*1, 30*2);

    /*  Implementamos la pantalla del juego  */
    buffer =create_bitmap(940,600);
    personaje = create_bitmap(30,30);
    play_midi(musica1,1);//iniciamos musica de fondo


  while(win_juego()==true && lose_juego()==false ){
        if(key[KEY_ESC]) return 0;

        movimiento_personaje();

        clear(buffer);//limpiamos pantalla

        dibujar_mapa();
        dibujar_personaje();

        A.mover_enemigo();
        B.mover_enemigo();
        C.mover_enemigo();
        D.mover_enemigo();
        E.mover_enemigo();
        F.mover_enemigo();
        G.mover_enemigo();
        H.mover_enemigo();
        I.mover_enemigo();

        pantalla();
        rest(70);

        clear (personaje);
        blit(personajebmp,personaje,4*33,0,0,0,33,33);// imprimir imagen de personaje
        draw_sprite(buffer, personaje, px,py);
        pantalla();
        rest(90);

  }


  clear(buffer);
  clear(personaje);
  clear(roca);
  clear(personajebmp);
  clear(comida);
  clear(muertebmp);
  clear(poke1);
  clear(poke2);
  clear(screen);


    destruir_pila();// calculamos el bono


    int Total=puntaje+bonusPoke1+bonusPoke2;
     //dibujamos las pantallas para  cada caso !!!
    while(!salir){
    /*-----  pierdee ------*/
    if(lose_juego()==true){

        blit(loser,buffer,0,0,60,0,880,600);
        textout(buffer,font,"Tu Puntaje es:",220,350,pallete_color[14]);
        textout_ex(buffer, font, itoa(puntaje,c1,10), 240, 380,  0xfff000, -1);
        textout(buffer,font,"Bonus Poke 2(200) :      Bonus  Poke 1(100):",220,410,pallete_color[14]);
        textout_ex(buffer, font, itoa(bonusPoke2,c2,10), 300, 430,  0xfff000, -1);
        textout_ex(buffer, font, itoa(bonusPoke1,c2,10), 450, 430,  0xfff000, -1);
        textout(buffer,font,"Total de Puntos :",220,460,pallete_color[14]);
        textout_ex(buffer, font, itoa(Total,c2,10), 400, 460,  0xfff000, -1);
        textout(buffer,font,"Presione ESC o ENTER para salir",220,490,pallete_color[14]);
        blit(buffer,screen,0,0,0,0,880,600);
        midi_pause();
        if(key[KEY_ESC]||key[KEY_ENTER]){
            salir=true;
        }
    }

    /*----- ganaa ------*/
    if(win_juego()==false){
        blit(win,buffer,0,0,60,0,880,600);
        textout(buffer,font,"Tu Puntaje es:",220,350,pallete_color[14]);
        textout_ex(buffer, font, itoa(puntaje,c1,10), 240, 380,  0xfff000, -1);
        textout(buffer,font,"Bonus Poke 2(200) :      Bonus  Poke 1(100):",220,410,pallete_color[14]);
        textout_ex(buffer, font, itoa(bonusPoke2,c2,10), 300, 430,  0xfff000, -1);
        textout_ex(buffer, font, itoa(bonusPoke1,c2,10), 450, 430,  0xfff000, -1);
        textout(buffer,font,"Total de Puntos :",220,460,pallete_color[14]);
        textout_ex(buffer, font, itoa(Total,c2,10), 400, 460,  0xfff000, -1);
        textout(buffer,font,"Presione ESC o ENTER para salir",220,490,pallete_color[14]);
        blit(buffer,screen,0,0,0,0,880,600);
        midi_pause();
        if(key[KEY_ESC]||key[KEY_ENTER]){
            salir=true;
        }
    }
    }

    destroy_midi(musica1);
    destroy_bitmap(buffer);
    destroy_bitmap(win);
    destroy_bitmap(loser);
    destroy_bitmap(personajebmp);
    destroy_bitmap(personaje);
    destroy_bitmap(comida);
    destroy_bitmap(roca);
    destroy_bitmap(muertebmp);
    destroy_bitmap(poke1);
    destroy_bitmap(poke2);


}
END_OF_MAIN();

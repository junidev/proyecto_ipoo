template <class T>
class Personaje{
public:
    BITMAP *personajebmp;
    BITMAP *personaje;
    T dir ;
    //px, py;
    T anteriorpx, anteriorpy;

    Personaje(T px, T py){
        px = px;
        py = py;
        dir = 4;
        personajebmp = load_bitmap("images/jugador.bmp", NULL);
        personaje = create_bitmap(30,30);

    }

    T getX(){return px;}
    T getY(){return py;}
    BITMAP getPersonaje(){return personaje;}
    T getAnteriorpx(){return anteriorpx;}
    T getAnteriorpy(){return anteriorpy;}
    T getDir(){ return dir;}
    void setX(T x) {x = x;}
    void setY(T y) {y = y;}
    void setAnteriorpx(T x) {anteriorpx = x;}
    void setAnteriorpy(T y) {anteriorpx = y;}
    void setDir(T new_dir){ dir = new_dir; }

    void dibujar_personaje(){
         // coordenas para el persona
        //los ultimso son los tamaño dela imagen
        blit(personajebmp,personaje,dir*33,0,0,0,33,33);// imprimir imagen de personaje
         // coordenas en donde  situan en la pantalla
        draw_sprite(buffer, personaje, px,py);
    }

    void mover_personaje(T px, T py){
          anteriorpx = px;
          anteriorpy = py;
          if(key[KEY_RIGHT]) dir=1;
          else if(key[KEY_LEFT]) dir=0;
          else if(key[KEY_UP]) dir=2;
          else if(key[KEY_DOWN]) dir=3;


            //avance del personaje
          if(dir == 0){
                //validacion de los muros
                if(mapa[py/30][(px-30)/30]!='X')
                    px -= 30;
                else dir = 4;
            }
          if(dir == 1){
                if(mapa[py/30][(px+30)/30]!='X')
                   px += 30;
                else dir = 4;
          }
          if(dir == 2){
                if(mapa[(py-30)/30][(px)/30]!='X')
                   py -= 30;
                else dir = 4;
          }
          if(dir == 3){
                if(mapa[(py+30)/30][(px)/30]!='X')
                   py += 30;
                else dir = 4;
          }
          if(px <= -30) px = 870;
           else if (px>=870) px = -30;
    }


};
















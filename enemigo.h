// ----------------------- Comportamientos -------------------------
class AtaqueComportamiento{
};


class velocidad1 : public AtaqueComportamiento{
	public:
		int cambio(){
			return 20;
		}
};

class velocidad2 : public AtaqueComportamiento{
	public:
		int cambio(){
			return 30;
		}
};




template <class T>
class Enemigo{
private:
    AtaqueComportamiento *ataqueComportamiento;
    BITMAP *enemigobmp;
    BITMAP *enemigo;
    T fdir ;
    T _x, _y;

public:
    Enemigo(T x, T y){
        _x = x;
        _y = y;
        fdir = rand()%4;
        enemigobmp = load_bitmap("images/enemigo.bmp",NULL);
        enemigo = create_bitmap(30,30);

    }

    T get_X(){return _x;}
    T get_Y(){return _y;}
    T get_fdir(){ return  fdir;}
    void set_X(T x) {_x = x;}
    void set_Y(T y) {_y = y;}
    void set_fdir(T new_fdir){ fdir = new_fdir; }


    void dibujar_enemigo(T _x, T _y){
         blit(enemigobmp,enemigo ,0,0,0,0,30,30);
         draw_sprite(buffer, enemigo, _x,_y);
    }

    void mover_enemigo(){
        dibujar_enemigo(_x, _y);
        choque_personaje(_x, _y);
        if(mapa[_y/30][_x/30] == '|'){
            fdir = rand()%4;
        }
        if(fdir == 0){
           if(mapa[_y/30][(_x-30)/30]!= 'X') _x-=30;
                else fdir = rand()%4;
        }
        if(fdir == 1){
           if(mapa[_y/30][(_x+30)/30]!= 'X') _x+=30;
                else fdir = rand()%4;
        }
        if(fdir == 2)        {
           if(mapa[(_y-30)/30][(_x)/30]!= 'X') _y-=30;
                else fdir = rand()%4;
        }
        if(fdir == 3){
           if(mapa[(_y+30)/30][(_x)/30]!= 'X') _y+=30;
                else fdir = rand()%4;
        if(_x <= -30) _x=870;
                else if(_x >= 870) _x = -30;
         }

    }

    void choque_personaje(T _x, T _y){
        if(py== _y && px == _x || _y ==anteriorpy && _x==anteriorpx)
        {

            for(int j=0;j<=5;j++){
                clear(personaje);
                clear(buffer);
                dibujar_mapa();

                blit(muertebmp, personaje,j*33,0,0,0,33,33);
                draw_sprite(buffer,personaje,px,py);

                pantalla();
                rest(80);

            }
            vidas--;
            cout<<endl<<"vidas"<<vidas<<endl;
            pop();//desapilar TOS
            px =30*1;
            py =30*2;
            dir =4;
        }
    }
};


















void movimiento_personaje(){
      anteriorpx = px;
      anteriorpy = py;
      if(key[KEY_RIGHT]) dir=1;
      else if(key[KEY_LEFT]) dir=0;
      else if(key[KEY_UP]) dir=2;
      else if(key[KEY_DOWN]) dir=3;


        //avance del personaje
      if(dir == 0)
        {
            //validacion de los muros
            if(mapa[py/30][(px-30)/30]!='X')
                px -= 30;
            else dir = 4;
        }
      if(dir == 1)
      {
            if(mapa[py/30][(px+30)/30]!='X')
               px += 30;
            else dir = 4;
      }
      if(dir == 2)
      {
            if(mapa[(py-30)/30][(px)/30]!='X')
               py -= 30;
            else dir = 4;
      }
      if(dir == 3)
      {
            if(mapa[(py+30)/30][(px)/30]!='X')
               py += 30;
            else dir = 4;
      }
      if(px <= -30) px = 870;
       else if (px>=870) px = -30;


}

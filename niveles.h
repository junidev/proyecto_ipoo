template <class T>
class Nivel{
private:
    T mapa;

public:
    Nivel();

void dibujar_mapa(T mapa){
      int row, col;
      for (row = 0 ; row<MAXFILAS ; row++)
      {
        for (col = 0 ; col<MAXCOLS ; col++)
        {
          if(mapa[row][col] == 'X')
          {
               // x 30 por la imagen....
            draw_sprite(buffer, roca, col*30, row*30);
          }
          else if(mapa[row][col] == 'O')
                {
                    draw_sprite(buffer, comida, col*30, row*30);
                     //si personaje esta en la comida  vacealo
                    //divdimoa en 30 xk asimlo tamos moviendo al personaje
                    //y comienxa en py pero x 30... x pixeles
                    if(py/30 == row && px/30 == col)
                      {
                          mapa[row][col] = ' ';
                          puntaje=puntaje+10;

                      }
                }
                else if(mapa[row][col]=='A')//  personaje come un diamante azul
                {
                    draw_sprite(buffer,diamante1,col*30,row*30);
                    if(py/30 == row && px/30 == col)
                      {
                          mapa[row][col] = ' ';
                          push('A');

                        }
                }

                if(mapa[row][col]=='R') //personaje come un diamante rojo
                {
                    draw_sprite(buffer,diamante2,col*30,row*30);
                    if(py/30 == row && px/30 == col)
                      {
                          mapa[row][col] = ' ';
                          push('R');

                        }
                }
                char c1[3];
                textout_ex(buffer, font, "Vidas:", 885, 30,  0xfff000, -1);
                textout_ex(buffer, font, itoa(vidas,c1,10), 895, 60,  0xfff000, -1);//muestra las vidas en pantalla

                //muestra tiempo
                std::clock_t start;
                double duration;
                start = std::clock();
                //
                duration = ( std::clock() - 50 ) / (double) CLOCKS_PER_SEC;
                textout_ex(buffer, font, "Tiempo:", 885, 90,  0xfff000, -1);
                textout_ex(buffer, font, itoa(duration,c1,10), 895, 110,  0xfff000, -1);//muestra las vidas en pantalla
                mostrar_pila();//dibujar diamantes apilados en pantalla
        }
      }
}






};


















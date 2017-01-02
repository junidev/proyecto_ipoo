/*----------Funcion que determina si las monedas se acabaron------*/
bool win_juego(){
    int row, col;

  for (row = 0 ; row<MAXFILAS ; row++){
    for (col = 0 ; col<MAXCOLS ; col++){
      if(mapa[row][col] == 'O')  return true;
    }
  }
  return false;
}

/*------- Funcion que activa el fin del juego si es que las vidas llegan a cero ------*/
bool lose_juego(){
    if(vidas==0) return true;
    return false;
}

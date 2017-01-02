using namespace std;
struct nodo {
    char item;
    struct nodo *sgte;
};

typedef nodo *Puntero;

Puntero p=NULL;

int puntaje=0;
int bonusPoke1=0;
int bonusPoke2=0;

/*----Funcion Apilar valor----*/
void push( char valor )
{
     Puntero aux;
     aux = new(struct nodo);
     aux->item = valor;
     cout<<endl<<aux->item;
     aux->sgte = p ;
     p = aux ;
}
/*---Funcion que es llamada cuando pacan pierde una vida  ----*/
int pop()
{   char it;

     Puntero aux;
     if(p!=NULL){
     aux = p ;
     it = aux->item;
     cout<<endl<<"desapilado:"<<it<<endl;
     p = aux->sgte ;
     delete(aux);
     } else cout<<endl<<"no hay elementos"<<endl;


}

/*Funcion que muestra el elemento apilado en pantalla*/
void mostrar_pila()
{
     int c=0;
     Puntero aux;
     aux = p;     // apunta al inicio de la lista

     while( aux !=NULL )
     {      if(aux->item=='A')//POKE 1
            draw_sprite(buffer,poke1,30*30,d-c*30);//posiciona la imagen a la derecha lo resta..

            if(aux->item=='R')//POKE 2
            draw_sprite(buffer,poke2,30*30,d-c*30);

            aux = aux->sgte;
            c++;
     }
}

/*---- Funcion que desapila y destruye la pila -----*/
void destruir_pila( )
{
     Puntero aux;

     while( p != NULL)
     {
           aux = p;
           p = aux->sgte;
           if(aux->item=='A')
                bonusPoke1=bonusPoke1+100;
           if(aux->item=='R')
                bonusPoke2=bonusPoke2+200;
           delete(aux);

     }
}


#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct nodo{
  string palabra;
  int frecuencia;
  int indicador;
  nodo *sig;
};

int posicion(string palabra){
  int i=0;
  int o;
  char aux, posicion[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  for(i=0;i<26;i++){
    aux=tolower(palabra[0]);
    if(aux==posicion[i]){
      return i;
    }

  }
}

nodo *crear_lista(nodo *lista, string palabra){
  int cont=0;
  nodo *q; //Para ingesar un dato nuevo
  nodo *r; //Para recorrer la lista.
  q=new nodo; //Para buscar y asignarle un espacio de memoria.
  q->palabra = palabra;
  q->frecuencia=1;
  q->indicador=posicion(palabra);
  q->sig=NULL; //Cuando se le agrega un dato nuevo, no hay "siguientes"
  if(lista==NULL){
    lista=q;
  }else{
    r=lista; //Guardamos la lista completa en r
    while(r->sig!=NULL && cont==0 ){
      if(r->palabra == q->palabra){
        r->frecuencia++;
        cont++;
      }
      r=r->sig;
    }
    if(r->palabra == q->palabra){ //Se repite la comparación para hacerla con la última posición de la lista
        r->frecuencia++;
        cont++;
    }
    if(cont==0){
      r->sig=q;
    }

  }
  return lista;
}


int main(void)
{
  int cont=0;
  char opc;
  nodo * lista = NULL; // Estoy dandolo el "Primer valor a lista", Lista es la "cabeza" de nuestra lista
  string palabra, aux;
  fstream Entrada("archivo_4.tex"); //Se crea variabe para archivo de entrada
  while(Entrada>>palabra) //Aquí se realiza la lectura y la condición de que aún no ha terminado el archivo
  {
    lista = crear_lista(lista, palabra);
  }
  while(lista){
    if(lista->indicador==19){
      cout<<lista->palabra<<" "<<lista->indicador<<" "<<lista->frecuencia<<endl;
      cont++;
    }
    lista=lista->sig;
  }
}



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

void distintas(nodo *lista){
  nodo *aux;
  aux=lista;
  int cont = 0, i; //Para contar las palabras con frecuencia 1
    while(aux){
      i = posicion(aux->palabra);
        if(aux->indicador == i){
          if(aux->frecuencia==1){
            cont++;
          }
        }
      aux=aux->sig;
    }
  cout<<"Existen "<<cont<<" palabras distintas en el archivo"<<endl;
}

void mayor_frecuencia(nodo *lista){
  nodo *aux;
  aux=lista;
  int mayor=0, i;
  string palabramayor;
  while(aux){
    i = posicion(aux->palabra);
      if (aux->indicador == i){
        if(mayor<aux->frecuencia){
          mayor=aux->frecuencia;
          palabramayor=aux->palabra;
        }
      }
    aux=aux->sig;
  }
  cout<<"La palabra con mayor frecuencia es: "<<palabramayor<<endl;
  cout<<"y su frecuencia es: "<<mayor<<endl;
}

void buscar_palabra(nodo *lista){
  nodo *aux;
  aux=lista;
  string palabraIn;
  int cont=0, i;
  cout<<"Ingrese la palabra que desea buscar: ";
  cin>>palabraIn;
  while(aux){
    i = posicion(aux->palabra);
      if(aux->indicador == i){
        if(palabraIn == aux->palabra){
          cout<<"La palabra "<<palabraIn<<" se encuentra en el archivo "<<aux->frecuencia<<" veces"<<endl;
          cont++;
        }
      }
    aux=aux->sig;
  }
  if(cont==0){
    cout<<"La palabra "<<palabraIn<<" no se encuentra en el archivo"<<endl;
  }
  palabraIn.clear();
}

void imp_lista(nodo *aux)
{
  while (aux)
  {
    cout<<aux->palabra<< "  " <<aux->frecuencia<< endl;
    aux = aux->sig;
  }
  cout << endl;
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
  cout<<"1.- Encontrar la palabra"<<endl;
  cout<<"2.- Encontrar palabras distintas "<<endl;
  cout<<"3.- Encontrar palabra con mayor frecuencia"<<endl;
  cout<<"4.- Imprimir la lista (palabra  frecuencia)"<<endl;
  cout<<"5.- Salir"<<endl;
  cout<<"Ingrese la opción que desea: ";
  cin>>opc;
  while(opc!='5'){
    if(opc=='1'){
      buscar_palabra(lista); // Se busca la palabra que escriba el usario
    }
    else
    if(opc=='2'){
      distintas(lista); //Se busca cuantas palabras distintas existen en el texto
    }
    else if(opc=='3'){
      mayor_frecuencia(lista); //Se busca la palabra con mayor frecuencia
    }
    else if(opc=='4'){
      imp_lista(lista); //Se imprime la lista completa con la frecuencia de cada palabra (palabra  frecuencia)
    }
    else{
      cout<<"Ingrese una opción válida";
      cin>>opc;
    }
    cout<<"Ingrese la opción que desea: ";
    cin>>opc;
  }

}

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct nodo{
  string palabra;
  int frecuencia;
  nodo *sig;
};

nodo *crear_lista(nodo *lista, string palabra); //* Por que se retorna el nodo tipo puntero 
void mayor_frecuencia(nodo *lista);


int main(void)
{
  nodo * lista = NULL; // Estoy dandolo el "Primer valor a lista", Lista es la "cabeza" de nuestra lista
  nodo * auxl;

  unsigned int i=0, n, j, k, l = 0, mayor=0;
  //char opc,letra;
  string palabra, aux;

 fstream Entrada("archivo_4.tex"); //Se crea variabe para archivo de entrada

  while(Entrada>>palabra) //Aquí se realiza la lectura y la condición de que aún no ha terminado el archivo
  {
  	//cout<<palabra<<endl;
  	lista=crear_lista(lista, palabra);
  }
  mayor_frecuencia(lista);
 }

 nodo *crear_lista(nodo *lista, string palabra){
 	int cont=0;
 	nodo *q; //Para ingesar un dato nuevo
 	nodo *r; //Para recorrer la lista.
 	q=new nodo; //Para buscar y asignarle un espacio de memoria.
 	q->palabra = palabra;
 	q->frecuencia=1;
 	q->sig=NULL; //Cuando se le agrega un dato nuevo, no hay "siguientes"
 	//cout<<q->palabra<<endl;
 	if(lista==NULL){
 		lista=q;
 	}else{
 		r=lista; //Guardamos la lista completa en r
 		while(r->sig!=NULL && cont==0 ){
 			//cout<<"flag"<<endl;
 			//cout<<r->palabra<<"=="<<q->palabra<<endl;
 			//cout<<"flag"<<endl;
 			if(r->palabra == q->palabra){
 				r->frecuencia++;
 				cont++;
 			//	cout<<"ENTRÓ"<<endl;
 			}
 			r=r->sig;
 		}
 		if(r->palabra == q->palabra){ //Se repite la comparación para hacerla con la última posición de la lista
 				r->frecuencia++;
 				cont++;
 		}
 		if(cont==0){
 			r->sig=q;
 			//cout<<"Flag"<<endl;

 		}

 	}
 	return lista;
}

void mayor_frecuencia(nodo *lista){
	nodo *aux;
	aux=lista;
	int mayor=0;
	string palabramaiogggg;
	while(aux!=NULL){
		if(mayor<aux->frecuencia){
			mayor=aux->frecuencia;
			palabramaiogggg=aux->palabra;
		}
		aux=aux->sig;
	}
	cout<<"La palabra con frecuencia MAIOGGGGGG es: "<<palabramaiogggg<<endl;
	cout<<"y su frecuencia es: "<<mayor<<endl;
}
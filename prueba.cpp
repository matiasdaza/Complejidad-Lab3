#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct nodo{
  string p;
  int repeticiones;
  nodo *sig;
};
/*
void quicksort(unsigned int **datos, int inicio, int fin) // Método de ordenamiento Quicksort
{
  int pivote;
  if(inicio<fin)
  {
    pivote = divide(datos, inicio,fin);
    //ordenar menores
    quicksort(datos,inicio,pivote-1);
    //ordenar mayores
    quicksort(datos,pivote+1,fin);
  }
}
*/
void crear_lista(nodo *&lista, unsigned int &i, string palabra){
  nodo * aux1; //aux
  nodo * aux2;  //ele
  bool esta;
  if(lista==NULL) // Se agrega el primer elemento en la lista
  {
    aux2 = new nodo;
    aux2->p=palabra;
    aux2->repeticiones=1;
    aux2->sig = NULL;

    lista=aux2;
    i++;
  }
  else
  {
    aux1=lista;
    esta=false;
    while(true) // Se cuenta la frecuencia de dígitos consecutivos en el archivo cuando el número está en la lista
    {
      if(aux1-> p == palabra)
      {
        aux1 -> repeticiones++;
        esta=true;
        break;
      }
      else if(aux1->sig==NULL)
      {
        break;
      }
      aux1=aux1->sig;
    }
    if(esta==false)
    {
      aux2=new nodo;
      aux2->p=palabra;
      aux2->repeticiones=1;
      aux2->sig=NULL;
      aux1->sig=aux2;
      i++;
    }
  }
}

int main(void)
{
  nodo * lista = NULL;
  nodo * auxl;

  unsigned int i=0, n, j, k, l = 0;
  //char opc,letra;
  string palabra;

 fstream Entrada("archivo_4.tex"); //Se crea variabe para archivo de entrada

  while(!Entrada.eof())
  {
  Entrada>>palabra;
  if (Entrada.eof())
    break;
  cout<<palabra<<endl;
  crear_lista(lista, i, palabra);
  }
  cin>>n;
  while(lista) // Se copia la lista a un arreglo para luego eliminarla
      {
      cout<<lista->p<<endl;
        lista=lista->sig;
  
      }

 //Entrada.close(); // Se cierran los archivos
}

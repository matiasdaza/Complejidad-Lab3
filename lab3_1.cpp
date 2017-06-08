#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct nodo{
  string palabra;
  int frecuencia;
  nodo *sig;
};

nodo *crear_lista(nodo *lista, string palabra); //* Por que se retorna el nodo tipo puntero 
nodo *cola( nodo *actual);
nodo *particion(nodo *cabeza, nodo *fin, nodo **newCabeza, nodo **newFin);
nodo *quickSortRecur(nodo *cabeza, nodo *fin);
void mayor_frecuencia(nodo *lista);
void distintas(nodo *lista);
void buscar_palabra(nodo *lista);
void imp_lista(nodo *lista);
void quickSort(struct nodo **cabezaRef);


int main(void)
{
  char opc;
  nodo * lista = NULL; // Estoy dandolo el "Primer valor a lista", Lista es la "cabeza" de nuestra lista
  string palabra, aux;
  fstream Entrada("archivo_4.tex"); //Se crea variabe para archivo de entrada
  while(Entrada>>palabra) //Aquí se realiza la lectura y la condición de que aún no ha terminado el archivo
  {
    lista=crear_lista(lista, palabra);
  }
  quickSort(&lista); // Se ordena la lista con el método de ordenamiento QuickSort
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
    else if(opc=='2'){
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

nodo *cola(nodo *actual)
{
  while (actual != NULL && actual->sig != NULL)
    actual = actual->sig;
  return actual;
}

nodo *particion(nodo *cabeza, nodo *fin, nodo **newCabeza, nodo **newFin)
{
  nodo *pivote = fin;
  nodo *prev = NULL, *actual = cabeza, *cola = pivote;

  //Durante la partición, ambas cabezas y finales de la lista podrían cambiar
  while (actual != pivote)
  {
    if (actual->frecuencia < pivote->frecuencia)
    {
      // El primer nodo que tiene un valor menor que el pívote se transforma en la nueva cabeza
      if ((*newCabeza) == NULL)
        (*newCabeza) = actual;

      prev = actual;  
      actual = actual->sig;
    }
    else //Si el actual nodo es mayor qu el pivote
    { //Se mueve el actual nodo al siguiente espacio de la cola, y se cambia la cola
      if (prev)
        prev->sig = actual->sig;
      nodo *aux = actual->sig;
      actual->sig = NULL;
      cola->sig = actual;
      cola = actual;
      actual = aux;
    }
  }

  // Si el pivote de la frecuencia es el menor elemento en la lista, el pivote se transforma en la cabeza
  if ((*newCabeza) == NULL)
    (*newCabeza) = pivote;

  // Actualizar newFin con el actual último nodo
  (*newFin) = cola;

  // Retornar el nodo pivote
  return pivote;
}

//Aquí ocurre el ordenamiento sólo si exclusivamente es el final del nodo
nodo *quickSortRecur(nodo *cabeza, nodo *fin)
{
    //Condición base 
    if (!cabeza || cabeza == fin)
        return cabeza;
 
    nodo *newCabeza = NULL, *newFin = NULL;
 
    // Se divide la lista, newCabeza y newFin podrían actualizarse por la función
    nodo *pivote = particion(cabeza, fin, &newCabeza, &newFin);
 
    // Si el pivote es menor que la frecuencia entrante, no es necesario hacer la recursividad para la parte izquierda
    if (newCabeza != pivote)
    {
        // Actualizar el nodo antes de que nodo pivote sea NULL
        nodo *aux = newCabeza;
        while (aux->sig != pivote)
            aux = aux->sig;
        aux->sig = NULL;
 
        // Aplicar recursividad para la lista antes del pivote
        newCabeza = quickSortRecur(newCabeza, aux);
 
        // Cambiar sig del último nodo de la mitad izquierda del pivote
        aux = cola(newCabeza);
        aux->sig =  pivote;
    }
 
    // Se aplica la recursivdad a la lista después del elemento del pivote
    pivote->sig = quickSortRecur(pivote->sig, newFin);
 
    return newCabeza;
}

// Función quickSort
void quickSort(nodo **cabezaRef)
{
    (*cabezaRef) = quickSortRecur(*cabezaRef, cola(*cabezaRef));
    return;
}

void mayor_frecuencia(nodo *lista){
	nodo *aux;
	aux=lista;
	int mayor=0;
	string palabramayor;
	while(aux!=NULL){
		if(mayor<aux->frecuencia){
			mayor=aux->frecuencia;
			palabramayor=aux->palabra;
		}
		aux=aux->sig;
	}
	cout<<"La palabra con frecuencia mayor es: "<<palabramayor<<endl;
	cout<<"y su frecuencia es: "<<mayor<<endl;
}

void distintas(nodo *lista){
  nodo *aux;
  aux=lista;
  int cont = 0; //Para contar las palabras con frecuencia 1
  while(aux!=NULL){
    if(aux->frecuencia==1){
      cont++;
    }
    aux=aux->sig;
  }
  cout<<"Existen "<<cont<<" palabras distintas en el archivo"<<endl;
}

void buscar_palabra(nodo *lista){
  nodo *aux;
  aux=lista;
  string palabraIn;
  int cont=0;
  cout<<"Ingrese la palabra que desea buscar: ";
  cin>>palabraIn;
  while(aux!=NULL){
    if(palabraIn == aux->palabra){
      cout<<"La palabra "<<palabraIn<<" se encuentra en el archivo "<<aux->frecuencia<<" veces"<<endl;
      cont++;
    }
    aux=aux->sig;
  }
  if(cont==0){
    cout<<"La palabra "<<palabraIn<<" no se encuentra en el archivo"<<endl;
  }
  palabraIn.clear();
}

void imp_lista(nodo *cabeza)
{
  while (cabeza)
  {
    cout<<cabeza->palabra<< "  " <<cabeza->frecuencia <<endl;
    cabeza = cabeza->sig;
  }
  cout << endl;
}

#include <iostream>
#include <fstream>
#include <string.h>



using namespace std;

struct nodo{
  int numero; 
  int repeticiones;
  nodo *sig;  
};

void crear_lista(nodo *&lista, unsigned int &i, int n){
  nodo * aux1; //aux
  nodo * aux2;  //ele
  bool esta;
  if(lista==NULL) // Se agrega el primer elemento en la lista
  { 
    aux2 = new nodo;
    aux2->numero=n;
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
      if(aux1-> numero == n)
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
      aux2->numero=n;
      aux2->repeticiones=1;
      aux2->sig=NULL;
      aux1->sig=aux2;
      i++;
    }
  }
}

int divide(unsigned int **datos, int inicio, int fin) //divide el vector usando el método de ordenamiento Quicksort
{
  int izquierda, derecha, pivote, auxNumero, auxRepeticiones;
  pivote=datos[inicio][1];
  izquierda=inicio;
  derecha=fin;

  while(izquierda < derecha)
  {
    while(datos[derecha][1] > pivote)
    {
      derecha--;
    }
    while( (izquierda < derecha) && (datos[izquierda][1]) <= pivote)
    {
      izquierda++;
    } 
    if(izquierda<derecha)
    {
      auxNumero=datos[izquierda][0];
      auxRepeticiones=datos[izquierda][1];
      datos[izquierda][0] = datos[derecha][0];
      datos[izquierda][1] = datos[derecha][1];
      datos[derecha][0]=auxNumero;
      datos[derecha][1]=auxRepeticiones;
    }
  }
  auxNumero=datos[derecha][0];
  auxRepeticiones=datos[derecha][1];

  datos[derecha][0]=datos[inicio][0];
  datos[derecha][1]=datos[inicio][1];

  datos[inicio][0]=auxNumero;
  datos[inicio][1]=auxRepeticiones;

  return derecha;
}
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

void frecuencia_mayor(unsigned int largo, unsigned int **datos) //Se muestran la o las cadenas de digitos con mayor frecuencia
{
  int i;
  for(i=largo;i>=0;i--)
  {
    cout<<datos[i][0]<<" "<<datos[i][1];
    if(datos[i-1][1]<datos[i][1])
    {
      break;
    }
  }
}
void frecuencia(unsigned int largo, unsigned int **datos) //Se muestran las cadenas repetidas al menos una vez
{ 
  int i;
  for(i=largo;i>=0;i--)
  {
      if(datos[i][1]==1)
      {
          break;
      }
      cout<<hex<<datos[i][0]<<" "<<datos[i][1]<<endl;
  }


}
void frecuencia_6(unsigned largo, unsigned int **datos) // Se muestran las cadenas de seis dígitos repetidas al menos una vez
{
    int i;
    bool flag=false;

    for(i=largo;i>=0;i--)
    {
        if(datos[i][1]==1)
        {
            break;
        }
        cout<<datos[i][0]<<" "<<datos[i][1]<<endl;
        flag = true;
    }
    if (flag == false)
    {
      cout<<"No se encontraron cadenas de caracteres repetidos"<<endl;
    }


}


int main(void)
{
  nodo * lista = NULL;
  nodo * auxl;

  unsigned int **datos;
  unsigned int i=0, n, j, k, l = 0;
  char opc, aux[5], aux3[7]="";;
  cout<<"\n\n";
  cout<<"Opción 1: archivo_1.tex"<<endl;
  cout<<"Opción 2: archivo_2.tex"<<endl;
  cout<<"Opción 3: archivo_3.tex"<<endl;
  cout<<"\n\n";

  cout<<"\n Elija el archivo con el que desea trabajar: ";
  cin>>opc;

  switch (opc)
  {
    case '1':
    {
      ifstream Entrada("archivo_1.tex"); //Se crea variabe para archivo de entrada
      ofstream Salida("Salida.txt"); // Se crea variable para archivo de salida
      ifstream AuxIn; // Se crea variable para archivo auxiliar
     
      //Primera serie de 4 números
      Entrada>>aux[0];
      Entrada>>aux[1];
      Entrada>>aux[2];
      Entrada>>aux[3];
      aux[4]='\n';

      Salida<<aux;
      aux[0]=aux[1];
      aux[1]=aux[2];
      aux[2]=aux[3];

      // Ahora para el resto de todos los números

      while(Entrada>>aux[3]) //Cuando el archivo esté desde la tercera posición en adelante, para copiar en el resto de los archivos
      { // Se guardan los siguientes 4 digitios en el archivo auxiliar, y así sucesivamente
        Salida<<aux;
        aux[0]=aux[1];
        aux[1]=aux[2];
        aux[2]=aux[3];
      }
      Entrada.close(); // Se cierran los archivos
      Salida.close();

      AuxIn.open("Salida.txt"); //Se lee el archivo auxiliar con los numeros divididos en bloques de 4 digitos
      while(AuxIn>>n) //Se crea la lista con los numeros del archivo auxiliar
      {
        crear_lista(lista, i, n);
      }

      AuxIn.close();

      datos=new unsigned int*[i]; // Se crea el arreglo datos para copiar lo de lista (Con el mismo tamaño de esta)
      for(j=0;j<i;j++)
      {
        datos[j]=new unsigned int[2];
      }

      j=0;

      while(lista) // Se copia la lista a un arreglo para luego eliminarla
      {
        auxl=lista;
        lista=lista->sig;
        datos[j][0]=auxl->numero;
        datos[j][1]=auxl->repeticiones;
        delete auxl;
        j++;
      }

      k=i;

      quicksort(datos,0,k-1); // Se aplica el metodo de ordenamiento QuickSort para el arreglo 

      cout<<"\n Los números que más se repiten son: ";
      frecuencia_mayor(k-1, datos); // Se muestra el numero con mayor frecuencia en el archivo
      break;
    }
    case '2':
    {
      ifstream Entrada("archivo_2.tex");
      ofstream Salida("Salida2.txt");
      ifstream AuxIn;
       //Primera serie de 4 números
      Entrada>>aux[0];
      Entrada>>aux[1];
      Entrada>>aux[2];
      Entrada>>aux[3];
      aux[4]='\0';

      Salida<<aux<<endl;

      aux[0] = aux[1];
      aux[1] = aux[2];
      aux[2] = aux[3];
      //Se lee el archivo original en bloques de a 4 digitos
      while(Entrada>>aux[3])
      {
        // Se guardan los siguientes 4 digitios en el archivo auxiliar, y así sucesivamente
        Salida<<aux<<endl;
        aux[0] = aux[1];
        aux[1] = aux[2];
        aux[2] = aux[3];

      }
      Entrada.close();
      Salida.close();

      // Se lee el archivo auxiliar con los numeros dividido en bloques de 4 digitos
      AuxIn.open("Salida2.txt");
      while(AuxIn>>hex>>n) //Se crea la lista con los numeros en hexadecimal del archivo auxiliar
      {
        crear_lista(lista,l,n);
      }
      AuxIn.close();

      datos = new unsigned int*[l]; // Se crea el arreglo datos para copiar lo de lista (Con el mismo tamaño de esta)
      for(i=0;i<l;i++)
      {
          datos[i] = new unsigned int[2];
      }

      i=0;
      while(lista) // Se copia la lista a un arreglo para luego eliminarla
      {
          auxl=lista;
          lista=lista->sig;
          datos[i][0]=auxl->numero;
          datos[i][1]=auxl->repeticiones;
          i++;
          delete auxl;
      }

      quicksort(datos,0,l-1); // Se aplica el metodo de ordenamiento QuickSort para el arreglo 
      cout<<"\nLos numeros que se repiten son:"<<endl<<endl;
      frecuencia(l-1,datos); // Se muestran los numeros en hexadecimal con sus frecuencias respecto al archivo
      break;
    }
    case '3':
    {
      ifstream Entrada("archivo_3.tex");
      ofstream Salida("Salida3.txt");
      ifstream AuxIn;
       

       //Primera serie de 6 números
      while( Entrada.read(aux3,sizeof(aux3)-1) ) //Se separa en bloques de largo 6 y se ingresan al archivo auxiliar
      { 
        Salida<<aux3<<endl;
      }
      Entrada.close();
      Salida.close();

      AuxIn.open("Salida3.txt"); // Se lee el archivo auxiliar con los numeros dividido en bloques de 6 digitos
      while(AuxIn>>n) //Se crea la lista con los numeros del archivo auxiliar
      {
        crear_lista(lista, i, n);
      }

      AuxIn.close();

      //Se crea el arreglo datos para copiar lo de lista (Con el mismo tamaño de esta)
      datos=new unsigned int*[i];
      for(j=0;j<i;j++){
        datos[j]=new unsigned int[2];
      }

      j=0;

      //Se copia la lista a un arreglo para luego eliminar la lista.
      while(lista)
      {
        auxl=lista;
        lista=lista->sig;
        datos[j][0]=auxl->numero;
        datos[j][1]=auxl->repeticiones;
        delete auxl;
        j++;
      }

      k=i;

      quicksort(datos,0,k-1); // Se aplica el metodo de ordenamiento QuickSort para el arreglo 
      frecuencia_6(k-1, datos); // Se muestran los numeros en hexadecimal con sus frecuencias respecto al archivo
      break;
    }
    default: 
    {
      cout<<"Elija opcíon correcta"; 
      break; 
    }
  }
}
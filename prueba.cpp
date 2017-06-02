#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(void)
{
  int i=0, n, j, k, l = 0;
  char opc, aux[100], aux3[7]="", letra;
  string palabra;

 fstream Entrada("archivo_4.tex"); //Se crea variabe para archivo de entrada

 while(!Entrada.eof()){
 Entrada>>palabra;
 if (Entrada.eof())
   break;
 cout<<palabra<<endl;

}
 //Entrada.close(); // Se cierran los archivos
}

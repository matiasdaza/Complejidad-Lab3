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
 ofstream Salida("Salida.txt"); // Se crea variable para archivo de salida
 ifstream AuxIn; // Se crea variable para archivo auxiliar
 while(!Entrada.eof()){
 Entrada>>palabra;
 cout<<palabra<<endl;
 cin>>n;
}
 //Entrada.close(); // Se cierran los archivos
}
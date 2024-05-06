#include "Archivo.h"
using namespace std;

/// METODOS CLASE ARCHIVO

// RECIBE EL NOMBRE DEL ARCHIVO Y LO ABRE
bool Archivo::abrir(string modo){
   _pFile = fopen(_fileName.c_str(), modo.c_str());

   if(_pFile == nullptr){
      return false;
   }
   return true;
}

// CIERRA EL ARCHIVO
void Archivo::cerrar(){
   fclose(_pFile);
}

#include "Archivo.h"
using namespace std;

bool Archivo::abrir(string modo){
   _pFile = fopen(_fileName.c_str(), modo.c_str());

   if(_pFile == nullptr){
      return false;
   }
   return true;
}

void Archivo::cerrar(){
   fclose(_pFile);
}

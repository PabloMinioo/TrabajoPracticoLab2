#pragma once
#include <string>
#include <cstdio>
class Archivo {
public:

protected:
   FILE* _pFile;
   std::string _fileName;

   bool abrir(std::string modo="rb");
   void cerrar();
};

#pragma once
#include <string>
#include "Empresa.h"
#include "Archivo.h"

class EmpresaArchivo: public Archivo {
private:
public:
    EmpresaArchivo();
    EmpresaArchivo(std::string fileName);

    bool guardar(Empresa empresa);
    bool guardar(int index, Empresa empresa);
    Empresa leer(int index);
    int buscar(int numeroEmpresa);
    bool eliminar(int numeroEmpresa);
    int getCantidadRegistros();
    bool isExist(int numeroEmpresa);
    bool copiaSeguridad(std::string fileName="empresa.bkp");
    bool restaurarCopiaSeguridad(std::string fileName="empresa.bkp");
    bool modificar(Empresa empresa, int index);
//    Empresa leerCopiaSeguridad(int index);
//    Empresa leerDatosInicio(int index);
};

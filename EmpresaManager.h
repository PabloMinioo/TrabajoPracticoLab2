#pragma once
#include "Empresa.h"
#include "EmpresaArchivo.h"

class EmpresaManager{
public:
    void menu();
private:
    Empresa crearEmpresa();
    void mostrar(Empresa empresa);
    void buscarEmpresa();
    void cargarEmpresa();
    void listarEmpresas();
    void eliminarEmpresas();
    void realizarCopiaSeguridad();
    void restaurarCopiaSeguridad();
    EmpresaArchivo empresaArchivo;
};

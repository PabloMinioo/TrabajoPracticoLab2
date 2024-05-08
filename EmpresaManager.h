#pragma once
#include "Empresa.h"
#include "EmpresaArchivo.h"

class EmpresaManager{
private:
    Empresa crearEmpresa();
    void mostrar(Empresa empresa);
    void buscarEmpresa();
    void cargarEmpresa();
    void listarEmpresas();
    void listarCopiaSeguridad();
    void eliminarEmpresas();
    void realizarCopiaSeguridad();
    void restaurarCopiaSeguridad();
    EmpresaArchivo empresaArchivo;
public:
    void menu();
};

#pragma once
#include "Empresa.h"
#include "EmpresaArchivo.h"
#include "MunicipioArchivo.h"

class EmpresaManager{
private:
    Empresa crearEmpresa();
    void mostrar(Empresa empresa);
    void buscarEmpresa();
    void cargarEmpresa();
    void listarEmpresas();
    void listarCopiaSeguridad();
    void listarDatosInicioEmpresa();
    void eliminarEmpresas();
    EmpresaArchivo empresaArchivo;
    MunicipioArchivo archivoMunicipio;
//    Fecha fecha;
public:
    void menu();
};

#pragma once
#include "Empresa.h"
#include "EmpresaArchivo.h"
#include "MunicipioArchivo.h"
#include "Fecha.h"

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
    void modificarFechaCreacion();
    EmpresaArchivo empresaArchivo;
    MunicipioArchivo archivoMunicipio;
    Fecha fechaCreacion;
public:
    void menu();
};

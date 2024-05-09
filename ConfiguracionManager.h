#pragma once
#include <string>
#include "EmpresaArchivo.h"
#include "MunicipioArchivo.h"
#include "Archivo.h"

class ConfiguracionManager {
private:
    EmpresaArchivo empresaArchivo;
    MunicipioArchivo municipioArchivo;
    void crearCopiaSeguridadEmpresas();
    void crearCopiaSeguridadMunicipios();
    void restaurarCopiaSeguridadEmpresas();
    void restaurarCopiaSeguridadMunicipios();
public:
    void menu();

};

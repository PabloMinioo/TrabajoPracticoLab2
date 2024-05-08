#pragma once
#include <string>
#include "EmpresaArchivo.h"
#include "Archivo.h"

class ConfiguracionManager {
private:
    EmpresaArchivo empresaArchivo;
    void crearCopiaSeguridadEmpresas();
    void crearCopiaSeguridadMunicipios();
    void restaurarCopiaSeguridadEmpresas();
    void restaurarCopiaSeguridadMunicipios();
public:
    void menu();

};

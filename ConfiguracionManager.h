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
    void copiarArchivosInicio(std::string archivoOrigen, std::string archivoDestino);
    void copiarArchivos(std::string archivoOrigen, std::string archivoDestino);
    void establecerDatosInicio();
public:
    void menu();

};

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
    void establecerDatosInicio();
    void copiarArchivos(std::string archivoOrigen, std::string archivoDestino);
//    void copiarArchivosInicio(std::string archivoOrigen, std::string archivoDestino);
public:
    void menu();

};

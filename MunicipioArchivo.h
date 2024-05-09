#pragma once
#include <string>
#include "Municipio.h"
#include "Archivo.h"


class MunicipioArchivo : public Archivo {
private:
public:
    MunicipioArchivo();
    MunicipioArchivo(std::string filename);
    bool guardar(Municipio municipio);
    int buscar(int numMunicipio);
    Municipio leer(int index);
    Municipio leerCopiaSeguridad(int index);
    bool modificar(Municipio municipio, int index);
    bool eliminar(int numMunicipio);
    int getCantidadMunicipios();
    bool copiaSeguridad(std::string fileName="municipios.bkp");
    bool restaurarCopiaSeguridad(std::string fileName="municipios.bkp");
};

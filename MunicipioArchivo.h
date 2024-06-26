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
    bool isExist(int numeroMunicipio);
    Municipio leer(int index);
    bool modificar(Municipio municipio, int index);
    bool eliminar(int numMunicipio);
    int getCantidadMunicipios();
    bool copiaSeguridad(std::string fileName="municipios.bkp");
    bool restaurarCopiaSeguridad(std::string fileName="municipios.bkp");
//    Municipio leerCopiaSeguridad(int index);
//    Municipio leerDatosInicio(int index);
};

#pragma once
#include "Municipio.h"
#include "MunicipioArchivo.h"


class MunicipioManager {
private:
    void cargarMunicipio();
    void buscarMunicipio();
    void modificarCantHabitantes();
    void eliminarMunicipio();
    void listarMunicipios();
    MunicipioArchivo archivoMunicipio;
//    void listarDatosInicio();
//    void listarCopiaSeguridad();
public:
    Municipio crearMunicipio();
    void mostrar(Municipio municipio);
    void menu();

};

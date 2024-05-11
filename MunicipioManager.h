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
    void listarDatosInicio();
    void listarCopiaSeguridad();
    MunicipioArchivo archivoMunicipio;
public:
    Municipio crearMunicipio();
    void mostrar(Municipio municipio);
    void menu();

};

#pragma once
#include "Municipio.h"
#include "MunicipioArchivo.h"


class MunicipioManager {
    public:
    Municipio crearMunicipio();
    void mostrar(Municipio municipio);
    void menu();

    private:
    void cargarMunicipio();
    void buscarMunicipio();
    void modificarCantHabitantes();
    void eliminarMunicipio();
    void listarMunicipios();
    void crearCopiaSeguridad();
    void restaurarCopiaSeguridad();
    MunicipioArchivo archivoMunicipio;
};

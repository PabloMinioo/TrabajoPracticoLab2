#include <iostream>
#include "MunicipioArchivo.h"

using namespace std;

// CONSTRUCTOR POR OMISION
MunicipioArchivo::MunicipioArchivo() {
    _fileName = "municipios.dat";
}

// CONSTRUCTOR POR DEFECTO
MunicipioArchivo::MunicipioArchivo(string fileName) {
    _fileName = fileName;
}

// GUARDA EL REGISTRO EN EL ARCHIVO
bool MunicipioArchivo::guardar(Municipio municipio) {
    int guardo;
    if(!abrir("ab")) {
        return false;
    }
    guardo = fwrite(&municipio, sizeof(Municipio), 1, _pFile);
    cerrar();
    return guardo;
}

// RECIBE UN NUMERO DE MUNICIPIO Y DEVUELVE LA POSICION QUE OCUPA EN EL REGISTRO
int MunicipioArchivo::buscar(int numMunicipio) {
    int index = 0;
    Municipio municipio;
    if(abrir("rb+") == false) {
        return -1;
    }
    while(fread(&municipio, sizeof(Municipio), 1, _pFile)) {
        if(municipio.getNumeroMunicipio() == numMunicipio) {
            break;
        }
        index++;
    }
    cerrar();
    if(municipio.getNumeroMunicipio() == numMunicipio) {
        return index;
    } else {
        return -1;
    }
}

// RECIBE UN NUMERO DE MUNICIPIO Y VALIDA SI EXISTE EL NUMERO DE MUNICIPIO
bool MunicipioArchivo::isExist(int numeroMunicipio) {
    return buscar(numeroMunicipio) != -1;
}


// RECIBE UNA POSICION Y DEVUELVE EL REGISTRO DE DICHA POSICION
Municipio MunicipioArchivo::leer(int index) {
    Municipio municipio;
    if(!abrir()) {
        return municipio;
    }
    fseek(_pFile, index * sizeof(Municipio), SEEK_SET);
    fread(&municipio, sizeof(Municipio), 1, _pFile);
    cerrar();
    return municipio;
}

// RECIBE EL NOMBRE DE UN ARCHIVO Y LO MUESTRA (BAKC UP)
Municipio MunicipioArchivo::leerCopiaSeguridad(int index) {
    Municipio municipioBackUp;
    FILE *pFile = fopen("municipios.bkp", "rb");
    if (pFile == nullptr) {
        return municipioBackUp;
    }
    fseek(pFile, index * sizeof(Municipio), SEEK_SET);
    fread(&municipioBackUp, sizeof(Municipio), 1, pFile);
    fclose(pFile);
    return municipioBackUp;
}

// RECIBE EL NOMBRE DE UN ARCHIVO Y LO MUESTRA (DATOS DE INICIO)
Municipio MunicipioArchivo::leerDatosInicio(int index) {
    Municipio municipioDatosInicio;
    FILE *pFile = fopen("municipios_datos_inicio.init", "rb");
    if (pFile == nullptr) {
        return municipioDatosInicio;
    }
    fseek(pFile, index * sizeof(Municipio), SEEK_SET);
    fread(&municipioDatosInicio, sizeof(Municipio), 1, pFile);
    fclose(pFile);
    return municipioDatosInicio;
}

// RECIBE UN OBJETO MUNICIPIO Y UNA POSICION, Y MODIFICA LOS DATOS
bool MunicipioArchivo::modificar(Municipio municipio, int index) {
    int modifico;
    if(!abrir("rb+")) {
        return false;
    }
    fseek(_pFile, index * sizeof(Municipio), SEEK_SET);
    modifico = fwrite(&municipio, sizeof(Municipio), 1, _pFile);
    cerrar();
    return modifico;
}

// RECIBE UN NUMERO DE MUNICIPIO REALIZA UNA BAJA LOGICA DEL REGISTRO
bool MunicipioArchivo::eliminar(int numMunicipio) {
    Municipio municipio;
    int index;
    index = buscar(numMunicipio);
    municipio = leer(index);
    municipio.setEstado(0);
    return modificar(municipio, index);
}

// DEVUELVE LA CANTIDAD DE MUNICIPIOS DEL ARCHIVO
int MunicipioArchivo::getCantidadMunicipios() {
    if(!abrir("rb")) {
        return 0;
    }
    fseek(_pFile, 0, SEEK_END);
    int bytesTotales = ftell(_pFile);
    cerrar();
    return bytesTotales / sizeof(Municipio);
}

// RECIBE EL NOMBRE DE UN ARCHIVO Y CREA LA COPIA DE SEGURIDAD
bool MunicipioArchivo::copiaSeguridad(string fileName) {
    FILE *pFileBkp;
    Municipio municipio;
    pFileBkp = fopen(fileName.c_str(), "wb");
    if(pFileBkp == nullptr) {
        return false;
    }
    int cantReg = getCantidadMunicipios();
    for(int i=0; i<cantReg; i++) {
        municipio = leer(i);
        fwrite(&municipio, sizeof (Municipio), 1, pFileBkp);
    }
    fclose(pFileBkp);
    return true;
}

// RECIBE EL NOMBRE DE UN ARCHIVO Y ESCRIBE LOS REGISTROS DEL ARCHIVO BACK UP EN EL ARCHIVO ORIGINAL
bool MunicipioArchivo::restaurarCopiaSeguridad(string fileName) {
    Municipio municipio;
    MunicipioArchivo archiBak(fileName);
    if(!abrir("wb")) {
        return false;
    }
    int cantReg = archiBak.getCantidadMunicipios();
    for(int i=0; i<cantReg; i++) {
        municipio= archiBak.leer(i);
        fwrite(&municipio, sizeof (Municipio), 1, _pFile);
    }
    cerrar();
    return true;
}

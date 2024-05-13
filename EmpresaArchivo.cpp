#include "EmpresaArchivo.h"

using namespace std;

// CONSTRUCTOR POR OMISION
EmpresaArchivo::EmpresaArchivo() {
    _fileName = "empresas.dat";
}

// CONSTRUCTOR POR DEFECTO
EmpresaArchivo::EmpresaArchivo(string filename) {
    _fileName = filename;
}

// DEVUELVE LA CANTIDAD DE REGISTROS DEL ARCHIVO
int EmpresaArchivo::getCantidadRegistros() {
    if(abrir("rb") == false) {
        return 0;
    }
    fseek(_pFile, 0, SEEK_END);
    int tamanio = ftell(_pFile);
    cerrar();
    return tamanio / sizeof(Empresa);
}

// GUARDA EL REGISTRO EN EL ARCHIVO
bool EmpresaArchivo::guardar(Empresa empresa) {
    int grabo;
    if(abrir("ab") == false) {
        return false;
    }
    grabo = fwrite(&empresa, sizeof (Empresa), 1, _pFile);
    cerrar();
    return grabo;
}

// GUARDA EL REGISTRO MODIFICADO EN EL ARCHIVO
bool EmpresaArchivo::guardar(int index, Empresa empresa) {
    int grabo;
    if(abrir("rb+") == false) {
        return false;
    }
    fseek(_pFile, index * sizeof(Empresa), SEEK_SET);
    grabo = fwrite(&empresa, sizeof (Empresa), 1, _pFile);
    cerrar();
    return grabo;
}

// RECIBE UN NUMERO DE EMPRESA Y DEVUELVE LA POSICION QUE OCUPA EN EL REGISTRO
int EmpresaArchivo::buscar(int numeroEmpresa) {
    int index = 0;
    Empresa empresa;
    if(abrir("rb+") == false) {
        return -1;
    }
    while(fread(&empresa, sizeof (Empresa), 1, _pFile)) {
        if(empresa.getNumeroEmpresa() == numeroEmpresa) {
            break;
        }
        index++;
    }
    cerrar();
    if(empresa.getNumeroEmpresa() == numeroEmpresa) {
        return index;
    } else {
        return -1;
    }
}

// RECIBE UNA POSICION Y DEVUELVE EL REGISTRO DE DICHA POSICION
Empresa EmpresaArchivo::leer(int index) {
    Empresa empresa;
    if(abrir("rb") == false) {
        return empresa;
    }
    fseek(_pFile, index * sizeof(Empresa), SEEK_SET);
    fread(&empresa, sizeof(Empresa), 1, _pFile);
    cerrar();
    return empresa;
}

// RECIBE EL NOMBRE DE UN ARCHIVO Y LO MUESTRA (BAKC UP)
Empresa EmpresaArchivo::leerCopiaSeguridad(int index) {
    Empresa empresaBackUp;
    FILE *pFile = fopen("empresas.bkp", "rb");
    if (pFile == nullptr) {
        return empresaBackUp;
    }
    fseek(pFile, index * sizeof(Empresa), SEEK_SET);
    fread(&empresaBackUp, sizeof(Empresa), 1, pFile);
    fclose(pFile);
    return empresaBackUp;
}

// RECIBE EL NOMBRE DE UN ARCHIVO Y LO MUESTRA (DATOS INICIO)
Empresa EmpresaArchivo::leerDatosInicio(int index) {
    Empresa empresaDatosInicio;
    FILE *pFile = fopen("empresas_datos_inicio.ini", "rb");
    if (pFile == nullptr) {
        return empresaDatosInicio;
    }
    fseek(pFile, index * sizeof(Empresa), SEEK_SET);
    fread(&empresaDatosInicio, sizeof(Empresa), 1, pFile);
    fclose(pFile);
    return empresaDatosInicio;
}


// RECIBE UN NUMERO DE EMPRESA Y VALIDA SI EXISTE EL NUMERO DE EMPRESA
bool EmpresaArchivo::isExist(int numeroEmpresa) {
    return buscar(numeroEmpresa) != -1;
}


// RECIBE EL NOMBRE DE UN ARCHIVO Y CREA LA COPIA DE SEGURIDAD
bool EmpresaArchivo::copiaSeguridad(string fileName){
    FILE *pFileBkp;
    Empresa reg;
    pFileBkp = fopen(fileName.c_str(), "wb");
    if(pFileBkp == nullptr){
        return false;
    }
    int cantReg = getCantidadRegistros();
    for(int i=0;i<cantReg;i++){
        reg=leer(i);
        fwrite(&reg, sizeof reg, 1, pFileBkp);
    }
    fclose(pFileBkp);
    return true;
}

// RECIBE EL NOMBRE DE UN ARCHIVO Y ESCRIBE LOS REGISTROS DEL ARCHIVO BACK UP EN EL ARCHIVO ORIGINAL
bool EmpresaArchivo::restaurarCopiaSeguridad(string fileName){
    Empresa reg;
    EmpresaArchivo archiBak(fileName);
    if(!abrir("wb")){
        return false;
    }
    int cantReg = archiBak.getCantidadRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archiBak.leer(i);
        fwrite(&reg, sizeof (Empresa), 1, _pFile);
    }
    cerrar();
    return true;
}

// RECIBE UN NUMERO DE EMPRESA Y REALIZA UNA BAJA LOGICA DEL REGISTRO DE DICHA EMPRESA
bool EmpresaArchivo::eliminar(int numeroEmpresa){
    int indice;
    Empresa empresa;
    indice = buscar(numeroEmpresa);
    empresa = leer(indice);
    empresa.setEstado(0);
    return guardar(indice, empresa);
}

// RECIBE UN REGISTRO Y UNA POSICION, Y LO MODIFICA
bool EmpresaArchivo::modificar(Empresa empresa, int index) {
    int modifico;
    if(!abrir("rb+")) {
        return false;
    }
    fseek(_pFile, index * sizeof(Empresa), SEEK_SET);
    modifico = fwrite(&empresa, sizeof(Empresa), 1, _pFile);
    cerrar();
    return modifico;
}


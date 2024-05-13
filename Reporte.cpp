#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Reporte.h"
#include "MunicipioArchivo.h"
#include "EmpresaArchivo.h"

using namespace std;

/// CONSTRUCTOR
// CONSTRUCTOR POR OMISION
Reporte::Reporte(){
    _numeroMunicipio = 0;
    strcpy(_nombreMunicipio, "");
    _cantidadEmpleados = 0;
}

// CONSTRUCTOR POR DEFECTO
Reporte::Reporte(int numeroMunicipio, string nombreMunicipio, int cantidadEmpleados){
    _numeroMunicipio = numeroMunicipio;
    strcpy(_nombreMunicipio, nombreMunicipio.c_str());
    _cantidadEmpleados = cantidadEmpleados;
}

/// GET
int Reporte::getNumeroMunicipio() {
    return _numeroMunicipio;
}

string Reporte::getNombreMunicipio(){
    return _nombreMunicipio;
}

int Reporte::getCantidadEmpleados(){
    return _cantidadEmpleados;
}

/// METODOS
// MOSTRAR REGISTRO
void Reporte::mostrar(Reporte reporte) {
    cout << "Numero municipio: " << reporte.getNumeroMunicipio() << endl;
    cout << "Nombre municipio: " << reporte.getNombreMunicipio() << endl;
    cout << "Cantidad de empleados: " << reporte.getCantidadEmpleados() << endl;
}

// GENERAR ARCHIVO
void Reporte::generarReporte() {
    MunicipioArchivo municipioArchivo;
    EmpresaArchivo empresaArchivo;
    // PEDIMOS EL NUMERO DE MUNICIPIO POR TECLADO
    int numeroMunicipio;
    cout << "INGRESE NUMERO DE MUNICIPIO: ";
    cin >> numeroMunicipio;
    // BUSCAMOS Y GUARDAMOS EL REGISTRO DEL MUNICIPIO
    Municipio municipio;
    municipio = municipioArchivo.leer(municipioArchivo.buscar(numeroMunicipio));
    // CONTAMOS LA CANTIDAD DE EMPLEADOS
    int cantidadEmpleados = 0;
    int cantidadEmpresas = empresaArchivo.getCantidadRegistros();
    for(int i=0; i< cantidadEmpresas; i++) {
        Empresa empresa = empresaArchivo.leer(i);
        if(empresa.getNumeroMunicipio() == numeroMunicipio && empresa.getEstado() == true) {
            cantidadEmpleados += empresa.getCantidadEmpleados();
        }
    }
    // GENERAMOS EL ARCHIVO
    Reporte reporte(municipio.getNumeroMunicipio(), municipio.getNombre(), cantidadEmpleados);
    FILE *pFile;
    pFile = fopen("reporte1.dat", "wb");
    if(pFile == nullptr) {
        cout << "NO SE GENERO EL REPORTE" << endl;
        return;
    }
    fwrite(&reporte, sizeof (Reporte), 1, pFile);
    fclose(pFile);
    cout << "REPORTE GENERADO CON EXITO" << endl;
}

// MOSTRAR ARCHIVO
void Reporte::mostrarReporte() {
    Reporte reporte;
    FILE *pFile;
    pFile = fopen("reporte1.dat", "rb");
    if(pFile == nullptr) {
        cout << "NO SE PUEDE MOSTRAR EL ARCHIVO" << endl;
        return ;
    }
    fread(&reporte, sizeof (Reporte), 1, pFile);
    fclose(pFile);
    mostrar(reporte);
}

// MENU REPORTE
void Reporte::menu() {
    int opcion;
    do {
        system("cls");
        cout << "--------- MENU REPORTE -------" << endl;
        cout << "-------------------------------" << endl;
        cout << "1- GENERAR REPORTE 1  " << endl;
        cout << "2- MOSTRAR REPORTE 1  " << endl;
        cout << "-------------------------------" << endl;
        cout << "0- VOLVER AL MENU PRINCIPAL " << endl;
        cout << "-------------------------------" << endl;
        cout << "INGRESE LA OPCION: ";
        cin >> opcion;
        switch(opcion) {
        case 1:
            system("cls");
            generarReporte();
            break;
        case 2:
            system("cls");
            mostrarReporte();
            break;
        case 0:
            return;
        default:
            system("cls");
            cout << "OPCION INVALIDA, INGRESE NUEVAMENTE" << endl;
        }
        system("pause");
    } while(opcion != 0);
}

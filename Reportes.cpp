#include <string>
#include <iostream>
#include <cstring>
#include "MunicipioArchivo.h"
#include "AppManager.h"
/*
using namespace std;

class Reporte {
private:
/// PROPIEDADES
    int _numero;
    char _nombre[30];
    int _cantidadEmpleados;

public:
/// CONSTRUCTOR
    Reporte(int numero=0, std::string nombre="", int cantidadEmpleados=0) {
        _numero = numero;
        strcpy(_nombre, nombre.c_str());
        _cantidadEmpleados = cantidadEmpleados;
    }
    void mostrar() {
        cout << "Numero municipio: " << _numero << endl;
        cout << "Nombre municipio: " << _nombre << endl;
        cout << "Cantidad de empleados: " << _cantidadEmpleados << endl;
    }
};

void AppManager::generarReporte1() {
    MunicipioArchivo archMun;
    EmpresaArchivo archEmp;
    int numeroMunicipio;
    cout << "Ingrese numero de municipio: ";
    cin >> numeroMunicipio;
    Municipio municipio;
    municipio = archMun.leer(archMun.buscar(numeroMunicipio));
    int cantidadEmpleados = 0;
    int cantidadEmpresas = archEmp.getCantidadRegistros();
    for(int i=0; i< cantidadEmpresas; i++) {
        Empresa emp = archEmp.leer(i);
        if(emp.getNumeroMunicipio() == numeroMunicipio && emp.getEstado() == true) {
            cantidadEmpleados += emp.getCantidadEmpleados();
        }
    }
    /// generar el archivo
    /// numero municipio, nombre, cantidad empleados totales
    Reporte1 repo(municipio.getNumeroMunicipio(), municipio.getNombre(), cantidadEmpleados);
    FILE *pFile;
    pFile = fopen("reporte1.dat", "wb");
    if(pFile == nullptr) {
        cout << "No se pudo generar el reporte... "<<endl;
        system("pause");
        return ;
    }
    fwrite(&repo, sizeof (Reporte1), 1, pFile);
    fclose(pFile);
    cout << "Reporte generado con exito!" << endl;
    system("pause");
}

void AppManager::mostrarReporte1() {
    Reporte1 repo;
    FILE *pFile;
    pFile = fopen("reporte1.dat", "rb");
    if(pFile == nullptr) {
        cout << "No se pude mostrar el reporte... "<<endl;
        system("pause");
        return ;
    }
    fread(&repo, sizeof (Reporte1), 1, pFile);
    fclose(pFile);
    repo.mostrar();
    system("pause");
}

void AppManager::menu() {
    int opcion;
    do {
        system("cls");
        cout << "--------- MENU PRINCIPAL -------" << endl;
        cout << "-------------------------------" << endl;
        cout << "1- EMPRESAS  " << endl;
        cout << "2- MUNICIPIO " << endl;
        cout << "3- CONFIGURACION " << endl;
        cout << "4- REPORTES" << endl;
        cout << "5- GENERAR REPORTE #1" << endl;
        cout << "6- MOSTRAR REPORTE #1" << endl;
        cout << "-------------------------------" << endl;
        cout << "0- SALIR " << endl;
        cout << "-------------------------------" << endl;
        cout << "Opcion: " << endl;
        cin >> opcion;
        switch(opcion) {
        case 1:
            system("cls");
            empresaManager.menu();
            break;
        case 2:
            system("cls");
            municipioManager.menu();
            break;
        case 3:
            system("cls");
            break;
        case 5:
            generarReporte1();
            break;
        case 6:
            mostrarReporte1();
            break;
        case 0:
            system("cls");
            cout << "Gracias por utilizar mi aplicacion, pagame un cafecito :) " << endl;
            system("pause");
        }
    } while(opcion != 0);

}
*/

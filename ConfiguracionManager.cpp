#include <string>
#include <iostream>
#include "ConfiguracionManager.h"
#include "EmpresaManager.h"
#include "MunicipioManager.h"

using namespace std;

// CREA COPIA DE SEGURIDAD DEL ARCHIVO EMPRESAS
void ConfiguracionManager::crearCopiaSeguridadEmpresas() {
    bool hacerCopia;
    cout << "REALIZAR COPIA DE SEGURIDAD? 1- SI || 0- NO ";
    cin >> hacerCopia;
    if (hacerCopia) {
        if (empresaArchivo.copiaSeguridad("empresa.bkp")) {
            cout << "LA COPIA DE SEGURIDAD SE REALIZO CON EXITO" << endl;
        } else {
            cout << "NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD" << endl;
        }
    } else {
        cout << "LA OPERACION FUE CANCELADA" << endl;
    }
}

// CREA COPIA DE SEGURIDAD DEL ARCHIVO MUNICIPIOS
void ConfiguracionManager::crearCopiaSeguridadMunicipios() {
    bool hacerCopia;
    cout << "REALIZAR COPIA DE SEGURIDAD? 1- SI || 0- NO ";
    cin >> hacerCopia;
    if (hacerCopia) {
        if (municipioArchivo.copiaSeguridad("municipio.bkp")) {
            cout << "LA COPIA DE SEGURIDAD SE REALIZO CON EXITO" << endl;
        } else {
            cout << "NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD" << endl;
        }
    } else {
        cout << "LA OPERACION FUE CANCELADA" << endl;
    }
}

// ESCRIBE LOS DATOS DEL ARCHIVO BACKUP, AL ARCHIVO ORIGINAL DE EMPRESAS
void ConfiguracionManager::restaurarCopiaSeguridadEmpresas() {
    bool hacerCopia;
    cout << "RESTAURAR LA COPIA DE SEGURIDAD? 1- SI || 0- NO ";
    cin >> hacerCopia;
    if(hacerCopia) {
        if(empresaArchivo.restaurarCopiaSeguridad("empresa.bkp")) {
            cout << "LA COPIA DE SEGURIDAD SE RESTUARO CON EXITO" << endl;
        } else {
            cout << "NO SE PUDO RESTAURAR LA COPIA DE SEGURIDAD"<< endl;
        }
    } else {
        cout << "LA OPERACION FUE CANCELADA" << endl;
    }
}

// ESCRIBE LOS DATOS DEL ARCHIVO BACKUP, AL ARCHIVO ORIGINAL DE MUNICIPIOS
void ConfiguracionManager::restaurarCopiaSeguridadMunicipios() {
    bool hacerCopia;
    cout << "RESTAURAR LA COPIA DE SEGURIDAD? 1- SI || 0- NO ";
    cin >> hacerCopia;
    if(hacerCopia) {
        if(municipioArchivo.restaurarCopiaSeguridad("municipio.bkp")) {
            cout << "LA COPIA DE SEGURIDAD SE RESTUARO CON EXITO" << endl;
        } else {
            cout << "NO SE PUDO RESTAURAR LA COPIA DE SEGURIDAD"<< endl;
        }
    } else {
        cout << "LA OPERACION FUE CANCELADA" << endl;
    }
}


// MENU CONFIGURACION
void ConfiguracionManager::menu() {
    int opcion;
    do {
        system("cls");
        cout << "--------- MENU CONFIGURACION -------" << endl;
        cout << "-------------------------------" << endl;
        cout << "1- COPIA DE SEGURIDAD DEL ARCHIVO DE EMPRESAS" << endl;
        cout << "2- COPIA DE SEGURIDAD DEL ARCHIVO DE MUNICIPIOS" << endl;
        cout << "3- RESTAURAR EL ARCHIVO DE EMPRESAS" << endl;
        cout << "4- RESTAURAR EL ARCHIVO DE MUNICIPIO " << endl;
        cout << "5- ESTABLECER DATOS DE INICIO" << endl;
        cout << "-------------------------------" << endl;
        cout << "0- VOLVER AL MENU PRINCIPAL " << endl;
        cout << "-------------------------------" << endl;
        cout << "INGRESE LA OPCION: ";
        cin >> opcion;
        switch(opcion) {
        case 1:
            system("cls");
            crearCopiaSeguridadEmpresas();
            break;
        case 2:
            system("cls");
            crearCopiaSeguridadMunicipios();
            break;
        case 3:
            system("cls");
            restaurarCopiaSeguridadEmpresas();
            break;
        case 4:
            system("cls");
            restaurarCopiaSeguridadMunicipios();
            break;
        case 5:
            // DATOS DE INICIO
            system("cls");
        case 0:
            return;
        default:
            system("cls");
            cout<< "OPCION INVALIDA, INGRESE NUEVAMENTE"<<endl;
        }
        system("pause");
    } while(opcion != 0);
}

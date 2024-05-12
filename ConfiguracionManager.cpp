#include <string>
#include <iostream>
#include <cstdlib>
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
        if (empresaArchivo.copiaSeguridad("empresas.bkp")) {
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
        if (municipioArchivo.copiaSeguridad("municipios.bkp")) {
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
        if(empresaArchivo.restaurarCopiaSeguridad("empresas.bkp")) {
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
        if(municipioArchivo.restaurarCopiaSeguridad("municipios.bkp")) {
            cout << "LA COPIA DE SEGURIDAD SE RESTUARO CON EXITO" << endl;
        } else {
            cout << "NO SE PUDO RESTAURAR LA COPIA DE SEGURIDAD"<< endl;
        }
    } else {
        cout << "LA OPERACION FUE CANCELADA" << endl;
    }
}

// RECIBE UN ARCHIVO ORIGEN Y UN ARCHIVO DESTINO, Y REALIZA UNA COPIA A DICHO ARCHIVO
// ** PARA COPIAR LOS DATOS DE LOS ARCHIVOS.DAT A LOS ARCHIVOS.INIT**
void ConfiguracionManager::copiarArchivosInicio(string archivoOrigen, string archivoDestino) {
    bool copiar;
    cout << endl << "DESEA COPIAR LOS DATOS DEL ARCHIVO '" << archivoOrigen << "' AL ARCHIVO '" << archivoDestino << "'? 1-SI || 0- NO " << endl;
    cout << "OPCION: ";
    cin >> copiar;
    // COPIAMOS LOS ARCHIVOS. AL USAR WINDOWS USAMOS "COPY"
    if (copiar) {
        string copiarArchivo = "copy " + string(archivoOrigen) + " " + string(archivoDestino);
        int seCopio = system(copiarArchivo.c_str()); // COMANDO DE SYSTEM PARA COPIAR ARCHIVOS. 0 = EXITO || 1 = FALLA
        cout << endl;
        if (seCopio == 0) {
            cout << "EL ARCHIVO SE COPIO CORRECTAMENTE" << endl;
        } else {
            cout << "NO SE PUDO COPIAR EL ARCHIVO" << endl;
        }
    } else {
        cout << "LA OPERACION FUE CANCELADA" << endl;
    }
}

// RECIBE UN ARCHIVO ORIGEN Y UN ARCHIVO DESTINO Y REALIZA UNA COPIA A DICHO ARCHIVO
// ** PARA COPIAR LOS DATOS DE LOS ARCHIVOS.INIT A LOS ARCHIVOS.DAT**
void ConfiguracionManager::copiarArchivos(string archivoOrigen, string archivoDestino) {
    bool copiar;
    cout << endl << "DESEA COPIAR LOS DATOS DEL ARCHIVO '" << archivoOrigen << "' AL ARCHIVO '" << archivoDestino << "'? 1-SI || 0- NO " << endl;
    cout << "OPCION: ";
    cin >> copiar;
    // COPIAMOS LOS ARCHIVOS. AL USAR WINDOWS USAMOS "COPY"
    if (copiar) {
        string copiarArchivo = "copy " + string(archivoOrigen) + " " + string(archivoDestino);
        int seCopio = system(copiarArchivo.c_str()); // COMANDO DE SYSTEM PARA COPIAR ARCHIVOS. 0 = EXITO || 1 = FALLA

        if (seCopio == 0) {
            cout << "EL ARCHIVO SE COPIO CORRECTAMENTE" << endl;
        } else {
            cout << "NO SE PUDO COPIAR EL ARCHIVO" << endl;
        }
    } else {
        cout << "LA OPERACION FUE CANCELADA" << endl;
    }
}
//// COPIA LOS DATOS DEL ARCHIVO ORIGEN AL ARCHIVO DESTINO
void ConfiguracionManager::establecerDatosInicio() {
    bool copiar;
    cout << "DESEA COPIAR LOS DATOS DE INCIO A SUS RESPECTIVOS ARCHIVOS.DAT? 1-SI || 0- NO " << endl;
    cout << "OPCION: ";
    cin >> copiar;
    if (copiar) {
        copiarArchivos("empresas_datos_inicio.init", "empresas.dat");
        copiarArchivos("municipios_datos_inicio.init", "municipios.dat");
        cout << endl << "AMBOS ARCHIVOS FUERON COPIADOS CORRECTAMENTE" << endl;
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
        cout << "6- COPIAR ARCHIVOS A 'DATOS_INICIO.INI'" << endl;
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
            system("cls");
            establecerDatosInicio();
            break;
        case 6:
            system("cls");
            copiarArchivosInicio("empresas.dat", "empresas_datos_inicio.init");
            copiarArchivosInicio("municipios.dat", "municipios_datos_inicio.init");
            break;
        case 0:
            return;
        default:
            system("cls");
            cout<< "OPCION INVALIDA, INGRESE NUEVAMENTE"<<endl;
        }
        system("pause");
    } while(opcion != 0);
}

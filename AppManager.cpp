#include <string>
#include <iostream>
#include <cstring>
#include "AppManager.h"

using namespace std;

/// MENU PRINCIPAL
void AppManager::menu() {
    int opcion;
    do {
        system("cls");
        cout << "--------- MENU PRINCIPAL -------" << endl;
        cout << "-------------------------------" << endl;
        cout << "1- MENU EMPRESAS  " << endl;
        cout << "2- MENU MUNICIPIOS " << endl;
        cout << "3- REPORTES " << endl;
        cout << "4- CONFIGURACION" << endl;
        cout << "5- REPORTES PRUEBAS" << endl;
        cout << "-------------------------------" << endl;
        cout << "0- SALIR " << endl;
        cout << "-------------------------------" << endl;
        cout << "INGRESE LA OPCION: ";
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
            // REPORTE.MENU
            break;
        case 4:
            system("cls");
            configuracionManager.menu();
            // CONFIGURACION:MENU
            break;
        case 5:
            system("cls");
            // REPORTEPRUEBA.MENU
            break;
        case 0:
            system("cls");
            cout << "GRACIAS POR USAR LA APLICACION" << endl;
            break;
        default:
            system("cls");
            cout<< "OPCION INVALIDA, INGRESE NUEVAMENTE dsadsa"<<endl;
            break;
        }
        system("pause");
    } while(opcion != 0);
}

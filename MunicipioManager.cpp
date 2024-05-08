#include <iostream>
#include "MunicipioManager.h"

using namespace std;

// CREA EL MUNICIPIO
Municipio MunicipioManager::crearMunicipio() {
    int numeroMunicipio, seccionPerteneciente, cantHabitantes;
    string nombre;
    bool estado;
    cout<< "INGRESE NUMERO DE MUNICIPIO: "<<endl;
    cin>> numeroMunicipio;
    cin.ignore();
    cout<< "INGRESE NOMBRE: "<<endl;
    getline(cin, nombre);
    cout<< "INGRESE SECCION PERTENECIENTE: "<<endl;
    cin>> seccionPerteneciente;
    cout<< "INGRESE CANTIDAD DE HABITANTES: "<<endl;
    cin>> cantHabitantes;
    return Municipio(numeroMunicipio, nombre, seccionPerteneciente, cantHabitantes, estado = true);
}

// MUESTRA EL MUNICIPIO
void MunicipioManager::mostrar(Municipio municipio) {
    cout<< "NUMERO DE MUNICIPIO: "<< municipio.getNumeroMunicipio()<<endl;
    cout<< "NOMBRE: "<< municipio.getNombre()<<endl;
    cout<< "SECCION PERTENECIENTE: "<< municipio.getSeccionPerteneciente()<<endl;
    cout<< "CANTIDAD DE HABITANTES: "<< municipio.getCantHabitantes()<<endl;
    cout<< "ESTADO: "<< (municipio.getEstado() ? "DISPONIBLE" : "NO DISPONIBLE")<<endl;
}

// GUARDA EL REGISTRO EN EL ARCHIVO
void MunicipioManager::cargarMunicipio() {
    Municipio municipio;
    municipio = crearMunicipio();
    if(archivoMunicipio.guardar(municipio)) {
        cout<< "EL MUNICIPIO FUE CARGADO CON EXITO."<<endl;
    } else {
        cout<< "ERROR. EL MUNICIPIO NO FUE CARGADO"<<endl;
    }
}

// RECIBE UN NUMERO DE EMPRESA, LA BUSCA EN EL ARCHIVO Y LA MUESTRA
void MunicipioManager::buscarMunicipio() {
    Municipio municipio;
    int numMunicipio, index;
    cout<< "INGRESE NUMERO DE MUNICIPIO: "<<endl;
    cin>> numMunicipio;
    index = archivoMunicipio.buscar(numMunicipio);
    if(index >= 0) {
        municipio = archivoMunicipio.leer(index);
        mostrar(municipio);
    } else {
        cout << "NO SE ENCUENTRA EL MUNICIPIO" << endl;
    }
}

// RECIBE UNA POSICION DEL REGISTRO, BUSCA EL REGISTRO EN EL ARCHIVO Y MODIFICA LA CANTIDAD DE HABITANTES
void MunicipioManager::modificarCantHabitantes() {
    Municipio municipio;
    int cantHabitantes, numMunicipio, index;
    cout<< "INGRESE MUNICIPIO A MODIFICAR: "<<endl;
    cin>>numMunicipio;
    index = archivoMunicipio.buscar(numMunicipio);
    if(index >= 0) {
        municipio = archivoMunicipio.leer(index);
        cout<< "INGRESE CANTIDAD DE HABITANTES NUEVA: "<<endl;
        cin>>cantHabitantes;
        municipio.setCantHabitantes(cantHabitantes);
        archivoMunicipio.modificar(municipio, index);
        mostrar(municipio);
    } else {
        cout << "NO SE ENCUENTRA EL MUNICIPIO" << endl;
    }
}

// RECIBE UNA POSICION DEL REGISTRO Y REALIZA UNA BAJA LOGICA
void MunicipioManager::eliminarMunicipio() {
    Municipio municipio;
    int numMunicipio;
    cout<< "INGRESE NUMERO DE MUNICIPIO A ELIMINAR: "<<endl;
    cin>>numMunicipio;
    archivoMunicipio.eliminar(numMunicipio);
}

// LISTA TODOS LOS REGISTROS DEL ARCHIVO
void MunicipioManager::listarMunicipios() {
    Municipio municipio;
    int cantidadMuncipios;
    cantidadMuncipios = archivoMunicipio.getCantidadMunicipios();
    for(int i=0; i<cantidadMuncipios; i++) {
        municipio = archivoMunicipio.leer(i);
        cout<<"-------------------------"<<endl;
        mostrar(municipio);
        cout<<"-------------------------"<<endl;
    }
}

// CREA LA COPIA DE SEGURIDAD
void MunicipioManager::crearCopiaSeguridad() {
    bool hacerCopia;
    cout<< "¿DESEA CREAR LA COPIA DE SEGURIDAD? 1- SI || 0- NO."<<endl;
    cin>> hacerCopia;
    if(hacerCopia) {
        if(archivoMunicipio.copiaSeguridad("municipios.bkp")) {
            cout<< "LA COPIA SE CARGO CON EXITO."<<endl;
        } else {
            cout<< "LA COPIA NO PUDO SER CARGADA."<<endl;
        }
    } else {
        cout<< "LA COPIA NO PUDO SER CARGADA."<<endl;
    }
}

// ESCRIBE LOS REGISTROS DEL ARCHIVO BACK UP EN EL ARCHIVO ORIGINAL
void MunicipioManager::restaurarCopiaSeguridad() {
    bool hacerCopia;
    cout<< "DESEA CREAR LA COPIA DE SEGURIDAD? 1-SI 0-NO."<<endl;
    cin>> hacerCopia;
    if(hacerCopia) {
        if(archivoMunicipio.restaurarCopiaSeguridad("municipios.bkp")) {
            cout<< "LA COPIA SE CARGO CON EXITO."<<endl;
        } else {
            cout<< "LA COPIA NO PUDO SER CARGADA."<<endl;
        }
    } else {
        cout<< "LA COPIA NO PUDO SER CARGADA."<<endl;
    }
}


void MunicipioManager::menu() {
    int opcion;
    do {
        system("cls");
        cout << "--------- MENU MUNICIPIOS -------" << endl;
        cout << "-------------------------------" << endl;
        cout << "1- CARGAR MUNICIPIO"<<endl;
        cout << "2- BUSCAR MUNICIPIO POR NUMERO EMPRESA"<<endl;
        cout << "3- MODIFICAR CANTIDAD DE HABITANTES."<<endl;
        cout << "4- ELIMINAR MUNICIPIO"<<endl;
        cout << "5- LISTAR MUNICIPIOS"<<endl;
        cout << "6- CREAR COPIA DE SEGURIDAD"<<endl;
        cout << "7- RESTAURAR COPIA DE SEGURIDAD"<<endl;
        cout << "-------------------------------" << endl;
        cout << "0- VOLVER AL MENU PRINCIPAL " << endl;
        cout << "-------------------------------" << endl;
        cout << "INGRESE LA OPCION: ";
        cin >> opcion;
        switch(opcion) {
        case 1:
            system("cls");
            cargarMunicipio();
            break;
        case 2:
            system("cls");
            buscarMunicipio();
            break;
        case 3:
            system("cls");
            modificarCantHabitantes();
            break;
        case 4:
            system("cls");
            eliminarMunicipio();
            break;
        case 5:
            system("cls");
            listarMunicipios();
            break;
        case 6:
            system("cls");
            crearCopiaSeguridad();
            break;
        case 7:
            restaurarCopiaSeguridad();
            system("cls");
            break;
        case 0:
            return;
        default:
            system("cls");
            cout<< "OPCION INVALIDA, INGRESE NUEVAMENTE"<<endl;
        }
        system("pause>nul");

    } while(opcion != 0);



}

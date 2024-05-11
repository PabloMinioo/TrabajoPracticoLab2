#include <iostream>
#include "MunicipioManager.h"
#include "ConfiguracionManager.h"

using namespace std;

// CREA EL MUNICIPIO
Municipio MunicipioManager::crearMunicipio() {
    int numeroMunicipio, seccionPerteneciente, cantHabitantes;
    string nombre;
    bool estado;
    // NUMERO DE MUNICIPIO AUTOMATIZADO
    numeroMunicipio = archivoMunicipio.getCantidadMunicipios() + 1;
    cout << "NUMERO MUNIICPIO: " << numeroMunicipio << endl;
    cin.ignore();
    cout<< "INGRESE NOMBRE DE MUNICIPIO: ";
    getline(cin, nombre);
    cout<< "INGRESE SECCION PERTENECIENTE: ";
    cin>> seccionPerteneciente;
    cout<< "INGRESE CANTIDAD DE HABITANTES: ";
    cin>> cantHabitantes;
    return Municipio(numeroMunicipio, nombre, seccionPerteneciente, cantHabitantes, estado = true);
}

// MUESTRA EL MUNICIPIO
void MunicipioManager::mostrar(Municipio municipio) {
    if (municipio.getEstado()) {
        cout<< "NUMERO DE MUNICIPIO: "<< municipio.getNumeroMunicipio()<<endl;
        cout<< "NOMBRE DE MUNICIPIO: "<< municipio.getNombre()<<endl;
        cout<< "SECCION PERTENECIENTE: "<< municipio.getSeccionPerteneciente()<<endl;
        cout<< "CANTIDAD DE HABITANTES: "<< municipio.getCantHabitantes()<<endl;
        cout<< "ESTADO: "<< (municipio.getEstado() ? "DISPONIBLE" : "NO DISPONIBLE")<<endl;
    }
}

// GUARDA EL REGISTRO EN EL ARCHIVO
void MunicipioManager::cargarMunicipio() {
    Municipio municipio;
    municipio = crearMunicipio();
    // VALIDACION CANTIDAD DE MUNICIPIOS
    int cantidadRegistro = archivoMunicipio.getCantidadMunicipios();
    if (cantidadRegistro == 15) {
        cout << endl << "EL MUNICIPIO NO SE PUDO GUARDAR. SE HA ALCANZADO LA CANTIDAD MAXIMA DE MUNICIPIOS" << endl;
        return;
    }
    // VALIDACION SECCION PERTENECIENTE
    if (municipio.getSeccionPerteneciente() < 1 || municipio.getSeccionPerteneciente() > 9){
        cout << endl << "EL MUNICIPIO NO SE PUDO GUARDAR. SECCION PERTENECIENTE NO VALIDA" << endl;
        return;
    }
    // VALIDACION CANTIDAD HABITANTES
    if (municipio.getCantHabitantes() <= 0){
        cout << endl << "EL MUNICIPIO NO SE PUDO GUARDAR. CANTIDAD DE HABITANTES NO VALIDA" << endl;
        return;
    }
    if(archivoMunicipio.guardar(municipio)) {
        cout << endl << "EL MUNICIPIO FUE CARGADO CON EXITO"<<endl;
    } else {
        cout << endl << "EL MUNICIPIO NO SE PUDO GUARDAR"<<endl;
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
    cout<< "INGRESE MUNICIPIO A MODIFICAR: ";
    cin>>numMunicipio;
    index = archivoMunicipio.buscar(numMunicipio);
    if(index >= 0) {
        municipio = archivoMunicipio.leer(index);
        cout<< "INGRESE CANTIDAD DE HABITANTES NUEVA: ";
        cin>>cantHabitantes;
        municipio.setCantHabitantes(cantHabitantes);
        archivoMunicipio.modificar(municipio, index);
        mostrar(municipio);
    } else {
        cout << "EL NUMERO DE MUNICIPIO INGRESADO NO EXISTE" << endl;
    }
}

// RECIBE UNA POSICION DEL REGISTRO Y REALIZA UNA BAJA LOGICA
void MunicipioManager::eliminarMunicipio() {
    int numeroMunicipio, indice;
    cout << "INGRESE NUMERO DE MUNICIPIO A ELIMINAR: "<< endl;
    cin >> numeroMunicipio;
    indice = archivoMunicipio.buscar(numeroMunicipio);
    if (indice != -1) {
        Municipio municipio = archivoMunicipio.leer(indice);
        bool eliminar;
        mostrar(municipio);
        cout << "ESTA SEGURO QUE DESEA ELIMINAR EL MUNICIPIO? 1- SI || 0- NO ";
        cin >> eliminar;
        if(eliminar) {
            if(archivoMunicipio.eliminar(numeroMunicipio)) {
                cout << "EL MUNICIPIO SE ELIMINO CORRECTAMENTE"<<endl;
            } else {
                cout << "NO SE PUDO ELIMINAR EL MUNICIPIO" << endl;
            }
        } else {
            cout << "LA OPERACION FUE CANCELADA" << endl;
        }
    } else {
        cout << "EL NUMERO DE MUNICIPIO INGRESADO NO EXISTE" << endl;
    }
}

// LISTA TODOS LOS REGISTROS DEL ARCHIVO
void MunicipioManager::listarMunicipios() {
    Municipio municipio;
    int cantidadMuncipios;
    cantidadMuncipios = archivoMunicipio.getCantidadMunicipios();
    for(int i=0; i<cantidadMuncipios; i++) {
        municipio = archivoMunicipio.leer(i);
        cout << "**********************" << endl;
        mostrar(municipio);
        cout << "**********************" << endl;
    }
}

// LISTA TODAS LAS EMPRESAS DEL ARCHIVO BACK UP
void MunicipioManager::listarCopiaSeguridad() {
    MunicipioArchivo backupArchivo("municipios.bkp");
    int cantidadMunicipio = backupArchivo.getCantidadMunicipios();
    cout << "LISTADO DE EMPRESAS DEL BACK UP"<< endl;
    for (int i = 0; i < cantidadMunicipio; i++) {
        Municipio municipio = backupArchivo.leerCopiaSeguridad(i);
        cout << "**********************" << endl;
        mostrar(municipio);
        cout << "**********************" << endl;
    }
}

// LISTA TODAS LAS EMPRESAS DEL ARCHIVO DATOS DE INICIO
void MunicipioManager::listarDatosInicio() {
    MunicipioArchivo inicioArchivo("municipios_datos_inicio.init");
    int cantidadMunicipio = inicioArchivo.getCantidadMunicipios();
    cout << "LISTADO DE EMPRESAS DEL BACK UP"<< endl;
    for (int i = 0; i < cantidadMunicipio; i++) {
        Municipio municipio = inicioArchivo.leerDatosInicio(i);
        cout << "**********************" << endl;
        mostrar(municipio);
        cout << "**********************" << endl;
    }
}


// MENU MUNICIPIO
void MunicipioManager::menu() {
    int opcion;
    do {
        system("cls");
        cout << "--------- MENU MUNICIPIOS -------" << endl;
        cout << "-------------------------------" << endl;
        cout << "1- AGREGAR MUNICIPIO"<<endl;
        cout << "2- LISTAR MUNICIPIO POR NUMERO"<<endl;
        cout << "3- LISTAR TODAS LOS MUNICIPIOS"<<endl;
        cout << "4- MODIFICAR CANTIDAD DE HABITANTES"<<endl;
        cout << "5- ELIMINAR REGISTRO"<<endl;
        cout << "6- LISTAR COPIA DE SEGURIDAD"<<endl;
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
            listarMunicipios();
            break;
        case 4:
            system("cls");
            modificarCantHabitantes();
            break;
        case 5:
            system("cls");
            eliminarMunicipio();
            break;
        case 6:
            system("cls");
            listarCopiaSeguridad();
            break;
        case 7:
            system("cls");
            listarDatosInicio();
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

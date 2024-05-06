#include <string>
#include <iostream>
#include "EmpresaManager.h"

using namespace std;

/// METODOS CLASE EMPRESA
// CREA LA EMPRESA
Empresa EmpresaManager::crearEmpresa() {
    int numeroEmpresa, cantidadEmpleados, categoria, numeroMunicipio;
    float facturacionAnual;
    string nombreEmpresa;
//  Fecha fechaCreacion;
    while(true) {
        cout << "INGRESE NUMERO DE EMPRESA: ";
        cin >> numeroEmpresa;

        // VALIDACION PARA NO REPETIR NUMERO DE EMPRESA
        if(empresaArchivo.isExist(numeroEmpresa)) {
            cout << "YA EXISTE EL NUMERO DE EMPRESA" << endl;
        } else {
            break;
        }
    }

    cin.ignore();
    cout << "INGRESE NOMBRE DE LA EMPRESA: ";
    getline(cin, nombreEmpresa);

    cout << "INGRESE CANTIDAD DE EMPLEADOS: ";
    cin >> cantidadEmpleados;

    cout << "INGRESE CATEGORIA: ";
    cin >> categoria;

    cout << "INGRESE NUMERO DE MUNICIPIO: ";
    cin >> numeroMunicipio;

    cout << "INGRESE FACTURACION ANUAL";
    cin >> facturacionAnual;

    return Empresa(numeroEmpresa, nombreEmpresa, cantidadEmpleados, categoria, numeroMunicipio, facturacionAnual, true);
}

// MUESTRA LA EMPRESA
void EmpresaManager::mostrar(Empresa empresa) {
    cout << "NUMERO EMPRESA: " << empresa.getNumeroEmpresa() << endl;
    cout << "NOMBRE: " << empresa.getNombreEmpresa() << endl;
    cout << "CANTIDAD DE EMPLEADOS: " << empresa.getCantidadEmpleados() << endl;
    cout << "CATEGORIA: " << empresa.getCategoria() << endl;
    cout << "NUMERO DE MUNICIPIO: " << empresa.getNumeroMunicipio() << endl;
    cout << "FACTURACION ANUAL: " << empresa.getFacturacionAnual() << endl;
    cout << "DISPONIBILIDAD: " << (empresa.getEstado() ? "DISPONIBLE" : "NO DISPONIBLE") << endl;
}

// GUARDA EL REGISTRO EN EL ARCHIVO
void EmpresaManager::cargarEmpresa(){
     Empresa empresa;
     empresa = crearEmpresa();
     if(empresaArchivo.guardar(empresa)){
        cout << "Empresa guardada con exito!" << endl;
     }
     else{
        cout << "No se pudo guardar la empresa :(" << endl;
     }
}

// RECIBE UN NUMERO DE EMPRESA Y LA BUSCA
void EmpresaManager::buscarEmpresa() {
    int index, numeroEmpresa;
    Empresa empresa;
    cout << "INGRESE EL NUMERO DE EMPRESA A BUSCAR: "<< endl;
    cin >> numeroEmpresa;
    index = empresaArchivo.buscar(numeroEmpresa);
    if(index >= 0) {
        empresa = empresaArchivo.leer(index);
        mostrar(empresa);
    } else {
        cout << "LA EMPRESA NO EXISTE" << endl;
    }
}

// LISTA TODAS LAS EMPRESAS DEL ARCHIVO
void EmpresaManager::listarEmpresas() {
    int cantidad = empresaArchivo.getCantidadRegistros();
    for(int i=0; i < cantidad ; i++) {
        Empresa empresa = empresaArchivo.leer(i);
        cout << "---------------" << endl;
        mostrar(empresa);
        cout << "---------------" << endl;
    }
}

// CREA LA COPIA DE SEGURIDAD
void EmpresaManager::realizarCopiaSeguridad() {
    bool hacerCopia;
    cout << "Realmente quiere hacer una copia de seguridad? 1-Si 0-No: ";
    cin >> hacerCopia;
    if(hacerCopia) {
        if(empresaArchivo.copiaSeguridad("empresa.bkp")) {
            cout << "La copia de seguridad se realizo con exito!" << endl;
        } else {
            cout << "No se pudo realizar la copia de seguridad"<< endl;
        }
    } else {
        cout << "No se realizo la copia de seguridad." << endl;
    }
}

// ESCRIBE LOS REGISTROS DEL ARCHIVO BACK UP EN EL ARCHIVO ORIGINAL
void EmpresaManager::restaurarCopiaSeguridad() {
    bool hacerCopia;
    cout << "Realmente quiere resturar la copia de seguridad? 1-Si 0-No: ";
    cin >> hacerCopia;
    if(hacerCopia) {
        if(empresaArchivo.restaurarCopiaSeguridad("empresa.bkp")) {
            cout << "La copia de seguridad se restauro con exito!" << endl;
        } else {
            cout << "No se pudo restaurar la copia de seguridad"<< endl;
        }
    } else {
        cout << "No se realizo la restauracion de la copia de seguridad." << endl;
    }
}

// PIDE UN NUMERO DE EMPRESA Y UNA POSICION DEL REGISTRO Y REALIZA UNA BAJA LOGICA
void EmpresaManager::eliminarEmpresas() {
    int numeroEmpresa, indice;
    cout << "Ingrese numero de empresa que quiere eliminar: ";
    cin >> numeroEmpresa;
    indice = empresaArchivo.buscar(numeroEmpresa);
    if(indice != -1) {
        Empresa empresa = empresaArchivo.leer(indice);
        bool eliminar;
        mostrar(empresa);
        cout << "Esta seguro que quiere eliminar la empresa? 1-SI 0-NO: ";
        cin >> eliminar;
        if(eliminar) {
            if(empresaArchivo.eliminar(numeroEmpresa)) {
                cout << "La empresa se elimino correctamente!"<<endl;
            } else {
                cout << "La empresa no se pudo eliminar..." << endl;
            }
        } else {
            cout << "La empresa no se elimino. " << endl;
        }
    } else {
        cout << "La empresa no existe..." << endl;
    }
}


void EmpresaManager::menu() {
    int opcion;
    do {
        system("cls"); /// borar la pantalla
        cout << "--------- MENU EMPRESAS -------" << endl;
        cout << "-------------------------------" << endl;
        cout << "1- CARGAR EMPRESA  " << endl;
        cout << "2- BUSCAR EMPRESA POR NUMERO  " << endl;
        cout << "3- LISTAR TODAS LAS EMPRESAS" << endl;
        cout << "5- ELIMINAR EMPRESA LOGICA " << endl;
        cout << "6- REALIZAR COPIA DE SEGURIDAD" << endl;
        cout << "7- RESTAURAR COPIA DE SEGURIDAD" << endl;
        cout << "-------------------------------" << endl;
        cout << "0- SALIR " << endl;
        cout << "-------------------------------" << endl;
        cout << "Opcion: " << endl;
        cin >> opcion;

        switch(opcion) {
        case 1:
            system("cls");
            cargarEmpresa();
            break;
        case 2:
            system("cls");
            buscarEmpresa();
            break;
        case 3:
            system("cls");
            listarEmpresas();
            break;
        case 5:
            system("cls");
            eliminarEmpresas();
            break;
        case 6:
            system("cls");
            realizarCopiaSeguridad();
            break;
        case 7:
            system("cls");
            restaurarCopiaSeguridad();
            break;
        }
        system("pause");

    } while(opcion != 0);


}

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
    cout << "INGRESE FACTURACION ANUAL: ";
    cin >> facturacionAnual;
    return Empresa(numeroEmpresa, nombreEmpresa, cantidadEmpleados, categoria, numeroMunicipio, facturacionAnual, true);
}

// MUESTRA LA EMPRESA
void EmpresaManager::mostrar(Empresa empresa) {
    if (empresa.getEstado()) {
        cout << "NUMERO EMPRESA: " << empresa.getNumeroEmpresa() << endl;
        cout << "NOMBRE EMPRESA: " << empresa.getNombreEmpresa() << endl;
        cout << "CANTIDAD DE EMPLEADOS: " << empresa.getCantidadEmpleados() << endl;
        cout << "CATEGORIA: " << empresa.getCategoria() << endl;
        cout << "NUMERO DE MUNICIPIO: " << empresa.getNumeroMunicipio() << endl;
        cout << "FACTURACION ANUAL: " << empresa.getFacturacionAnual() << endl;
        cout << "DISPONIBILIDAD: " << (empresa.getEstado() ? "DISPONIBLE" : "NO DISPONIBLE") << endl;
    }
}

// GUARDA EL REGISTRO EN EL ARCHIVO
void EmpresaManager::cargarEmpresa() {
    Empresa empresa;
    empresa = crearEmpresa();
    if(empresaArchivo.guardar(empresa)) {
        cout << "LA EMPRESA GUARDADA CON EXITO" << endl;
    } else {
        cout << "LA EMPRESA NO SE PUDO GUARDAR" << endl;
    }
}

// RECIBE UN NUMERO DE EMPRESA, LA BUSCA EN EL ARCHIVO Y LA MUESTRA
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

// LISTA TODAS LAS EMPRESAS DEL ARCHIVO BACK UP
void EmpresaManager::listarCopiaSeguridad() {
    EmpresaArchivo backupArchivo("empresa.bkp");
    int cantidad = backupArchivo.getCantidadRegistros();
    cout << "LISTADO DE EMPRESAS DEL BACK UP"<< endl;
    for (int i = 0; i < cantidad; i++) {
        Empresa empresa = backupArchivo.leerCopiaSeguridad(i);
        cout << "*****************" << endl;
        mostrar(empresa);

        cout << "*****************" << endl;
    }
}
/*
// CREA LA COPIA DE SEGURIDAD
void EmpresaManager::realizarCopiaSeguridad() {
    bool hacerCopia;
    cout << "REALIZAR COPIA DE SEGURIDAD? 1- SI || 2- NO ";
    cin >> hacerCopia;
    if(hacerCopia) {
        if(empresaArchivo.copiaSeguridad("empresa.bkp")) {
            cout << "LA COPIA DE SEGURIDAD SE REALIZO CON EXITO" << endl;
        } else {
            cout << "NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD"<< endl;
        }
    } else {
        cout << "LA OPERACION FUE CANCELADA" << endl;
    }
}
*/

// ESCRIBE LOS REGISTROS DEL ARCHIVO BACK UP EN EL ARCHIVO ORIGINAL
void EmpresaManager::restaurarCopiaSeguridad() {
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

// PIDE UN NUMERO DE EMPRESA Y UNA POSICION DEL REGISTRO Y REALIZA UNA BAJA LOGICA
void EmpresaManager::eliminarEmpresas() {
    int numeroEmpresa, indice;
    cout << "INGRESAR NUMERO DE EMPRESA QUE SE QUIERA ELIMINAR";
    cin >> numeroEmpresa;
    indice = empresaArchivo.buscar(numeroEmpresa);
    if(indice != -1) {
        Empresa empresa = empresaArchivo.leer(indice);
        bool eliminar;
        mostrar(empresa);
        cout << "ESTA SEGURO QUE DESEA ELIMINAR LA EMPRESA? 1- SI || 0- NO ";
        cin >> eliminar;
        if(eliminar) {
            if(empresaArchivo.eliminar(numeroEmpresa)) {
                cout << "LA EMPRESA SE ELIMINO CORRECTAMENTE"<<endl;
            } else {
                cout << "NO SE PUDO ELIMINAR LA EMPRESA" << endl;
            }
        } else {
            cout << "LA OPERACION FUE CANCELADA" << endl;
        }
    } else {
        cout << "EL NUMERO DE EMPRESA INGRESADO NO EXISTE" << endl;
    }
}

/// MENU EMPRESAS
void EmpresaManager::menu() {
    int opcion;
    do {
        system("cls");
        cout << "--------- MENU EMPRESAS -------" << endl;
        cout << "-------------------------------" << endl;
        cout << "1- CARGAR EMPRESA  " << endl;
        cout << "2- BUSCAR EMPRESA POR NUMERO  " << endl;
        cout << "3- LISTAR TODAS LAS EMPRESAS" << endl;
        cout << "5- ELIMINAR EMPRESA LOGICA " << endl;
        cout << "6- LISTAR COPIA SEGURIDAD" << endl;
        cout << "7- RESTAURAR COPIA DE SEGURIDAD" << endl;
        cout << "-------------------------------" << endl;
        cout << "0- VOLVER AL MENU PRINCIPAL " << endl;
        cout << "-------------------------------" << endl;
        cout << "INGRESE LA OPCION: ";
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
            listarCopiaSeguridad();
            break;
        case 7:
            system("cls");
            restaurarCopiaSeguridad();
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

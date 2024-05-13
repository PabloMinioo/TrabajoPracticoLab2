#include <string>
#include <iostream>
#include "EmpresaManager.h"
#include "ConfiguracionManager.h"
#include "MunicipioArchivo.h"
#include "Fecha.h"

using namespace std;

/// METODOS CLASE EMPRESA
// CREA LA EMPRESA
Empresa EmpresaManager::crearEmpresa() {
    int numeroEmpresa, cantidadEmpleados, categoria, numeroMunicipio;
    float facturacionAnual;
    Fecha fechaCreacion;
    string nombreEmpresa;
    cout << "INGRESE NUMERO DE EMPRESA: ";
    cin >> numeroEmpresa;
    cin.ignore();
    cout << "INGRESE NOMBRE DE LA EMPRESA: ";
    getline(cin, nombreEmpresa);
    cout << "INGRESE CANTIDAD DE EMPLEADOS: ";
    cin >> cantidadEmpleados;
    cout << "INGRESE CATEGORIA: ";
    cin >> categoria;
    cout << "INGRESE NUMERO DE MUNICIPIO: ";
    cin >> numeroMunicipio;
    cout << "FECHA DE CREACION" << endl;
    fechaCreacion.cargarFecha();
    cout << "INGRESE FACTURACION ANUAL: ";
    cin >> facturacionAnual;
    return Empresa(numeroEmpresa, nombreEmpresa, cantidadEmpleados, categoria, numeroMunicipio, fechaCreacion, facturacionAnual, true);
}

// MUESTRA LA EMPRESA
void EmpresaManager::mostrar(Empresa empresa) {
    cout << "NUMERO EMPRESA: " << empresa.getNumeroEmpresa() << endl;
    cout << "NOMBRE EMPRESA: " << empresa.getNombreEmpresa() << endl;
    cout << "CANTIDAD DE EMPLEADOS: " << empresa.getCantidadEmpleados() << endl;
    cout << "CATEGORIA: " << empresa.getCategoria() << endl;
    cout << "NUMERO DE MUNICIPIO: " << empresa.getNumeroMunicipio() << endl;
    cout << "FECHA DE CREACION: ";
    empresa.getFechaCreacion().mostrarFecha();
    cout << "FACTURACION ANUAL: " << empresa.getFacturacionAnual() << endl;
    cout << "DISPONIBILIDAD: " << (empresa.getEstado() ? "DISPONIBLE" : "NO DISPONIBLE") << endl;
}

// GUARDA EL REGISTRO EN EL ARCHIVO
void EmpresaManager::cargarEmpresa() {
    Empresa empresa;
    empresa = crearEmpresa();
    // VALIDACION NUMERO DE EMPRERSA POSITIVO
    if (empresa.getNumeroEmpresa() <= 0) {
        cout << endl << "LA EMPRESA NO SE PUDO GUARDAR. NUMERO DE EMPRESA NO VALID" << endl;
        return;
    }
    // VALIDACION NUMERO DE EMPRESA EXISTENTE
    if(empresaArchivo.isExist(empresa.getNumeroEmpresa())) {
        if (empresa.getEstado() == false) {
            cout << endl << "LA EMPRESA NO SE PUDO GUARDAR. NUMERO DE EMPRESA EXISTENTE PERO DADO DE BAJA" << endl;
        }
        cout << endl << "LA EMPRESA NO SE PUDO GUARDAR. NUMERO DE EMPRESA EXISTENTE" << endl;
        return;
    }
    // VALIDACION CANTIDAD DE EMPLEADOS
    if(empresa.getCantidadEmpleados() <= 0) {
        cout << endl << "LA EMPRESA NO SE PUDO GUARDAR. CANTIDAD DE EMPLADOS NO VALIDA" << endl;
        return;
    }
    // VALIDACION CATEGORIA
    if (empresa.getCategoria() < 1 || empresa.getCategoria() > 80) {
        cout << endl << "LA EMPRESA NO SE PUDO GUARDAR. CATEGORIA NO VALIDA" << endl;
        return;
    }
    // VALIDACION MUNICIPIO EXISTENTE
    if (!archivoMunicipio.isExist(empresa.getNumeroMunicipio())) {
        cout << endl << "LA EMPRESA NO SE PUDO GUARDAR. NO EXISTE EL NUMERO DE MUNICIPIO" << endl;
        return;
    }
    // VALIDACION FECHA VALIDA
    if (!fechaCreacion.fechaValida(empresa.getFechaCreacion())) {
        cout << endl << "LA EMPRESA NO SE PUDO GUARDAR. FECHA DE CREACION NO VALIDA" << endl;
        return;
    }
    if(empresaArchivo.guardar(empresa)) {
        cout << endl << "LA EMPRESA GUARDADA CON EXITO" << endl;
    } else {
        cout << endl << "LA EMPRESA NO SE PUDO GUARDAR" << endl;
    }
}

// RECIBE UN NUMERO DE EMPRESA, LA BUSCA EN EL ARCHIVO Y LA MUESTRA
void EmpresaManager::buscarEmpresa() {
    int index, numeroEmpresa;
    Empresa empresa;
    cout << "INGRESE EL NUMERO DE EMPRESA A BUSCAR: ";
    cin >> numeroEmpresa;
    index = empresaArchivo.buscar(numeroEmpresa);
    if(index >= 0) {
        cout << "**********************" << endl;
        empresa = empresaArchivo.leer(index);
        mostrar(empresa);
        cout << "**********************" << endl;
    } else {
        cout << "LA EMPRESA NO EXISTE" << endl;
    }
}

// LISTA TODAS LAS EMPRESAS DEL ARCHIVO
void EmpresaManager::listarEmpresas() {
    int cantidad = empresaArchivo.getCantidadRegistros();
    for(int i=0; i < cantidad ; i++) {
        Empresa empresa = empresaArchivo.leer(i);
        if (empresa.getEstado()) {
            cout << "**********************" << endl;
            mostrar(empresa);
            cout << "**********************" << endl;
        }
    }
}

// LISTA TODAS LAS EMPRESAS DEL ARCHIVO BACK UP
void EmpresaManager::listarCopiaSeguridad() {
    EmpresaArchivo backupArchivo("empresas.bkp");
    int cantidad = backupArchivo.getCantidadRegistros();
    cout << "LISTADO DE EMPRESAS DEL BACK UP" << endl;
    for (int i = 0; i < cantidad; i++) {
        Empresa empresa = backupArchivo.leerCopiaSeguridad(i);
        cout << "**********************" << endl;
        mostrar(empresa);
        cout << "**********************" << endl;
    }
}

// LISTA TODAS LAS EMPRESAS DEL ARCHIVO DATOS DE INICIO
void EmpresaManager::listarDatosInicioEmpresa() {
    EmpresaArchivo inicioArchivo("empresas_datos_inicio.ini");
    int cantidad = inicioArchivo.getCantidadRegistros();
    cout << "LISTADO DE EMPRESAS DEL ARCHIVO DATOS DE INICIO" << endl;
    for (int i = 0; i < cantidad; i++) {
        Empresa empresa = inicioArchivo.leerDatosInicio(i);
        cout << "**********************" << endl;
        mostrar(empresa);
        cout << "**********************" << endl;
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

// RECIBE UNA POSICION DEL REGISTRO, BUSCA EL REGISTRO EN EL ARCHIVO Y MODIFICA LA FECHA DE CREACION
void EmpresaManager::modificarFechaCreacion() {
    Empresa empresa;
    int numeroEmpresa, index, dia, mes, anio;
    cout << "INGRESE NUMERO DE EMPRESA A MODIFICAR: ";
    cin >> numeroEmpresa;
    index = empresaArchivo.buscar(numeroEmpresa);
    if(index >= 0) {
        empresa = empresaArchivo.leer(index);
        cout << "INGRESE LA NUEVA FECHA DE CREACION" << endl;
        cout << "DIA: ";
        cin >> dia;
        cout << "MES: ";
        cin >> mes;
        cout << "ANIO: ";
        cin >> anio;
        Fecha nuevaFecha(dia, mes, anio);
        empresa.setFechaCreacion(nuevaFecha);
        if (nuevaFecha.fechaValida(empresa.getFechaCreacion())) {
            empresaArchivo.modificar(empresa, index);
            mostrar(empresa);
        } else {
            cout << "NO SE MODIFICO LA FECHA. FECHA DE CREACION NO VALIDA" << endl;
        }
    } else {
        cout << "EL NUMERO DE MUNICIPIO INGRESADO NO EXISTE" << endl;
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
        cout << "4- MODIFICAR FECHA DE CREACION" << endl;
        cout << "5- ELIMINAR EMPRESA LOGICA " << endl;
        cout << "6- LISTAR COPIA SEGURIDAD" << endl;
        cout << "7- LISTAR DATOS DE INICIO" << endl;
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
        case 4:
            system("cls");
            modificarFechaCreacion();
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
            listarDatosInicioEmpresa();
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

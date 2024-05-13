#include<ctime>
#include <iostream>
#include "Fecha.h"

using namespace std;

// CONSTRUCTOR POR OMISION
Fecha::Fecha() {
    _dia = 0;
    _mes = 0;
    _anio = 0;
}
// CONSTRUCTOR POR DEFECTO
Fecha::Fecha(int dia, int mes,int anio) {
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

// SET Y GET
void Fecha::setDia(int dia) {
    _dia = dia;
}
int Fecha::getDia() {
    return _dia;
}

void Fecha::setMes(int mes) {
    _mes = mes;
}
int Fecha::getMes() {
    return _mes;
}

void Fecha::setAnio(int anio) {
    _anio = anio;
}
int Fecha::getAnio() {
    return _anio;
}

// CARGA LA FECHA
void Fecha::cargarFecha() {
    cout <<"INGRESE DIA DE CREACION: ";
    cin >> _dia;
    cout << "INGRESE MES DE CREACION: ";
    cin >> _mes;
    cout << "INGRESE EL ANIO DE CREACION: ";
    cin >> _anio;
}

// MUESTRA LA FECHA
void Fecha::mostrarFecha() {
    cout << _dia << "/" << _mes << "/" << _anio << endl;
}

// GUARDAMOS EL OBJETO FECHA CON LA FECHA ACTUAL
Fecha Fecha::obtenerFechaActual() {
    time_t t = time(0); // GUARDA EN 'T' EL TIEMPO ACTUAL
    tm *now = localtime(&t);
    int dia = now->tm_mday; // 1 - 31
    int mes = now->tm_mon + 1; // 1 - 12
    int anio = now->tm_year + 1900; // 1900 - HOY
    return Fecha(dia, mes, anio);
}

bool Fecha::fechaValida(Fecha fecha){
    // VALIDAMOS LOS RANGOS DE LA FECHA
    if (fecha.getDia() < 0 || fecha.getDia() > 31){
        return false;
    }
    if (fecha.getMes() < 1 || fecha.getMes() > 13){
        return false;
    }
    if (fecha.getAnio() < 0){
        return false;
    }
    // VALIDAMOS CON LA FECHA ACTUAL
    Fecha fechaActual;
    fechaActual = obtenerFechaActual();
    if (fecha.getAnio() > fechaActual.getAnio()){
        return false;
    } else if(fecha.getAnio() == fechaActual.getAnio() && fecha.getMes() > fechaActual.getMes()) {
        return false;
    } else if(fecha.getAnio() == fechaActual.getAnio() && fecha.getMes() == fechaActual.getMes() && fecha.getDia() > fechaActual.getDia()){
        return false;
    }
    return true;
}

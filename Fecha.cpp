#include "Fecha.h"
#include<ctime>
#include <iostream>

using namespace std;

//CONSTRUCTOR POR OMISION
Fecha::Fecha() {
    _dia = 0;
    _mes = 0;
    _anio = 0;
}
//CONSTRUCTOR POR DEFECTO
Fecha::Fecha(int dia, int mes,int anio) {

    setDia(dia);
    setMes(mes);
    setAnio(anio);

}
void Fecha::cargarFecha() {
    time_t  t;
    t = time(NULL);
    struct tm *fecha;
    fecha = localtime(&t);
    int dia, mes,anio;
    Fecha fechaCreacion;
    cout<<"Ingrese dia de creacion:";
    cin>> dia;
    fechaCreacion.setDia(dia);
    cout<<"Ingrese mes de creacion: ";
    cin>>mes;
    fechaCreacion.setMes(mes);
    cout<<"Ingrese año de creacion: ";
    cin>>anio;
    fechaCreacion.setAnio(anio);
}

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



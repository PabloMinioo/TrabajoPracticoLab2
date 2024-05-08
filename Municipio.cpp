#include <string>
#include <cstring>
#include "Municipio.h"

using namespace std;

/// CONSTRUCTOR, SET Y GET DE CLASE MUNICIPIO
// CONSTRUCTOR POR OMISION
Municipio::Municipio() {
    _numeroMunicipio = 0;
    strcpy(_nombre, "");
    _seccionPerteneciente = 0;
    _cantHabitantes = 0;
    _estado = false;
}

// CONSTRUCTOR POR DEFECTO
Municipio::Municipio(int numeroMunicipio, string nombre, int seccionPerteneciente, int cantHabitantes, bool estado) {
    _numeroMunicipio = numeroMunicipio;
    strcpy(_nombre, nombre.c_str());
    _seccionPerteneciente = seccionPerteneciente;
    _cantHabitantes = cantHabitantes;
    _estado = estado;
}

// SETS Y GETS
void Municipio::setNumeroMunicipio(int numeroMunicipio) {
    _numeroMunicipio = numeroMunicipio;
}

int Municipio::getNumeroMunicipio() {
    return _numeroMunicipio;
}

void Municipio::setNombre(string nombre) {
    if(nombre.size() <= 29) {
        strcpy(_nombre, nombre.c_str());
    }
    else {
        strcpy(_nombre, "SIN DATOS");
    }
}

string Municipio::getNombre() {
    return _nombre;
}

void Municipio::setSeccionPerteneciente(int seccionPerteneciente) {
    _seccionPerteneciente = seccionPerteneciente;
}

int Municipio::getSeccionPerteneciente() {
    return _seccionPerteneciente;
}

void Municipio::setCantHabitantes(int cantHabitantes) {
    _cantHabitantes = cantHabitantes;
}

int Municipio::getCantHabitantes() {
    return _cantHabitantes;
}

void Municipio::setEstado(bool estado) {
    _estado = estado;
}

bool Municipio::getEstado() {
    return _estado;
}

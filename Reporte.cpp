#include <string>
#include <cstring>
#include "Reporte.h"

using namespace std;

/// CONSTRUCTOR, SET Y GET DE CLASE REPORTE
// CONSTRUCTOR POR OMISION
Reporte::Reporte(){
    _numeroMunicipio = 0;
    strcpy(_nombreMunicipio, "");
    _cantidadEmpleados = 0;
}

// CONSTRUCTOR POR DEFECTO
Reporte::Reporte(int numeroMunicipio, string nombreMunicipio, int cantidadEmpleados){
    _numeroMunicipio = numeroMunicipio;
    strcpy(_nombreMunicipio, nombreMunicipio.c_str());
    _cantidadEmpleados = cantidadEmpleados;
}

// GET
int Reporte::getNumeroMunicipio() {
    return _numeroMunicipio;
}

string Reporte::getNombreMunicipio(){
    return _nombreMunicipio;
}

int Reporte::getCantidadEmpleados(){
    return _cantidadEmpleados;
}

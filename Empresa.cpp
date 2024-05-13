#include <string>
#include <cstring>
#include "Empresa.h"

using namespace std;

/// CONSTRUCTOR, SET Y GET DE CLASE EMPRESA
// CONSTRUCTOR POR OMISION
Empresa::Empresa() {
    _numeroEmpresa = 0;
    strcpy(_nombreEmpresa, "");
    _cantidadEmpleados = 0;
    _categoria = 0;
    _numeroMunicipio = 0;
    _fechaCreacion = Fecha();
    _facturacionAnual = 0;
    _estado = false;
}

// CONSTRUCTOR POR DEFECTO
Empresa::Empresa(int numeroEmpresa, string nombreEmpresa, int cantidadEmpleados, int categoria, int numeroMunicipio, Fecha fechaCreacion, float facturacionAnual, bool estado) {
    setNumeroEmpresa(numeroEmpresa);
    setNombreEmpresa(nombreEmpresa);
    setCantidadEmpleados(cantidadEmpleados);
    setCategoria(categoria);
    setNumeroMunicipio(numeroMunicipio);
    setFechaCreacion(fechaCreacion);
    setFacturacionAnual(facturacionAnual);
    setEstado(estado);
}

// SET Y GET
int Empresa::getNumeroEmpresa() {
    return _numeroEmpresa;
}

void Empresa::setNumeroEmpresa(int numero) {
    _numeroEmpresa = numero;
}

string Empresa::getNombreEmpresa() {
    return _nombreEmpresa;
}

void Empresa::setNombreEmpresa(string nombreEmpresa) {
    if(nombreEmpresa.size() <= 29) {
        strcpy(_nombreEmpresa, nombreEmpresa.c_str());
    } else {
        strcpy(_nombreEmpresa, "SIN DATOS");
    }
}

int  Empresa::getCantidadEmpleados() {
    return _cantidadEmpleados;
}

void Empresa::setCantidadEmpleados(int cantidadEmpleados) {
    _cantidadEmpleados  = cantidadEmpleados;
}

int  Empresa::getCategoria() {
    return _categoria;
}

void Empresa::setCategoria(int categoria) {
    _categoria = categoria;
}

int  Empresa::getNumeroMunicipio() {
    return _numeroMunicipio;
}

void Empresa::setNumeroMunicipio(int numeroMunicipio) {
    _numeroMunicipio = numeroMunicipio;
}

void Empresa::setFechaCreacion(Fecha fechaCreacion){
    _fechaCreacion = fechaCreacion;
}
Fecha Empresa::getFechaCreacion(){
    return _fechaCreacion;
}

float Empresa::getFacturacionAnual( ){
    return _facturacionAnual;
}

void Empresa::setFacturacionAnual(float facturacionAnual){
    _facturacionAnual = facturacionAnual;
}

bool Empresa::getEstado() {
    return _estado;
}

void Empresa::setEstado(bool estado) {
    _estado = estado;
}

#pragma once
#include <string>

/* LAS PROPIEDRAS Y METODOS DE LA CLASE, DEPENDERA DEL ARCHIVO QUE SE QUIERA CREAR.
*/
/// CLASE REPORTE = ARCHIVO CON LA CANTIDAD DE EMPLEADOS DE UN MUNICIPIO INGRESADO POR TECLADO
class Reporte{
private:
    // PROPIEDADES
    int _numeroMunicipio;
    char _nombreMunicipio[30];
    int _cantidadEmpleados;

public:
    // CONSTRUCTOR
    Reporte();
    Reporte(int numeroMunicipio, std::string nombreMunicipio, int cantidadEmpleados);

    // GET
    int getNumeroMunicipio();
    std::string getNombreMunicipio();
    int getCantidadEmpleados();

    // METODOS
    void mostrar(Reporte reporte);
    void generarReporte();
    void mostrarReporte();
    void menu();
};


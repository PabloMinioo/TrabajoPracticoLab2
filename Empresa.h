#pragma once
#include <string>
/*
CLASE EMPRESA:
    NUMERO EMPPRESA
    NOMBRE EMPRESA (30 CARACTERES)
    CANTIDAD EMPLEADOS
    CATEGORIA (1 - 80)
    MUNICIPIO (1 - 135)
    FECHA CREACION
    FACTURACION ANUAL
    ESTADO
*/

class Empresa{
private:
    /// PROPIEDADES
    int _numeroEmpresa;
    char _nombreEmpresa[30];
    int _cantidadEmpleados;
    int _categoria;
    int _numeroMunicipio;
//    Fecha _fechaCreacion;
    float _facturacionAnual;
    bool _estado;
public:
    /// CONSTRUCTOR
    Empresa();
        Empresa(int numeroEmpresa, std::string nombreEmpresa, int cantidadEmpleados, int categoria, int numeroMunicipio, float facturacionAnual, bool estado);   // AGREGAR FECHA CREACION

    /// SET Y GET
    void setNumeroEmpresa(int numeroEmpresa);
    int getNumeroEmpresa();

    std::string getNombreEmpresa();
    void setNombreEmpresa(std::string nombreEmpresa);

    void setCantidadEmpleados(int cantidadEmpleados);
    int getCantidadEmpleados();

    void setCategoria(int categoria);
    int getCategoria();

    void setNumeroMunicipio(int numeroMunicipio);
    int getNumeroMunicipio();

    void setFacturacionAnual(float facturacionAnual);
    float getFacturacionAnual();

    void setEstado(bool estado);
    bool getEstado();
};

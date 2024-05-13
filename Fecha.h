#pragma once
#include <ctime>

/*
CLASE FECHA:
    DIA
    MES
    AÑO
*/
class Fecha {
private:
    /// PROPIEDADES
    int _dia;
    int _mes;
    int _anio;
public:
    /// CONSTRUCTOR
    Fecha();
    Fecha(int dia,int mes,int anio);
    /// SET Y GET
    void setDia(int dia);
    int getDia();

    void setMes(int mes);
    int getMes();

    void setAnio(int anio);
    int getAnio();
    /// METODOS
    void cargarFecha();
    void mostrarFecha();
    Fecha obtenerFechaActual();
    bool fechaValida(Fecha fecha);
};

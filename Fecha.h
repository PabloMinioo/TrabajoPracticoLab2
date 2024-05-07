#pragma once
#include <ctime>

class Fecha {
private:
    int _dia;
    int _mes;
    int _anio;
public:
    Fecha();
    Fecha(int dia,int mes,int anio);
    void setDia(int dia);
    int getDia();
    void setMes(int mes);
    int getMes();
    void setAnio(int anio);
    int getAnio();
    void cargarFecha();
};

#pragma once
#include <string>

/*
CLASE MUNICIPIO:
    NUMERO MUNICIPIO (1 - 135)
    NOMBRE MUNICIPIO (30 CARACTERES)
    SECCION (1 - 9)
    CANTIDAD HABITANTES
    ESTADO
*/

class Municipio {
private:
    /// PROPIEDADES
    int _numeroMunicipio;
    char _nombre[30];
    int _seccionPerteneciente;
    int _cantHabitantes;
    bool _estado;
public:
    /// CONSTRUCTOR
    Municipio();
    Municipio(int numeroMunicipio, std::string nombre, int seccionPerteneciente, int cantHabitantes, bool estado);

    /// SET Y GETS
    void setNumeroMunicipio(int numeroMunicipio);
    int getNumeroMunicipio();

    void setNombre(std::string nombre);
    std::string getNombre();

    int getSeccionPerteneciente();
    void setSeccionPerteneciente(int seccionPerteneciente);

    void setCantHabitantes(int cantHabitantes);
    int getCantHabitantes();

    void setEstado(bool estado);
    bool getEstado();
};

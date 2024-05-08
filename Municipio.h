#pragma once
#include <string>

class Municipio {
    /// PROPIEDADES
private:
    int _numeroMunicipio;
    char _nombre[30];
    int _seccionPerteneciente;
    int _cantHabitantes;
    bool _estado;
    /// METODOS
public:
    /// CONSTRUCTOR
    Municipio();
    Municipio(int numeroMunicipio, std::string nombre, int seccionPerteneciente, int cantHabitantes, bool estado);

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

#pragma once
#include "Reporte.h"
#include "EmpresaArchivo.h"
#include "MunicipioArchivo.h"

class ReporteManager{
private:
    void mostrar(Reporte reporte);
    void generarReporte();
    void mostrarReporte();
public:
    void menu();
};

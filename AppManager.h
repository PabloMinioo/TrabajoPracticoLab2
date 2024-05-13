#pragma once
#include "EmpresaManager.h"
#include "MunicipioManager.h"
#include "ConfiguracionManager.h"
#include "Reporte.h"

class AppManager{
public:
    void menu();
private:
    EmpresaManager empresaManager;
    MunicipioManager municipioManager;
    Reporte reporte;
    ConfiguracionManager configuracionManager;
};


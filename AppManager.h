#pragma once
#include "EmpresaManager.h"
#include "MunicipioManager.h"
#include "ReporteManager.h"
#include "ConfiguracionManager.h"

class AppManager{
public:
    void menu();
private:
    EmpresaManager empresaManager;
    MunicipioManager municipioManager;
    ReporteManager reporteManager;
    ConfiguracionManager configuracionManager;
};


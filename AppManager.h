#pragma once
#include "EmpresaManager.h"
#include "MunicipioManager.h"
#include "ConfiguracionManager.h"

class AppManager{
public:
    void menu();
private:
    EmpresaManager empresaManager;
    MunicipioManager municipioManager;
    ConfiguracionManager configuracionManager;
};


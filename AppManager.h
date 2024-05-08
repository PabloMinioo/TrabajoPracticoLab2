#pragma once
#include "EmpresaManager.h"
#include "MunicipioManager.h"

class AppManager{
public:
    void menu();
private:
    EmpresaManager empresaManager;
    MunicipioManager municipioManager;
};


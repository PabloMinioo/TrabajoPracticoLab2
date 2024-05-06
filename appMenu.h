#pragma once

using namespace std;
/*

MENU PRINCIPAL
    1 - MENU EMPRESAS
    2 - MENU MUNICPIO
    3 - REPORTES
    4 - CONFIGURACION

    0 - SALIR
*/

/// MENU PRINCIPAL DE LA APLICACION
void menuApp(){
    while(true) {
        int opcion;
        cout<<" ** MENU PRINCIPAL ** "<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"1 - MENU EMPRESAS"<<endl;
        cout<<"2 - MENU MUNICIPIOS"<<endl;
        cout<<"3 - REPORTES"<<endl;
        cout<<"4 - CONFIGURACION"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"0 - FIN DEL PROGRAMA"<<endl;

        cout<< endl <<"SELECCIONE UNA DE LAS OPCIONES: ";
        cin>>opcion;
        system("cls");
        switch(opcion) {
        case 1:
            // Llama al menu Empresas
            break;
        case 2:
            // Llama al menu Muncipio
            break;
        case 3:
            // Llama al menu reportes
            break;
        case 4:
            // Llama al menu de configuracion
            break;
        case 0:
            cout << "GRACIAS POR USAR MI APLICACION" << endl;
            return;
        default:
            cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
            break;
        }
       system("pause");
    }
}

#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstring>

using namespace std;
#include "protofuncionesGlobales.h"
#include "Fecha.h"
#include "directores.h"
#include "salas.h"
#include "peliculas.h"
#include "ventas.h"
#include "datos.h"
#include "submenusalas.h"
#include "submenudatos.h"
#include "submenupeliculas.h"
#include "submenudirector.h"
#include "submenuventas.h"
#include "funcionesGlobales.h"





int main(){
    int opc;
    director obj;
    ventas lol;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) MENU DIRECTORES "<<endl;
        cout<<"2) MENU SALAS "<<endl;
        cout<<"3) MENU PELICULAS"<<endl;
        cout<<"4) MENU VENTAS ENTRADAS"<<endl;
        cout<<"5) MENU DATOS"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) FIN DEL PROGRAMA "<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES : ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: SubMenuDirector();

                    break;
            case 2: SubMenuSalas();
                break;
            case 3: SubMenuPeliculas();
                    break;
            case 4: SubMenuVentas();
                    break;
            case 5: SubMenuDatos();
                    break;
            case 0: return 0;
                    break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    break;
        }
        cout <<endl;

    }

    return 0;
}

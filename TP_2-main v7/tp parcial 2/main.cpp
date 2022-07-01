#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstring>

using namespace std;

#include "funcionesGlobales.h"
#include "Fecha.h"
#include "directores.h"
#include "salas.h"
#include "peliculas.h"
#include "ventas.h"
#include "SubMenuVentas.h"
#include "SubMenuDatos.h"

int main(){
    int opc;
    Salas aux;
    pelicula reg;
    director obj;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) MENU VENTAS ENTRADAS "<<endl;
        cout<<"2) MENU DATOS "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) FIN DEL PROGRAMA "<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES : ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: SubMenuVentas();
                    break;
            case 2: SubMenuDatos();
                    break;
            case -1: reg.cargar();
            if(reg.grabarEnDisco()==true)
            {
                cout << "registro agregado"<<endl;
            }
            else
            {
                cout <<"No se pudo agregar el registro"<<endl;
            }
                    break;
            case -2: obj.cargar();
                    break;
            case -3:
                reg.mostrarPeliculas();
                break;
            case -4: aux.mostrarSalaCine();
                break;
            case -5: aux.cargar();
                break;

            case 0: return 0;
                    break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    break;
        }
        cout <<endl;
        system("pause");
    }

    return 0;
}

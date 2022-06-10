#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstring>

using namespace std;
#include "funcionesGlobales.h"
#include "Fecha.h"
#include "ventas.h"
#include "directores.h"
#include "salas.h"
#include "peliculas.h"


int main(){
    int opc;
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
            case 1:
                    break;
            case 2:

                    break;
            case -1:
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

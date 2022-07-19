#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstring>
#include <windows.h>
using namespace std;
#include "decorado.h"
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

    //system("mode con: cols=79"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
    system("COLOR E4"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
    dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
    dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO

        gotoxy(30,2); printf("MENU PRINCIPAL "); //// 10 puntos
        gotoxy(25,8);cout<<"1) MENU DIRECTORES "<<endl;
        gotoxy(25,9);cout<<"2) MENU SALAS "<<endl;
        gotoxy(25,10);cout<<"3) MENU PELICULAS"<<endl;
        gotoxy(25,11);cout<<"4) MENU VENTAS ENTRADAS"<<endl;
        gotoxy(25,12);cout<<"5) MENU DATOS"<<endl;
        gotoxy(25,13);cout<<"-----------------------------"<<endl;
        gotoxy(25,14);cout<<"0) FIN DEL PROGRAMA "<<endl;
        gotoxy(25,15);cout<<"SELECCIONE UNA DE LAS OPCIONES : ";
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

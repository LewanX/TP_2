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
#include "submenuconfiguracion.h"




int main(){
    int opc;
    director obj;
    ventas lol;

    while(true){
    system("COLOR E4"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
    dibujarCuadro(0,0,117,24); //SE DIBUJA EL CUADRO PRINCIPAL
    dibujarCuadro(1,1,115,3); //SE DIBUJA EL CUADRO DEL TITULO

        gotoxy(51,2); printf("MENU PRINCIPAL "); //// 10 puntos
        gotoxy(45,8);cout<<"1) MENU DIRECTORES "<<endl;
        gotoxy(45,9);cout<<"2) MENU SALAS "<<endl;
        gotoxy(45,10);cout<<"3) MENU PELICULAS"<<endl;
        gotoxy(45,11);cout<<"4) MENU VENTAS ENTRADAS"<<endl;
        gotoxy(45,12);cout<<"5) MENU DATOS"<<endl;
        gotoxy(45,13);cout<<"6) MENU CONFIGURACION"<<endl;
        gotoxy(45,14);cout<<"-----------------------------"<<endl;
        gotoxy(45,15);cout<<"0) FIN DEL PROGRAMA "<<endl;
        gotoxy(45,16);cout<<"SELECCIONE UNA DE LAS OPCIONES : ";
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
            case 6: SubmenuConfiguracion();
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

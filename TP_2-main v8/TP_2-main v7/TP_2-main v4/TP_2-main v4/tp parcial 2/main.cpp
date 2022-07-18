#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstring>
#include <windows.h>
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


void gotoxy(int x, int y){
     HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD poss;
    poss.X = x;
    poss.Y = y;

    SetConsoleCursorPosition(handle,poss);

}
//FUNCION QUE DIBUJA EL CUADRO
void dibujarCuadro(int x1,int y1,int x2,int y2){
    int i;

    for (i=x1;i<x2;i++){
        gotoxy(i,y1); cout << "\304"; //linea horizontal superior
        gotoxy(i,y2); cout << "\304"; //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
        gotoxy(x1,i); cout <<"\263"; //linea vertical izquierda
        gotoxy(x2,i); cout <<"\263"; //linea vertical derecha
    }

    gotoxy(x1,y1); cout<< "\332";
    gotoxy(x1,y2); cout<< "\300";
    gotoxy(x2,y1); cout<< "\277";
    gotoxy(x2,y2); cout<< "\331";
}


int main(){
    int opc;
    director obj;
    ventas lol;
    while(true){

    system("mode con: cols=80 lines=30"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
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

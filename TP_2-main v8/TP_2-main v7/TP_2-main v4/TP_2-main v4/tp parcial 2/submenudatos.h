#ifndef SUBMENUDATOS_H_INCLUDED
#define SUBMENUDATOS_H_INCLUDED

void SubMenuDatos();

void SubMenuDatos(){
    int opc;
    datos reg;
    while(true){
        system("cls");
            system("COLOR E4"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
            dibujarCuadro(0,0,117,24); //SE DIBUJA EL CUADRO PRINCIPAL
            dibujarCuadro(1,1,115,3); //SE DIBUJA EL CUADRO DEL TITULO
        gotoxy(51,2);cout<<"MENU DATOS :";
        gotoxy(40,8);cout<<"1) MOSTRAR RECAUDACION POR CADA PELICULA ";
        gotoxy(40,9);cout<<"2) MOSTRAR PELICULA MAS TAQUILLERA ";
        gotoxy(40,10);cout<<"3) MOSTRAR RECAUDACION POR CADA DIRECTOR";
        gotoxy(40,11);cout<<"4) MOSTRAR DIRECTOR MAS TAQUILLERO";
        gotoxy(40,12);cout<<"5) RECAUDACION TOTAL DE TEEMOPOLIS";
        gotoxy(40,13);cout<<"-----------------------------";
        gotoxy(40,14);cout<<"0) VOLVER AL MENU PRINCIPAL ";
        gotoxy(40,15);cout<<"SELECCIONE UNA DE LAS OPCIONES : ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                    reg.recaudacionpeliculas();
            system("pause");
                    break;
            case 2:
                    reg.peliculaMasTaquillera();
                system("pause");
                    break;
            case 3:
                reg.recaudaciondirector();
                system("pause");
                    break;
            case 4:
                reg.directormastaquillero();
                system("pause");
                    break;

            case 5: reg.RecaudacionCine(); ///funca
                    system("pause");
                    break;
            case 0: return ;
                    break;
            default: cout<<"OPCION INCORRECTA! "<<endl;
                    break;
        }
        cout <<endl;

    }

    return ;
}
#endif // SUBMENUDATOS_H_INCLUDED

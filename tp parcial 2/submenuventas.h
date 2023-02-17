#ifndef SUBMENUVENTAS_H_INCLUDED
#define SUBMENUVENTAS_H_INCLUDED

void SubMenuVentas();

void SubMenuVentas(){
    int opc;
    ventas lol;
    while(true){


        system("cls");
        system("COLOR E4"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
        dibujarCuadro(0,0,117,24); //SE DIBUJA EL CUADRO PRINCIPAL
        dibujarCuadro(1,1,115,3); //SE DIBUJA EL CUADRO DEL TITULO
        gotoxy(51,2);cout<<"MENU VENTAS : ";
        gotoxy(45,8);cout<<"1) AGREGAR VENTA ";
        gotoxy(45,9);cout<<"2) MOSTRAR VENTAS ";
        gotoxy(45,10);cout<<"3) MODIFICAR VENTAS ";
        gotoxy(45,11);cout<<"4) ELIMINAR VENTAS ";
        gotoxy(45,12);cout<<"-----------------------------";
        gotoxy(45,13);cout<<"0) VOLVER AL MENU PRINCIPAL ";
        gotoxy(45,14);cout<<"SELECCIONE UNA DE LAS OPCIONES : ";
        cin>>opc;
        system("cls");
        switch(opc){

            case 1:
                if(lol.cargar()==true && lol.grabarEnDisco()==true)
            {
                cout << "REGISTRO AGREGADO! "<<endl;
            }
            else
            {
                cout <<"ERROR AL AGREGAR REGISTRO! "<<endl;
            }
            system("pause");
                    break;
            case 2: lol.mostrarVentas();
                system("pause");
                    break;
            case 3:
                lol.ModificarVentas();
                system("pause");
                    break;
            case 4:
                lol.EliminarDeDisco();
                system("pause");
                    break;
            case 0: return;
                    break;


            default: cout<<"OPCION INCORRECTA"<<endl;
                    break;
        }
        cout <<endl;

    }

    return ;
}

#endif // SUBMENUVENTAS_H_INCLUDED

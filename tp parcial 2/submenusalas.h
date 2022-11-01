#ifndef SUBMENUSALAS_H_INCLUDED
#define SUBMENUSALAS_H_INCLUDED

void SubMenuSalas();

void SubMenuSalas(){
    int opc;
    Salas aux;
    while(true){


        system("cls");
            system("COLOR E4"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
            dibujarCuadro(0,0,117,24); //SE DIBUJA EL CUADRO PRINCIPAL
            dibujarCuadro(1,1,115,3); //SE DIBUJA EL CUADRO DEL TITULO
            gotoxy(51,2);cout<<"MENU SALAS: ";

        gotoxy(45,8);cout<<"1) AGREGAR SALA "<<endl;
        gotoxy(45,9);cout<<"2) MOSTRAR SALAS "<<endl;
        gotoxy(45,10);cout<<"3) MODIFICAR BUTACAS "<<endl;
        gotoxy(45,11);cout<<"4) ELIMINAR SALA "<<endl;
        gotoxy(45,12);cout<<"-----------------------------"<<endl;
        gotoxy(45,13);cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
        gotoxy(45,14);cout<<"SELECCIONE UNA DE LAS OPCIONES : ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                aux.cargar();
                if(aux.grabarEnDisco()==1){cout<<"REGISTRO AGREAGADO! "<<endl;}else{cout<<"ERROR AL GRABAR! "<<endl;}
                system("pause");
            break;

            case 2:
                 estructuraSala("ID SALA","CANTIDAD BUTACAS","BUTACAS DISPONIBLES");//tabla
                 aux.mostrarDeDisco();
                system("pause");
            break;
            case 3:
                aux.ModificarButacas();
                system("pause");
            break;
            case 4:
                aux.EliminarDeDisco();
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

#endif // SUBMENUSALAS_H_INCLUDED

#ifndef SUBMENUDIRECTOR_H_INCLUDED
#define SUBMENUDIRECTOR_H_INCLUDED
void SubMenuDirector();

void SubMenuDirector(){

    int opc;
    director reg;
    while(true){
        system("cls");

         system("COLOR E4"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
    dibujarCuadro(0,0,117,24); //SE DIBUJA EL CUADRO PRINCIPAL
    dibujarCuadro(1,1,115,3); //SE DIBUJA EL CUADRO DEL TITULO



        gotoxy(51,2);cout<<"MENU DIRECTORES ";

        gotoxy(45,8);cout<<"1) AGREGAR DIRECTOR";
        gotoxy(45,9);cout<<"2) MOSTRAR DIRECTORES ";
        gotoxy(45,10);cout<<"3) MODIFICAR NOMBRE DEL DIRECTOR";
        gotoxy(45,11);cout<<"4) MODIFICAR NACIONALIDAD DEL DIRECTOR";
        gotoxy(45,12);cout<<"5) ELIMINAR DIRECTOR";
        gotoxy(45,13);cout<<"0) VOLVER AL MENU PRINCIPAL ";
        gotoxy(45,14);cout<<"--------------------------------------";
        gotoxy(45,15);cout<<"SELECCIONE UNA DE LAS OPCIONES : ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                reg.cargar();
                if(reg.grabarEnDisco()==1){cout<<"\nREGISTRO AGREGADO"<<endl;}else{cout<<"\nERROR AL GRABAR"<<endl;}
                system("pause");
            break;
            case 2:
                reg.mostrardirectores();
                system("pause");
            break;
            case 3:
                reg.ModificarNombre();
                system("pause");
            break;
            case 4:
                reg.ModificarNacionalidad();
                system("pause");
            break;
            case 5:
                reg.EliminarDeDisco();
                system("pause");
            break;
            case 0:
            return ;
            break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    break;
        }
        cout <<endl;

    }

    return ;
}
















#endif // SUBMENUDIRECTOR_H_INCLUDED

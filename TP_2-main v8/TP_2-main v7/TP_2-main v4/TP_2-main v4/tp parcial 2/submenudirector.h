#ifndef SUBMENUDIRECTOR_H_INCLUDED
#define SUBMENUDIRECTOR_H_INCLUDED
void SubMenuDirector();

void SubMenuDirector(){

    int opc;
    director reg;
    while(true){
        system("cls");

         system("COLOR E4"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
        dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
        dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO



        gotoxy(30,2);cout<<"MENU DIRECTORES ";

        gotoxy(25,8);cout<<"1) AGREGAR DIRECTOR";
        gotoxy(25,9);cout<<"2) MOSTRAR DIRECTORES ";

        gotoxy(25,10);cout<<"3) ELIMINAR DIRECTOR";


        gotoxy(25,11);cout<<"0) VOLVER AL MENU PRINCIPAL ";
        gotoxy(25,12);cout<<"--------------------------------------";
        gotoxy(25,13);cout<<"SELECCIONE UNA DE LAS OPCIONES : ";
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
                reg.EliminarDeDisco();
                system("pause");
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

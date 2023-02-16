#ifndef SUBMENUEMISION_H_INCLUDED
#define SUBMENUEMISION_H_INCLUDED

void SubMenuEmision();

void SubMenuEmision(){

    int opc;

    emision reg;
    while(true){
        system("cls");

         system("COLOR E4"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
    dibujarCuadro(0,0,117,24); //SE DIBUJA EL CUADRO PRINCIPAL
    dibujarCuadro(1,1,115,3); //SE DIBUJA EL CUADRO DEL TITULO



        gotoxy(51,2);cout<<"MENU EMISION ";

        gotoxy(45,8);cout<<"1) AGREGAR EMISION";
        gotoxy(45,9);cout<<"2) MOSTRAR EMISION ";
        gotoxy(45,10);cout<<"3) ELIMINAR EMISION";
        gotoxy(45,11);cout<<"4) MODIFICAR EMISION";
        gotoxy(45,12);cout<<"5) ELIMINAR EMISION";
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
                reg.mostrar();
                system("pause");
            break;
            case 3:

                system("pause");
            break;
            case 4:

                system("pause");
            break;
            case 5:

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






#endif // SUBMENUEMISION_H_INCLUDED

#ifndef SUBMENUDIRECTOR_H_INCLUDED
#define SUBMENUDIRECTOR_H_INCLUDED
void SubMenuDirector();

void SubMenuDirector(){
    int opc;
    director reg;
    while(true){
        system("cls");
        cout<<"MENU PDIRECTORES : "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) AGREGAR DIRECTOR"<<endl;
        cout<<"2) MOSTRAR DIRECTORES "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES : ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                reg.cargar();
                if(reg.grabarEnDisco()==1){cout<<"\nREGISTRO AGREGADO"<<endl;}else{cout<<"\nERROR AL GRABAR"<<endl;}
            break;
            case 2:
                reg.mostrarDeDisco();
            break;
            case 0:
            return ;
            break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    break;
        }
        cout <<endl;
        system("pause");
    }

    return ;
}
















#endif // SUBMENUDIRECTOR_H_INCLUDED

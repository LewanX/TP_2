#ifndef SUBMENUVENTAS_H_INCLUDED
#define SUBMENUVENTAS_H_INCLUDED
void SubMenuVentas();

void SubMenuVentas(){
    int opc;

    while(true){
        system("cls");
        cout<<"MENU VENTAS : "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) AGREGAR VENTA "<<endl;
        cout<<"2) MOSTRAR VENTAS  "<<endl;
        cout<<"2) ELIMINAR VENTAS  "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES : ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                    break;
            case 2:

                    break;

            case 0: return ;
                    break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    break;
        }
        cout <<endl;
        system("pause");
    }

    return ;
}

#endif // SUBMENUVENTAS_H_INCLUDED

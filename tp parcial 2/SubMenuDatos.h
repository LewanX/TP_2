#ifndef SUBMENUDATOS_H_INCLUDED
#define SUBMENUDATOS_H_INCLUDED

void SubMenuDatos();

void SubMenuDatos(){
    int opc;

    while(true){
        system("cls");
        cout<<"MENU DATOS : "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) AGREGAR PELICULA "<<endl;
        cout<<"2) MOSTRAR PELICULAS "<<endl;
        cout<<"3) MOSTRAR PELICULA MAS TAQUILLERA "<<endl;
        cout<<"4) MOSTRAR PELICULA MAS TAQUILLERA EN EL MES "<<endl;
        cout<<"5) MOSTRAR DIRECTOR DE LA PELICULA MAS TAQUILLERA "<<endl;
        cout<<"6) RECAUDACION TOTAL DEL CINE TEEMOPOLIS "<<endl;
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
            case 3:
                    break;
            case 4:

                    break;
            case 5:
                    break;
            case 6:

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

#endif // SUBMENUDATOS_H_INCLUDED

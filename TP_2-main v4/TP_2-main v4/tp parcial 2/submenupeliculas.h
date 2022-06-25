#ifndef SUBMENUPELICULAS_H_INCLUDED
#define SUBMENUPELICULAS_H_INCLUDED

void SubMenuPeliculas();

void SubMenuPeliculas(){
    int opc;
    pelicula reg;
    Salas aux;
    while(true){
        system("cls");
        cout<<"MENU PELICULAS : "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) AGREGAR PELICULA "<<endl;
        cout<<"2) MOSTRAR PELICULAS "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES : ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:reg.cargar();
            if(reg.grabarEnDisco()==true)
            {
                cout << "registro agregado"<<endl;
            }
            else
            {
                cout <<"No se pudo agregar el registro"<<endl;
            }
                    break;
            case 2: reg.mostrarPeliculas();
                system("pause");
                 system("cls");
            case 3: aux.cargar();
                if(aux.grabarEnDisco()==true)
            {
                cout << "registro agregado"<<endl;
            }
            else
            {
                cout <<"No se pudo agregar el registro"<<endl;
            }
            break;
            case 4: aux.mostrarSalas();
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

#endif // SUBMENUPELICULAS_H_INCLUDED

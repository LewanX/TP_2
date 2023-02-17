#ifndef SUBMENUPELICULAS_H_INCLUDED
#define SUBMENUPELICULAS_H_INCLUDED

void SubMenuPeliculas();

void SubMenuPeliculas(){
    int opc;
    pelicula reg;
    while(true){
        system("cls");
            system("COLOR E4"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
            dibujarCuadro(0,0,117,24); //SE DIBUJA EL CUADRO PRINCIPAL
            dibujarCuadro(1,1,115,3); //SE DIBUJA EL CUADRO DEL TITULO
        gotoxy(51,2);cout<<"MENU PELICULAS";
        gotoxy(45,8);cout<<"1) AGREGAR PELICULA ";
        gotoxy(45,9);cout<<"2) MOSTRAR PELICULAS ";
        gotoxy(45,10);cout<<"3) MODIFICAR NOMBRE DE PELICULA ";
        gotoxy(45,11);cout<<"4) MODIFICAR GENERO DE PELICULA ";
        gotoxy(45,12);cout<<"5) MODIFICAR IDIOMA DE PELICULA ";
        gotoxy(45,13);cout<<"6) ELIMINAR PELICULA ";
        gotoxy(45,14);cout<<"-----------------------------";
        gotoxy(45,15);cout<<"0) VOLVER AL MENU PRINCIPAL ";
        gotoxy(45,16);cout<<"SELECCIONE UNA DE LAS OPCIONES : ";
        cin>>opc;
        system("cls");
        switch(opc){

            case 1://AGREGAR PELICULA

                if(reg.cargar()==true ){
                if (reg.grabarEnDisco()==1){
                    cout<<"REGISTRO AGREGADO! ";
                }
                }else{cout<<"ERROR AL GRABAR! ";}
                system("pause");
            break;

            case 2://MOSTRAR PELICULAS
                reg.mostrarPeliculas();
                system("pause");
            break;

            case 3: //MODIFICAR NOMBRE
                reg.ModificarNombrePelicula();
                system("pause");
            break;
            case 4: //MODIFICAR GENERO
                reg.ModificarGenero();
                system("pause");
            break;
            case 5: //MODIFICAR IDIOMA
                reg.ModificarIdioma();
                system("pause");
            break;
            case 6: //ELIMINAR PELICULA
                reg.EliminarDeDisco();
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

#endif // SUBMENUPELICULAS_H_INCLUDED

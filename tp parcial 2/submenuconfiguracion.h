#ifndef SUBMENUCONFIGURACION_H_INCLUDED
#define SUBMENUCONFIGURACION_H_INCLUDED

void SubmenuConfiguracion();

 void SubmenuConfiguracion(){
   director aux;
   pelicula obj;
   Salas salaux;
   ventas reg;
     int opc;
     while(true){
            system("COLOR E4"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
            dibujarCuadro(0,0,117,24); //SE DIBUJA EL CUADRO PRINCIPAL
            dibujarCuadro(1,1,115,3); //SE DIBUJA EL CUADRO DEL TITULO


 gotoxy(51,2);cout<<"MENU CONFIGURACION";
 gotoxy(40,9);cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE DIRECTORES";
 gotoxy(40,10);cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO SALAS";
 gotoxy(40,11);cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO PELICULAS";
 gotoxy(40,12);cout<<"4) COPIA DE SEGURIDAD DEL ARCHIVO VENTAS";
 gotoxy(40,14);cout<<"5) RESTAURAR DATOS DE DIRECTORES";
  gotoxy(40,15);cout<<"6) RESTAURAR DATOS DE SALAS";
  gotoxy(40,16);cout<<"7) RESTAURAR DATOS DE PELICULAS";
  gotoxy(40,17);cout<<"8) RESTAURAR DATOS DE VENTAS";
 gotoxy(40,18);cout<<"--------------------------------";
 gotoxy(40,19);cout<<"0) VOLVER AL MENU PRINCIPAL";
  gotoxy(40,20);cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
        cin>>opc;
        system("cls");
        system("COLOR E4"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
            dibujarCuadro(0,0,117,24); //SE DIBUJA EL CUADRO PRINCIPAL
            dibujarCuadro(1,1,115,3); //SE DIBUJA EL CUADRO DEL TITULO
            gotoxy(51,2);cout<<"MENU CONFIGURACION";
            gotoxy(47,12);
        switch (opc)
        {
        case 1:

            if(aux.backupdirector()==true){cout<<"COPIA REALIZADA";}
            break;
        case 2:

            if(salaux.backupsala()==true){cout<<"COPIA REALIZADA";}
            break;
        case 3:

            if(obj.backuppelicula()==true){cout<<"COPIA REALIZADA";}
            break;
        case 4:

            if(reg.backupventa()==true){cout<<"COPIA REALIZADA;";}
            break;
        case 5:

            if(aux.backupdirector()==true){cout<<"RECUPERACION  DE DIRECTORES REALIZADA";}
            break;
        case 6:

            if(salaux.recusala()==true){cout<<"RECUPERACION DE SALAS  REALIZADA";}
            break;
        case 7:

            if(obj.recupelicula()==true){cout<<"RECUPERACION DE PELICULAS REALIZADA";}
            break;
            case 8:

            if(reg.recuventa()==true){cout<<"RECUPERACION DE VENTAS REALIZADA";}
            break;
        case 0:
                return;
            break;

        default:
            break;
        }
        cout <<endl;
        gotoxy(47,13);
        system("pause");
        system("cls");

}


 }


#endif // SUBMENUCONFIGURACION_H_INCLUDED

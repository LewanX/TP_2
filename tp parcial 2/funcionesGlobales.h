#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED



///FIN PROTOTIPOS

void cargarCadena(char *pal, int tam)
{
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++)
    {
        pal[i]=cin.get();
        if (pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin);
}
int validacionIDpelicula(int id)
{
    pelicula reg;
        int pos=0;
        while(reg.leerEnDisco(pos++)==1){
            if(reg.getidPelicula()==id){

                     return 1;

            }
        }
    return 0;
}
int retornoNombrePelicula(int id)
{
    pelicula reg;
        int pos=0;
        while(reg.leerEnDisco(pos++)==1){
            if(reg.getidPelicula()==id){
                cout<<"PELICULA:"<<reg.getNombrePelicula()<<endl;
                     return 1;

            }
        }
    return 0;
}

bool validacionDatosPelicula(){

    Salas aux;
    director obj;
    bool Sala=false;
    bool Dir=false;
    int pos=0;
    int pos1=0;
    while(aux.leerEnDisco(pos++)){
        if(aux.getEstado()==true){

            Sala=true;
        }
    }
    while(obj.leerEnDisco(pos1++)){
        if(obj.getEstado()==true){
            Dir=true;
        }
    }
    if(Sala==true && Dir==true){

        return true;
    }
    else{
        return false;
    }

}

int validacionDir(int id){
    director aux;
        int pos=0;
        while(aux.leerEnDisco(pos++)==1){
            if(aux.getidDirector()==id&&aux.getEstado()==true){
                    cout<<"DIRECTOR:"<<aux.getnombreDirector();
                     return 1;

            }
        }
    return 0;
}

int validacionSala(int id){
    Salas aux;
    int pos=0;
        while(aux.leerEnDisco(pos++)==1)
        {
            if(aux.getidSala()==id){
                    return 1;

        }

        }
        return 0;
}
int validacionPrecio(int id, int pago){
 ventas aux;
 pelicula obj;
 Salas reg;
 int importe;
 int pos=0;

 while (obj.leerEnDisco(pos++)==1)
 {
     if(obj.getidPelicula()==id){
        importe=obj.getPrecio();
        if(pago==1){
            importe=importe*0.95;
        }else if(pago==2){
            importe=importe*1.20;
        }else{

            importe=importe*1.05;
        }

        return importe;
     }
 }
return 0;

}
int NomDir(int id){
    director aux;
        int pos=0;
        while(aux.leerEnDisco(pos++)==1){
            if(aux.getidDirector()==id){
                    cout<<"DIRECTOR:"<<aux.getnombreDirector();
                    return 1;

            }
        }
        return 0;
}
int verificarSala(int sala){
Salas aux;
int pos=0;
while(aux.leerEnDisco(pos++)){
    if(aux.getidSala()==sala){
        return 1;
    }
}
return 0;

}
int calcularVentas(int id){
    ventas obj;
    pelicula reg;
    int ventas=0;
    int pos=0;
    int pos2=0;
        while(reg.leerEnDisco(pos++)==1){

            if(reg.getSala()==id){
                    while(obj.leerEnDisco(pos2++)==1){
                            if(obj.getidPelicula()==reg.getidPelicula()){
                    ventas+=obj.getCantEntradas();
                    }

                   }

            }



        }
return ventas;

}

int autonumericoVentas(){
ventas obj;
int pos=0;
int c=0;
    while(obj.leerEnDisco(pos++)==1){
       c++;
    }

    return c;

}
int calcularPlazas(int id,int dia, int mes, int anio){
    ventas obj;
    int canttotal=0;
    int pos=0;
    int diaIni,mesIni,anioIni;
        while(obj.leerEnDisco(pos++)==1){
                if(obj.getidPelicula()==id){
                    diaIni=obj.getFecha().getDia();
                    mesIni=obj.getFecha().getMes();
                    anioIni=obj.getFecha().getAnio();
                    if(anio==anioIni&&mes==mesIni&&dia==diaIni){
                        canttotal+=obj.getCantEntradas();
                    }

                }

        }

    return canttotal;
}
int cantButacasSala(int id){
    pelicula reg;
    Salas aux;
    int cantbutacas=0;
        int pos=0;
        int pos2=0;
    while(reg.leerEnDisco(pos++)==1){
        if(reg.getidPelicula()==id){

            while(aux.leerEnDisco(pos2++)==1){
                if(aux.getidSala()==reg.getSala()){
                    cantbutacas=aux.getPlazas();
                    return cantbutacas;

                }



            }

        }
    }
return 0;

}

bool formatoValido(char *formato){
if(strcmp(formato,"2d")==0){
    return true;
}

if(strcmp(formato,"2D")==0){
    return true;
}

if(strcmp(formato,"3d")==0){
    return true;
}

if(strcmp(formato,"3D")==0){
    return true;
}

return false;
}

bool validacionDatosVenta(){
    pelicula aux;
    int pos=0;
    while(aux.leerEnDisco(pos++)){
        if(aux.getEstado()==true){
            return true;
        }
    }
        return false;

}
string determinarTurno(int turno){
    if(turno==1){
        return "MATUTINO";
    }
    if(turno==2){
        return "TARDE";
    }
    if(turno==3){
        return "NOCHE";
    }
}

int validacionIDsala(int salaid){
Salas aux;
int pos=0;
while(aux.leerEnDisco(pos++)){
    if(aux.getidSala()==salaid && aux.getEstado()==true){
        return 1;
        }
    }
return 0;
}

int buscarButacas(int salaid){
Salas aux;
int pos=0;
while(aux.leerEnDisco(pos++)){
    if(aux.getidSala()==salaid){
        return aux.getPlazas();
    }
}
return -1;
}

//int descontarButacas(int dia,int salaID,int turno){
/*int descontarButacas(int salaID,int turno){
emision obj;
ventas aux;
int pos=0;
while(obj.leerEnDisco(pos++)){
        if(obj.getSalaId()==salaID && obj.getTurno()==turno){
            if(validarVenta(salaID)==1){
                return aux.getCantEntradas();
            }
        }

}
}
*/
/*int validarVenta(int salaid){
ventas aux;
int pos=0;
while (aux.leerEnDisco(pos++)){
    if(aux.getSala()==salaid){
        return 1;
    }
}
return 0;
}
*/

bool emisionSala(int salaid,int dia){//CORROBORA SI LA SALA EST� OCUPADA EN SUS TRES TURNOS PARA DETERMINADO DIA
    int pos=0;
    int contadorTurno=0;
        emision reg;
        while(reg.leerEnDisco(pos++)==1){

            if(reg.getDia()==dia && reg.getSalaId()==salaid){
                    if((reg.getTurno()==1)  || (reg.getTurno()==2)  || (reg.getTurno()==3) ){
                            cout<<"TIENE TURNO:"<<determinarTurno(reg.getTurno())<<endl;
                        contadorTurno++;
                    }

            }


        }
        if(contadorTurno==3){
            return true;
        }else{
        return false;
        }

}

bool tieneTurno(int salaid,int dia,int turno){
int pos=0;
    int contadorTurno=0;
        emision reg;
        while(reg.leerEnDisco(pos++)==1){

            if(reg.getDia()==dia && reg.getSalaId()==salaid){
                    if((reg.getTurno()==turno)){
                        return true;
                    }

            }


        }
        return false;


}

///VENTAS
string obtenerNombrePelicula(int id){
pelicula reg;
int pos=0;
while(reg.leerEnDisco(pos++)==1){
    if(reg.getidPelicula()==id){
        return reg.getNombrePelicula();
    }



}
}
void TurnoDePelicula(int SalaID,int dia,int PeliculaId){
int pos=0;

emision reg;
while(reg.leerEnDisco(pos++)==1){
    if(reg.getDia()==dia && reg.getSalaId()==SalaID && reg.getIdPelicula()==PeliculaId){
        cout<<"TURNO:"<<determinarTurno(reg.getTurno())<<endl;
    }
}

}
bool mostrarEmisionesPelicula(int dia){
    emision reg;
    int pos=0;
    bool tienePeliculas=false;
    while(reg.leerEnDisco(pos++)==1){
        if(reg.getDia()==dia){
                tienePeliculas=true;
            cout<<"ID PELICULA:"<<reg.getIdPelicula()<<endl;
            cout<<"NOMBRE PELICULA:"<<obtenerNombrePelicula(reg.getIdPelicula())<<endl;
            cout<<"SALA NUM:"<<reg.getSalaId()<<endl;
            cout<<"TURNO:"<<determinarTurno(reg.getTurno());
             //TurnoDePelicula(reg.getSalaId(),dia,reg.getIdPelicula());
            cout<<endl<<endl;
        }


    }

return tienePeliculas;


}
bool validarPelicula(int dia,int IDpelicula){
emision reg;
int pos=0;
while(reg.leerEnDisco(pos++)==1){
    if(reg.getDia()==dia){
        if(reg.getIdPelicula() == IDpelicula){
            return true;
        }
    }

}

return false;
}

bool validarTurno(int dia,int idPelicula,int turno){

emision reg;
int pos=0;
while(reg.leerEnDisco(pos++)==1){
    if(reg.getDia()==dia && reg.getIdPelicula()==idPelicula){
        if(reg.getTurno()==turno){
            return true;
        }
    }


}
return false;
}
bool validarButacas(int dia,int idPelicula,int turno,int butacas){
emision reg;
int pos=0;
int resta=0;
while(reg.leerEnDisco(pos++)==1){
    if(reg.getDia()==dia && reg.getIdPelicula()==idPelicula && reg.getTurno()==turno){
       if(butacas <= reg.getbutacasDisponibles())

        resta=reg.getbutacasDisponibles()-butacas;

        reg.setbutacasDisponibles(resta);
        if(reg.ModificarEnDisco(pos)==1){
            return true;
        }


    }



}
return false;


}
#endif // FUNCIONESGLOBALES_H_INCLUDED

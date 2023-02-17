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

int fechaPelicula(int id){
    pelicula reg;
    int pos=0;
        int diaFin,mesFin,anioFin;
        int diaIni,mesIni,anioIni;
    while(reg.leerEnDisco(pos++)==1){
        if(reg.getidPelicula()==id && reg.getEstado()==true){
                cout<<"ELIJA UNA FECHA  VALIDA "<<endl;
                    diaIni=reg.getFechaIni().getDia();
                    mesIni=reg.getFechaIni().getMes();
                    anioIni=reg.getFechaIni().getAnio();

                    diaFin=reg.getFechaFin().getDia();
                    mesFin=reg.getFechaFin().getMes();
                    anioFin=reg.getFechaFin().getAnio();

                    cout<<"INICIO DE PROYECION:"<<diaIni<<"/"<<mesIni<<"/"<<anioIni<<endl;
                    cout<<"FINAL DE PROYECION :"<<diaFin<<"/"<<mesFin<<"/"<<anioFin<<endl;
                    return 1;
        }
        else {
            return 0;
        }
    }
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

#endif // FUNCIONESGLOBALES_H_INCLUDED

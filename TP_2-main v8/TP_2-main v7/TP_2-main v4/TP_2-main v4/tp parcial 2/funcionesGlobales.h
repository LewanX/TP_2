#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

void cargarCadena(char *pal, int tam);

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
                    cout<<"ID PELICULA: "<<reg.getidPelicula();
                     return 1;

            }
        }
    return 0;
}
int validacionDir(int id){
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
int validacionSala(int id){
    Salas aux;
    int pos=0;
    int precio=0;
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
                ventas+=obj.getCantEntradas();
                    }
            }



        }

    return ventas;

}
void fechaPelicula(int id){
    pelicula reg;
    int pos=0;
        int diaFin,mesFin,anioFin;
        int diaIni,mesIni,anioIni;
    while(reg.leerEnDisco(pos++)==1){
        if(reg.getidPelicula()==id){
                cout<<"ELIJA UNA FECHA  VALIDA "<<endl;
                    diaIni=reg.getFechaIni().getDia();
                    mesIni=reg.getFechaIni().getMes();
                    anioIni=reg.getFechaIni().getAnio();

                    diaFin=reg.getFechaFin().getDia();
                    mesFin=reg.getFechaFin().getMes();
                    anioFin=reg.getFechaFin().getAnio();

                    cout<<"INICIO DE PROYECION:"<<diaIni<<"/"<<mesIni<<"/"<<anioIni<<endl;
                    cout<<"FINAL DE PROYECION :"<<diaFin<<"/"<<mesFin<<"/"<<anioFin<<endl;


        }
    }
}
int validacionFecha(int id, int dia, int mes, int anio)
{
    pelicula reg;
        int pos=0, fechaIni, fechaFin, fechaActual;
        while(reg.leerEnDisco(pos++)==1){
            if(reg.getidPelicula()==id){
                    fechaIni=(reg.getFechaIni().getAnio()*10000)+(reg.getFechaIni().getMes()*100)+reg.getFechaIni().getDia();
                    fechaFin=(reg.getFechaFin().getAnio()*10000)+(reg.getFechaFin().getMes()*100)+reg.getFechaFin().getDia();
                    fechaActual=(anio*10000)+(mes*100)+dia;
                    if(fechaActual>=fechaIni && fechaActual<=fechaFin)
        {
            return 1;
        }
        else
        {
            return 0;
        }
            }

        }



}
int autonumerico(){
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
    pelicula reg;
    Salas aux;
    int plazas=0;
    int canttotal=0;
    int pos=0,pos2=0,pos3=0;
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

#endif // FUNCIONESGLOBALES_H_INCLUDED

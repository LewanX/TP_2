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
int fechaVentasSala(int anio, int mes, int dia)
{
    cout<<anio;
    cout<<mes;
    cout<<dia;
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

#endif // FUNCIONESGLOBALES_H_INCLUDED

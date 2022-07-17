#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

class datos
{
private:
    int recaudacionTotal=0;
    int recaudacionTotalCine=0;
    int idRecaudado;
    int idtaquillera;
    int totalRecaudado=0, totalpeliculataquillera=0;
    float sumaRecaudacion=0;

    ventas reg;
    pelicula aux;
public:
    ///sets
    void setRecaudacionTotal(int rt){recaudacionTotal=rt;}
    void setIdRecaudado(int idR){idRecaudado=idR;}
    void setRecaudacionTotalCine(int rtc){recaudacionTotalCine=rtc;}

    ///gets

    int getRecaudacionTotal(){return recaudacionTotal;}
    int getIdRecaudado(){return idRecaudado;}
    int getRecaudacionTotalCine(){return recaudacionTotalCine;}

float calcularRecaudacion (int id)
{
    int pos=0;
    while (reg.leerEnDisco(pos++))
    {
        if(reg.getidPelicula()==id)
        {
            sumaRecaudacion+=reg.getTotal();
        }
        return(float)sumaRecaudacion;
    }
}

int IDmastaquillero(int ID){
    ventas reg;
    int pos=0;
    int acumImporte=0;
    while(reg.leerEnDisco(pos++)==1){
        if(reg.getidPelicula()==ID){
            acumImporte+=reg.getTotal();

        }
    }
    return acumImporte;
}

void peliculaMasTaquillera()
{
    int pos=0;
    ventas reg;
    pelicula aux;
    director lol;
    while(reg.leerEnDisco(pos++)==1)
    {
        recaudacionTotal=IDmastaquillero(reg.getidPelicula());
        idtaquillera=reg.getidPelicula();
    }

    cout<<"La Pelicula mas Taquillera es la: "<<idtaquillera<<endl;
    cout<<"Con una recaudacion total de: "<<recaudacionTotal<<endl;
}
/*
int IDdirectortaquillero(int ID){
    ventas reg;
    director lol;
    int pos=0;
    int hola;
    const char idnombre[30];
    while(lol.leerEnDisco(pos++)==1){
        hola=peliculaMasTaquillera(lol.getidDirector());
        if(hola==1){
            strcpy(idnombre,lol.getnombreDirector());
            cout <<"EL DIRECTOR MAS TAQUILLERO ES: "<<idnombre<<endl;
        }
}
*/
int calcularPosMaximo(int *meses, int tam)
{
    int i,posMax=0;
    for(i=1;i<tam;i++)
    {
        if(meses[i]>meses[posMax])
            posMax=i;
    }
    return posMax;
}
int calcularMayor(int *meses, int tam)
{
    int i,mayor=0;
    for(i=1;i<tam;i++)
    {
        if(meses[i]>mayor)
            mayor=meses[i];
    }
    return mayor;
}

void peliculaMasTaquilleraEnUnMes()
{
    int pos=0;
    int meses[12]={0};
    int PeliculaMes;
    while(reg.leerEnDisco(pos++)==1)
    {
        meses[reg.getFecha().getMes()-1]+=reg.getTotal();
        PeliculaMes=reg.getidPelicula();

    }
    int mesMax=calcularPosMaximo(meses,12);
    int recaudacionMax=calcularMayor(meses,12);
    cout<<"LA PELICULA MAS TAQUILLERA: " <<PeliculaMes<<endl;
    cout<<"EN EL MES: " <<mesMax+1<<endl;
    cout<<"CON UNA RECAUDACION DE: "<<recaudacionMax<<endl;
}

void RecaudacionCine()
{
    int pos=0;
    while(reg.leerEnDisco(pos++)==1)
    {
        setRecaudacionTotalCine(reg.getTotal());
        totalRecaudado+=getRecaudacionTotalCine();
    }
    cout<<"LA RECAUDACION TOTAL DEL CINE FUE DE: "<<totalRecaudado<<endl;
}
};
#endif // DATOS_H_INCLUDED

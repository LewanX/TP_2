#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

class datos
{
public:
    int recaudacionTotal=0;
    int recaudacionTotalCine=0;
    int idRecaudado;
    int idDirector;
    ventas reg;
private:
    void setRecaudacionTotal(int rt){recaudacionTotal=rt;}
    void setIdRecaudado(int idR){idRecaudado=idR;}
    void setRecaudacionTotalCine(int rtc){recaudacionTotalCine=rtc;}
    void setIdDirector(int idD){idDirector=idD;}
    int getIDdirector(){return idDirector;}
    int getRecaudacionTotal(){return recaudacionTotal;}
    int getIdRecaudado(){return idRecaudado;}
    int getRecaudacionTotalCine(){return recaudacionTotalCine;}

float calcularRecaudacion (int id)
{
    int pos=0, sumaRecaudacion=0;
    while (reg.leerEnDisco(pos++))
    {
        if(reg.getidPelicula()==id)
        {
            sumaRecaudacion+=reg.getImporte();
        }
        return(float)sumaRecaudacion;
    }
}

void peliculaMasTaquillera()
{
    int pos=0;
    while(reg.leerEnDisco(pos++))
    {
        getRecaudacionTotal()=calcularRecaudacion(reg.getidPelicula())
        getIdRecaudado(reg.getidPelicula());

    }
    cout<<"La Pelicula mas Taquillera es la: "<<getIdRecaudado()<<endl;
    cout<<"Con una recaudacion total de: "<<getRecaudacionTotal()<<endl;
}

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
            mayor=i;
    }
    return mayor;
}
void peliculaMasTaquilleraEnUnMes()
{
    int pos=0;
    int meses[12]={0};
    int PeliculaMes;
    while(reg.leerEnDisco(pos++))
    {
        meses[reg.getFechaVenta().getMes()-1]+=reg.getImporte();
        PeliculaMes=reg.getidPelicula();

    }
    int mesMax=calcularPosMaximo(meses,12);
    int recaudacionMax=calcularMayor(meses,12);
    cout<<"La pelicula mas Taquillera en un mes es la: " <<PeliculaMes<<endl;
    cout<<"En el mes: " <<mesMax<<endl;
    cout<<"Con una recaudacion de: "<<recaudacionMax<<endl;
}
void RecaudacionCine()
{
    int pos=0;
    while(reg.leerEnDisco(pos++))
    {
        getRecaudacionTotalCine(reg.getImporte())+=;
    }
    cout<<"La recaudacion Total del cine fue de: "<<getRecaudacionTotalCine()<<endl;
}
};

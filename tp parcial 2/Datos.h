#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

class datos
{
private:
    int recaudacionTotal=0;
    int recaudacionTotalCine=0;
    int idRecaudado;
    int idtaquillera;
    int totalpeliculataquillera=0;
    float recaudacionporpelicula=0;
    char nombrePelicula[30];
    char nombreDirector[30];

    ventas reg;
    pelicula aux;
    director obj;
    emision lol;
public:
    ///sets
    void setNombrePelicula (const char *Np){strcpy(nombrePelicula,Np);}
    void setRecaudacionporpelicula(int rt){recaudacionporpelicula=rt;}
    void setRecaudacionTotal(int rt){recaudacionTotal=rt;}
    void setIdRecaudado(int idR){idRecaudado=idR;}
    void setRecaudacionTotalCine(int rtc){recaudacionTotalCine=rtc;}
    void setNombreDirector (const char *Nd){strcpy(nombreDirector,Nd);}

    ///gets
    float getrecaudacionporpelicula(){return recaudacionporpelicula;}
    int getRecaudacionTotal(){return recaudacionTotal;}
    int getIdRecaudado(){return idRecaudado;}
    int getRecaudacionTotalCine(){return recaudacionTotalCine;}
    const char *getnombreDirector (){return nombreDirector;}
    ///funciones




    void Mostrar(){
        cout<<"LA PELICULA MAS TAQUILLERO ES : "<<nombrePelicula<<endl;
        cout<<"CON UNA RECAUDACION TOTAL DE : "<<recaudacionporpelicula<<endl;

    }
    void MostrarDirector(){
         cout<<"EL DIRECTOR MAS TAQUILLERO ES : " <<nombreDirector<<endl;
        cout<<"CON UNA RECAUDACION TOTAL DE : "<<recaudacionporpelicula<<endl;
    }
    //////////////////////////////PUNTO 1///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/*
     ventas reg;
    pelicula aux;
    director obj;
    emision lol;

*/
float recpeli(int id){
    int pos=0;
    float canttotal=0;
        while(reg.leerEnDisco(pos++)==1){
                if(reg.getidPelicula()==id){
                    canttotal+=reg.getTotal();
                }

            }
            return canttotal;

    }
   void recaudacionpeliculas(){


            int pos=0;
        while(aux.leerEnDisco(pos++)==1){
                if(aux.getEstado()==true){
                    cout<<aux.getNombrePelicula()<<" RECAUDO UN TOTAL DE "<<recpeli(aux.getidPelicula())<<" PESOS"<<endl<<endl;
                }



        }

    }

//////////////////////////////PUNTO 2///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
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


int contarpeliculas(){
    int pos=0;
    int tam=0;
    while(aux.leerEnDisco(pos++)==1){
            if(aux.getEstado()==true){
                    tam+=1;
            }

    }
    return tam;
}
void peliculaMasTaquillera()
{   int max=0,posmax=0;
    datos *vDinamico;
    int cantpeliculas=contarpeliculas();
    vDinamico=new datos[cantpeliculas];
    if(vDinamico==NULL)return;

    for(int i=0;i<cantpeliculas;i++){
        aux.leerEnDisco(i);
        vDinamico[i].setNombrePelicula(aux.getNombrePelicula());
        vDinamico[i].setRecaudacionporpelicula(IDmastaquillero(aux.getidPelicula()));

    }
    max=vDinamico[0].getrecaudacionporpelicula();
    for(int i=0;i<cantpeliculas;i++){

        if(vDinamico[i].getrecaudacionporpelicula()>max){
            max=vDinamico[i].getrecaudacionporpelicula();
            posmax=i;
        }

    }

    for(int i=0;i<cantpeliculas;i++){
        if(posmax==i){
            vDinamico[posmax].Mostrar();
        }
    }

    delete vDinamico;

}


//////////////////////////////PUNTO 3///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
 float recdir(int id){
    int pos=0;
    float canttotal=0;
        while(aux.leerEnDisco(pos++)==1){
                if(aux.getidDirector()==id){
                    canttotal+=calcularRecaudacion(aux.getidPelicula());
                }

            }
            return canttotal;

    }
    void recaudaciondirector(){
            int pos=0;
        while(obj.leerEnDisco(pos++)==1){
                if(obj.getEstado()==true){
                    cout<<"EL DIRECTOR "<<obj.getnombreDirector()<<" RECAUDO UN TOTAL DE "<<recdir(obj.getidDirector())<<" PESOS"<<endl<<endl;
                }



        }

    }

float calcularRecaudacion (int id)
{
    float sumaRecaudacion=0;
    int pos=0;
    while (reg.leerEnDisco(pos++))
    {
        if(reg.getidPelicula()==id)
        {
            sumaRecaudacion+=reg.getTotal();
        }

    }
    return(float)sumaRecaudacion;
}
//////////////////////////////////PUNTO 4//////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
int contardirectores(){
    int pos=0;
    int tam=0;
    while(obj.leerEnDisco(pos++)==1){
            if(obj.getEstado()==true){
                    tam+=1;
            }

    }
    return tam;
}

void directormastaquillero()
{   int max=0,posmax=0;
    datos *vDinamico;
    int cantdirectores=contardirectores();
    vDinamico=new datos[cantdirectores];
    if(vDinamico==NULL)return;

    for(int i=0;i<cantdirectores;i++){
        obj.leerEnDisco(i);
        vDinamico[i].setNombreDirector(obj.getnombreDirector());
        vDinamico[i].setRecaudacionporpelicula(recdir(obj.getidDirector()));

    }
    max=vDinamico[0].getrecaudacionporpelicula();
    for(int i=0;i<cantdirectores;i++){

        if(vDinamico[i].getrecaudacionporpelicula()>max){
            max=vDinamico[i].getrecaudacionporpelicula();
            posmax=i;
        }

    }

    for(int i=0;i<cantdirectores;i++){
        if(posmax==i){
            vDinamico[posmax].MostrarDirector();
        }
    }

    delete vDinamico;

}
























//////////////////////////////////PUNTO 5//////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
void RecaudacionCine()
{
    int totalRecaudado=0;
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

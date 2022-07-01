#ifndef SALAS_H_INCLUDED
#define SALAS_H_INCLUDED

class Salas{
private:
    int idSala;
    int tipo;
    int c=1;
    int plazas;
    int Butacas, fila;
    int asientos[15][15]={0};
    int asientosEspeciales[10][10]={0};
    bool estado;

public:
     ///sets()

     void setidSala(int S){idSala=S;}
     void setTipo(int T){tipo=T;}
     void setButacas(int B){Butacas=B;}

     ///gets()

     int getidSala(){return idSala;}
     int getTipo(){return tipo;}
     int getButacas(){return Butacas;}

    ///disco
      int grabarEnDisco();
      int leerEnDisco(int);
      void mostrarDeDisco();

       bool cargarSalas()
      {
          FILE *s;
          bool escribio;
          Salas reg;
          s=fopen("salas.dat","ab");
          if (s==NULL) return false;
              cargar();
              escribio=fwrite(this,sizeof reg, 1,s);
              fclose(s);
              return escribio;

      }
/*
void mostrarSalas()
{
    FILE *s;
    s=fopen("salas.dat","rb");
    if (s==NULL) return;
    while(fread(this,sizeof (Salas),1,s)==1)
    {
        mostrarSalaCine();
    }
    fclose(s);
}
*/



void cargar(){
    cout<<"INGRESE EL ID DE LA SALA: ";cin>>idSala;
        while(validacionSala(idSala)==1){
        cout <<" ESTE ID DE SALA YA EXISTE! "<< endl;
        system("pause");
        system("cls");
        cout<<"INGRESE EL ID DE SALA: " <<endl;
        cin>>idSala;
    }
    cout<<"INGRESE LA CANTIDAD DE BUTACAS:";cin>>plazas;
}
void  mostrar(){
    cout<<"ID SALA:"<<idSala<<endl;
    plazas-=calcularVentas(idSala);
    cout<<"CANTIDAD DE BUTACAS:"<<plazas<<endl;
}
/*
void mostrarSalaCine()
{
    cout<<"Numero de ID de sala: "<< idSala<<endl;
    cout<<"Tipo de sala: "<< tipo<<endl;
    if (tipo==1)
    {
        cout<<"------------Pantalla----------\n";
        for (int i=0; i<15;i++)
        {
            for(int j=0; j<15;i++)
            {
            cout<<asientos[i][j]<<"\t";
            cout<<endl;
            }
        }
                }
    if (tipo==2)
    {
     cout<<"------------Pantalla----------\n";
      for (int i=0; i<10;i++)
    {
        for(int j=0; j<10;i++)
        {
            cout<<asientosEspeciales[i][j]<<"\t";
            cout<<endl;
        }
    }
}
}
void reservarAsiento(int fila,int Butacas)
{
    if(tipo==1)
    {
     cout<<"Ingresar Numero de Fila deseada(1-15)";
     cin>>fila;
     cout<<"Ingresar Numero de Columna deseada(1-15)";
     cin>>Butacas;
     if(asientos[fila-1][Butacas-1]==0)
     {
         asientos[fila-1][Butacas-1]=1;
         c=c+1;
         cout<<"Reserva Exitosa";
     }
     else
     {
         cout<<"Asiento Ocupado";
     }

    for (int i=0; i<15;i++)
    {
        for(int j=0; j<15;i++)
        {
            cout<<asientos[i][j]<<"\t";
            cout<<endl;
        }
    }
    }
    else
    {
        if(tipo==2)
        {
     cout<<"Ingresar Numero de Fila deseada(1-15)";
     cin>>fila;
     cout<<"Ingresar Numero de Columna deseada(1-15)";
     cin>>Butacas;
     if(asientosEspeciales[fila-1][Butacas-1]==0)
     {
         asientosEspeciales[fila-1][Butacas-1]=1;
         c=c+1;
         cout<<"Reserva Exitosa";
     }
     else
     {
         cout<<"Asiento Ocupado";
     }

    for (int i=0; i<10;i++)
    {
        for(int j=0; j<10;i++)
        {
            cout<<asientosEspeciales[i][j]<<"\t";
            cout<<endl;
        }
    }
        }
    }
}
*/
};

int Salas::grabarEnDisco()
{
    FILE *s;
    s=fopen("salas.dat","ab");
    if (s==NULL) return -1;
    int escribio=fwrite(this,sizeof(Salas),1,s);
    fclose(s);
    return escribio;
}

int Salas::leerEnDisco(int pos)
{
    FILE *s;
    s=fopen("salas.dat","rb");
    if (s==NULL) return -1;
    fseek(s,sizeof(Salas)*pos,0);
    int leyo=fread(this,sizeof(Salas),1,s);
    fclose(s);
    return leyo;
}
void Salas::mostrarDeDisco(){
    int pos=0;
    while(leerEnDisco(pos++)==1){

        mostrar();
        cout<<endl;

    }



}
#endif // SALAS_H_INCLUDED

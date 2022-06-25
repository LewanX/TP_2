#ifndef SALAS_H_INCLUDED
#define SALAS_H_INCLUDED

class Salas{
private:
    int idSala;
    int tipo;
    int cantButacas, cantFilas;
    int matriz[30][20]={0};
    bool estado;
public:
     ///sets()

     void setidSala(int S){idSala=S;}
     void setTipo(int T){tipo=T;}
     void setcantButacas(int B){cantButacas=B;}

     ///gets()

     int getidSala(){return idSala;}
     int getTipo(){return tipo;}
     int getcantButacas(){return cantButacas;}

    ///disco
      int grabarEnDisco();
      int leerEnDisco(int);

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




void cargar(){
    cout<<"INGRESE EL TIPO DE SALA:";cin>>tipo;
    if (tipo==1) cout<<"Sala Normal"<<endl;
    if (tipo==2) cout<<"Sala Con asientos Especiales"<<endl;
    cout<<"INGRESE LA CANTIDAD DE FILAS:";cin>>cantFilas;
    cout<<"INGRESE LA CANTIDAD DE ASIENTOS POR FILA:";cin>>cantButacas;
    for(int i=0; i<cantButacas; i++)
    {
    for(int j=0; j<cantFilas; j++)
    {
    matriz[i][j]=0;
    }
    }
}
void mostrarSalaCine()
{
    cout<<"Numro de ID de sala: "<< idSala<<endl;
    cout<<"Tipo de sala: "<< tipo<<endl;
    cout<<"------------Pantalla----------\n";
    for(int i=0;i<cantButacas;i++)
    {
        cout<<"("<<i+1<<")";
        for(int j=0;j<cantFilas;j++)
        {
            cout<<"["<<matriz[i][j]<<"]";
        }
        cout<<"\n";
    }
}
bool reservarAsiento(int i, int j)
{
    if(matriz[i][j]==0)
    {
        matriz[i][j]==1;
        cout<<"Se pudo reservar";
        return true;
    }
    else
    {
        cout<<"Ese asiento esta ocupado, seleccione otro\n";
    }
    return false;
}

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


#endif // SALAS_H_INCLUDED

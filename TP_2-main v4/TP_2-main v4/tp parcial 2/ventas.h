#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

class ventas
{
    private:

      int Nventa, CantEntradas, Importe, Pago,fila,asiento, idPelicula;
      Fecha FechaVenta;
       Salas aux;
       pelicula obj;
       bool estado;
    public:
        ///sets()
      void setidPelicula (int id){idPelicula=id;}
      void setNventa (int Nv){Nventa=Nv;}
      void setCantEntradas (int CantE){CantEntradas=CantE;}
      void setImporte (int Imp){Importe=Imp;}
      void setPago (int P){Pago=P;}
      void setFechaVenta (Fecha F){FechaVenta=F;}
      void setEstado(bool e){estado=e;}
      ///gets()
      int getidPelicula(){return idPelicula;}
      int getNventa (){return Nventa;}
      int getCantEntradas (){return CantEntradas;}
      int getImporte (){return Importe;}
      int getPago (){return Pago;}
      Fecha getFechaVenta () {return FechaVenta;}
      bool getEstado(){return estado;}
      ///disco


      int grabarEnDisco();
      int leerEnDisco(int);

      bool cargarVentas()
      {
          FILE *p;
          bool escribio;
          ventas reg;
          p=fopen("ventas.dat","ab");
          if (p==NULL) return false;
              cargar();
              escribio=fwrite(this,sizeof reg, 1,p);
              fclose(p);
              return escribio;

      }

void mostrarVentas()
{
    FILE *p;
    p=fopen("ventas.dat","rb");
    if (p==NULL) return;
    while(fread(this,sizeof (ventas),1,p)==1)
    {
        mostrar();
    }
    fclose(p);
}


void cargar(){
    estado=true;
    cout<<"Ingrese el numero de venta : "<<endl;
    cin >>Nventa;///aleatorio
    cout<<"Ingrese el Id de la Pelicula : " <<endl;
    cin>>idPelicula;
    cout<<"Ingrese la cantidad de entradas : "<<endl;
    cin>>CantEntradas;
    for (int i=0; i<CantEntradas;i++)
    {
     cout<<"Elegir fila: " << endl;
     cin>> fila;
     cout<<"Elegir Asiento: " << endl;
     cin>> asiento;
     aux.reservarAsiento(fila,asiento);
    }

    cout<<endl;
    cout<<"Ingrese el metodo de pago (1-efectivo 2-credito 3-debito)"<<endl;
    cin >>Pago;
    cout<<"El importe es de: "<<endl;
    Importe=150;
    cout<< Importe;
}
void mostrar()
{
    cout<<"Id de la pelicula: " <<endl;
    cout<<idPelicula<<endl;
    cout<<"Numero de venta : "<<endl;
    cout<<Nventa<<endl;
    cout<<"Cantidad de entradas : "<<endl;
    cout<<CantEntradas<<endl;
    cout<<"Fila Elegida: " << endl;
    cout<< fila<<endl;
    cout<<"Asiento Elegido: " << endl;
    cout<<asiento<<endl;
    cout<<"Metodo de pago Elegido"<<endl;
    cout<<Pago<<endl;
    cout<<"El importe es de: "<<endl;
    cout<< Importe<<endl;
}

};

int ventas::grabarEnDisco()
{
    FILE *p;
    p=fopen("ventas.dat","ab");
    if (p==NULL) return -1;
    int escribio=fwrite(this,sizeof(ventas),1,p);
    fclose(p);
    return escribio;
}

int ventas::leerEnDisco(int pos)
{
    FILE *p;
    p=fopen("ventas.dat","rb");
    if (p==NULL) return -1;
    fseek(p,sizeof(ventas)*pos,0);
    int leyo=fread(this,sizeof(ventas),1,p);
    fclose(p);
    return leyo;
}
#endif // VENTAS_H_INCLUDED

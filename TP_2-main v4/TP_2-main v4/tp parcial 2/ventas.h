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
    cout<<"INGRESE EL NUMERO DE VENTA : "<<endl;
    cin >>Nventa;///aleatorio
    cout<<"INGRESE EL ID DE LA PELICULA : " <<endl;
    cin>>idPelicula;
    cout<<"INGRESE CANTIDAD DE ENTRADAS : "<<endl;
    cin>>CantEntradas;
    for (int i=0; i<CantEntradas;i++)
    {
     cout<<"ELEGIR FILA: " << endl;
     cin>> fila;
     cout<<"ELEGIR ASIENTO: " << endl;
     cin>> asiento;
     aux.reservarAsiento(fila,asiento);
    }

    cout<<endl;
    cout<<"INGRESE METODO DE PAGO [(1=EFECTIVO) (2=CREDITO) (3=DEBITO)]"<<endl;
    cin >>Pago;
    cout<<"EL IMPORTE ES DE: "<<endl;
    Importe=150;
    cout<< Importe;
}
void mostrar()
{
    cout<<"ID DE LA PELICULA: " <<endl;
    cout<<idPelicula<<endl;
    cout<<"NUMERO DE VENTA: "<<endl;
    cout<<Nventa<<endl;
    cout<<"CANTIDAD DE ENTRADAS: "<<endl;
    cout<<CantEntradas<<endl;
    cout<<"FILA ELEGIDA: " << endl;
    cout<< fila<<endl;
    cout<<"ASIENTO ELEGIDO: " << endl;
    cout<<asiento<<endl;
    cout<<"METODO DE PAGO: "<<endl;
    cout<<Pago<<endl;
    cout<<"IMPORTE: "<<endl;
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

#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

class ventas
{
    private:

      int Nventa, CantEntradas, Importe=150, Pago,fila,asiento, idPelicula;
      Fecha FechaVenta;
      int Total;
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
      int getTotal (){return Total;}
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
    Nventa=autonumerico()+1;
    cout<<"NUMERO DE VENTA : "<<Nventa<<endl;
    cout<<"INGRESE EL ID DE LA PELICULA : " <<endl;//falta validacion
    cin>>idPelicula;

     cout<<"INGRESE CANTIDAD DE ENTRADAS : "<<endl;
    cin>>CantEntradas;

    cout<<endl;
    cout<<"INGRESE METODO DE PAGO [(1=EFECTIVO) (2=CREDITO) (3=DEBITO)]"<<endl;
    cin >>Pago;

    while(validacionPrecio(idPelicula, Pago)==0){
        cout <<"EL ID INGRESADO NO EXISTE! "<< endl;
        system("pause");
        system("cls");
        cout<<"INGRESE EL ID DE LA PELICULA : " <<endl;
        cin>>idPelicula;
    }

    cout<<"EL IMPORTE ES DE: ";
    Total=validacionPrecio(idPelicula, Pago);
    Total=Total*CantEntradas;
    cout<< Total<<endl;
    FechaVenta.Cargar();
}
void mostrar()
{
    cout<<"ID DE LA PELICULA: ";
    cout<<idPelicula<<endl;
    cout<<"NUMERO DE VENTA: "<<Nventa<<endl;
    cout<<"CANTIDAD DE ENTRADAS: ";
    cout<<CantEntradas<<endl;
    cout<<"METODO DE PAGO: ";
    cout<<Pago<<endl;
    cout<<"IMPORTE: ";
    cout<< Total<<endl;
    FechaVenta.Mostrar();
    cout <<" "<<endl<<endl;
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

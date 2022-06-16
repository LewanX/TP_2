#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

class ventas
{
    private:

      int Nventa, CantEntradas, Importe, Pago;
      Fecha FechaVenta;
       pelicula Idpelicula;
       bool estado;
    public:
        ///sets()
      void setIdpelicula (pelicula idP){Idpelicula=idP;}
      void setNventa (int Nv){Nventa=Nv;}
      void setCantEntradas (int CantE){CantEntradas=CantE;}
      void setImporte (int Imp){Importe=Imp;}
      void setPago (int P){Pago=P;}
      void setFechaVenta (Fecha F){FechaVenta=F;}
      void setEstado(bool e){estado=e;}
      ///gets()
      pelicula getIdpelicula (){return Idpelicula;}
      int getNventa (){return Nventa;}
      int getCantEntradas (){return CantEntradas;}
      int getImporte (){return Importe;}
      int getPago (){return Pago;}
      Fecha getFechaVenta () {return FechaVenta;}
      bool getEstado(){return estado;}
      ///disco

      void mostrar();
      int grabarEnDisco();
      int leerEnDisco(int);


void cargar(){
    estado=true;

    cout<<"Id de la Pelicula : " << Idpelicula.getidPelicula <<endl;
    cout<<"Ingrese el numero de venta : "<<endl;
    cin >>Nventa;
    cout<<"Ingrese la cantidad de entradas : "<<endl;
    cin>>CantEntradas;
    cout<<"Importe : "<< Importe <<endl;
    cout<<"Ingrese el metodo de pago (1-efectivo 2-credito 3-debito)"<<endl;
    cin >>Pago;
    ///cout<<FechaVenta;


}
};
#endif // VENTAS_H_INCLUDED

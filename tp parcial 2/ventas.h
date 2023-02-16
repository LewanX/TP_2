#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

class ventas
{
    private:

      int butacastotal=0,butacasvendidas=0,butacassala=0,Nventa, CantEntradas, Importe=150, Pago,fila,asiento, idPelicula;
      fechaAct fecha;
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
      void setFecha(fechaAct F) {fecha=F;}
      void setEstado(bool e){estado=e;}
      ///gets()
      int getidPelicula(){return idPelicula;}
      int getNventa (){return Nventa;}
      int getCantEntradas (){return CantEntradas;}
      int getImporte (){return Importe;}
      int getTotal (){return Total;}
      int getPago (){return Pago;}
      fechaAct getFecha () {return fecha;}

      bool getEstado(){return estado;}
      ///disco

      void EliminarDeDisco();
      int ModificarEnDisco(int pos);
      int grabarEnDisco();
      int leerEnDisco(int);
      bool recuventa();
      bool backupventa();
      int LeerDeDiscobkp(int pos);
      void ModificarVentas();

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


bool cargar(){
    if(validacionDatosVenta()==true){
    estado=true;
    Nventa=autonumericoVentas()+1;
    cout<<"NUMERO DE VENTA : "<<Nventa<<endl;
    cout<<"INGRESE EL ID DE LA PELICULA: " <<endl;
    cin>>idPelicula;
    /*if(fechaPelicula(idPelicula)==0){
        cout<<"ESTA PELICULA NO ESTA DISPONIBLE"<<endl;
        system("pause");
        return false;
    }
    fecha.Cargar();
    int diaAct=getFecha().getDia();
    int mesAct=getFecha().getMes();
    int anioAct=getFecha().getAnio();
    while(validacionFecha(idPelicula,diaAct,mesAct,anioAct)==0){
        cout <<"LA FECHA INGRESADA NO ES CORRECTA"<< endl;
        system("pause");
        system("cls");
        fechaPelicula(idPelicula);
        fecha.Cargar();
        diaAct=getFecha().getDia();
        mesAct=getFecha().getMes();
        anioAct=getFecha().getAnio();
    }*/
    while(validacionPrecio(idPelicula, Pago)==0){
        cout <<"EL ID INGRESADO NO EXISTE! "<< endl;
        system("pause");
        system("cls");
        cout<<"INGRESE EL ID DE LA PELICULA: " <<endl;
        cin>>idPelicula;
    }

    //butacassala=cantButacasSala(idPelicula);
    //butacasvendidas=calcularVentas(idPelicula);
    //butacastotal=butacassala-butacasvendidas;
    //cout<<"CANTIDAD DE BUTACAS DISPONIBLES:"<<butacastotal<<endl;
    /*if(butacastotal<=0){
        cout<<"LA SALA YA SE ENCUENTRA COMPLETA"<<endl;
        system("pause");
        system("cls");
        return cargar();

    }*/
     cout<<"INGRESE CANTIDAD DE ENTRADAS: ";
    cin>>CantEntradas;
    while(CantEntradas<10){
        cout <<" SE PUEDEN COMPRAR HASTA 10 ENTRADAS! "<< endl;
        system("pause");
        system("cls");
        cout<<"INGRESE LA CANTIDAD DE ENTRADAS: " <<endl;
        cin>>CantEntradas;
    }
    while(CantEntradas>butacastotal){
         cout <<"NO HAY SUFICIENTES BUTACAS!"<< endl;
        cout<<"CANTIDAD DE BUTACAS DISPONIBLES:"<<butacastotal<<endl;
        system("pause");
        system("cls");
        cout<<"INGRESE LA CANTIDAD DE ENTRADAS: " <<endl;
        cin>>CantEntradas;


    }
    cout<<endl;
    cout<<"INGRESE METODO DE PAGO [(1=EFECTIVO) (2=CREDITO) (3=DEBITO)]"<<endl;
    cin >>Pago;
    cout<<"EL IMPORTE ES DE: ";
    Total=validacionPrecio(idPelicula, Pago);
    Total=Total*CantEntradas;
    cout<< Total<<endl;
    return true;
    }
    else{
        cout<<"PRIMERO DEBE HABER PELICULAS CARGADAS"<<endl;
        return false;
    }
}


void mostrar()
{
    if(estado==true)
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
    fecha.Mostrar();
    cout <<" "<<endl<<endl;
    }

}

};
void ventas::EliminarDeDisco(){
       int pos=0;
       int idV;
        cout<<"INTRODUZCA EL ID DE VENTA A ELIMINAR: ";cin>>idV;
        while(leerEnDisco(pos)==1){
                if(getNventa()==idV){
                        cout<<"EL ID DE VENTA TIENE LOS SIGUIENTES DATOS"<<endl;
                        mostrar();
                        cout<<endl<<endl;
                        setEstado(false);
                        if(ModificarEnDisco(pos)==1){cout<<"REGISTRO ELIMINADO! ";}
                }
            pos++;
        }

}

void ventas::ModificarVentas(){
        int pos=0;
        int Entradas, Nv;
        cout<<"INTRODUCE EL NUMERO DE VENTA A LISTAR: ";cin>>Nv;
        while(leerEnDisco(pos)==1){
             if(getNventa()==Nv){
                    if(getEstado()==true){

                cout<<"INTRODUCE UNA NUEVA CANTIDAD DE ENTRADAS: ";cin>>Entradas;
                           setCantEntradas(Entradas);
                    if(ModificarEnDisco(pos)==1){cout<<"ENTRADAS MODIFICADA!"<<endl;}
                        cout<<endl<<endl;
                    }

                }
                pos++;
        }
    }

int ventas::ModificarEnDisco(int pos)
{

    FILE *p;
    p=fopen("ventas.dat","rb+");
    if (p==NULL) return -1;
    fseek(p,sizeof(ventas)*pos,0);
    int escribio=fwrite(this,sizeof(ventas),1,p);
    fclose(p);
    return escribio;
}
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
///BACKUP
int ventas::LeerDeDiscobkp(int pos){
    FILE *A;
        A=fopen("backup/ventas.bkp","rb");
            if(A==NULL){cout<<"ERROR DE LECTURA!";return-1;}
    fseek(A,sizeof(ventas)*pos,0);
    int leyo=fread(this,sizeof(ventas),1,A);
    fclose(A);
    return leyo;


}

bool ventas::backupventa(){

int pos=0;
FILE *b;
    b=fopen("backup/ventas.bkp","wb");
    if(b==NULL){return false;}
    while(leerEnDisco(pos)==1){
        fwrite(this,sizeof(ventas),1,b);
        pos++;
    }
    fclose(b);
    if(pos==0){return false;}
    return true;
}
 bool ventas::recuventa(){
int pos=0;
FILE *br;
    br=fopen("ventas.dat","wb");
    if(br==NULL){return false;}
    while(LeerDeDiscobkp(pos)==1){
        fwrite(this,sizeof(ventas),1,br);
        pos++;
    }
    fclose(br);
    if(pos==0){return false;}
    return true;

 }





#endif // VENTAS_H_INCLUDED

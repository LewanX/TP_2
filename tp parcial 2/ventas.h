#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

class ventas
{
    private:

      int butacastotal=0,Nventa, CantEntradas, Total=0, Pago,idPelicula,sala,turno,dia;
      fechaAct fecha;

       Salas aux;
       pelicula obj;
       bool estado;

    public:
        ///sets()
      void setidPelicula (int id){idPelicula=id;}
      void setNventa (int Nv){Nventa=Nv;}
      void setCantEntradas (int CantE){CantEntradas=CantE;}
      void setTotal (int Tot){Total=Tot;}
      void setPago (int P){Pago=P;}
      void setSala (int S){sala=S;}
      void setFecha(fechaAct F) {fecha=F;}
      void setEstado(bool e){estado=e;}
      void setDia(int D){dia=D;}
      void setTurno(int T){turno=T;}
      ///gets()
      int getidPelicula(){return idPelicula;}
      int getNventa (){return Nventa;}
      int getCantEntradas (){return CantEntradas;}
      int getDia(){return dia;}
      int getTurno(){return turno;}

      int getTotal (){return Total;}
      int getSala (){return sala;}
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






bool cargar(){
    if(validacionDatosVenta()==true){

    estado=true;
    Nventa=autonumericoVentas()+1;
    cout<<"NUMERO DE VENTA : "<<Nventa<<endl;

    cout<<"INGRESE EL DIA : ";
    cin>>dia;

    cout<<"ESTE DIA CUENTA CON LAS SIGUIENTES PELICULAS EN EMISION"<<endl;
    if(mostrarEmisionesPelicula(dia)==0){
     cout<<"ESTE DIA NO CUENTA CON EMISIONES EN ESE DIA: ";
     return false;
    }

    cout<<"INGRESE EL ID DE PELICULA: ";
    cin>>idPelicula;
    while(validarPelicula(dia,idPelicula)==false){
        cout<<"PORFAVOR INGRESE UN ID DE PELICULA VALIDO: ";
        cin>>idPelicula;
        cout<<endl;
    }

    cout<<"INGRESE EL ID DE LA SALA: ";
    cin>>sala;
      while(validarPeliculaSala(dia,idPelicula,sala)==false){
        cout<<"PORFAVOR INGRESE UN ID DE SALA VALIDO: ";
        cin>>sala;
        cout<<endl;
    }



    cout<<"INGRESE EL TURNO [1:MATUTINO 2:TARDE 3:NOCHE] : ";
    cin>>turno;
    while(validarTurno(dia,idPelicula,turno)==false){
        cout<<"INGRESE UN TURNO VALIDO [1:MATUTINO 2:TARDE 3:NOCHE]: "<<endl;
        cin>>turno;
    }

     cout<<"INGRESE CANTIDAD DE ENTRADAS: ";
    cin>>CantEntradas;
    while(validarButacas(dia,idPelicula,turno,CantEntradas)==false){
         cout<<"DATOS INCORRECTOS VUELVA A INTENTAR: ";
    cin>>CantEntradas;
    }
    Total=CantEntradas*obtenerPrecioPelicula(dia,idPelicula,turno);
    sala=salaDeVentas(dia,turno,idPelicula);
return true;
}
cout<<"NO EXISTEN EMISIONES!"<<endl;
return false;
}


void mostrar()
{
    if(estado==true)
    {
    cout<<"NUMERO DE VENTA: "<<Nventa<<endl;
    cout<<"ID DE LA PELICULA: ";
    cout<<idPelicula<<endl;
    cout<<"DIA DE EMISION: ";
    cout<<dia<<endl;
    cout<<"TURNO DE LA EMISION: ";
    cout<<determinarTurno(turno)<<endl;
    cout<<"SALA DE LA EMISION: ";
    cout<<sala<<endl;
    cout<<"CANTIDAD DE ENTRADAS: ";
    cout<<CantEntradas<<endl;
    cout<<"IMPORTE: ";
    cout<<"$ "<<Total<<endl;
    cout <<" "<<endl<<endl;
    }
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
};
void ventas :: EliminarDeDisco(){
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

                           while(actualizarButacasDisponibles(getDia(),getidPelicula(),getTurno(),Entradas,getCantEntradas())==false){
                            cout<<"DATOS INCORRECTOS, VUELVA A INTRODUCIR: ";
                            cin>>Entradas;
                           }
                           setCantEntradas(Entradas);
                           setTotal(Entradas*obtenerPrecioPelicula(getDia(),getidPelicula(),getTurno()));
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
int ventas :: LeerDeDiscobkp(int pos){
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

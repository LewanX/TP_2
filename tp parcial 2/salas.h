#ifndef SALAS_H_INCLUDED
#define SALAS_H_INCLUDED

class Salas{
private:
    int idSala;
    int tipo;
    int c=1;
    int plazas;
    bool estado;

public:
     ///sets()

     void setidSala(int S){idSala=S;}
     void setTipo(int T){tipo=T;}
     void setEstado(bool e){estado=e;}

     ///gets()

     int getidSala(){return idSala;}
     int getTipo(){return tipo;}
     int getPlazas(){return plazas;}
     bool getEstado(){return estado;}


    ///disco
      void EliminarDeDisco();
      int ModificarEnDisco(int pos);
      int grabarEnDisco();
      int leerEnDisco(int);
      void mostrarDeDisco();
      int LeerDeDiscobkp(int);
      bool backupsala();
      bool recusala();

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
    estado=true;
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
    if(estado==true)
       {
           cout<<"ID SALA:"<<idSala<<endl;
           plazas-=calcularVentas(idSala);
           cout<<"CANTIDAD DE BUTACAS:"<<plazas<<endl;
       }

}

};
void Salas::EliminarDeDisco(){
       int pos=0;
       int idS;
        cout<<"INTRODUZCA EL ID DE SALA A ELIMINAR: ";cin>>idS;
        while(leerEnDisco(pos)==1){
                if(getidSala()==idS){
                        cout<<"EL ID DE SALA TIENE LOS SIGUIENTES DATOS"<<endl;
                        mostrar();
                        cout<<endl<<endl;
                        setEstado(false);
                        if(ModificarEnDisco(pos)==1){cout<<"REGISTRO ELIMINADO! ";}
                }
            pos++;
        }

}
int Salas::ModificarEnDisco(int pos)
{

    FILE *s;
    s=fopen("salas.dat","rb+");
    if (s==NULL) return -1;
    fseek(s,sizeof(Salas)*pos,0);
    int escribio=fwrite(this,sizeof(Salas),1,s);
    fclose(s);
    return escribio;
}
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

///BACKUP
int Salas::LeerDeDiscobkp(int pos){
    FILE *A;
        A=fopen("backup/sala.bkp","rb");
            if(A==NULL){cout<<"ERROR DE LECTURA!";return-1;}
    fseek(A,sizeof(Salas)*pos,0);
    int leyo=fread(this,sizeof(Salas),1,A);
    fclose(A);
    return leyo;


}

bool Salas::backupsala(){

int pos=0;
FILE *b;
    b=fopen("backup/sala.bkp","wb");
    if(b==NULL){return false;}
    while(leerEnDisco(pos)==1){
        fwrite(this,sizeof(Salas),1,b);
        pos++;
    }
    fclose(b);
    if(pos==0){return false;}
    return true;
}
 bool Salas::recusala(){
int pos=0;
FILE *br;
    br=fopen("director.dat","wb");
    if(br==NULL){return false;}
    while(LeerDeDiscobkp(pos)==1){
        fwrite(this,sizeof(Salas),1,br);
        pos++;
    }
    fclose(br);
    if(pos==0){return false;}
    return true;

 }






#endif // SALAS_H_INCLUDED

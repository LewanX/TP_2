#ifndef SALAS_H_INCLUDED
#define SALAS_H_INCLUDED

class Salas{
private:
    int idSala;
    int tipo;
    int c=1;
    int plazas;
    int taquillaPelicula[28][3]={0};
    bool estado;

public:
     ///sets()

     void setidSala(int S){idSala=S;}
     void setTipo(int T){tipo=T;}
     void setEstado(bool e){estado=e;}
     void setPlazas(int P){plazas=P;}

     ///gets()

     int getidSala(){return idSala;}
     int getTipo(){return tipo;}
     int getPlazas(){return plazas;}
     bool getEstado(){return estado;}


    ///disco
   void mostrarSalas();
      void EliminarDeDisco();
      int ModificarEnDisco(int pos);
      int grabarEnDisco();
      void ModificarButacas();
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
void  mostrar(int y){
    //gotoxy(10,2);gotoxy(50,2);gotoxy(90,2);
    gotoxy(10,y);
    cout<<idSala;
    gotoxy(95,y);
    cout<<plazas;
cout<<endl;
}

};
void Salas::EliminarDeDisco(){
       int pos=0;
       int idS;
       int y=4;
        cout<<"INTRODUZCA EL ID DE SALA A ELIMINAR: ";cin>>idS;
        while(leerEnDisco(pos)==1){
                if(getidSala()==idS){
                        cout<<"EL ID DE SALA TIENE LOS SIGUIENTES DATOS"<<endl;
                        mostrar(y);
                        cout<<endl<<endl;
                        setEstado(false);
                        if(ModificarEnDisco(pos)==1){cout<<"REGISTRO ELIMINADO! ";}
                }
            pos++;
        }

}

void Salas::ModificarButacas(){
        int pos=0;
        int Id, butaca;
        int y=4;
        cout<<"INTRODUCE EL ID DE SALA A LISTAR: ";cin>>Id;
        while(leerEnDisco(pos)==1){
             if(getidSala()==Id){
                    if(getEstado()==true){
                       estructuraSala("ID SALA","CANTIDAD BUTACAS");
                       mostrar(y);
                cout<<"INTRODUCE UNA NUEVA CANTIDAD DE BUTACAS: ";cin>>butaca;

                    setPlazas(butaca);
                    if(ModificarEnDisco(pos)==1){cout<<"BUTACA MODIFICADA!"<<endl;}
                        cout<<endl<<endl;
                    }

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
    int y=4;
    while(leerEnDisco(pos++)==1){

        //gotoxy(56,y);mostrar(y);
        //cout<<endl;
        mostrar(y);


        y+=4;


    }



}
/*void Salas::mostrarSalas()
{
    int y=0;
    FILE *p;
    p=fopen("salas.dat","rb");
    if (p==NULL) return;
    while(fread(this,sizeof (Salas),1,p)==1)
    {
        mostrar(y);
        y++;
            }
    fclose(p);
}
*/


///BACKUP




int Salas::LeerDeDiscobkp(int pos){
    FILE *A;
        A=fopen("backup/salas.bkp","rb");
            if(A==NULL){cout<<"ERROR DE LECTURA!";return-1;}
    fseek(A,sizeof(Salas)*pos,0);
    int leyo=fread(this,sizeof(Salas),1,A);
    fclose(A);
    return leyo;


}

bool Salas::backupsala(){

int pos=0;
FILE *b;
    b=fopen("backup/salas.bkp","wb");
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
    br=fopen("salas.dat","wb");
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

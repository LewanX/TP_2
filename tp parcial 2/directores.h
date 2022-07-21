#ifndef DIRECTORES_H_INCLUDED
#define DIRECTORES_H_INCLUDED

class director
{
    private:
      int idDirector;
      char nombreDirector[30], Nacionalidad[20];
      Fecha FechaNacimiento;
       bool estado;
    public:
        ///sets()
      void setidDirector (int idD){idDirector=idD;}
      void setnombreDirector (const char *Nd){strcpy(nombreDirector,Nd);}
      void setNacionalidad (const char *N){strcpy(Nacionalidad,N);}
      void setFechaNacimiento(Fecha F) {FechaNacimiento=F;}
      void setEstado(bool e){estado=e;}
      ///gets()
      int getidDirector (){return idDirector;}
      const char *getnombreDirector (){return nombreDirector;}
      const char *getNacionalidad (){return Nacionalidad;}
      Fecha getFechaNacimiento () {return FechaNacimiento;}
      bool getEstado(){return estado;}
      ///disco
      void EliminarDeDisco();
      int ModificarEnDisco(int pos);
      void mostrarDeDisco();
      int grabarEnDisco();
      int leerEnDisco(int);


void cargar()
{
    estado=true;
    fflush(stdin);
    cout<<"INGRESAR EL ID DE DIRECTOR"<<endl;
    cin >>idDirector;
    while(validacionDir(idDirector)==1){
        cout <<" TIENE ESE ID "<< endl;
        system("pause");
        system("cls");
        cout<<"INGRESE EL ID DEL DIRECTOR : " <<endl;
        cin>>idDirector;
    }
    cin.ignore();
    cout<<"INGRESAR EL NOMBRE DEL DIRECTOR " <<endl;
    cin.getline(nombreDirector,30,'\n');
    fflush(stdin);
    cout<<"INGRESE LA NACIONALIDAD DEL DIRECTOR"<<endl;

    cin.getline(Nacionalidad,20,'\n');
    fflush(stdin);
    cout<<"FECHA DE NACIMIENTO DEL DIRECTOR"<<endl;
    FechaNacimiento.Cargar();
}
void mostrar()
{
    if(estado==true)
    {
    cout<<"ID: ";
    cout<<idDirector<<endl;
    cout<<"NOMBRE DEL DIRECTOR: ";
    cout<<nombreDirector<<endl;
    cout<<"NACIONALIDAD: ";
    cout<<Nacionalidad<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    FechaNacimiento.Mostrar();
    }
    cout<< endl;

}

void mostrardirectores()
{
    FILE *p;
    p=fopen("director.dat","rb");
    if (p==NULL) return;
    while(fread(this,sizeof (director),1,p)==1)
    {
        mostrar();
    }
    fclose(p);
}

};



///DISCO
void director::EliminarDeDisco(){
       int pos=0;
       int idD;
        cout<<"INTRODUZCA EL ID DE DIRECTOR A ELIMINAR: ";cin>>idD;
        while(leerEnDisco(pos)==1){
                if(getidDirector()==idD){
                        cout<<"EL ID DE DIRECTOR TIENE LOS SIGUIENTES DATOS"<<endl;
                        mostrar();
                        cout<<endl<<endl;
                        setEstado(false);
                        if(ModificarEnDisco(pos)==1){cout<<"REGISTRO ELIMINADO! ";}
                }
            pos++;
        }

}
int director::ModificarEnDisco(int pos)
{

    FILE *p;
    p=fopen("director.dat","rb+");
    if (p==NULL) return -1;
    fseek(p,sizeof(director)*pos,0);
    int escribio=fwrite(this,sizeof(director),1,p);
    fclose(p);
    return escribio;
}
int director::grabarEnDisco()
{
    FILE *p;
    p=fopen("director.dat","ab");
    if (p==NULL) return -1;
    int escribio=fwrite(this,sizeof(director),1,p);
    fclose(p);
    return escribio;
}

int director::leerEnDisco(int pos)
{
    FILE *p;
    p=fopen("director.dat","rb");
    if (p==NULL) return -1;
    fseek(p,sizeof(director)*pos,0);
    int leyo=fread(this,sizeof(director),1,p);
    fclose(p);
    return leyo;
}

#endif // DIRECTORES_H_INCLUDED

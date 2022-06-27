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
      void mostrarDeDisco();
      int grabarEnDisco();
      int leerEnDisco(int);


void cargar()
{
    fflush(stdin);
    cout<<"Ingrese el nombre del director " <<endl;
    cin.getline(nombreDirector,30,'\n');
    fflush(stdin);
    cout<<"ingrese el Id del director"<<endl;
    cin >>idDirector;
    cout<<"Ingrese la nacionalidad del director"<<endl;
    cin.ignore();
    cin.getline(Nacionalidad,20,'\n');
    fflush(stdin);
    cout<<"Fecha de nacimiento del director"<<endl;
    FechaNacimiento.Cargar();
}
void mostrar()
{
    cout<<"id: ";
    cout<<idDirector<<endl;
    cout<<"Nombre del director: ";
    cout<<nombreDirector<<endl;
    cout<<"Nacionalidad: ";
    cout<<Nacionalidad<<endl;
    cout<<"fecha de nacimiento: ";
    FechaNacimiento.Mostrar();
}

};



///DISCO
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
void director::mostrarDeDisco(){
    int pos=0;
    while(leerEnDisco(pos++)==1){
            mostrar();
            cout<<endl;
    }
}
#endif // DIRECTORES_H_INCLUDED

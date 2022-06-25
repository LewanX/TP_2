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

      int grabarEnDisco();
      int leerEnDisco(int);


void cargar()
{

    cout<<"Ingrese el nombre del director " <<endl;
    cargarCadena(nombreDirector,29);
    fflush(stdin);
    ///cout<<"ingrese el Id del director"<<endl;
    ///cin >>idDirector;
    cout<<"Ingrese la nacionalidad del director"<<endl;
    cargarCadena(Nacionalidad,19);
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
#endif // DIRECTORES_H_INCLUDED

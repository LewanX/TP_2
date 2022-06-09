#ifndef DIRECTORES_H_INCLUDED
#define DIRECTORES_H_INCLUDED

class director
{
    private:
      int idDirector;
      char nombreDirector[30], Nacionalidad[20];
      Fecha FechaNacimineto;
       bool estado;
    public:
        ///sets()
      void setidDirector (int idD){idDirector=idD;}
      void setnombreDirector (const char *Nd){strcpy(nombreDirector,Nd);}
      void setNacionalidad (const char *N){strcpy(Nacionalidad,N);}
      void setEstado(bool e){estado=e;}
      ///gets()
      int getidDirector (){return idDirector;}
      const char *getnombreDirector (){return nombreDirector;}
      const char *getNacionalidad (){return Nacionalidad;}
      bool getEstado(){return estado;}
      ///disco
      void cargar();
      void mostrar();
      int grabarEnDisco();
      int leerEnDisco(int);
};

void director::cargar()
{

    cout<<"Ingrese el nombre del director " << endl;
    cin>>cargarCadena(nombrePelicula,29);
    cout<<"ingrese el Id del director"<<endl;
    cin >>idDirector;
    cout<<"Ingrese la nacionalidad del director"<<endl;
    cin>>cargarCadena(Nacionalidad,19);
    cout<<<"Fecha de nacimiento del director"<<endl;
    cin>> FechaNacimineto;

}
#endif // DIRECTORES_H_INCLUDED

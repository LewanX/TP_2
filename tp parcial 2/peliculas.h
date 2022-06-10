#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

class pelicula
{
    private:
      int idPelicula, idDirector, duracion, sala, calificacion;
      char nombrePelicula[30], genero[20];
      Fecha FechaPelicula;
      bool estado;
    public:
        ///sets()
      void setidPelicula (int idP){idPelicula=idP;}
      void setidDirector(int idDir){idDirector=idDir;}
      void setduracion (int d){duracion=d;}
      void setSala (int s){sala=s;}
      void setCalificacion(int c){calificacion=c;}
      void setNombrePelicula (const char *Np){strcpy(nombrePelicula,Np);}
      void setGenero (const char *g){strcpy(genero,g);}
      void setFechaPelicula (Fecha F){FechaPelicula=F;}
      void setEstado(bool e){estado=e;}
      ///gets()
      int getidPelicula (){return idPelicula;}
      int getidDirector (){return idDirector;}
      int getDuracion (){return duracion;}
      int getSala (){return sala;}
      int getCalificacion (){return calificacion;}
      const char *getNombrePelicula (){return nombrePelicula;}
      const char *getGenero (){return genero;}
      Fecha getFechaPelicula () {return FechaPelicula;}
      bool getEstado(){return estado;}
      ///disco
      void cargar();
      void mostrar();
      int grabarEnDisco();
      int leerEnDisco(int);
};

void pelicula::cargar()
{


    cout<<"Ingrese el nombre de la pelicula " << endl;
    cin.getline(nombrePelicula,30);
    cout <<"Genero"<<genero<<endl;
    cout<<"Ingresar el formato de la pelicula (2D,3D,4D)"<<endl;
    cin>>formato;
    cout<<"Ingresar el idioma (Castellano o subtitulado)"<<endl;
    cin>>idioma;
    cout<<"Director de la pelicula"<<idDirector<<endl;
    cout<<"Ingresar el horario al cual desea ver la pelicula"<<endl;
    cin>>horarioIni;
    cout<<"Horario final de la pelicula"<<horarioFin<<endl;
    cout<<"Ingresar los asientos que desea"<<endl;
    cin>>asientos;
    cout<<"Ingresar el metodo de pago"<<endl;
    cin>>metodoPago;
    cout<<"Precio" << precio<<endl;

}

#endif // PELICULAS_H_INCLUDED

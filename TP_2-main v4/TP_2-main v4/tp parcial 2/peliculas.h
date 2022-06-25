#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

class pelicula
{
    private:
      int idPelicula,idDirector, duracion, precio, sala;
      char nombrePelicula[30], genero[20], formato[3], idioma[5];
      Fecha fechaIni;
      Fecha fechaFin;
      director direc;
      Salas salaNum;
       bool estado;
    public:
        ///sets()
      void setidPelicula (int idP){idPelicula=idP;}
      void setidDirector (int idD) {idDirector=idD;}
      void setFormato (const char *f) {strcpy(formato,f);}
      void setIdioma (const char *i) {strcpy(idioma,i);}
      void setDuracion (int d) {duracion=d;}
      void setPrecio (int p) {precio=p;}
      void setSala (int s) {sala=s;}
      void setNombrePelicula (const char *Np){strcpy(nombrePelicula,Np);}
      void setGenero (const char *g){strcpy(genero,g);}
      void setEstado(bool e){estado=e;}
      ///gets()
      int getidPelicula (){return idPelicula;}
      int getidDirector () {return idDirector;}
      const char *getFormato () {return formato;}
      const char *getIdioma () {return idioma;}
      int getDuracion () {return duracion;}
      int getPrecio () {return precio;}
      int getSala () {return sala;}
      const char *getNombrePelicula (){return nombrePelicula;}
      const char *getGenero (){return genero;}
      bool getEstado(){return estado;}
      ///disco
      int grabarEnDisco();
      int leerEnDisco(int);

      bool cargarPeliculas()
      {
          FILE *p;
          bool escribio;
          pelicula reg;
          p=fopen("pelicula.dat","ab");
          if (p==NULL) return false;
              cargar();
              escribio=fwrite(this,sizeof reg, 1,p);
              fclose(p);
              return escribio;

      }

void mostrarPeliculas()
{
    FILE *p;
    p=fopen("pelicula.dat","rb");
    if (p==NULL) return;
    while(fread(this,sizeof (pelicula),1,p)==1)
    {
        mostrar();
    }
    fclose(p);
}

void cargar()
{
    estado=true;

    cout<<"Ingrese el nombre de la pelicula " << endl;
    cin.getline(nombrePelicula,30);
    fflush(stdin);
    cout<<"Ingrese el ID de la pelicula "<<endl;
    cin>> idPelicula;
    cout <<"Ingresar el Genero de la pelicula"<<endl;
    cin.getline(genero,20);
    fflush(stdin);
    cout<<"Ingresar el formato de la pelicula (2D,3D,4D)"<<endl;
    cin.getline(formato,3);
    fflush(stdin);
    cout<<"Ingresar el idioma (cast=Castellano o sub=subtitulado)"<<endl;
    cin.getline(idioma,5);
    fflush(stdin);
    cout<<"Ingresar la duracion de la pelicula"<<endl;
    cin>>duracion; ///en minutos
    cout<<"Ingresar id del director"<<endl;
    cin>>idDirector; /// si el id de director ya existe, no cargar nada mas, en cambio si no existe, cargar los datos del directos
    direc.cargar();
    cout<<endl;
    cout<<"Ingresar la fecha incial de proyeccion de la pelicula"<<endl;
    fechaIni.Cargar();
    cout<<"Ingresar la fecha final de proyeccion de la pelicula"<<endl;
    fechaFin.Cargar();
    cout<<"Ingresar el ID de la sala en donde ver la pelicula"<<endl;
    cin>>sala;
    salaNum.cargar();
    if(salaNum.getTipo()==1)
    {
        precio=500;
    }
    else
    {
        if(salaNum.getTipo()==2)
        {
            precio=600;
        }
    }
    cout<<"Precio de la entrada: "<<precio<<endl;

}
void mostrar()
{
        cout<<"Nombre de pelicula: ";
        cout<<nombrePelicula<<endl;
        cout<<"GENERO: ";
        cout<<genero<<endl;
        cout<<"Formato: ";
        cout<<formato<<endl;
        cout<<"Idioma: ";
        cout<<idioma<<endl;
        cout<<"Duracion: ";
        cout<<duracion<<" Minutos"<<endl;
        direc.mostrar();
        cout<<"Fecha inicial de la proyeccion: ";
        fechaIni.Mostrar();
        cout<<"Fecha final de la proyeccion: ";
        fechaFin.Mostrar();
        cout<<"Numero de sala asignada: ";
        salaNum.mostrarSalas();
        cout<<endl;
        cout<<"Precio de la entrada: ";
        cout<<precio<<endl;


}
};
int pelicula::grabarEnDisco()
{
    FILE *p;
    p=fopen("pelicula.dat","ab");
    if (p==NULL) return -1;
    int escribio=fwrite(this,sizeof(pelicula),1,p);
    fclose(p);
    return escribio;
}

int pelicula::leerEnDisco(int pos)
{
    FILE *p;
    p=fopen("pelicula.dat","rb");
    if (p==NULL) return -1;
    fseek(p,sizeof(pelicula)*pos,0);
    int leyo=fread(this,sizeof(pelicula),1,p);
    fclose(p);
    return leyo;
}

#endif // PELICULAS_H_INCLUDED

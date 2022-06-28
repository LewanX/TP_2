#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

class pelicula
{
    private:
      int idPelicula,idDirector, duracion, precio, sala, idioma;
      char nombrePelicula[30], genero[20], formato[3];
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
      void setIdioma (int I) {idioma=I;}
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
      int getIdioma() {return idioma;}
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

    //cin.getline(nombreDirector,30,'\n');
    fflush(stdin);

    cout<<"INGRESE EL NOMBRE DE LA PELICULA: " << endl;
    cin.getline(nombrePelicula,30,'\n');
    fflush(stdin);

    cout<<"INGRESE ID: "<<endl;
    cin>> idPelicula;

    cout <<"INGRESE EL GENERO: "<<endl;
    cin.ignore();
    cin.getline(genero,20,'\n');
    fflush(stdin);

    cout<<"INGRESE EL FOTMATO (2D,3D,4D): "<<endl;
    cin.getline(formato,3,'\n');
    fflush(stdin);

    cout<<"INGRESE EL IDIOMA [ (1=Castellano) , (2=subtitulado) ] :"<<endl;
    cin>>idioma;
    fflush(stdin);

    cout<<"INGRESE LA DURACION [minutos]: "<<endl;
    cin>>duracion; ///en minutos

    cout<<"INGRESE EL ID DEL DIRECTOR: "<<endl;
    cin>>idDirector; /// si el id de director ya existe, no cargar nada mas, en cambio si no existe, cargar los datos del directos
    if(validacionDir(idDirector)==0){
        cout<<"ESTE DIRECTOR NO SE ENCUENTRA EN LOS REGISTROS"<<endl;
    }
    cout<<endl;

    cout<<"INGRESAR LA EMISION INICIAL DE LA PELICULA:"<<endl;
    fechaIni.Cargar();
    cout<<"INGRESAR LA EMISION FINAL DE LA PELICULA:"<<endl;
    fechaFin.Cargar();

    cout<<"INGRESE EL ID DE LA SALA DONDE VER LA PELICULA"<<endl;
    cin>>sala;
    precio=validacionSala(sala);
    cout<<"PRECIO DE LA ENTRADA: "<<precio<<endl;

}
void mostrar()
{
        cout<<"NOMBRE DE LA PELICULA: ";
        cout<<nombrePelicula<<endl;
        cout<<"GENERO: ";
        cout<<genero<<endl;
        cout<<"FORMATO: ";
        cout<<formato<<endl;
        cout<<"IDIOMA: ";
        cout<<idioma<<endl;
        cout<<"DURACION: ";
        cout<<duracion<<" MINUTOS"<<endl;
        validacionDir(idDirector);
        //NomDir(idDirector);
        cout<<endl;
        //direc.mostrar();
        cout<<"FECHA INICIAL DE LA PROYECCION: ";
        fechaIni.Mostrar();
        cout<<"FECHA FINAL DE LA PROYECCION: ";
        fechaFin.Mostrar();
        cout<<"NUMERO DE SALAS ASIGNADAS:"<<sala;
        cout<<"PRECIO DE LA ENTRADA: ";
        cout<<precio<<endl;
        cout<<""<<endl<<endl;


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

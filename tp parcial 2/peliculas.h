#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

class pelicula
{
    private:
      int idPelicula,idDirector, duracion, precio, sala, idioma;
      char nombrePelicula[30], genero[20], formato[3];
      Fecha fechaIni;
      fechaFin fin;
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
      void setFechaIni (Fecha I) {fechaIni=I;}
      void setFechaFin(fechaFin FI) {fin=FI;}
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
      Fecha getFechaIni () {return fechaIni;}
      fechaFin getFechaFin () {return fin;}
      bool getEstado(){return estado;}
      ///disco
      int ModificarEnDisco(int pos);
      void EliminarDeDisco();
      int grabarEnDisco();
      int leerEnDisco(int);
      void ModificarNombrePelicula();
      void ModificarGenero();
      void ModificarIdioma();
      int LeerDeDiscobkp(int pos);
      bool backuppelicula();
      bool recupelicula();
      bool recuperarPeliculaPorID();

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
bool cargar()
{
    if(validacionDatosPelicula()==true){
    precio=500;
    estado=true;

    cout<<"INGRESE ID: "<<endl;
    cin>> idPelicula;
    while(validacionIDpelicula(idPelicula)==1){
        cout <<"\n EL ID INGRESADO YA EXISTE! "<< endl;
        system("pause");
        system("cls");
        cout<<"INGRESE EL ID DE LA PELICULA : " <<endl;
        cin>>idPelicula;
    }

    cout<<"INGRESE EL NOMBRE DE LA PELICULA: " << endl;
    cargarCadena(nombrePelicula,29);

    cout <<"INGRESE EL GENERO: "<<endl;
    cargarCadena(genero,19);


    cout<<"INGRESE EL FORMATO (2D o 3D): "<<endl;
    cargarCadena(formato,3);


    while (formatoValido(formato)!=true){
        cout <<"INGRESE UN FORMATO VALIDO (2D o 3D)"<<endl;
        cargarCadena(formato,3);
    }


    cout<<"INGRESE EL IDIOMA [ (1=CASTELLANO) , (2=SUBTITULADO) ] :"<<endl;
    cin>>idioma;


    while(idioma<1 || idioma>2){
        cout<<"INGRESE UN IDIOMA VALIDO :"<<endl;
        cin>>idioma;
    }

    cout<<"INGRESE LA DURACION [minutos]: "<<endl;
    cin>>duracion; ///en minutos

    cout<<"INGRESE EL ID DEL DIRECTOR: "<<endl;
    cin>>idDirector; /// si el id de director ya existe, no cargar nada mas, en cambio si no existe, cargar los datos del director
    while(validacionDir(idDirector)==0){
        cout<<"ESTE DIRECTOR NO SE ENCUENTRA EN LOS REGISTROS"<<endl;
        system("pause");
        system("cls");
        cout<<"INGRESE EL ID DEL DIRECTOR: "<<endl;
        cin>>idDirector;
    }
    cout<<endl;

    /*cout<<"INGRESAR LA EMISION INICIAL DE LA PELICULA:"<<endl;
    fechaIni.Cargar();
    cout<<"INGRESAR LA EMISION FINAL DE LA PELICULA:"<<endl;
    fin.Cargar();*/
    cout<<"INGRESE EL ID DE LA SALA DONDE VER LA PELICULA"<<endl;
    cin>>sala;
    while(validacionSala(sala)==0){
        cout<<"ESTA ID DE SALA NO EXISTE"<<endl;
        cout<<"INGRESE EL ID DE LA SALA DONDE VER LA PELICULA"<<endl;
        cin>>sala;
    }
    if(strcmp(formato,"3D")==0 || strcmp(formato,"3d")==0){
        precio+=100;
    }
    cout<<"PRECIO DE LA ENTRADA: "<<precio<<endl;
    return true;;
    }
    else{
        cout<<"PRIMERO SE DEBER CARGAR DIRECTORES O SALAS!!!"<<endl;
        return false;
    }
}
void mostrar()
{
    if(estado==true)
    {
       cout<<"ID DE LA PELICULA: "<<idPelicula<<endl;
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
        cout<<endl;
        //cout<<"FECHA INICIAL DE LA PROYECCION: ";
        //fechaIni.Mostrar();
        //cout<<"FECHA FINAL DE LA PROYECCION: ";
        //fin.Mostrar();
        cout<<"NUMERO DE SALAS ASIGNADAS:"<<sala<<endl;
        cout<<"PRECIO DE LA ENTRADA: ";
        cout<<precio<<endl;
        cout<<""<<endl<<endl;

    }


}
};
void pelicula::EliminarDeDisco(){
       int pos=0;
       int id;
        cout<<"INTRODUZCA EL ID DE PELICULA A ELIMINAR: ";cin>>id;
        while(leerEnDisco(pos)==1){
                if(getidPelicula()==id){
                        cout<<"EL ID DE PELICULA TIENE LOS SIGUIENTES DATOS"<<endl;
                        mostrar();
                        cout<<endl<<endl;
                        setEstado(false);
                        if(ModificarEnDisco(pos)==1){cout<<"REGISTRO ELIMINADO! ";}
                }
            pos++;
        }

}

int pelicula::ModificarEnDisco(int pos)
{
    FILE *p;
    p=fopen("pelicula.dat","rb+");
    if (p==NULL) return -1;
    fseek(p,sizeof(pelicula)*pos,0);
    int escribio=fwrite(this,sizeof(pelicula),1,p);
    fclose(p);
    return escribio;
}
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

void pelicula::ModificarNombrePelicula(){
        int pos=0;
        char peli[30];
        int Id;
        cout<<"INTRODUCE EL ID DE LA PELICULA A LISTAR: ";cin>>Id;
        while(leerEnDisco(pos)==1){
             if(getidPelicula()==Id){
                    if(getEstado()==true){
                       cout<<"NOMBRE DE LA PELICULA : "<<getNombrePelicula()<<endl;
                        cout<<"GENERO: "<<getGenero()<<endl;
                        cout<<"FORMATO: "<<getFormato()<<endl;
                        cout<<"IDIOMA: "<<getIdioma()<<endl;
                        cout<<"DURACION : "<<getDuracion()<<endl;
                cout<<"INTRODUCE UN NUEVO NOMBRE DE LA PELICULA: ";
                    cargarCadena(peli,29);
                        setNombrePelicula(peli);
                    if(ModificarEnDisco(pos)==1){cout<<"NOMBRE MODIFICADO!"<<endl;}
                        cout<<endl<<endl;
                    }

                }
                pos++;
        }


    }

void pelicula::ModificarGenero(){
        int pos=0;
        char gene[30];
        int Id;
        cout<<"INTRODUCE EL ID DE DIRECTOR A LISTAR: ";cin>>Id;
        while(leerEnDisco(pos)==1){
             if(getidPelicula()==Id){
                    if(getEstado()==true){
                       cout<<"NOMBRE DE LA PELICULA : "<<getNombrePelicula()<<endl;
                        cout<<"GENERO: "<<getGenero()<<endl;
                        cout<<"FORMATO: "<<getFormato()<<endl;
                        cout<<"IDIOMA: "<<getIdioma()<<endl;
                        cout<<"DURACION : "<<getDuracion()<<endl;
                cout<<"INTRODUCE UN NUEVO GENERO DE LA PELICULA: ";cin>>gene;
                           setGenero(gene);
                    if(ModificarEnDisco(pos)==1){cout<<"GENERO MODIFICADO!"<<endl;}
                        cout<<endl<<endl;
                    }

                }
                pos++;
        }


    }

void pelicula::ModificarIdioma(){
        int pos=0;
        int idi;
        int Id;
        cout<<"INTRODUCE EL ID DE DIRECTOR A LISTAR: ";cin>>Id;
        while(leerEnDisco(pos)==1){
             if(getidPelicula()==Id){
                    if(getEstado()==true){
                       cout<<"NOMBRE DE LA PELICULA : "<<getNombrePelicula()<<endl;
                        cout<<"GENERO: "<<getGenero()<<endl;
                        cout<<"FORMATO: "<<getFormato()<<endl;
                        cout<<"IDIOMA: "<<getIdioma()<<endl;
                        cout<<"DURACION : "<<getDuracion()<<endl;
                cout<<"INTRODUCE UN NUEVO IDIOMA DE LA PELICULA [ (1=CASTELLANO) , (2=SUBTITULADO) ] : ";cin>>idi;
                           setIdioma(idi);
                    if(ModificarEnDisco(pos)==1){cout<<"IDIOMA MODIFICADO!"<<endl;}
                        cout<<endl<<endl;
                    }

                }
                pos++;
        }


    }







///BACKUP
int pelicula::LeerDeDiscobkp(int pos){
    FILE *A;
        A=fopen("backup/pelicula.bkp","rb");
            if(A==NULL){cout<<"ERROR DE LECTURA!";return-1;}
    fseek(A,sizeof(pelicula)*pos,0);
    int leyo=fread(this,sizeof(pelicula),1,A);
    fclose(A);
    return leyo;


}

bool pelicula::backuppelicula(){

int pos=0;
FILE *b;
    b=fopen("backup/pelicula.bkp","wb");
    if(b==NULL){return false;}
    while(leerEnDisco(pos)==1){
        fwrite(this,sizeof(pelicula),1,b);
        pos++;
    }
    fclose(b);
    if(pos==0){return false;}
    return true;
}
 bool pelicula::recupelicula(){
int pos=0;
FILE *br;
    br=fopen("pelicula.dat","wb");
    if(br==NULL){return false;}
    while(LeerDeDiscobkp(pos)==1){
        fwrite(this,sizeof(pelicula),1,br);
        pos++;
    }
    fclose(br);
    if(pos==0){return false;}
    return true;
 }

bool pelicula::recuperarPeliculaPorID(){
    int pos=0;
        char id;
        int Id;
        cout<<"INTRODUCE EL ID DE PELICULA A RECUPERAR: ";cin>>Id;
        while(leerEnDisco(pos)==1){
             if(getidPelicula()==Id){
                    if(getEstado()==false){
                        setEstado(true);
                    if(ModificarEnDisco(pos)==1){cout<<"PELICULA RECUPERADA!"<<endl;}
                        cout<<endl;
                    }
                    else{
                        cout<<"ESTA PELICULA YA SE ENCUENTRA DISPONIBLE" <<endl;
                    }
                }
                pos++;
        }
}


#endif // PELICULAS_H_INCLUDED

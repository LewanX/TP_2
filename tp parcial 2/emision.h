#ifndef EMISION_H_INCLUDED
#define EMISION_H_INCLUDED
class emision
{
private:
    int dia;
    int salaID;
    int turno;
    int Idpelicula;
    int butacasDisponibles;
    bool hayFuncion;


public:
    int getDia(){return dia;}
    int getSalaId(){return salaID;}
    int getTurno(){return turno;}
    int getIdPelicula(){return Idpelicula;}

  void cargar();
  void mostrar();
  void mostrarDatos(int);
  int grabarEnDisco();
  int leerEnDisco(int);
  void mostrarDeDisco();

  void mostrarDatos(){
  cout<<"ID SALA: "<<salaID<<endl;
  cout<<"ID PELICULA: "<<Idpelicula<<endl;
  cout<<"TURNO: "<<determinarTurno(turno)<<endl;


  }
};


 void emision::cargar(){



        cout<<"INGRESE EL ID DE PELICULA A AGREGAR EMISION: ";
            cin>>Idpelicula;

        if(validacionIDpelicula(Idpelicula)==0){
            cout<<"ESTA PELICULA NO EXISTE: "<<endl;
            return;
        }

        cout<<"SELECCIONE UN DIA VALIDO DEL MES DE FEBRERO [1...28]: ";
            cin>>dia;

        cout<<"SELECCIONE UN TURNO [1:MATUTINO 2:TARDE 3:NOCHE]: ";
            cin>>turno;

        cout<<"SELECCIONE EN QUE SALA QUIERE QUE SE EMITA LA PELICULA: ";
            cin>>salaID;
        system("pause");

    }

    void emision::mostrar(){
        int dia;
        int pos=0;
    cout<<"INGRESE UN DIA PARA VER PELICULAS DISPONIBLES: ";
        cin>>dia;
    while(leerEnDisco(pos++)==1){
        if(getDia()==dia){
            mostrarDatos();
        }
        //gotoxy(56,y);mostrar(y);
        //cout<<endl;

    }
    }
///DISCO
    int emision::leerEnDisco(int pos)
{
    FILE *p;
    p=fopen("emision.dat","rb");
    if (p==NULL) return -1;
    fseek(p,sizeof(emision)*pos,0);
    int leyo=fread(this,sizeof(emision),1,p);
    fclose(p);
    return leyo;
}
int emision::grabarEnDisco()
{
    FILE *p;
    p=fopen("emision.dat","ab");
    if (p==NULL) return -1;
    int escribio=fwrite(this,sizeof(emision),1,p);
    fclose(p);
    return escribio;
}


#endif // EMISION_H_INCLUDED
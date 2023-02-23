#ifndef EMISION_H_INCLUDED
#define EMISION_H_INCLUDED
class emision
{
private:
    int IDemision;
    int dia;
    int salaID;
    int turno;
    int Idpelicula,precio;
    char formato[3];
    int butacasDisponibles=0,butacasDescontadas=0,butacasTotales=0;
    bool hayFuncion, estado;

public:

    ///GETS
    int getIDemision(){return IDemision;}
    int getDia(){return dia;}
    int getPrecio(){return precio;}
    int getSalaId(){return salaID;}
    int getTurno(){return turno;}
    int getIdPelicula(){return Idpelicula;}
    const char *getFormato() {return formato;}
    int getbutacasDisponibles(){return butacasDisponibles;}
    bool getEstado () {return estado;}
    ///SETS

    void setIDEmision (int IDE){IDemision=IDE;}
    void setDia(int D){dia=D;}
    void setPrecio(int P){precio=P;}
    void setSalaID (int SaID){salaID=SaID;}
    void setTurno (int T){turno=T;}
    void setIDPelicula (int IDP){Idpelicula=IDP;}
    void setFormato (const char *F){strcpy(formato,F);}
    void setbutacasDisponibles(int butacasD){butacasDisponibles=butacasD;}
    void setEstado (bool E){estado=E;}
    ///FUNCIONES
    void EliminarDeDisco();
    bool cargar();
  void mostrar();
  void mostrarDatos(int);
  int grabarEnDisco();
  int leerEnDisco(int);
  void mostrarDeDisco();
  bool ModificarPrecio();
  int ModificarEnDisco(int);
  int LeerDeDiscobkp(int pos);
  bool backupemision();
  bool recuemisiones();
  bool ModificarDia();
  bool ModificarTurno();
  void mostrarDatos(){
    cout<<dia<<" FEBRERO"<<endl;
    cout<<"ID DE EMISION: "<<IDemision<<endl;
    cout<<"ID SALA: "<<salaID<<endl;
    cout<<"ID PELICULA: "<<Idpelicula<<endl;
    cout<<"TURNO: "<<determinarTurno(turno)<<endl;
    cout<<"BUTACAS DISPONIBLES: "<<butacasDisponibles<<endl;
    cout<<"FORMATO DE LA PELICULA :"<<formato<<endl;
    cout<<"PRECIO DE LA ENTRADA :"<<precio<<endl;
    cout<<""<<endl;
  }
};


 bool emision::cargar(){
        estado=true;
        IDemision=autonumericoEmision();
        cout<<"ID DE LA EMISION: "<<IDemision<<endl;
        cout<<"SELECCIONE EN QUE SALA QUIERE QUE SE EMITA LA PELICULA: ";
            cin>>salaID;
            while(validacionIDsala(salaID)==0){
                cout<<"ESTA SALA NO EXISISTE !!!"<<endl;
                cout<<"SELECCIONE EN QUE SALA QUIERE QUE SE EMITA LA PELICULA: ";
                cin>>salaID;
            }

            cout<<"SELECCIONE UN DIA VALIDO DEL MES DE FEBRERO [1...28]: ";
            cin>>dia;
            while(dia<=0 && dia>28){
                cout<<"INGRESE UN DIA VALIDO (1-28) " <<endl;
                cin>>dia;
            }
            if(emisionSala(salaID,dia)==true){
                cout<<"ESTA SALA CUENTA CON TODOS LOS TURNOS OCUPADOS PARA EL DIA "<<dia<<", POR FAVOR ELIJA OTRA"<<endl;
                return false;
            }
            cout<<"SELECCIONE UN TURNO [1:MATUTINO 2:TARDE 3:NOCHE]: ";
            cin>>turno;
            while((turno != 1) && (turno != 2) && (turno != 3)){
                cout<<"SELECCIONE UN TURNO VALIDO [1:MATUTINO 2:TARDE 3:NOCHE]: ";
                cin>>turno;
            }
           while(tieneTurno(salaID,dia,turno)==true){
                    cout<<"ESTA SALA YA CUENTA CON EL TURNO "<<determinarTurno(turno)<<" OCUPADO"<<endl;
                    cout<<"SELECCIONE OTRO TURNO"<<endl;
                    cin>>turno;
            }

            cout<<"INGRESE EL ID DE PELICULA A AGREGAR EMISION: ";
            cin>>Idpelicula;

            while(validacionIDpelicula(Idpelicula)==0){
            cout<<"ESTA PELICULA NO EXISTE: "<<endl;
            system("cls");
            cout<<"INGRESE EL ID DE PELICULA A AGREGAR EMISION: ";
            cin>>Idpelicula;
            }
            butacasDisponibles=buscarButacas(salaID);
            cout<<"INGRESE EL FORMATO (2D o 3D): "<<endl;
            cargarCadena(formato,2);
            while (formatoValido(formato)!=true){
            cout <<"INGRESE UN FORMATO VALIDO (2D o 3D)"<<endl;
            cargarCadena(formato,2);
            }
            cout<<"INGRESE UN PRECIO (NUMERICO) : ";
            cin>>precio;
            while(precio <1 ){
                 cout<<"INGRESE UN PRECIO VALIDO: ";
            cin>>precio;
            }
    system("pause");
            return true;

    }

    void emision::mostrar(){
        int dia;
        int pos=0;
    cout<<"INGRESE UN DIA PARA VER PELICULAS DISPONIBLES [1-28]: ";
        cin>>dia;
    while(leerEnDisco(pos++)==1){
        if(getDia()==dia && getEstado()==true){
            mostrarDatos();
        }

    }
    }
/// MODS
bool emision::ModificarPrecio(){
        int pos=0;
        int idEmi;
        cout <<"INTRODUZCA UN ID DE EMISION A MODIFICAR"<<endl;
        cin>> idEmi;
        while(leerEnDisco(pos++)==1){
             if(getIDemision()==idEmi){
                    if(getEstado()==true){
                        cout<<"ESTE ID DE EMISION CONTIENE LOS SIGUIENTES DATOS"<<endl;
                        mostrarDatos();
                        cout<<""<<endl;


                        cout<<"INGRESE UN NUEVO VALOR PARA EL PRECIO: "<<endl;
                        cin>>precio;
                        while(precio<=0){
                            cout<<"INGRESE UN NUEVO VALOR MAYOR A CERO: "<<endl;
                        cin>>precio;
                        }


                                setPrecio(precio);
                                if(ModificarEnDisco(pos-1)==1){cout<<"PRECIO MODIFICADO!"<<endl;
                                return true;


                                }

                        }
                        else{
                            cout <<"EL TURNO YA ESTA OCUPADO "<<endl;
                        }

                    }

                }
            return false;
        }




bool emision::ModificarTurno(){
        int pos=0;
        int turno,idEmi;
        cout <<"INTRODUZCA UN ID DE EMISION A MODIFICAR"<<endl;
        cin>> idEmi;
        while(leerEnDisco(pos++)==1){
             if(getIDemision()==idEmi){
                    if(getEstado()==true){
                        cout<<"ESTE ID DE EMISION CONTIENE LOS SIGUIENTES DATOS"<<endl;
                        mostrarDatos();
                        cout<<""<<endl;


                        cout<<"INGRESE UN NUEVO VALOR PARA EL TURNO: "<<endl;
                        cin>>turno;

                        if(verificarTurnoSala(getSalaId(),getDia(),turno)==true){


                                setTurno(turno);
                                if(ModificarEnDisco(pos-1)==1){cout<<"TURNO MODIFICADO!"<<endl;
                                return true;


                                }

                        }
                        else{
                            cout <<"EL TURNO YA ESTA OCUPADO "<<endl;
                        }

                    }

                }

        }
        return false;
    }


bool emision::ModificarDia(){
        int pos=0;
        int dia,idEmi;
        cout <<"INTRODUZCA UN ID DE EMISION A MODIFICAR"<<endl;
        cin>> idEmi;
        while(leerEnDisco(pos++)==1){
             if(getIDemision()==idEmi){
                    if(getEstado()==true){
                        cout<<"ESTE ID DE EMISION CONTIENE LOS SIGUIENTES DATOS"<<endl;
                        mostrarDatos();
                        cout<<""<<endl;


                        cout<<"INGRESE UN NUEVO VALOR PARA EL DIA: "<<endl;
                        cin>>dia;


                        while(dia<1 && dia>28){
                        cout<<"INGRESE UN DIA VALIDO!!!";
                        cin>>dia;
                        }



                        if(verificarTurnoSala(getSalaId(),dia,getTurno())==true){


                                setDia(dia);
                                if(ModificarEnDisco(pos-1)==1){cout<<"DIA MODIFICADO!"<<endl;
                                return true;


                                }

                        }
                        else{
                            cout <<"EL TURNO Y SALA YA ESTAN OCUPADOS PARA ESE DIA"<<endl;
                        }

                    }

                }

        }
        return false;
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
int emision::ModificarEnDisco(int pos)
{

    FILE *p;
    p=fopen("emision.dat","rb+");
    if (p==NULL) return -1;
    fseek(p,sizeof(emision)*pos,0);
    int escribio=fwrite(this,sizeof(emision),1,p);
    fclose(p);
    return escribio;
}

///BACKUP

int emision :: LeerDeDiscobkp(int pos){
    FILE *A;
        A=fopen("backup/emision.bkp","rb");
            if(A==NULL){cout<<"ERROR DE LECTURA!";return-1;}
    fseek(A,sizeof(emision)*pos,0);
    int leyo=fread(this,sizeof(emision),1,A);
    fclose(A);
    return leyo;
}

bool emision::backupemision(){

int pos=0;
FILE *b;
    b=fopen("backup/emision.bkp","wb");
    if(b==NULL){return false;}
    while(leerEnDisco(pos)==1){
        fwrite(this,sizeof(emision),1,b);
        pos++;
    }
    fclose(b);
    if(pos==0){return false;}
    return true;
}

 bool emision::recuemisiones(){
int pos=0;
FILE *br;
    br=fopen("emision.dat","wb");
    if(br==NULL){return false;}
    while(LeerDeDiscobkp(pos)==1){
        fwrite(this,sizeof(emision),1,br);
        pos++;
    }
    fclose(br);
    if(pos==0){return false;}
    return true;

 }
 void emision::EliminarDeDisco(){
       int pos=0;
       int idD;
        cout<<"INTRODUZCA EL ID DE EMISION A ELIMINAR: ";cin>>idD;
        while(leerEnDisco(pos)==1){
                if(getIDemision()==idD){
                        cout<<"EL ID DE EMISION TIENE LOS SIGUIENTES DATOS"<<endl;
                        mostrarDatos();
                        cout<<endl<<endl;
                        setEstado(false);
                        if(ModificarEnDisco(pos)==1){cout<<"REGISTRO ELIMINADO! ";}
                }
            pos++;
        }

}

#endif // EMISION_H_INCLUDED

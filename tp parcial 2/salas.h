#ifndef SALAS_H_INCLUDED
#define SALAS_H_INCLUDED

class Salas{
private:
    int idSala;
    int tipo;
    int cantButacas;
    bool estado;
public:
     ///sets()

     void setidSala(int S){idSala=S;}
     void setTipo(int T){tipo=T;}
     void setcantButacas(int B){cantButacas=B;}

     ///gets()

     int getidSala(){return idSala;}
     int getTipo(){return tipo;}
     int getcantButacas(){return cantButacas;}

    ///disco
      void cargar();
      void mostrar();
      int grabarEnDisco();
      int leerEnDisco(int);
      void mostrarsalas();


};

void Salas::cargar(){
    estado=true;
    cout<<"INGRESE EL ID DE SALA:";cin>>idSala;
    cout<<"INGRESE EL TIPO DE SALA:";cin>>tipo;
    cout<<"INGRESE LA CANTIDAD DE BUTACAS:";cin>>cantButacas;


}
void Salas::mostrar()
{

      if(estado=true){

    cout<<"INGRESE EL ID DE SALA:"<<idSala<<endl;
    cout<<"INGRESE EL TIPO DE SALA:"<<tipo<<endl;
    cout<<"INGRESE LA CANTIDAD DE BUTACAS:"<<cantButacas<<endl;
    cout<<endl<<endl;

 }
}


///DISCO///
int Salas::grabarEnDisco(){
    FILE *S;
    fopen("salas.dat","wb");
        if(S==NULL){cout<<"ERROR AL GRABAR ARCHIVO"<<endl;return -1;}
    int leyo=fwrite(this,sizeof(Salas),1,S);
    fclose(S);
    return leyo;


}
int Salas::leerEnDisco(int pos){

 FILE *S;
    S=fopen("salas.dat","rb");
    if (S==NULL) return -1;
    fseek(S,sizeof(Salas)*pos,0);
    int leyo=fread(this,sizeof(Salas),1,S);
    fclose(S);
    return leyo;
}

void Salas::mostrarsalas(){
    FILE *S;
    S=fopen("salas.dat","rb");
    if (S==NULL) return;
    while(fread(this,sizeof (Salas),1,S)==1)
    {
        mostrar();
    }
    fclose(S);





}





#endif // SALAS_H_INCLUDED

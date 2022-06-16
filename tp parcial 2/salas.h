#ifndef SALAS_H_INCLUDED
#define SALAS_H_INCLUDED

class Salas{
private:
    int idSala;
    int tipo;
    int cantFilas;
    int cantButacas;
    bool estado;
    int matriz[30][20]={0};
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
      void mostrarSalaCine();


};

void Salas::cargar(){
    cout<<"INGRESE EL ID DE SALA:";cin>>idSala;
    cout<<"INGRESE EL TIPO DE SALA:";cin>>tipo;
    if (tipo==1) cout<<"Sala Normal"<<endl;
    if (tipo==2) cout<<"Sala Con asientos Especiales"<<endl;
    cout<<"INGRESE LA CANTIDAD DE ASIENTOS POR FILA:";cin>>cantButacas;
    cout<<"INGRESE LA CANTIDAD DE FILAS:";cin>>cantFilas;
    for(int i=0; i<cantButacas; i++)
    {
    for(int j=0; j<cantFilas; j++)
    {
    matriz[30][20]=0;
    }
    }
}
void Salas::mostrar()
{
    cout<<idSala;
}
void Salas::mostrarSalaCine()
{
    cout<<"------Pantalla-----\n";
    cout<<"     (1)(2)(3)(4)(5)(6)\n";
    for(int i=0;i<cantButacas;i++)
    {
        cout<<"("<<i+1<<")";
        for(int j=0;j<cantFilas;j++)
        {
            cout<<"["<<matriz[30][20]<<"]";
        }
        cout<<"\n";
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

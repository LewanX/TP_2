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


};

void Salas::cargar(){
    cout<<"INGRESE EL ID DE SALA:";cin>>idSala;



}
void Salas::mostrar()
{
    cout<<idSala;
}

#endif // SALAS_H_INCLUDED

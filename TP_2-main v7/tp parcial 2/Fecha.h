#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
private:///es accesible dentro de la clase
    int dia, mes, anio;///propiedades
public:///es accesible dentro y fuera de la clase
    Fecha(int d=0, int m=0, int a=0){
        this->dia=d;
        this->mes=m;
        this->anio=a;
    }
    ///gets() funciones de la clase que permiten hacer conocer al exterior de la clase el valor de cada prop.
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    ///sets() funciones que permiten modificar los valores de cada una de las propiedades
    void setDia(int d){if(d>=1 && d<=31) dia=d;}
    void setMes(int m){if (m>=1 && m<=12) mes=m;}
    void setAnio(int a){if (a>=2021 && a<=2022) anio=a;}


    void Cargar();
    void Mostrar();
    int modificarEnDiscoFecha(int);
    void Mostrar_this(){
        cout<<this<<endl;
    }

};

void Fecha::Cargar(){
        int d, m, a;

        cout<<"INGRESE EL DIA: ";
        cin>>d;
        cout<<"INGRESE EL MES: ";
        cin>>m;
        cout<<"INGRESE EL ANIO: ";
        cin>>a;
        setDia(d);
        setMes(m);
        setAnio(a);

    }

void Fecha::Mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        cout<<endl<<endl;

    }

#endif // FECHA_H_INCLUDED

#ifndef DECORADO_H_INCLUDED
#define DECORADO_H_INCLUDED
void gotoxy(int x, int y){
     HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD poss;
    poss.X = x;
    poss.Y = y;

    SetConsoleCursorPosition(handle,poss);

}

//FUNCION QUE DIBUJA EL CUADRO
void dibujarCuadro(int x1,int y1,int x2,int y2){
    int i;

    for (i=x1;i<x2;i++){
        gotoxy(i,y1); cout << "\304"; //linea horizontal superior
        gotoxy(i,y2); cout << "\304"; //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
        gotoxy(x1,i); cout <<"\263"; //linea vertical izquierda
        gotoxy(x2,i); cout <<"\263"; //linea vertical derecha
    }

    gotoxy(x1,y1); cout<< "\332";
    gotoxy(x1,y2); cout<< "\300";
    gotoxy(x2,y1); cout<< "\277";
    gotoxy(x2,y2); cout<< "\331";
}
void estructuraSala(string option1,string option2)
{
    dibujarCuadro(1,1,115,3);
    gotoxy(10,2);cout<<option1;//"IDSALA";
    gotoxy(90,2);cout<<option2;//"BUTACAS TOTALES";
                 //"BUTACAS DISPONIBLES";

}


#endif // DECORADO_H_INCLUDED

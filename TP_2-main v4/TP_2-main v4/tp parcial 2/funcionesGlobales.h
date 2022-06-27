#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

void cargarCadena(char *pal, int tam);
///FIN PROTOTIPOS

void cargarCadena(char *pal, int tam)
{
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++)
    {
        pal[i]=cin.get();
        if (pal[i]=='\n')break;
    }
    pal[i]=='\0';
    fflush(stdin);
}
int validacionDir(int id){
    director aux;
        int pos=0;
        while(aux.leerEnDisco(pos++)==1){
            if(aux.getidDirector()==id){
                    cout<<"DIRECTOR:"<<aux.getnombreDirector();
                     return 1;

            }
        }
    return 0;


}
int validacionSala(int id){
    Salas aux;
    int pos=0;
    int precio=0;
        while(aux.leerEnDisco(pos++)==1)
        {
            if(aux.getidSala()==id){
                if(id==1){
                    return precio=500;
                }else{
                    return precio=600;
                }

            }
        }

}
int NomDir(int id){
    director aux;
        int pos=0;
        while(aux.leerEnDisco(pos++)==1){
            if(aux.getidDirector()==id){
                    cout<<"DIRECTOR:"<<aux.getnombreDirector();
                    return 1;

            }
        }



}
#endif // FUNCIONESGLOBALES_H_INCLUDED

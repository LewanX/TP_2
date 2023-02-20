#ifndef PROTOFUNCIONESGLOBALES_H_INCLUDED
#define PROTOFUNCIONESGLOBALES_H_INCLUDED
//PROTOTIPOS

void cargarCadena(char *pal, int tam);
int validacionIDpelicula(int id);
int validacionDir(int id);

int validacionSala(int id);

int validacionPrecio(int id, int pago);

int NomDir(int id);

bool validacionDatosPelicula();

int calcularVentas(int id);

int autonumericoVentas();
int fechaPelicula(int id);
int calcularPlazas(int id, int dia, int mes, int anio);
int cantButacasSala(int id);

bool validacionDatosVenta();

bool formatoValido(char *formato);

///EMISIONES
string determinarTurno(int turno);
int validacionIDsala(int salaid);
int buscarButacas(int salaid);
int descontarButacas(int dia,int salaID,int turno);
bool emisionSala(int salaidm, int dia);
bool tieneTurno(int salaid, int dia,int turno);
///VENTAS
bool mostrarEmisionesPelicula(int dia);
bool validarPelicula(int dia,int IDpelicula);
void TurnoDePelicula(int salaID,int dia,int PeliculaID);
//int VentaAutonumerica();
#endif // PROTOFUNCIONESGLOBALES_H_INCLUDED

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




//int VentaAutonumerica();
#endif // PROTOFUNCIONESGLOBALES_H_INCLUDED

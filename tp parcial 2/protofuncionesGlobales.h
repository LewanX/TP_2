#ifndef PROTOFUNCIONESGLOBALES_H_INCLUDED
#define PROTOFUNCIONESGLOBALES_H_INCLUDED
//PROTOTIPOS

void cargarCadena(char *pal, int tam);
int validacionIDpelicula(int id);
int validacionDir(int id);

int validacionSala(int id);

int validacionPrecio(int id, int pago);

int NomDir(int id);
int validarVenta(int salaid);
bool validacionDatosPelicula();
int verificarSala(int sala);
int calcularVentas(int id);


int fechaPelicula(int id);
int calcularPlazas(int id, int dia, int mes, int anio);
int cantButacasSala(int id);

bool validacionDatosVenta();

bool formatoValido(char *formato);

///EMISIONES
int autonumericoEmision();
string determinarTurno(int turno);
int validacionIDsala(int salaid);
int buscarButacas(int salaid);
int descontarButacas(int dia,int salaID,int turno);
int descontarButacas(int salaID,int turno);
bool emisionSala(int salaidm, int dia);
bool tieneTurno(int salaid, int dia,int turno);
bool verificarCambioDia(int salaid,int dia,int turno);
bool verificarTurnoSala(int Sala,int Dia,int Turno);
///VENTAS
int autonumericoVentas();
bool mostrarEmisionesPelicula(int dia);
bool validarPelicula(int dia,int IDpelicula);
bool validarPeliculaSala(int dia,int idPelicula,int sala);
void TurnoDePelicula(int salaID,int dia,int PeliculaID);
bool validarTurno(int dia,int idPelicula,int turno);
bool validarButacas(int dia,int idPelicula,int turno,int butacas,int sala);
int salaDeVentas(int dia, int turno,int idPelicula);
int obtenerPrecioPelicula(int dia,int idPelicula,int turno);
bool actualizarButacasDisponibles(int dia,int idPelicula,int turno,int butacas,int butacasVendidas,int sala);
bool restaurarButacasDisponibles(int dia,int idPelicula,int turno,int CantEntradas,int sala);

#endif // PROTOFUNCIONESGLOBALES_H_INCLUDED

#ifndef PROTOFUNCIONESGLOBALES_H_INCLUDED
#define PROTOFUNCIONESGLOBALES_H_INCLUDED
//PROTOTIPOS
int validacionIDpelicula(int id);
int validacionDir(int id);

int validacionSala(int id);

int validacionPrecio(int id, int pago);

int NomDir(int id);

int calcularVentas(int id);
int fechaVentasSala(int anio, int mes, int dia);
int autonumerico();
//int VentaAutonumerica();
#endif // PROTOFUNCIONESGLOBALES_H_INCLUDED
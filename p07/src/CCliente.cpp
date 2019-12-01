#include "CCliente.hpp"
#include "CFicha.hpp"
#include "CHora.hpp"
#include "types.hpp"
#include <string>

CCliente::CCliente(string name, int age, CHora hora, string dni) {
  int horas=0, minutos=0, segundos=0;
  char *formato = new char[32]();

  hora.ObtenerHora(horas, minutos, segundos, formato);

  this->SetDNI(dni);
  this->AsignarNombre(name);
  this->AsignarEdad(age);
  this->AsignarNacio(horas, minutos, segundos, formato);

  delete[] formato;
}

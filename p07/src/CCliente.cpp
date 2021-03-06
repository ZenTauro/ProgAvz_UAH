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

ostream &operator<<(ostream &os, const CCliente &cliente) {
  auto hora = cliente.ObtenerNacio();
  os << "[" << hora << "] "
     << "Cliente: " << cliente.ObtenerNombre() << " " << cliente.GetDNI();

  return os;
}

void CCliente::show() const {
  cout << *this << endl;
}

CFicha * CCliente::Clone() const {
  auto copy = new CCliente{*this};
  return copy;
}

CCliente::~CCliente() {
#ifndef NDEBUG
  cout << "CCliente: " << this << "\n";
#endif
}

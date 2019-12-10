#include "CEmpleado.hpp"
#include "CFicha.hpp"
#include "types.hpp"
#include <string>
#include <iostream>

using namespace std;

CEmpleado::CEmpleado(const string &sNombre, const string category,
                     uint32 antiguedad, int nEdad, const CHora time) {
  int nHoras=0, nMinutos=0, nSegundos=0;
  auto fmt = new char[32]();

  time.ObtenerHora(nHoras, nMinutos, nSegundos, fmt);

  this->AsignarNombre(sNombre);
  this->SetCategoria(category);
  this->SetAntiguedad(antiguedad);
  this->AsignarEdad(nEdad);
  this->AsignarNacio(nHoras, nMinutos, nSegundos, fmt);

  delete[] fmt;
}

ostream &
operator<<(ostream &os, const CEmpleado &emp) {
  os << emp.ObtenerNombre() << " " << emp.m_sCategoria << " " << emp.m_nAntiguedad;
  return os;
}

void CEmpleado::show() {
  cout << *this << "\n";
}

CFicha *CEmpleado::Clone() const {
  auto copy = new CEmpleado{*this};
  return copy;
}

CEmpleado::~CEmpleado() {
#ifndef NDEBUG
  cout << "CEmpleado: " << this << "\n";
#endif
}

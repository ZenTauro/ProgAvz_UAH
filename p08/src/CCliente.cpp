#include "CCliente.hpp"
#include "CContrato.hpp"

CCliente::CCliente(const string &Nom, const CContrato &c) {}

ostream &operator<<(ostream &os, CCliente &c) {
  os << c.m_Nombre;

  return os;
}

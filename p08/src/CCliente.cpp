#include "CCliente.hpp"
#include "CContrato.hpp"
#include <cstdint>

CCliente::CCliente(const string &Nom, const CContrato &c) {
  this->m_Nombre = Nom;
  this->m_Contratos.AgregarObjeto(c);
}

void CCliente::AgregarContrato(const CContrato &c) {
  this->m_Contratos.AgregarObjeto(c);
}

ostream &operator<<(ostream &os, CCliente &c) {
  os << "nombre: " << c.m_Nombre << " contratos ";
  c.m_Contratos.Restart();
  while(c.m_Contratos.TieneMas()) {
    os << c.m_Contratos.GetActual() << " ";
  }
  c.m_Contratos.Restart();

  return os;
}

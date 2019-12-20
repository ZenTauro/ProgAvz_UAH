#include "CCliente.hpp"
#include "CContrato.hpp"
#include <cstdint>

CCliente::CCliente(const string &Nom, const CContrato &c) {
  this->m_Nombre = Nom;
  this->m_Contratos.AgregarObjeto(c);
}

CCliente& CCliente::AgregarContrato(const CContrato &c) {
  this->m_Contratos.AgregarObjeto(c);
  return *this;
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

CCliente::operator long() const {
  long ret = 0;

  this->m_Contratos.Restart();
  while (this->m_Contratos.TieneMas()) {
    ret++;
    this->m_Contratos.GetActual();
  }
  this->m_Contratos.Restart();

  return ret;
}

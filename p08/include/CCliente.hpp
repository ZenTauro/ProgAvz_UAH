#pragma once

#include "CLista.hpp"
#include "CContrato.hpp"
#include <string>

using namespace std;

class CCliente {
protected:
  string m_Nombre;
  CLista<CContrato> m_Contratos;
public:
  CCliente(const string &Nom = "Sin Nombre") : m_Nombre(Nom),
                                               m_Contratos() {}
  CCliente(const string &Nom, const CContrato &c);
  inline void SetNombre(const string &Nom) { this->m_Nombre = Nom; };
  inline string GetNombre() const { return this->m_Nombre; };
  void AgregarContrato(const CContrato &c);

  friend ostream &operator<<(ostream &os, CCliente &c);
};

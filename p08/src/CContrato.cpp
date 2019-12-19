#include "CLista.hpp"
#include "CSiniestro.hpp"
#include "CContrato.hpp"
#include <iostream>
#include <string>

using namespace std;

void CContrato::AgregarSiniestro(CSiniestro &s) {
  this->m_Siniestros.AgregarObjeto(s.Clonar());
}

void CContrato::MostrarSiniestros(ostream &os) {
  for(uint64_t i=0;;i++) {
    try {
      cout << this->m_Siniestros[i] << ", ";
    } catch(CIndiceIncorrecto &e) {
      break;
    }
  }
  cout << "\n";
}

CContrato &CContrato::operator=(const CContrato &c) {
  auto copy = CContrato{c};

  m_NumSerie = copy.m_NumSerie;
  m_Descripcion = copy.m_Descripcion;
  m_FechaFin = copy.m_FechaFin;
  m_Poliza = copy.m_Poliza;
  m_ValorCompra = copy.m_ValorCompra;
  m_Siniestros = copy.m_Siniestros;

  return *this;
}

ostream &operator<<(ostream &os, CContrato &c) {
  os << c.GetDescripcion();
  return os;
}

CContrato::~CContrato() {}

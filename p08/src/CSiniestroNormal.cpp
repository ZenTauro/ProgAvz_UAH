#include "CSiniestroNormal.hpp"
#include <iostream>

float CSiniestroNormal::m_CosteHoraMO;

void CSiniestroNormal::Presupuestar(float Horas, float Piezas) {
  this->m_CosteHoraMO = 1;
  this->m_HorasMO = Horas;
  this->m_CostePiezas = Piezas;
}

void CSiniestroNormal::Mostrar(ostream &os) const {
  os << *this << "\n";
}

CSiniestroNormal *CSiniestroNormal::Clonar() const {
  return new CSiniestroNormal{*this};
}

ostream& operator<<(ostream &os, const CSiniestro &sin) {
  os << "{\"codigo\":\"" << sin.GetCodigo()
     << "\",\"presupuesto\":\"" << sin.GetPresupuesto() << "\"}";
  return os;
}

CSiniestroNormal::~CSiniestroNormal() {}

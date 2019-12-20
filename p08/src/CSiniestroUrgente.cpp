#include "CSiniestroUrgente.hpp"

float CSiniestroUrgente::m_Recargo = 15;
float CSiniestroUrgente::m_CosteHoraMO = 20;

CSiniestroUrgente::CSiniestroUrgente(TSituacion s, const string &Desc) : CSiniestro{} {
  this->m_Situacion = s;
  this->m_Descripcion = Desc;
}

void CSiniestroUrgente::Presupuestar(float Horas, float Piezas) {
  this->m_Coste = this->m_CosteHoraMO * Horas + this->m_CostePiezas * Piezas + this->m_Recargo;
}

ostream &operator<<(ostream &os, const CSiniestroUrgente &sin) {
  os << "[" << sin.m_Situacion << "]"
     << " Coste: " << sin.m_Coste << ", descripcion: " << sin.m_Descripcion;
  return os;
}

void CSiniestroUrgente::Mostrar(ostream &os) const {
  os << *this << "\n";
}

CSiniestroUrgente *CSiniestroUrgente::Clonar() const {
  return new CSiniestroUrgente{*this};
}

float CSiniestroUrgente::GetPresupuesto() const {
  return m_Coste;
}

ostream &operator<<(ostream &os, const TSituacion &s) {
  switch (s) {
  case TSituacion::internacional: {
    os << "internacional";
    break;
  }
  case TSituacion::nacional: {
    os << "nacional";
    break;
  }
  case TSituacion::local: {
    os << "local";
    break;
  }
  }
  return os;
}

CSiniestroUrgente::~CSiniestroUrgente() {}

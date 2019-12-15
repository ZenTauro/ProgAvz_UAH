#pragma once

#include "CSiniestro.hpp"
#include <iostream>
#include <string>

using namespace std;

enum class TSituacion {
    local, nacional, internacional
};

class CSiniestroUrgente : public CSiniestro {
private:
  TSituacion m_Situacion;
  static float m_Recargo;
  static float m_CosteHoraMO;

public:
  CSiniestroUrgente(TSituacion s, const string &Desc = "Sin Descripción");

  void Presupuestar(float Horas = 0.5f, float Piezas = 0);
  void Mostrar(ostream &os = cout) const;
  CSiniestroUrgente *Clonar() const;
  float GetPresupuesto() const;
};

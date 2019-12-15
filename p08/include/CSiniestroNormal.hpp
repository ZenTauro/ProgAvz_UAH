#pragma once

#include "CSiniestro.hpp"
#include <iostream>
#include <string>

using namespace std;

class CSiniestroNormal : public CSiniestro {
private:
  static float m_CosteHoraMO;

public:
  CSiniestroNormal(const string &Desc = "Sin Descripción");

  void Presupuestar(float Horas = 0.5f, float Piezas = 0);
  void Mostrar(ostream &os = cout) const;
  CSiniestroNormal *Clonar() const;
  float GetPresupuesto() const;
};

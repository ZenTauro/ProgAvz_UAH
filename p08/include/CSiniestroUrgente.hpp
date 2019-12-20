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

  void Presupuestar(float Horas = 0.5f, float Piezas = 0) override;
  void Mostrar(ostream &os = cout) const override;
  CSiniestroUrgente *Clonar() const override;
  float GetPresupuesto() const override;

  ~CSiniestroUrgente() override;

  friend ostream& operator<<(ostream &os, const CSiniestroUrgente &sin);
};

ostream &operator<<(ostream &os, const TSituacion &s);

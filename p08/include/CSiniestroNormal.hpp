#pragma once

#include "CSiniestro.hpp"
#include <iostream>
#include <string>

using namespace std;

class CSiniestroNormal : public CSiniestro {
private:
  static float m_CosteHoraMO;

public:
  CSiniestroNormal(const string &Desc = "Sin Descripción")
    : CSiniestro(Desc) {};

  inline float GetPresupuesto() const override {
    return this->m_CosteHoraMO * this->m_HorasMO + this->m_CostePiezas;
  };

  void Presupuestar(float Horas = 0.5f, float Piezas = 0) override;
  void Mostrar(ostream &os = cout) const override;
  CSiniestroNormal *Clonar() const override;

  ~CSiniestroNormal() override;

  friend ostream& operator<<(ostream &os, const CSiniestro& sin);
};

#pragma once

#include <iostream>
#include <string>

using namespace std;

class CSiniestro {
  private:
    int m_Codigo;
    static int m_SigCodigo;

  protected:
    string m_Descripcion;
    float m_HorasMO;
    float m_CostePiezas;
    float m_Coste;

  public:
    CSiniestro(const string &Desc = "Sin Descripción");

    virtual float GetPresupuesto() const = 0;
    inline int GetCodigo() const { return m_Codigo; };
    inline float GetCoste() const { return m_Coste; };

    virtual void Presupuestar(float Horas, float Piezas) = 0;
    virtual void Mostrar(ostream &os = cout) const;
    virtual CSiniestro *Clonar() const = 0;

    virtual ~CSiniestro(){};
};

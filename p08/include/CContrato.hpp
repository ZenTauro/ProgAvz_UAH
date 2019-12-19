#pragma once

#include "CLista.hpp"
#include "CSiniestro.hpp"
#include <iostream>
#include <string>

using namespace std;

class CContrato {
private:
  int    m_NumSerie;
  string m_Descripcion;
  string m_FechaFin;
  long   m_Poliza;
  long   m_ValorCompra;
  CLista<CSiniestro *> m_Siniestros;

public:
  CContrato(int NumSerie, const string &Desc = "", const string &FF = "",
            long Poliza = 0, long ValorCompra = 0)
    : m_NumSerie(NumSerie), m_Descripcion(Desc), m_FechaFin(FF),
      m_Poliza(Poliza), m_ValorCompra(ValorCompra) {
    this->m_Siniestros = CLista<CSiniestro *>{};
  };
  CContrato(const CContrato &c)
      : m_NumSerie(c.m_NumSerie), m_Descripcion(c.m_Descripcion), m_FechaFin(c.m_FechaFin),
        m_Poliza(c.m_Poliza), m_ValorCompra(c.m_ValorCompra), m_Siniestros(c.m_Siniestros) {};

  inline void SetNumSerie(int ns) { m_NumSerie = ns; }
  inline void SetDescripcion(const string &d) { m_Descripcion = d; }
  inline void SetFechaFin(const string &ff) { m_FechaFin = ff; }
  inline void SetPoliza(long p) { m_Poliza = p; }
  inline void SetValorCom(long vc) { m_ValorCompra = vc; }

  inline int GetNumSerie() const { return m_NumSerie; }
  inline string GetDescripcion() const { return m_Descripcion; }
  inline string GetFechaFin() const { return m_FechaFin; }
  inline long GetPoliza() const { return m_Poliza; }
  inline long GetValorCom() const { return m_ValorCompra; }

  void AgregarSiniestro(CSiniestro &s);
  void MostrarSiniestros(ostream &os = cout);

  CContrato &operator=(const CContrato &c);

  friend ostream &operator<<(ostream &os, CContrato &c);

  ~CContrato();
};

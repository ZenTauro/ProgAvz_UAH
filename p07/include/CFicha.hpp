#pragma once

#include "CHora.hpp"
#include <string>

using namespace std;

class CFicha {
private:
  string m_sNombre;
  int m_nEdad;
  CHora m_horaNacio;

public:
  CFicha(const string &sNombre = "", int nEdad = 0, int nHoras = 12, int nMinutos = 0,
         int nSegundos = 0, const string &sFormato = "AM");

  virtual void AsignarNombre(const string &sNombre);
  virtual string ObtenerNombre() const;
  virtual void AsignarEdad(int nEdad);
  virtual int ObtenerEdad() const;
  virtual bool AsignarNacio(int nHoras, int nMinutos, int nSegundos,
                    const string &sFormato);
  virtual CHora ObtenerNacio() const;
  virtual void operator=(CFicha &obj);

  virtual void show() = 0;
};

void VisualizarHora(CFicha &ficha);

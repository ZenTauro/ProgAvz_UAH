#pragma once

#include "CFicha.hpp"
#include "types.hpp"
#include <string>

using namespace std;

class CEmpleado : public CFicha {
private:
  string m_sCategoria;
  uint32 m_nAntiguedad;

public:
  CEmpleado(const string &sNombre = "", const string category = "",
            uint32 antiguedad = 0, int nEdad = 0, const CHora time = CHora{});

  inline void SetCategoria(const string& sCategoria) {
    this->m_sCategoria = sCategoria;
  };
  inline void SetAntiguedad(uint32 nAntiguedad) {
    this->m_nAntiguedad = nAntiguedad;
  };

  inline string GetCategoria() {
    return this->m_sCategoria;
  };
  inline uint32 GetAntiguedad() {
    return this->m_nAntiguedad;
  };

  friend ostream &operator<<(ostream &os, const CEmpleado &emp);

  void show() override;
  CFicha* Clone() override;

  ~CEmpleado();
};

ostream &operator<<(ostream &os, const CEmpleado &emp);

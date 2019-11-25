#pragma once

#include "CFicha.hpp"
#include "types.hpp"
#include <string>

using namespace std;

class CEmpleado : CFicha {
private:
  string m_sCategoria;
  uint32 m_nAntiguedad;
public:
  inline void SetCategoria(const string& sCategoria) { this->m_sCategoria = sCategoria; };
  inline void SetAntiguedad(uint32 nAntiguedad) { this->m_nAntiguedad = nAntiguedad; };
};

#pragma once

#include "CFicha.hpp"
#include "types.hpp"
#include <string>

using namespace std;

class CCliente : CFicha {
private:
  string m_sDNI;
public:
  inline void SetDNI(const string& sDNI) { this->m_sDNI = sDNI; };
};

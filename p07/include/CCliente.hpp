#pragma once

#include "CFicha.hpp"
#include "CHora.hpp"
#include "types.hpp"
#include <string>

using namespace std;

class CCliente : public CFicha {
private:
  string m_sDNI;
public:
  inline void SetDNI(const string& sDNI) { this->m_sDNI = sDNI; };
  inline string GetDNI() { return this->m_sDNI; };
  CCliente(string name = "", int age = 0, CHora hora = CHora{}, string dni = "");
};

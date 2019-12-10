#pragma once

#include "CFicha.hpp"
#include "CHora.hpp"
#include "types.hpp"
#include <iostream>
#include <string>

using namespace std;

class CCliente : public CFicha {
private:
  string m_sDNI;
public:
  // Getters and Setters
  inline void SetDNI(const string& sDNI) { this->m_sDNI = sDNI; };
  inline string GetDNI() const { return this->m_sDNI; };

  // Constructors
  CCliente(string name = "", int age = 0, CHora hora = CHora{}, string dni = "");

  //
  void show() override;
  CFicha *Clone() const override;

  ~CCliente();
};

ostream &operator<<(ostream &os, const CCliente &Cliente);

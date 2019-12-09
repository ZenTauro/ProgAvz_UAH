#include "CRegistroDiario.hpp"
#include "CFicha.hpp"
#include "types.hpp"
#include <exception>
#include <iostream>
#include <vector>

using namespace std;

CRegistroDiario CRegistroDiario::operator=(CRegistroDiario const &from) {
  this->nElementosMax = from.nElementosMax;

#if WITH_VECTORS
  for(auto& x : from.personas) {
    this->personas.push_back(x->Clone());
  }
#else
  this->personas = new CFicha*[nElementosMax]();
  for (uint32 i=0; i<nElementosMax; i++) {
    cout << "Plz fix this" << "\n";
    this->personas[i] = from.personas[i];
  }
#endif

  return *this;
}

CRegistroDiario::CRegistroDiario(int num) : length{0} {
  if(num <= 0) {
    throw invalid_argument("Negative or zero size");
  }

  this->length = 0;

  this->nElementosMax = num;
#if WITH_VECTORS
  this->personas = vector<CFicha*>(num);
#else
  this->personas = new CFicha*[num]();
#endif
}

CRegistroDiario::CRegistroDiario(const CRegistroDiario &original) {
  this->nElementosMax = original.nElementosMax;
}

CRegistroDiario::~CRegistroDiario() {
#if WITH_VECTORS
#else
  for (uint32 i=0; i< this->nElementosMax; i++) {
    delete this->personas[i];
  }
  delete[] this->personas;
#endif
}

CRegistroDiario CRegistroDiario::Add(CFicha &per) {
  this->length++;

#if WITH_VECTORS
  this->personas.push_back(&per);
#else
#endif

  return *this;
}

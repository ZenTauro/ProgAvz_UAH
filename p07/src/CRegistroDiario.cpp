#include "CRegistroDiario.hpp"
#include "CFicha.hpp"
#include "types.hpp"
#include <exception>
#include <iostream>
#include <vector>

using namespace std;

CRegistroDiario& CRegistroDiario::operator=(CRegistroDiario const &from) {
  if(this == &from) {
    throw invalid_argument("Trying to self assign");
  }
  this->nElementosMax = from.nElementosMax;
  this->length = from.length;

#if defined WITH_VECTORS
  this->personas = vector<CFicha *>{};
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
#if defined WITH_VECTORS
  this->personas = vector<CFicha*>{};
  this->personas.reserve(num);
#else
  this->personas = new CFicha*[num]();
#endif
}

CRegistroDiario::CRegistroDiario(const CRegistroDiario &original) {
  this->nElementosMax = original.nElementosMax;
}

CRegistroDiario::~CRegistroDiario() {
#if defined WITH_VECTORS
  for(auto &reg : this->personas) {
    delete reg;
  }
#else
  for (uint32 i=0; i< this->length; i++) {
    delete this->personas[i];
  }
  delete[] this->personas;
#endif
}

bool CRegistroDiario::Add(CFicha &per) {
  bool ret = true;

  this->length++;

#if defined WITH_VECTORS
  this->personas.push_back(&per);
#else
  if(this->length <= this->nElementosMax) {
    this->personas[length - 1] = &per;
  } else {
    ret = false;
  }
#endif

  return ret;
}

const CFicha &CRegistroDiario::operator[](uint64_t i) {
  if(i<0 || i >= this->length) {
    throw out_of_range("Index out of range");
  }
#if defined WITH_VECTORS
  return *this->personas[i];
#else
  return *this->personas[i];
#endif
}

void CRegistroDiario::ShowRegister() {
#if defined WITH_VECTORS
  for (auto &ficha : this->personas ) {
    ficha->show();
  }
#else
  for (uint64_t i=0; i<this->length; i++) {
    this->personas[i]->show();
  }
#endif
}

void CRegistroDiario::ShowEmployees() {
#if defined WITH_VECTORS
  for (auto &ficha : this->personas) {
    if ( CRegistroDiario::EsEmpleado(*ficha) ) {
      ficha->show();
    }
  }
#else
  for (uint64_t i = 0; i < this->length; i++) {
    if (CRegistroDiario::EsEmpleado(*this->personas[i])) {
      this->personas[i]->show();
    }
  }
#endif
}

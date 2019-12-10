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
#ifndef WITH_VECTORS
  if(this->personas != nullptr) {
    delete[] this->personas;
  }
#endif

  this->nElementosMax = from.nElementosMax;
  this->length = from.length;

#if defined WITH_VECTORS
  this->personas = vector<CFicha *>{};
  for(auto& x : from.personas) {
    this->personas.push_back(x->Clone());
  }
#else
  this->personas = new CFicha*[nElementosMax]();
  for (uint32 i=0; i<from.length; i++) {
    this->personas[i] = from.personas[i]->Clone();
  }
#endif

  return *this;
}

CRegistroDiario::CRegistroDiario(int num) : length{0} {
  if(num <= 0) {
    throw invalid_argument("Negative or zero size");
  }

#ifndef NDEBUG
  cout << "Constructing reg: " << this << "\n";
#endif
  this->length = 0;

  this->nElementosMax = num;
#if defined WITH_VECTORS
  this->personas = vector<CFicha*>{};
  this->personas.reserve(num);
#else
  this->personas = new CFicha*[num]();
#ifndef NDEBUG
  cout << " --- [i] Internal array located at: " << this->personas << "\n";
#endif
#endif
}

CRegistroDiario::CRegistroDiario(const CRegistroDiario &original) {
#ifndef NDEBUG
  cout << "Constructing reg: " << this << "\n";
#endif
#if defined WITH_VECTORS
  this->personas = vector<CFicha*>{};
#else
  this->personas = nullptr;
#endif
  this->length = original.length;
  this->nElementosMax = original.nElementosMax;
  *this = original;
}

CRegistroDiario::~CRegistroDiario() {
#if defined WITH_VECTORS
  for(auto &reg : this->personas) {
#ifndef NDEBUG
    cout << reg << endl;
#endif
    delete reg;
  }
#else
  for (uint32 i=0; i< this->length; i++) {
    delete this->personas[i];
  }
#ifndef NDEBUG
  cout << "deleting reg: " << this << "\n";
  cout << " --- [i] Deleting internal array at: " << this->personas << "\n";
#endif
  delete[] this->personas;
#endif
}

bool CRegistroDiario::Add(CFicha const &per) {
  bool ret = true;

#if defined WITH_VECTORS
  this->personas.push_back(per.Clone());
  this->length++;
#else
  if(this->length < this->nElementosMax) {
    this->personas[length] = per.Clone();
    this->length++;
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

const CFicha & CRegistroDiario::FindByName(const string &name) const {
  CFicha*res = nullptr;

#if defined WITH_VECTORS
  for (auto &ficha : this->personas) {
    if (ficha->ObtenerNombre() == name) {
      res = ficha;
    }
  }
#else
  for (uint64_t i = 0; i < this->length; i++) {
    if (this->personas[i]->ObtenerNombre() == name) {
      res = ficha;
    }
  }
#endif

  return *res;
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

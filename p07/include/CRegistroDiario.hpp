#pragma once

#include "types.hpp"
#include "CFicha.hpp"
#include <vector>

using namespace std;

const uint32 DEFAULT_REGSIZE = 256;

class CRegistroDiario {
private:
  uint32 nElementosMax;
  uint32 length;
#if WITH_VECTORS
  vector<CFicha *> personas;
#else
  CFicha** personas;
#endif

public:
  CRegistroDiario(int num = DEFAULT_REGSIZE);
  CRegistroDiario(const CRegistroDiario &original);

  inline uint32 GetMaxSize() { return this->nElementosMax; };
  inline uint32 Length() { return this->length; };

  CRegistroDiario& operator=(CRegistroDiario const &from);
  CRegistroDiario Add(CFicha &per);

  const CFicha& operator[](uint64_t i);

  ~CRegistroDiario();
};

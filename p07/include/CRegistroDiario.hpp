#pragma once

#include "CEmpleado.hpp"
#include "CFicha.hpp"
#include "types.hpp"
#include <vector>

using namespace std;

const uint32 DEFAULT_REGSIZE = 256;

class CRegistroDiario {
private:
  uint32 nElementosMax;
  uint32 length;
#if defined WITH_VECTORS
  vector<CFicha *> personas;
#else
  CFicha** personas;
#endif

public:
  CRegistroDiario(int num = DEFAULT_REGSIZE);
  CRegistroDiario(const CRegistroDiario &original);

  inline uint32 GetMaxSize() { return this->nElementosMax; };
  inline uint32 Length() { return this->length; };

  static inline bool EsEmpleado(const CFicha & obj) {
    bool ret = true;
    try {
      auto _dummy = dynamic_cast<const CEmpleado &>(obj);
    } catch (bad_cast &e) {
      ret = false;
    }

    return ret;
  };

  CRegistroDiario& operator=(CRegistroDiario const &from);
  bool Add(CFicha &per);
  void ShowRegister();
  void ShowEmployees();

  const CFicha& operator[](uint64_t i);

  ~CRegistroDiario();
};

#pragma once

#include "CMonomio.hpp"
#include "CTermino.hpp"
#include "types.hpp"
#include <cstdint>
#include <vector>

using namespace std;

class CPolinomio {
private:
  u32 max_term;
  CTermino *head;

public:
  inline u32 grado() const & { return this->max_term; };
  inline CTermino const & next() const & { return *(this->head); };

  CPolinomio();
  CPolinomio(CPolinomio const &poli);
  CPolinomio(vector<CMonomio> &monomios);
  ~CPolinomio();

  CPolinomio& operator<<(const CMonomio &mono);
  void operator=(const CPolinomio &poli) noexcept;
};

ostream &operator<<(ostream &os, const CPolinomio &poli);

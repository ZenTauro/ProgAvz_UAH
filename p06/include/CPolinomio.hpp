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
  inline CTermino const &next() const & { return *(this->head); };

  CPolinomio(CPolinomio const &poli);
  CPolinomio(CMonomio &mon);
  CPolinomio(vector<CMonomio> &monomios);
  ~CPolinomio();
  CPolinomio(i32 c = 0, u32 e = 0, CTermino *next = NULL);

  CPolinomio &operator<<(const CMonomio &mono);
  CPolinomio &operator<<(const CPolinomio &poli);

  void operator=(const CPolinomio &poli) noexcept;
  CPolinomio &operator+=(CPolinomio &poli) noexcept;
  CPolinomio &operator-=(CPolinomio &poli) noexcept;
  CPolinomio &operator*=(CPolinomio &poli) noexcept;

  bool operator<(const CPolinomio &poli) const;
  bool operator>(const CPolinomio &poli) const;

  i32 operator[](u32 idx);
  i32 operator()(i32 val);

  friend CPolinomio &operator-(CPolinomio &self);
  friend CPolinomio &operator+(CPolinomio &self, CPolinomio &other);
  friend CPolinomio operator*(CPolinomio &self, CPolinomio &other);

  friend ostream &operator<<(ostream &os, const CPolinomio &poli);

  inline operator int() { return this->head->GetExp(); }
};

ostream &operator<<(ostream &os, const CPolinomio &poli);

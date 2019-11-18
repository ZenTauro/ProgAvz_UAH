#include "CMonomio.hpp"
#include "types.hpp"
#include <iostream>
#include <cmath>

using namespace std;

CMonomio::CMonomio(i32 dCoef, u32 nExp) {
  this->SetCoef(dCoef);
  this->SetExp(nExp);
}

i32 CMonomio::operator()(i32 val) {
  return this->coef * pow(val, this->exp);
}

bool CMonomio::operator<(CMonomio const &op) const {
  return (this->exp < op.exp) || (this->coef < op.coef);
}

bool CMonomio::operator>(CMonomio const  &op) const {
  return !(*this < op);
}

CMonomio operator*(CMonomio a, CMonomio b) {
  CMonomio temp;
  temp.SetCoef(a.GetCoef() * b.GetCoef());
  temp.SetExp(a.GetExp() * b.GetExp());

  return temp;
}

ostream &operator<<(ostream &os, const CMonomio &mono) {
  os << showpos;
  if (!mono.GetExp())
    os << mono.GetCoef();
  else {
    if (mono.GetCoef() != 1)
      os << mono.GetCoef();
    os << noshowpos;
    if (mono.GetExp() == 1)
      os << "x";
    else
      os << "x^" << mono.GetExp();
  }
  os << noshowpos;
  return os;
  }

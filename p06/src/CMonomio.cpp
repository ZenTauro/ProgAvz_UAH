#include "CMonomio.hpp"
#include "types.hpp"
#include <iostream>

using namespace std;

CMonomio::CMonomio(u32 dCoef, i32 nExp) {}

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

#pragma once

#include "types.hpp"
#include <iostream>

using namespace std;

class CMonomio {
private:
  i32 coef;
  u32 exp;

public:
  CMonomio(u32 dCoef = 0, i32 nExp = 0);

  inline i32 GetCoef() const { return this->coef; }
  inline u32 GetExp() const { return this->exp; }

  inline void SetCoef(i32 dCoef) { this->coef = dCoef; };
  inline void SetExp(u32 dExp) { this->exp = dExp; };

  CMonomio operator-() const { return CMonomio(-this->coef, this->exp); }
};

ostream &operator<<(ostream &os, const CMonomio &Mono);

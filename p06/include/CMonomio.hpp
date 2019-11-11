#pragma once

#include "types.hpp"
#include <iostream>

using namespace std;

class CMonomio {
private:
  i32 coef;
  u32 exp;

public:
  CMonomio(i32 dCoef = 0, u32 nExp = 0);

  inline i32 GetCoef() const { return this->coef; }
  inline u32 GetExp() const { return this->exp; }

  inline void SetCoef(i32 dCoef) { this->coef = dCoef; };
  inline void SetExp(u32 dExp) { this->exp = dExp; };

  CMonomio operator-() const { return CMonomio(-this->coef, this->exp); }

  bool operator<(CMonomio const &op) const;
  bool operator>(CMonomio const &op) const;

  friend CMonomio operator*(CMonomio a, CMonomio b);
  i32 operator()(i32 val);
};

ostream &operator<<(ostream &os, const CMonomio &Mono);

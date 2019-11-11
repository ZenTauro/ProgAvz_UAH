#include "CPolinomio.hpp"
#include "CMonomio.hpp"
#include "CTermino.hpp"
#include "types.hpp"

#include <vector>

CPolinomio::CPolinomio(vector<CMonomio> &monomios) {
  for (const auto &mon : monomios) {
    (*this) << mon;
  }
}

CPolinomio::CPolinomio(i32 c, u32 e) { *this << CMonomio{c, e}; }

CPolinomio::CPolinomio(CPolinomio const &poli) { (*this) = poli; }

CPolinomio::CPolinomio(CMonomio &mon) { *this << mon; }

CPolinomio &CPolinomio::operator<<(const CPolinomio &poli) {
  auto next = poli.head;

  while (next != NULL) {
    *this << next->GetMono();

    next = next->GetNext();
  }

  return *this;
}

bool CPolinomio::operator>(const CPolinomio &poli) const {
  return this->head < poli.head;
}

bool CPolinomio::operator<(const CPolinomio &poli) const {
  return this->head < poli.head;
}

CPolinomio &operator-(CPolinomio &self) {
  auto next = self.head;

  while (next != NULL) {
    next->SetCoef(-next->GetCoef());
    next = next->GetNext();
  }

  return self;
}

CPolinomio &operator-(CPolinomio &self, CPolinomio &other) {
  return self.operator<<(-other);
}

CPolinomio &operator+(CPolinomio &self, CPolinomio &other) {
  return self << other;
}

CPolinomio operator*(CPolinomio &self, CPolinomio &other) {
  auto next_1 = self.head;
  auto next_2 = other.head;
  CPolinomio temp;

  while (next_1 != NULL) {
    while (next_2 != NULL) {
      temp << (next_1->GetMono() * next_2->GetMono());

      next_2 = next_2->GetNext();
    }
    next_1 = next_1->GetNext();
  }

  return temp;
}

CPolinomio &operator-=(CPolinomio &one, CPolinomio &two) {
  one = -two;

  return one;
}

CPolinomio &CPolinomio::operator+=(CPolinomio &poli) noexcept {
  CPolinomio temp = *this;

  return temp << poli;
}

CPolinomio &CPolinomio::operator*=(CPolinomio &two) noexcept {
  *this = *this * two;

  return *this;
}

CPolinomio &CPolinomio::operator-=(CPolinomio &poli) noexcept {
  CPolinomio temp = *this;

  return temp << -poli;
}

void CPolinomio::operator=(const CPolinomio &poli) noexcept {
  auto next_mon = poli.head;

  if (this == &poli)
    return;

  // We first check if there is data in the datastructure, if there is
  // we proceed to free it to avoid memory leaks.
  if (this->head) {
    this->~CPolinomio();
  }
  (*this) << next_mon->GetMono();
}

CPolinomio &CPolinomio::operator<<(const CMonomio &mono) {
  if (mono.GetCoef() == 0)
    return *this;

  auto temp = new CTermino{CMonomio{mono}};
  auto next_pol = this->head;
  auto prev_pol = this->head;
  if (next_pol == NULL) {
    this->head = temp;
  }
  next_pol = prev_pol->GetNext();

  while (true) {
    if (next_pol != NULL) {
      if (next_pol->GetExp() == temp->GetExp()) {
        auto coef = temp->GetCoef() + next_pol->GetCoef();
        if (coef == 0) {
          prev_pol->SetNext(next_pol->GetNext());
          delete next_pol;

          break;
        }
        next_pol->SetCoef(coef);

        break;
      }
      if (temp->GetExp() > next_pol->GetExp()) {
        temp->SetNext(next_pol);
        prev_pol->SetNext(temp);

        break;
      }

      prev_pol = next_pol;
      next_pol = next_pol->GetNext();
      continue;
    }

    prev_pol->SetNext(temp);
    break;
  }

  return *this;
}

CPolinomio::~CPolinomio() {
  auto to_free = this->head;
  CTermino *next;

  while (true) {
    if (to_free == NULL)
      break;
    next = to_free->GetNext();
    delete to_free;
    to_free = next;
  }
}

i32 CPolinomio::operator[](u32 idx) {
  CMonomio val;
  auto next = this->head;

  while (next != NULL) {
    if (next->GetExp() == idx)
      return next->GetMono().GetCoef();
    next = next->GetNext();
  }

  return 0;
}

i32 CPolinomio::operator()(i32 val) {
  i32 acc = 0;
  auto next = this->head;

  while (next != NULL) {
    auto temp = next->GetMono();
    acc += temp(val);

    next = next->GetNext();
  }

  return 0;
}

ostream &operator<<(ostream &os, const CPolinomio &poli) {
  auto next = poli.head;

  while (next != NULL) {
    cout << next;
    next = next->GetNext();
  }

  return os;
}

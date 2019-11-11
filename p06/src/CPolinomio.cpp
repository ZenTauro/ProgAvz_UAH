#include "CPolinomio.hpp"
#include "CMonomio.hpp"
#include "types.hpp"

#include <vector>

CPolinomio::CPolinomio() {
  this->head = NULL;
}

CPolinomio::CPolinomio(vector<CMonomio> &monomios) {
  for (const auto& mon : monomios) {
    (*this) << mon;
  }
}

CPolinomio::CPolinomio(CPolinomio const &poli) {
  (*this) = poli;
}

void CPolinomio::operator=(const CPolinomio& poli) noexcept {
  auto next_mon = poli.head;

  // We first check if there is data in the datastructure, if there is
  // we proceed to free it to avoid memory leaks.
  if (this->head) {
    this->~CPolinomio();
  }
  (*this) << next_mon->GetMono();
}

CPolinomio& CPolinomio::operator<<(const CMonomio& mono) {
  if (mono.GetCoef() == 0) return *this;

  auto temp = new CTermino{CMonomio{mono}};
  auto next_pol = this->head;
  auto prev_pol = this->head;
  if (next_pol == NULL) {
    this->head = temp;
  }
  next_pol = prev_pol->GetNext();

  while(true) {
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

  while(true) {
    if (to_free == NULL) break;
    next = to_free->GetNext();
    delete to_free;
    to_free = next;
  }
}

ostream &operator<<(ostream &os, const CPolinomio &poli) {
  auto next = poli.next();

  while(next != NULL) {
    os << next;
  }

  return os;
}

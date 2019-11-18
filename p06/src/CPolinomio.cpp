#include "CPolinomio.hpp"
#include "CMonomio.hpp"
#include "CTermino.hpp"
#include "types.hpp"

#include <vector>

CPolinomio::CPolinomio(vector<CMonomio> &monomios) {
  this->head = NULL;
  for (const auto &mon : monomios) {
    (*this) << mon;
  }
}

CPolinomio::CPolinomio(i32 c, u32 e, CTermino *next) {
  this->head = next;
  *this << CMonomio{c, e};
}

CPolinomio::CPolinomio(CPolinomio const &poli) {
  this->head = NULL;
  (*this) = poli;
}

CPolinomio::CPolinomio(CMonomio &mon) {
  this->head = NULL;
  *this << mon;
}

CPolinomio &CPolinomio::operator<<(const CPolinomio &poli) {
  auto next = poli.head;

  while (next != NULL) {
    *this << next->GetMono();

    next = next->GetNext();
  }

  return *this;
}

bool CPolinomio::operator>(const CPolinomio &poli) const {
  return this->head > poli.head;
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
  return self.operator<<(other);
}

CPolinomio operator*(CPolinomio &self, CPolinomio &other) {
  auto next_1 = self.head;
  auto next_2 = other.head;
  auto temp = CPolinomio{};

  while (next_1 != NULL) {
    while (next_2 != NULL) {
      temp << (next_1->GetMono() * next_2->GetMono());

      next_2 = next_2->GetNext();
    }
    next_1 = next_1->GetNext();
  }

  return temp;
}

CPolinomio &operator-=(CPolinomio &one, CPolinomio &two) { return one << -two; }

CPolinomio &CPolinomio::operator+=(CPolinomio &poli) noexcept {
  return *this << poli;
}

CPolinomio &CPolinomio::operator*=(CPolinomio &two) noexcept {
  auto temp = *this * two;
  this->head = temp.head;
  temp.head = NULL;

  return *this;
}

CPolinomio &CPolinomio::operator-=(CPolinomio &poli) noexcept {
  return ((*this) << -poli);
}

void CPolinomio::operator=(const CPolinomio &poli) noexcept {
  auto next_mon = poli.head;

  if (this == &poli) {
    cout << "attempting to auto assign" << endl;

    return;
  }

  // We first check if there is data in the datastructure, if there is
  // we proceed to free it to avoid memory leaks.
  if (this->head) {
    this->~CPolinomio();
  }
  (*this) << next_mon->GetMono();
}

CPolinomio &CPolinomio::operator<<(const CMonomio &mono) {
  auto temp = new CTermino{mono};
  auto curr_pol = this->head;
  auto prev_pol = this->head;

  if (mono.GetCoef() == 0) {
    delete temp;
    return *this;
  }


  if (curr_pol == NULL) {
    this->head = temp;
    return *this;
  }
  if (prev_pol->GetExp() < temp->GetExp()) {
    temp->SetNext(prev_pol);
    this->head = temp;

    return *this;
  }
  if (prev_pol->GetExp() == temp->GetExp()) {
    prev_pol->SetCoef(prev_pol->GetCoef() + temp->GetCoef());
    if (prev_pol->GetCoef() == 0){
      this->head = prev_pol->GetNext();
      delete prev_pol;
    }

    delete temp;
    return *this;
  }

  curr_pol = prev_pol->GetNext();

  while (true) {
    // Check whether there is an element
    if (curr_pol != NULL) {
      // Check if the exponent is the same, if so, add them together
      if (curr_pol->GetExp() == temp->GetExp()) {
        auto coef = temp->GetCoef() + curr_pol->GetCoef();
        if (coef == 0) {
          prev_pol->SetNext(curr_pol->GetNext());
          delete curr_pol;
          delete temp;

          break;
        }
        curr_pol->SetCoef(coef);
        delete temp;

        break;
      }
      // Check if the current element is lower. If so, put it behind
      // the new element and add the new to the list.
      if (temp->GetExp() > curr_pol->GetExp()) {
        temp->SetNext(curr_pol);
        prev_pol->SetNext(temp);
        if (this->head == prev_pol) {
          this->head = temp;
        }

        break;
      }
      // We didn't find any terminating condition, compute the next one.
      prev_pol = curr_pol;
      curr_pol = curr_pol->GetNext();
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

  this->head = NULL;
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
    if (next == next->GetNext()) {
      cout << "\nBucle en la lista, esto no deberia de ocurrir" << endl;
      break;
    }

    cout << next->GetMono();
    next = next->GetNext();
  }

  return os;
}

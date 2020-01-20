#include "CCliente.hpp"
#include "types.hpp"
#include <cstdlib>
#include <cstring>

const uint32 DEFAULT_CAPACITY = 100;

template<typename T>
class CEmpresa {
private:
  T *m_pElem;
  int m_nElem;
  uint32 max_capacity;
public:
  CEmpresa() : m_nElem{0}, max_capacity(DEFAULT_CAPACITY), m_pElem{new T[DEFAULT_CAPACITY]{}} {};
  CEmpresa(const CEmpresa &a) {
    this->m_nElem = a.m_nElem;
    this->m_pElem = new T[a.m_nElem]{};
    for (uint32 i = 0; i < a.m_nElem; i++) {
      this->m_pElem[i] = a.m_pElem[i];
    }
  }

  void AgregarElemento(const T &elem) {
    if (m_nElem >= max_capacity) {
      auto tmp = new T[max_capacity * 2]{};
      memcpy(tmp, m_pElem, sizeof(T) * max_capacity);
      delete [] m_pElem;
      m_pElem = tmp;
    }
    m_pElem[m_nElem] = elem;
    m_nElem++;
  }

  int Size() const { return this->m_nElem; };
  T &GetElemento(int nElem) const {
    if(nElem < 0 || nElem >= m_nElem) {
      throw std::out_of_range("Out of range");
    }
    return m_pElem[nElem];
  };

  CEmpresa &operator=(const CEmpresa &a);
  T &operator[](int nElem) const {
    return this->GetElemento(nElem);
  };

  ~CEmpresa() {
    delete[] this->m_pElem;
  };
};

namespace cempresa {
  void from_file(CEmpresa<CCliente> &empresa, const string &path);
}

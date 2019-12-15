#pragma once

#include "CLista.hpp"

// Forward declaration of templated class
// this way we avoid a circular dependency problem
template <class T> class CLista;

template <class T>
class CNodoLista {
  friend CLista<T>;

private:
  T m_Dato;
  CNodoLista<T> *m_pSigNodo;

public:
  CNodoLista() { this->m_pSigNodo = nullptr; };
  CNodoLista(const T &obj, CNodoLista<T> *pNodo = nullptr) {
    this->m_Dato = obj;
    this->m_pSigNodo = pNodo;
  };
  CNodoLista(const CNodoLista<T> &NodoLista) {
    this->m_Dato = T{NodoLista.m_Dato};
    this->m_pSigNodo = nullptr;
  };

  inline CNodoLista<T> *GetSigNodo() const { return this->m_pSigNodo; };
  inline void SetSigNodo(CNodoLista<T> *pNodo) { this->m_pSigNodo = pNodo; };
  T &GetDato() { return m_Dato; };

  CNodoLista<T> &operator=(const CNodoLista<T> &NodoLista) {
    this->m_Dato = T{NodoLista.m_Dato};

    return *this;
  };

  ~CNodoLista() {
    this->m_pSigNodo = nullptr;
  };
};

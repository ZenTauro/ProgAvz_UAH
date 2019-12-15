#pragma once

// Forward declaration of templated class
// this way we avoid a circular dependency problem
template <class T> class CLista;

#include "CLista.hpp"

template <class T>
class CNodoLista {
  friend CLista<T>;

private:
  T m_Dato;
  CNodoLista<T> *m_pSigNodo;
  CNodoLista<T> *m_pPrvNodo;

public:
  CNodoLista() { this->m_pSigNodo = nullptr; };
  CNodoLista(const T &Obj, CNodoLista<T> *pNodo = nullptr);
  CNodoLista(const CNodoLista<T> &NodoLista);

  inline CNodoLista<T> *GetSigNodo() const { return this->m_pSigNodo; };
  inline CNodoLista<T> *GetPrvNodo() const { return this->m_pSigNodo; };
  inline void SetSigNodo(CNodoLista<T> *pNodo) { this->m_pSigNodo = pNodo; };
  inline void SetPrvNodo(CNodoLista<T> *pNodo) { this->m_pPrvNodo = pNodo; };
  T &GetDato() { return m_Dato; };

  CNodoLista<T> &operator=(const CNodoLista<T> &NodoLista);

  ~CNodoLista();
};

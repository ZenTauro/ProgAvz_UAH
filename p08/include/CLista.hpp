#pragma once

#include "CNodoLista.hpp"

// Forward declaration of templated class
// this way we avoid a circular dependency problem
template <class T> class CNodoLista;

template <class T>
class CLista {
private:
  CNodoLista<T> *m_Primero;
  CNodoLista<T> *m_Actual;
  CNodoLista<T> *m_Ultimo;

public:
  CLista();
  CLista(const T &Obj);
  CLista(const CLista<T> &Lista);

  inline bool EstaVacia() const { return m_Primero == nullptr; }
  inline bool TieneMas() const { return m_Actual != nullptr; };
  void AgregarObjeto(const T &Obj);
  void Vaciar() noexcept;
  void Restart() const;

  T &GetPrimero() const;
  T &GetActual() const;

  CLista<T> &operator=(const CLista<T> &Lista);

  ~CLista();
};


template <class T>
CLista<T>::CLista() {
  this->m_Actual = nullptr;
  this->m_Primero = nullptr;
  this->m_Ultimo = nullptr;
}

template <class T>
CLista<T>::CLista(const CLista<T> &lista) {
  this->m_Actual = nullptr;
  this->m_Primero = nullptr;
  this->m_Ultimo = nullptr;
  *this = lista;
}

template <class T>
CLista<T>::CLista(const T &obj) {
  this->m_Actual = nullptr;
  this->m_Primero = nullptr;
  this->m_Ultimo = nullptr;

  this->AgregarObjeto(obj);
}

template <class T>
CLista<T> &CLista<T>::operator=(const CLista<T> &Lista) {
  // vaciar lista referenciada por this
  this->Vaciar();
  if (!Lista.EstaVacia()) {
    // copiar el primer elemento y posicionar m_Actual
    m_Actual = m_Ultimo = m_Primero = new CNodoLista<T>{Lista.GetPrimero()};
    // copiar el resto de los elementos
    while (Lista.TieneMas()) {
      m_Actual->SetSigNodo(new CNodoLista<T>{Lista.GetActual()});
      m_Ultimo = m_Actual = m_Actual->GetSigNodo();
    }
  }

  return *this;
}

template <class T>
void CLista<T>::Vaciar() noexcept {
  if (this->m_Primero != nullptr) {
    auto current = this->m_Primero;
    CNodoLista<T> *next = nullptr;

    do {
      next = current->GetSigNodo();
      delete current;
      current = next;
    } while (next != nullptr);
  }

  this->m_Actual = nullptr;
  this->m_Primero = nullptr;
  this->m_Ultimo = nullptr;
}

template <class T>
void CLista<T>::Restart() const {
  this->m_Actual = this->m_Primero;
}

template <class T>
void CLista<T>::AgregarObjeto(const T &Obj) {
  if (EstaVacia()) {
    m_Primero = m_Actual = m_Ultimo = new CNodoLista<T>(Obj);
  } else {
    m_Ultimo->SetSigNodo(new CNodoLista<T>(Obj));
    m_Ultimo = m_Ultimo->GetSigNodo();
  }
}

template <class T>
T &CLista<T>::GetActual() const {
  CNodoLista<T> *temp = m_Actual;
  const_cast<CLista<T> *>(this)->m_Actual = m_Actual->GetSigNodo();
  return temp->GetDato();
}

template <class T>
T &CLista<T>::GetPrimero() const {
  const_cast<CLista<T> *>(this)->m_Actual = m_Primero->GetSigNodo();
  return m_Primero->GetDato();
}

template <class T>
CLista<T>::~CLista() {
  this->Vaciar();
}

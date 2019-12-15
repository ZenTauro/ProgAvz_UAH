#include "CLista.hpp"
#include "CNodoLista.hpp"

template <class T>
CLista<T>::CLista(const CLista<T> &lista) {
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
void CLista<T>::Vaciar() noexcept {
  if (this->m_Primero != nullptr) {
    auto current = this->m_Primero;
    CNodoLista<T> *next = nullptr;

    do {
      next = current->GetSigNodo();
      delete current;
    } while (next != nullptr);
  }

  this->m_Actual = nullptr;
  this->m_Primero = nullptr;
  this->m_Ultimo = nullptr;
}

template <class T>
CLista<T> &CLista<T>::operator=(const CLista<T> &Lista) {
  // vaciar lista referenciada por this
  this->Vaciar();
  if (!Lista.EstaVacia()) {
    // copiar el primer elemento y posicionar m_Actual
    m_Actual = m_Ultimo = m_Primero = new CNodoLista<T>(Lista.GetPrimero());
    // copiar el resto de los elementos
    while (Lista.TieneMas()) {
      m_Actual->SetSigNodo(new CNodoLista<T>(Lista.GetActual()));
      m_Ultimo = m_Actual = m_Actual->GetSigNodo();
    }
  }

  return *this;
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

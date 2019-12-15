#pragma once

#include "CNodoLista.hpp"

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

  bool EstaVacia() const { return m_Primero == nullptr; }
  bool TieneMas() const { return m_Actual != nullptr; };
  void AgregarObjeto(const T &Obj);
  void Vaciar() noexcept;
  void Restart() const;

  T &GetPrimero() const;
  T &GetActual() const;

  CLista<T> &operator=(const CLista<T> &Lista);

  ~CLista();
};

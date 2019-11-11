#pragma once

#include "CMonomio.hpp"
#include "types.hpp"

class CTermino {
private:
  CMonomio monomio;
  CTermino *next;

public:
  // Constructors

  /**
   * Simplemente pasamos monomio ya que cabe en una direccion.
   * El comportamiento es exactamente el mismo que un const CMonomio&
   * pero nos evitamos una indireccion
   */
  inline CTermino(const CMonomio& monomio) {};

  /**
   * Construimos el objecto a partir de un coeficiente, exponente y el
   * siguiente nodo, todos inicializados a 0 por defecto.
   */
  inline CTermino(i32 coef=0, u32 exp=0, CTermino *next=NULL);

  inline CTermino(CTermino &term, CTermino *next=NULL);

  // Getters/Setters
  inline i32 GetCoef() const { return this->monomio.GetCoef(); }
  inline u32 GetExp() const { return this->monomio.GetExp(); }
  inline CMonomio GetMono() const { return this->monomio; }
  inline CTermino* GetNext() const { return this->next; }

  inline void SetCoef(i32 coef) { this->monomio.SetCoef(coef); }
  inline void SetExp(u32 exp) { this->monomio.SetExp(exp); }
  inline void SetMono(const CMonomio& mono) { this->monomio = mono; }
  inline void SetNext(CTermino * sig) { this->next = sig; }
};

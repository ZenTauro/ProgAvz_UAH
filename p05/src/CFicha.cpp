#include <CFicha.hpp>
#include <CHora.hpp>
#include <StrUtils.hpp>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

CFicha::CFicha(const string &sNombre, int nEdad, int nHoras, int nMinutos,
               int nSegundos, const string &sFormato) {
  auto temp = sFormato;
  auto hora = CHora{nHoras, nMinutos, nSegundos, sFormato.c_str()};

  this->m_sNombre = sNombre;
  this->m_nEdad = nEdad;
  this->m_horaNacio = hora;
}

void CFicha::AsignarNombre(const string &sNombre) {
  this->m_sNombre = sNombre;
}

string CFicha::ObtenerNombre() const {
  return this->m_sNombre;
}

void CFicha::AsignarEdad(int nEdad) {
  if (nEdad < 0) throw invalid_argument("Negative age is not allowed");

  this->m_nEdad = nEdad;
}

int CFicha::ObtenerEdad() const {
  return this->m_nEdad;
}

bool CFicha::AsignarNacio(int nHoras, int nMinutos, int nSegundos,
                          const string &sFormato) {
  auto hora = CHora{nHoras, nMinutos, nSegundos, sFormato.c_str()};

  this->m_horaNacio = hora;

  return hora.EsHoraCorrecta();
}

CHora CFicha::ObtenerNacio() const {
  return this->m_horaNacio;
}

void VisualizarHora(CFicha& ficha) {
  int hh=0, mm=0, ss=0;
  char *fmt = new char[10]();

  ficha.ObtenerNacio().ObtenerHora(hh, mm, ss, fmt);

  cout << ficha.ObtenerNombre() << ": " << ficha.ObtenerEdad() << " " << hh
       << ":" << mm << ":" << ss << " " << fmt << endl;

  delete[] fmt;
}

void CFicha::operator=(CFicha &obj) {
  this->m_nEdad = obj.m_nEdad;
  this->m_sNombre = obj.m_sNombre;
  this->m_horaNacio = obj.m_horaNacio;
}

#include <CHora.hpp>
#include <cstring>
#include <iostream>

using namespace std;

const char *const AM = "AM";
const char *const PM = "PM";
const char *const H24 = "24 Horas";

bool CHora::AsignarFormato(const char *const pszFormato) {
  try {
    if (this->m_pszFormato != NULL) {
      delete[] this->m_pszFormato;
    }

    int8_t size = pszFormato[1] == 'M' || pszFormato[1] == 'm' ? 2 : 8;

    this->m_pszFormato = new char[size];
    for (uint8_t i = 0; i < size; i++) {
      this->m_pszFormato[i] = toupper(pszFormato[i]);
    }
    return true;
  } catch (exception &e) {
    return false;
  }
}

bool CHora::Formato24() const {
  if (strncmp(this->m_pszFormato, H24, sizeof(char) * 8)) {
    return true;
  } else
    return false;
}

bool CHora::EsHoraCorrecta() const {
  if (strncmp(this->m_pszFormato, AM, 2 * sizeof(char)) ||
      strncmp(this->m_pszFormato, PM, 2 * sizeof(char))) {
    if (!(this->m_nHoras < 1 || this->m_nHoras > 12 || this->m_nMinutos < 0 ||
          this->m_nMinutos > 60 || this->m_nSegundos < 0 ||
          this->m_nSegundos > 60)) {

      return true;
    }
  } else {
    if (EsHoraCorrecta()) {
      if (!(this->m_nHoras < 0 || this->m_nHoras > 23 || this->m_nMinutos < 0 ||
            this->m_nMinutos > 60 || this->m_nSegundos < 0 ||
            this->m_nSegundos > 60)) {

        return true;
      }
    }
  }

  return false;
}

void CHora::Iniciar() {
  this->m_nHoras = 0;
  this->m_nMinutos = 0;
  this->m_nSegundos = 0;
  if (this->m_pszFormato) {
    delete[] this->m_pszFormato;
  }
  this->m_pszFormato = NULL;
}

bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos,
                        char *pszFormato) {
  if (!AsignarFormato(pszFormato))
    return false;

  this->m_nHoras = nHoras;
  this->m_nMinutos = nMinutos;
  this->m_nSegundos = nSegundos;

  return this->EsHoraCorrecta();
}

void CHora::ObtenerHora(int &nHoras, int &nMinutos, int &nSegundos,
                        char *pszFormato) const {
  nHoras = this->m_nHoras;
  nMinutos = this->m_nMinutos;
  nSegundos = this->m_nSegundos;

  uint8_t size = strnlen(this->m_pszFormato, sizeof(char) * 8);
  for (uint8_t i = 0; i < size; i++) {
    pszFormato[i] = this->m_pszFormato[i];
  }
}

void CHora::Destruir() {
  if (this->m_pszFormato) {
    delete[] this->m_pszFormato;
    this->m_pszFormato = NULL;
  }
}

CHora::CHora() { Iniciar(); }

CHora::~CHora() { Destruir(); }

#include <CHora.hpp>
#include <cstring>
#include <iostream>

using namespace std;

const char *const AM = "AM";
const char *const PM = "PM";
const char *const H24 = "24 HORAS";

bool CHora::AsignarFormato(const char *const pszFormato) {
  try {
    if (pszFormato == NULL) {
      cout << "Invalid memory direction" << endl;
      return false;
    };
    if (this->m_pszFormato != NULL) {
      delete[] this->m_pszFormato;
    }

    int8_t size = pszFormato[1] == 'M' || pszFormato[1] == 'm' ? 2 : 9;

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
  if ( this->m_pszFormato[1] == 'M' &&
     ( this->m_pszFormato[0] == 'A' || this->m_pszFormato[0] == 'P' )) {
    if (!(this->m_nHoras < 1 || this->m_nHoras > 12 || this->m_nMinutos < 0 ||
          this->m_nMinutos > 60 || this->m_nSegundos < 0 ||
          this->m_nSegundos > 60)) {

      return true;
    }
  }

  if (strncmp(this->m_pszFormato, H24, 8 * sizeof(char)) == 0) {
    if (!(this->m_nHoras < 0 || this->m_nHoras > 23 || this->m_nMinutos < 0 ||
          this->m_nMinutos > 60 || this->m_nSegundos < 0 ||
          this->m_nSegundos > 60)) {

      return true;
    }
  }

  return false;
}

void CHora::Iniciar() {
  this->m_nHoras = 0;
  this->m_nMinutos = 0;
  this->m_nSegundos = 0;
  this->m_pszFormato = NULL;
}

bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos,
                        const char *const pszFormato) {
  if (!AsignarFormato(pszFormato)) {
    return false;
  }

  this->m_nHoras = nHoras;
  this->m_nMinutos = nMinutos;
  this->m_nSegundos = nSegundos;

  return this->EsHoraCorrecta();
}

void CHora::ObtenerHora(int &nHoras, int &nMinutos, int &nSegundos,
                        char *pszFormato) const {
  if (this->m_pszFormato == NULL) {
    std::cout << "Hora no inicializada" << endl;

    *pszFormato = 0;

    return;
  }

  nHoras    = this->m_nHoras;
  nMinutos  = this->m_nMinutos;
  nSegundos = this->m_nSegundos;

  uint8_t size = strnlen(this->m_pszFormato, sizeof(char) * 8);

  // Se optimiza por una llamada a memcpy
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

#include "CHora.hpp"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

const char AM[] = "AM";
const char PM[] = "PM";
const char H24[] = "24 HORAS";

bool CHora::AsignarFormato(const char *const pszFormato) {
  try {
    if (pszFormato == NULL) {
      cout << "Invalid memory direction" << endl;
      return false;
    };
    if (this->m_pszFormato.length() == 0) {
      this->m_pszFormato.clear();
    }

    this->m_pszFormato = pszFormato;

    std::transform(this->m_pszFormato.begin(), this->m_pszFormato.end(),
                   this->m_pszFormato.begin(), ::toupper);

    return true;
  } catch (exception &e) {
    return false;
  }
}

bool CHora::Formato24() const {
  if (this->m_pszFormato == H24) {
    return true;
  } else
    return false;
}

bool CHora::EsHoraCorrecta() const {
  if (this->m_pszFormato == AM || this->m_pszFormato == PM) {
    if (!(this->m_nHoras < 1 || this->m_nHoras > 12 || this->m_nMinutos < 0 ||
          this->m_nMinutos > 60 || this->m_nSegundos < 0 ||
          this->m_nSegundos > 60)) {

      return true;
    }
  }

  if (this->m_pszFormato == H24) {
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
  this->m_pszFormato = string{};
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
  auto size = this->m_pszFormato.length();
  if (size == 0) {
    std::cout << "Hora no inicializada" << endl;

    *pszFormato = 0;

    return;
  }

  nHoras    = this->m_nHoras;
  nMinutos  = this->m_nMinutos;
  nSegundos = this->m_nSegundos;

  // Se optimiza por una llamada a memcpy
  for (uint8_t i = 0; i < size; i++) {
    pszFormato[i] = this->m_pszFormato[i];
  }
}


void CHora::operator=(CHora &obj){
  this->m_nHoras = obj.m_nHoras;
  this->m_nMinutos = obj.m_nMinutos;
  this->m_nSegundos = obj.m_nSegundos;
  // Asumimos que los objetos solo pueden ser creados
  // con formato correcto
  this->m_pszFormato = obj.m_pszFormato;
}

bool CHora::operator==(const CHora &hora) const {
  if (this->m_nHoras == hora.m_nHoras &&
      this->m_nMinutos == hora.m_nMinutos &&
      this->m_nSegundos == hora.m_nSegundos) {
    return true;
  }
  return false;
}

CHora::~CHora() {}

CHora::CHora(int hora, int min, int seg, const char *formato) {
  this->m_nHoras = hora;
  this->m_nMinutos = min;
  this->m_nSegundos = seg;
  AsignarFormato(formato);

  // cout << "Fmt: " << this->m_pszFormato << " " << m_nHoras << ":" << m_nMinutos << ":" << m_nSegundos << endl;

  if (!EsHoraCorrecta()) {
    this->m_pszFormato.clear();
  }
}

CHora::CHora(const CHora &obj) {
  this->m_nHoras = obj.m_nHoras;
  this->m_nMinutos = obj.m_nMinutos;
  this->m_nSegundos = obj.m_nSegundos;
  // Asumimos que los objetos solo pueden ser creados
  // con formato correcto
  this->m_pszFormato = obj.m_pszFormato;
}

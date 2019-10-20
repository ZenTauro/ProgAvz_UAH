#pragma once
#include <string>

class CHora {
private:
  /// AM/PM: 1 a 12,  24 HORAS: 0 a 23
  int m_nHoras;
  /// AM/PM/24 HORAS: 0 a 59
  int m_nMinutos;
  /// AM/PM/24 HORAS: 0 a 59
  int m_nSegundos;
  /// Almacena los valores "AM", "PM" o "24 HORAS"
  std::string m_pszFormato;

  /// Verifica que pszFormato no es nulo.
  /// Copia en m_pszFormato el formato dado por pszFormato,
  /// asignando la cantidad de memoria necesaria, y lo convierte
  /// a mayúsculas. Si fuera necesario, previamente se liberará
  /// la memoria que hubiera asignada. Devuelve true si la
  /// operación se realiza con éxito y false en caso contrario.
  bool AsignarFormato(const char *const pszFormato);

  /// Devuelve true si el formato es "24 HORAS".
  /// En otro caso, devuelve false.
  bool Formato24() const;

public:
  /// Verifica si una hora es correcta:
  /// 1) verificar que el formato es 24 HORAS, AM o PM
  /// 2) y verificar que las horas, minutos y segundos están dentro
  /// de los límites según el formato sea o no 24 HORAS.
  /// Devuelve true si es correcta y false en otro caso.
  bool EsHoraCorrecta() const;

  /// Será invocada cada vez que se defina un objeto.
  /// Pone a 0 todos los atributos de CHora.
  void Iniciar();

  /// Recibe 4 argumentos, correspondientes a una hora,
  /// y los almacena en las variables
  /// m_nHoras, m_nMinutos, m_nSegundos y m_pszFormato
  /// correspondientes al objeto que recibe el mensaje.
  ///
  /// Invoca a AsignarFormato y a EsHoraCorrecta.
  /// Devuelve false si no pudo ser asignado el formato
  /// o el valor retornado por EsHoraCorrecta.
  bool AsignarHora(int nHoras, int nMinutos, int nSegundos,
                   const char *const pszFormato);

  /// Obtener una hora. Permite obtener los datos hora,
  /// minutos, segundos y formato correspondientes
  /// al objeto que recibe el mensaje.
  void ObtenerHora(int &nHoras, int &nMinutos, int &nSegundos,
                   char *pszFormato) const;

  /// Libera la memoria reservada dinámicamente para un objeto y
  /// pone el puntero m_pszFormato a cero.
  void Destruir();

  void operator=(CHora&);

  CHora();
  CHora( const CHora &obj );
  CHora(int hora = 0, int min = 0, int seg = 0, const char * = "24 HORAS");
  ~CHora();
};

#ifndef HPP_UTILS
#define HPP_UTILS

#include <iostream>
namespace utils {
  enum MenuOps { introducir=1, visualizar=2, terminar=3, other };

  int     CrearMenu(const char *const opciones_menu[], int num_opciones);
  MenuOps LeerEntrada();
  float   LeerFloat();
  void    LeerCadena(char *c, int n);
  char   *ConverMayus(char *str);

  std::string &ConverMayus(std::string & str);

  void clear();
  void pause();
}
#endif

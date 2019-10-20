#pragma once

#include <iostream>

namespace utils {
  enum MenuOps { introducir=1, visualizar=2, terminar=3, other };

  class CUtils {
    static int CrearMenu(const char *const opciones_menu[], int num_opciones);
    static MenuOps LeerEntrada() throw();
    static bool LeerInt(int*);
    static bool LeerCadena(char *c, int n);
    static char *ConverMayus(char *str);

    static std::string &ConverMayus(std::string &str);

    static void clear();
    static void pause();
  };
}

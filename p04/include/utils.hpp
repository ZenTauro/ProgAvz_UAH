#pragma once

#include <iostream>

enum class Menu { other };

namespace utils {
enum MenuOps1 {
  local = 1,
  dyn = 2,
  copy = 3,
  asignacion = 4,
  other
};
enum MenuOps2 {
  predeterminada = 1,
  param1 = 2,
  param2 = 3,
  param3 = 4,
  param4 = 5,
  ret
};

class CUtils {
public:
  static int CrearMenu(const char *const opciones_menu[], int num_opciones);
  static MenuOps2 LeerEntrada2();
  static MenuOps1 LeerEntrada1();
  static bool LeerInt(int *);
  static bool LeerCadena(char *c, int n);
  static char *ConverMayus(char *str);

  static std::string &ConverMayus(std::string &str);

  static void clear();
  static void pause();
};
} // namespace utils


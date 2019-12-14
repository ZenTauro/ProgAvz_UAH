#pragma once

#include "types.hpp"
#include <iostream>

enum class Menu { other };

namespace utils {
enum class MenuOps1 {
  EnterEmploy = 1,
  EnterClient = 2,
  FindByName = 3,
  ShowReg = 4,
  ShowEmploy = 5,
  MakeCopy = 6,
  RestoreCopy = 7,
  Exit = 8,
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
  static bool LeerString(std::string &s);
  static char *ConverMayus(char *str);
  static bool LeerUInt(uint32 *ret);

  static std::string &ConverMayus(std::string & str);

  static void clear();
  static void pause();
};
} // namespace utils

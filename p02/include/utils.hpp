#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include <CMatFloat.hpp>

namespace utils {
  void clear();
  void pause();

  void menu();
  std::tuple<int, int> auxMatrixConstructor();
  template <typename A, typename B, typename C, typename D>
  inline void opts(A construir, B introducir, C volcar, D destruir);
} // namespace utils

template <typename A, typename B, typename C, typename D>
inline void utils::opts(A construir, B introducir, C volcar, D destruir) {
  // Para capturar las opciones utilizamos un string que luego pasaremos
  // a op para poder capturar las excepciones que pueda generar.
  std::string opt;
  int op = 0;

  while (op != 5) {
    utils::menu();
    std::cin >> opt;

    try {
      // Pasamos opt a int con stoi para capturar las excepciones en caso
      // de que la entrada sea invalida.
      op = stoi(opt);
    } catch (std::exception &) {
      // Si la entrada es invalida simplemente pedimos otra seleccion
      std::cout << "Seleccione una opcion del menu";
      continue;
    }

    switch (op) {
    case 1:
      construir();
      break;
    case 2:
      introducir();
      break;
    case 3:
      volcar();
      break;
    case 4:
      destruir();
      break;
    case 5:
      continue;
    default:
      continue;
    }

    utils::pause();
    utils::clear();
  }

  destruir();
}

#endif // UTILS_HPP

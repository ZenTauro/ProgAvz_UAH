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

#endif // UTILS_HPP

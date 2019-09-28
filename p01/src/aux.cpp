#include <cstdlib>
#include <iostream>

/**
 * Limpia la pantalla
 */
void clear() {
#ifdef __unix__
  std::cout << "\x1B[2J\x1B[H";
#else
  std::system("cls");
#endif
}

/**
 * Pausa hasta que se pulsa enter
 */
void pause() {
  // Para prevenir que los enter introducidos anteriormente interfieran con
  // cin.get()
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout << "Presiona enter para continuar...";
  std::cin.get();
}

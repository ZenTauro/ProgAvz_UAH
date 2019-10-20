#include <iostream>
#include <utils.hpp>
#include <istream>
#include <string>

namespace utils {
    /**
     * Limpia la pantalla
     */
  void CUtils::clear() {
#ifdef __unix__
      std::cout << "\x1B[2J\x1B[H";
#else
      std::system("cls");
#endif
  }

  /**
   * Pausa hasta que se pulsa enter
   */
  void CUtils::pause() {
    // Para prevenir que los enter introducidos anteriormente interfieran con
    // cin.get()
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Presiona enter para continuar...";
    std::cin.get();
  }

  /**
   * Given a number of strings prints them in a menu
   */
  int CUtils::CrearMenu(const char *const opciones_menu[], int num_opciones) {
    for( uint8_t i = 0; i < num_opciones; i++ )
      std::cout << " " << i + 1 << ". " << opciones_menu[i] << std::endl;
    std::cout << std::endl << "propmt> ";

    return 0;
  }

  MenuOps CUtils::LeerEntrada() throw() {
    uint8_t a; MenuOps ret;
    auto buffer = std::string{};

    std::cin >> buffer;

    try {
      a = std::stoi(buffer);
      ret = static_cast<MenuOps>(a);
    } catch (std::exception &e) {
      ret = MenuOps::other;
    }

    return ret;
  }

  bool CUtils::LeerInt(int *ret) {
    uint8_t a;
    auto buffer = std::string{};

    if (ret == NULL) {
      return false;
    }

    std::cin >> buffer;
    if (std::cin.eof()) {
      return false;
    }

    try {
      a = std::stoi(buffer);
    } catch (std::exception &e) {
      *ret = 0;
      return false;
    }

    *ret = a;
    return true;
  }

  bool CUtils::LeerCadena(char *c, int n) {
    if (c == NULL) {
      return false;
    }

    std::cin.exceptions(std::ios::failbit | std::ios::badbit);
    std::cin.clear();
    try {
      std::cin.getline(c, n, '\n');
      if (std::cin.eof()) {
        return false;
      }
      std::cin.ignore(std::numeric_limits<int>::max(), '\n');
      std::cin.exceptions(std::ios::goodbit);
    } catch (std::exception &e) {
      std::cout << "Something bad happened" << std::endl;
    }

    return true;
  }
} // namespace utils

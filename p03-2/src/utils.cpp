#include <iostream>
#include <utils.hpp>
#include <istream>
#include <string>

namespace utils {
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

  /**
   * Given a number of strings prints them in a menu
   */
  int CrearMenu(const char *const opciones_menu[], int num_opciones) {
    for( uint8_t i = 0; i < num_opciones; i++ )
      std::cout << " " << i + 1 << ". " << opciones_menu[i] << std::endl;
    std::cout << std::endl << "propmt> ";

    return 0;
  }

  MenuOps LeerEntrada() throw() {
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

  int LeerInt() {
    uint8_t a;
    auto buffer = std::string{};

    std::cin >> buffer;

    try {
      a = std::stoi(buffer);
    } catch (std::exception &e) {
      throw;
    }

    return a;
  }

  void LeerCadena(char *c, int n) {
    std::cin.ignore(100000, '\n');
    std::cin.clear();


    std::cin.getline(c, n, '\n');
    if (false) {
      std::cin.setstate(std::ios::failbit);
    }
  }
} // namespace utils

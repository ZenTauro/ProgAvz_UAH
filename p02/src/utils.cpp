#include <optional>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include <iostream>
#include <string>
#include <CMatFloat.hpp>

using namespace std;

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

  void menu() {
    cout << "Selecciones operacion: " << endl
         << endl
         << "1. Construir matriz" << endl
         << "2. Introducir matriz" << endl
         << "3. Volcar matriz" << endl
         << "4. Destruir matriz" << endl
         << "5. Terminar" << endl;

  }

  std::tuple<int, int> auxMatrixConstructor() {
    int nfilas = 0, ncol = 0;

    cout << "introduzca numero de filas: ";
    cin >> nfilas;
    cout << "introduzca numero de columnas: ";
    cin >> ncol;
    cout << endl;

    auto res = std::make_tuple(nfilas, ncol);

    return res;
  }

  template <typename A, typename B, typename C, typename D>
  inline void opts(A construir, B introducir, C volcar, D destruir) {
    // Para capturar las opciones utilizamos un string que luego pasaremos
    // a op para poder capturar las excepciones que pueda generar.
    std::string opt;
    int op = 0;

    while (op != 5) {
      menu();
      cin >> opt;

      try {
        // Pasamos opt a int con stoi para capturar las excepciones en caso
        // de que la entrada sea invalida.
        op = stoi(opt);
      } catch(exception &) {
        // Si la entrada es invalida simplemente pedimos otra seleccion
        cout << "Seleccione una opcion del menu";
        continue;
      }

      switch (op) {
      case 1  : construir();  break;
      case 2  : introducir(); break;
      case 3  : volcar();     break;
      case 4  : destruir();   break;
      case 5  : continue;
      default : continue;
      }

      pause();
      clear();
    }
  }
}

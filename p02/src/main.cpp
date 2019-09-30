#include <CMatFloat.hpp>
#include <iostream>
#include <limits>
#include <string>
#include <tuple>

#include <utils.hpp>

using namespace std;

template <typename A, typename B, typename C, typename D>
inline void opts(A construir, B introducir, C volcar, D destruir) {
  // Para capturar las opciones utilizamos un string que luego pasaremos
  // a op para poder capturar las excepciones que pueda generar.
  std::string opt;
  int op = 0;

  while (op != 5) {
    utils::menu();
    cin >> opt;

    try {
      // Pasamos opt a int con stoi para capturar las excepciones en caso
      // de que la entrada sea invalida.
      op = stoi(opt);
    } catch (exception &) {
      // Si la entrada es invalida simplemente pedimos otra seleccion
      cout << "Seleccione una opcion del menu";
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
}

int main() {
  auto mat = CMatFloat{};

  opts(
      [&mat]() -> void {
        int nfilas, ncol;
        mat.Init();
        tie(nfilas, ncol) = utils::auxMatrixConstructor();
        cout << nfilas << " " << ncol << endl;
        mat.Build2DMatrix(nfilas, ncol);
      },
      [&mat]() -> void {
        mat.Enter();
      },
      [&mat]() -> void {
        mat.Show();
      },
      [&mat]() -> void {
        mat.Destroy();
      });
}

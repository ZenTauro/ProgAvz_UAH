#include <iostream>
#include <string>
#include <limits>
#include <tuple>

#include <matrix.h>

using namespace std;

int main() {
  auto matrix = floatMatrix();
  string opt;
  int op = 0;

  while (op != 5) {
    cout << "Selecciones operacion: " << endl << endl
         << "1. Construir matriz" << endl
         << "2. Introducir matriz" << endl
         << "3. Volcar matriz" << endl
         << "4. Destruir matriz" << endl
         << "5. Terminar" << endl;

    cin >> opt;

    try {
      op = stoi(opt);
    } catch(exception &) {
      cout << "Seleccione una opcion del menu";
      continue;
    }

    switch (op) {
    case 1 : {
      int nfilas, ncol;
      if (matrix.mtr.has_value()) {
        cout << "la matriz existe, destruyela para crear otra" << endl;
        break;
      }

      tie (nfilas, ncol) = auxMatrixConstructor();
      try {
        matrix.mtr = ConstruirMatriz(nfilas, ncol);
      } catch(exception &) {
        cout << "No se pudo crear la matriz, intente de nuevo";
      }

      break;
    }
    case 2 : matrix.modify();
      cout << "Modificando matriz" << endl;
      break;
    case 3 : matrix.show(); break;
    case 4 : matrix.remove(); break;
    case 5 : continue;
    default : continue;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    std::cout << "Presiona enter para continuar...";
    std::cin.get();

    std::cout << "\x1B[2J\x1B[H";
  }
}

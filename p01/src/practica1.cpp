#include <iostream>
#include <string>
#include <limits>

#include <funciones.h>

using namespace std;

int main() {
  MatFloat mat{0, 0, NULL};
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
        if (mat.ppMatriz != NULL) {
          cout << "La matriz existe, destruyela para crear otra" << endl;
          break;
        }
        int nfilas = 0, ncol = 0;
        cout << "Introduzca numero de filas: ";
        cin >> nfilas;
        cout << "Introduzca numero de columnas: ";
        cin >> ncol;
        cout << endl;

        mat.nFilas = nfilas;
        mat.nColumnas = ncol;
        mat.ppMatriz = ConstruirMatriz(nfilas, ncol);

        if (mat.ppMatriz == NULL) {
          return -1;
        };

        break;
      }
    case 2 : IntroducirDatos(&mat); break;
    case 3 : Mostrar(mat); break;
    case 4 : Destruir(&mat); break;
    case 5 : continue;
    default : continue;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    std::cout << "Presiona enter para continuar...";
    std::cin.get();

    std::cout << "\x1B[2J\x1B[H";
  }

  if (mat.ppMatriz != NULL) {
    Destruir(&mat);
  }
}

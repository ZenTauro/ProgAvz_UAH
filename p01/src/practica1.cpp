#include <iostream>
#include <string>
#include <limits>

#include <aux.h>
#include <funciones.h>

using namespace std;

int main() {
  // Declaracion de variables
  // Inicializamos la matriz con 0, 0, NULL para indicar que esta vacia
  MatFloat mat{0, 0, NULL};
  // Para capturar las opciones utilizamos un string que luego pasaremos
  // a op para poder capturar las excepciones que pueda generar.
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
      // Pasamos opt a int con stoi para capturar las excepciones en caso
      // de que la entrada sea invalida.
      op = stoi(opt);
    } catch(exception &) {
      // Si la entrada es invalida simplemente pedimos otra seleccion
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

        // En caso de no poder reservar memoria abortamos el programa retornando
        // 1 como codigo de error
        if (mat.ppMatriz == NULL) {
          return 1;
        };

        break;
      }
    case 2  : IntroducirDatos(&mat); break;
    case 3  : Mostrar        ( mat); break;
    case 4  : Destruir       (&mat); break;
    case 5  : continue;
    default : continue;
    }

    pause();
    clear();
  }

  // En el caso que la memoria usada por la matriz no haya sido liberada
  // la liberamos, para que no haya fugas de memoria
  if (mat.ppMatriz != NULL) {
    Destruir(&mat);
  }
}

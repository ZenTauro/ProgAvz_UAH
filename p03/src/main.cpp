#include <CHora.hpp>
#include <iostream>
#include <utils.hpp>

using namespace std;



int main() {
  static const char *const menu_ops[30] =
    { "Introducir hora", "Visualizar hora", "Terminar" };

  auto hora = CHora{};
  hora.Iniciar();

  cout << "C makes it easy to shoot yourself in the foot; C++ makes it" << endl
       << "harder, but when you do it blows your whole leg off" << endl
       << "  - Bjarne Stroustrup" << endl << endl;

  utils::MenuOps opt;
  bool keep = true;
  while(keep) {
    utils::CrearMenu(menu_ops, 3);
    opt = utils::LeerEntrada();

    switch (opt) {
    case utils::MenuOps::introducir: {

      break;
    };
    case utils::MenuOps::visualizar: {

      break;
    };
    case utils::MenuOps::terminar: {
      cout << "Finalizando" << endl;

      keep = false;
      break;
    };
    case utils::MenuOps::other: {
      cout << "Opcion no reconocida, vuelva a introducir" << endl;
      break;
    };
    }

    utils::pause();
    utils::clear();
  }

  return 0;
}

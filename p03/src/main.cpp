#include <CHora.hpp>
#include <iostream>
#include <utils.hpp>
#include <string>

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
      int h, m, s;
      auto buffer = string{};
      auto line = new char[10];
      try {
        cout << "Hora: ";
        h = utils::LeerInt();
        cout << "Minutos: ";
        m = utils::LeerInt();
        cout << "Segundos: ";
        s = utils::LeerInt();

        cout << "Formato: ";
        utils::LeerCadena(line, 10);
      } catch (exception &e) {
        cout << "Entrada no valida" << endl;
        break;
      }

      if (!hora.AsignarHora(h, m, s, line)) {
        cout << line << '*' << endl;
        cout << "Formato de fecha invalido" << endl;
      }

      break;
    };
    case utils::MenuOps::visualizar: {
      int h, m, s;
      char *f = new char[8];
      hora.ObtenerHora(h, m, s, f);

      if (f[0] == 0) break;

      cout << " " << h << ":" << m << ":" << s << " " << f << endl;
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

#include <CFicha.hpp>
#include <StrUtils.hpp>
#include <iostream>
#include <utils.hpp>
#include <vector>

using namespace std;

const char *opts[3] = {"Crear una ficha", "Visualizar ficha", "Terminar"};
const char *prompt = "Seleccion> ";

int main() {
  bool keep = true;
  int opt = 0;
  CFicha ficha = CFicha{};

  while (keep) {
    utils::CUtils::CrearMenu(opts, 3);

    cout << prompt;
    utils::CUtils::LeerInt(&opt);

    switch (opt) {
    case 1: {
      auto nombre = string{};
      auto formato = string{};
      int hh = 0, mm = 0, ss = 0, edad = 0;

      cout << "Nombre: ";
      utils::CUtils::LeerString(nombre);
      cout << "Formato: ";
      utils::CUtils::LeerString(formato);
      cout << "Hora: ";
      utils::CUtils::LeerInt(&hh);
      cout << "Minutos: ";
      utils::CUtils::LeerInt(&mm);
      cout << "Segundos: ";
      utils::CUtils::LeerInt(&ss);
      cout << "Edad: ";
      utils::CUtils::LeerInt(&edad);

      auto tmp = string(formato);

      trim(tmp);
      trim(nombre);

      auto temp = CFicha{nombre, edad, hh, mm, ss, tmp};
      ficha = temp;

      break;
    }

    case 2: {
      VisualizarHora(ficha);
      break;
    }

    case 3: {
      keep = false;
      break;
    }

    default: {
      cout << "Seleccione una opcion" << endl;
      break;
    }
    }

    utils::CUtils::pause();
    utils::CUtils::clear();
  }

  return 0;
}

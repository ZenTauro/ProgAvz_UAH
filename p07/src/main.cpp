#include "CCliente.hpp"
#include "CEmpleado.hpp"
#include "CHora.hpp"
#include "CRegistroDiario.hpp"
#include "types.hpp"
#include "utils.hpp"
#include <iostream>

using namespace std;
using namespace utils;

const uint32 MENU_ENTRIES = 8;
const char *menu1[MENU_ENTRIES] = {
  "Introducir empleado",
  "Introducir cliente",
  "Buscar por nombre",
  "Mostrar registro diario",
  "Mostrar empleados",
  "Copa de seguridad del registro diario",
  "Restaurar copia de seguridad",
  "Salir"
};

int main() {
  auto reg = CRegistroDiario{512};
  CRegistroDiario *backup = nullptr;
  MenuOps1 choice = MenuOps1::other;

  while(choice != MenuOps1::Exit) {
    CUtils::CrearMenu(menu1, MENU_ENTRIES);
    choice = CUtils::LeerEntrada1();

    switch(choice) {
    case MenuOps1::EnterEmploy: {
      string name = string{};
      cout << "Enter name: ";
      CUtils::LeerString(name);
#ifndef NDEBUG
      cout << "Name read: " << name << "\n";
#endif

      string category = string{};
      cout << "Enter category: ";
      CUtils::LeerString(category);
#ifndef NDEBUG
      cout << "Category read: " << category << "\n";
#endif

      uint32 seniority = 0;
      cout << "Enter seniority: ";
      CUtils::LeerUInt(&seniority);
#ifndef NDEBUG
      cout << "Seniority read: " << seniority << "\n";
#endif

      int age = 0;
      cout << "Enter age: ";
      CUtils::LeerInt(&age);
#ifndef NDEBUG
      cout << "Age read: " << age << "\n";
#endif

      auto empl = CEmpleado{name, category, seniority, age, CHora{}.Now()};
      reg.Add(empl);
      break;
    };

    case MenuOps1::EnterClient : {
      string name = string{};
      cout << "Enter name: ";
      CUtils::LeerString(name);
#ifndef NDEBUG
      cout << "Name read: " << name << "\n";
#endif

      string DNI = string{};
      cout << "Enter DNI: ";
      CUtils::LeerString(DNI);
#ifndef NDEBUG
      cout << "DNI read: " << DNI << "\n";
#endif

      int age = 0;
      cout << "Enter age: ";
      CUtils::LeerInt(&age);
#ifndef NDEBUG
      cout << "Age read: " << age << "\n";
#endif

      auto client = CCliente{name, age, CHora{}.Now(), DNI};
      reg.Add(client);
      break;
    };

    case MenuOps1::MakeCopy : {
      if (backup == nullptr) {
        backup = new CRegistroDiario{reg};
      } else {
        cout << "There is a backup already\n";
      }

      break;
    }

    case MenuOps1::RestoreCopy : {
      if (backup == nullptr) {
        cout << "There is no backup yet, please, make one first\n";
      } else {
        reg = *backup;
      }

      break;
    }

    case MenuOps1::ShowReg : {
      reg.ShowRegister();
      break;
    };
    case MenuOps1::ShowEmploy : {
      reg.ShowEmployees();
      break;
    }

    case MenuOps1::FindByName : {
      string name = string{};
      cout << "Enter name: ";
      CUtils::LeerString(name);

      try {
        reg.FindByName(name).show();
      } catch (invalid_argument &e) {
        cout << e.what() << "\n";
      }

      break;
    }

    case MenuOps1::other : {
      cout << "Please, enter a valid action\n";
      break;
    }
    case MenuOps1::Exit: {
      cout << "Goodbye" << endl;
      break;
    }
    }

    CUtils::pause();
    CUtils::clear();
  }

  if (backup != nullptr) {
    delete backup;
  }
}

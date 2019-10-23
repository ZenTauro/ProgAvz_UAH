#include <CHora.hpp>
#include <algorithm>
#include <iostream>
#include <menus.hpp>
#include <utils.hpp>
#include <vector>

int main() {
  bool keep = true;
  utils::MenuOps1 opt;

  std::vector<CHora *> vec{};

  while (keep) {
    utils::CUtils::CrearMenu(menu1, 5);
    opt = utils::CUtils::LeerEntrada1();

    switch (opt) {
    case utils::MenuOps1::local: {
      utils::CUtils::CrearMenu(menu2, 6);
      auto opt2 = utils::CUtils::LeerEntrada2();

      switch (opt2) {
      case (utils::MenuOps2::predeterminada): {
        CHora var{};
        int hh, mm, ss;
        auto fmt = new char[10]();
        var.ObtenerHora(hh, mm, ss, fmt);

        std::cout << hh << ":" << mm << ":" << ss << " " << fmt << std::endl;

        delete[] fmt;
        break;
      };
      case (utils::MenuOps2::param1): {
        int temp1;
        std::cout << "prompt> ";
        utils::CUtils::LeerInt(&temp1);

        CHora var{temp1};

        if (!var.EsHoraCorrecta()) {
          std::cout << "hora incorrecta" << std::endl;
          break;
        };

        int hh, mm, ss;
        auto fmt = new char[10]();
        var.ObtenerHora(hh, mm, ss, fmt);

        std::cout << hh << ":" << mm << ":" << ss << " " << fmt << std::endl;

        delete[] fmt;
        break;
      };
      case (utils::MenuOps2::param2): {
        int temp1, temp2;
        std::cout << "prompt> ";
        utils::CUtils::LeerInt(&temp1);
        std::cout << "prompt> ";
        utils::CUtils::LeerInt(&temp2);

        CHora var{temp1, temp2};

        if (!var.EsHoraCorrecta()) {
          std::cout << "hora incorrecta" << std::endl;
          break;
        };

        int hh, mm, ss;
        auto fmt = new char[10]();
        var.ObtenerHora(hh, mm, ss, fmt);

        std::cout << hh << ":" << mm << ":" << ss << " " << fmt << std::endl;

        delete[] fmt;
        break;
      };
      case (utils::MenuOps2::param3): {
        int temp1, temp2, temp3;
        std::cout << "prompt> ";
        utils::CUtils::LeerInt(&temp1);
        std::cout << "prompt> ";
        utils::CUtils::LeerInt(&temp2);
        std::cout << "prompt> ";
        utils::CUtils::LeerInt(&temp3);

        CHora var{temp1, temp2, temp3};

        if (!var.EsHoraCorrecta()) {
          std::cout << "hora incorrecta" << std::endl;
          break;
        };

        int hh, mm, ss;
        auto fmt = new char[10]();
        var.ObtenerHora(hh, mm, ss, fmt);

        std::cout << hh << ":" << mm << ":" << ss << " " << fmt << std::endl;

        delete[] fmt;
        break;
      };
      case (utils::MenuOps2::param4): {
        int temp1, temp2, temp3;
        auto temp4 = new char[10]();

        std::cout << "Horas > ";
        utils::CUtils::LeerInt(&temp1);
        std::cout << "Mins  > ";
        utils::CUtils::LeerInt(&temp2);
        std::cout << "Seg   > ";
        utils::CUtils::LeerInt(&temp3);
        std::cout << "Fmto  > ";
        utils::CUtils::LeerCadena(temp4, 9);

        CHora var{temp1, temp2, temp3, temp4};

        if (!var.EsHoraCorrecta()) {
          std::cout << "hora incorrecta" << std::endl;
          delete[] temp4;
          break;
        };

        int hh, mm, ss;
        auto fmt = new char[10]();
        var.ObtenerHora(hh, mm, ss, fmt);

        std::cout << hh << ":" << mm << ":" << ss << " " << fmt << std::endl;

        delete[] fmt;
        delete[] temp4;
        break;
      };
      case (utils::MenuOps2::ret): {
        break;
      };
      }
      break;
    };

    case utils::MenuOps1::dyn: {
      int temp1, temp2, temp3;
      auto temp4 = new char[10]();
      std::cout << "Horas > ";
      utils::CUtils::LeerInt(&temp1);
      std::cout << "Min   > ";
      utils::CUtils::LeerInt(&temp2);
      std::cout << "Seg   > ";
      utils::CUtils::LeerInt(&temp3);
      std::cout << "Fmto  > ";
      utils::CUtils::LeerCadena(temp4, 10);

      CHora *hora = new CHora{temp1, temp2, temp3, temp4};

      if (!hora->EsHoraCorrecta()) {
        std::cout << "Hora incorrecta" << std::endl;
        delete hora;
        delete[] temp4;
        break;
      }

      // auto *hora = new CHora{};
      vec.push_back(hora);
      int hh, mm, ss;
      auto fmt = new char[10]();
      hora->ObtenerHora(hh, mm, ss, fmt);

      std::cout << hh << ":" << mm << ":" << ss << " " << fmt << std::endl;

      delete[] fmt;
      delete[] temp4;
      break;
    };

    case utils::MenuOps1::copy: {
      if (vec.size() == 0) {
        std::cout << "No hay elementos dinamicos" << std::endl;
        break;
      }
      auto *hora = new CHora(*vec[0]);
      vec.push_back(hora);

      int hh, mm, ss;
      auto fmt = new char[10]();
      hora->ObtenerHora(hh, mm, ss, fmt);

      std::cout << hh << ":" << mm << ":" << ss << " " << fmt << std::endl;

      delete[] fmt;
      break;
    };

    case utils::MenuOps1::asignacion: {
      if (vec.size() == 0) {
        std::cout << "No hay elementos dinamicos" << std::endl;
        break;
      }
      auto hora = *vec[0];

      int hh, mm, ss;
      auto fmt = new char[10]();
      hora.ObtenerHora(hh, mm, ss, fmt);

      std::cout << hh << ":" << mm << ":" << ss << " " << fmt << std::endl;

      delete[] fmt;
      break;
    };

    case utils::MenuOps1::other: {
      keep = false;
      std::for_each(vec.begin(), vec.end(),
                    [](auto elem) {
                      elem->~CHora();
                      delete elem;
                    });

      break;
    };
    }

    utils::CUtils::pause();
    utils::CUtils::clear();
  }

  return 0;
}

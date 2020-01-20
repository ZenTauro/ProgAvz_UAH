#include "CEmpresa.hpp"
#include "CCliente.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <streambuf>
#include <string>
#include <vector>

using namespace std;

namespace cempresa {
  void from_file(CEmpresa<CCliente> &empresa, const string &path) {
    ifstream file{path};
    string str {
      istreambuf_iterator<char>{file}, istreambuf_iterator<char> {}
    };

    istringstream iss{str};
    vector<string> clients{istream_iterator<string>{iss},
                           istream_iterator<string>{}};

    for (auto &client_name : clients) {
      empresa.AgregarElemento(CCliente(client_name));
    }
  }
}

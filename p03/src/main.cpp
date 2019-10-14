#include <CHora.hpp>
#include <iostream>

using namespace std;

int main() {
  auto hora = CHora{};
  hora.Iniciar();

  cout << "C makes it easy to shoot yourself in the foot; C++ makes it" << endl
       << "harder, but when you do it blows your whole leg off" << endl
       << "- Bjarne Stroustrup" << endl;

      return 0;
}

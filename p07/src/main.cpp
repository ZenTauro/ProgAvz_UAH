#include "CRegistroDiario.hpp"
#include "types.hpp"
#include <iostream>

using namespace std;

int main() {
  uint32 ret=0;

  try {
    auto val = CRegistroDiario{-1};
  } catch(invalid_argument &e) {
    cout << "execution aborted due to exception: " << e.what() << "\n";
    ret = 1;
    goto ret_point;
  }

 ret_point: return ret;
}

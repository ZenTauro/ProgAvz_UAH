#include <CMatFloat.hpp>
#include <iostream>
#include <limits>
#include <string>
#include <tuple>

#include <utils.hpp>

using namespace std;
int main() {
  auto mat = CMatFloat{};

  utils::opts(
      [&mat]() -> void {
        int nfilas, ncol;
        mat.Init();
        tie(nfilas, ncol) = utils::auxMatrixConstructor();
        cout << nfilas << " " << ncol << endl;
        mat.Build2DMatrix(nfilas, ncol);
      },
      [&mat]() -> void {
        mat.Enter();
      },
      [&mat]() -> void {
        mat.Show();
      },
      [&mat]() -> void {
        mat.Destroy();
      });
}

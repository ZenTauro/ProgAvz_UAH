#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>

#include <matrix.h>

using namespace std;

floatMatrix::floatMatrix() {}
floatMatrix::~floatMatrix() {}

floatMatrix::floatMatrix(int nFilas, int nColumnas) {
  mtr = ConstruirMatriz(nFilas, nColumnas);
}

void floatMatrix::modify() {
  if (mtr.has_value()) {
    IntroducirDatos(mtr.value());
  } else {
    cerr << "La matriz no existe" << endl;
  }
}

void floatMatrix::show() {
  auto v = mtr.value();

  for (long unsigned int i = 0; i < v.size(); i++) {
    for (long unsigned int j = 0; j < v[0].size(); j++) {
      cout << v[i][j] << ' ';
    }
    cout << endl;
  }
}

void floatMatrix::remove() {
  this->mtr.reset();
}

std::tuple<int, int> auxMatrixConstructor() {
  int nfilas = 0, ncol = 0;

  cout << "introduzca numero de filas: ";
  cin >> nfilas;
  cout << "introduzca numero de columnas: ";
  cin >> ncol;
  cout << endl;

  auto res = std::make_tuple(nfilas, ncol);

  return res;
}

mat ConstruirMatriz(int nFilas, int nColumnas) {
  mat matrix (nFilas, vector<float>(nColumnas, 0));
  return matrix;
}

void IntroducirDatos(mat &v) {
  string buf{};

  for ( long unsigned int i = 0; i < v.size(); i++ ) {
    for ( long unsigned int j = 0; j < v[0].size(); j++ ) {
      cout << " [" << i << "][" << j << "]: ";
      cin >> buf;

      try {
        v[i][j] = stof(buf);
      } catch (exception &e) {
        cout << "Please enter it again";
        j--;
      }
    }
    cout << endl;
  }
}

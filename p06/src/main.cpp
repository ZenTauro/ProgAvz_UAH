#include "CMonomio.hpp"
#include "CPolinomio.hpp"

#include <iostream>

using namespace std;

int main() {
  cout << "Hello world" << endl;

  CPolinomio P, Q, R, S, T, U, V, W, X, Y, Z, N;
  CMonomio m1, m2(2, 2), m3(3, 3), m4(4, 4);

  P << m1 << m2 << -m4 << m3;
  Q << m4 << m1 << m2 << -m3;
  R << m3 << m4 << -m2;
  S << m2 << m3 << m4 << -m2;
  T << -m2 << -m3 << -m4 << m3;
  U << m2 << m3 << m4 << -m4;
  V << m2 << m3 << m4 << -m2 << -m3 << -m4;
  W << m2 << m3 << -m2 << -m3;
  X << m2 << -m2;
  Y << m2 << m3 << m4 << m2;
  Z << -m2 << -m3 << -m4 << -m3;
  N << m2 << m3 << m4 << m4;

  cout << "P = " << P << endl
       << "Q = " << Q << endl
       << "R = " << R << endl
       << "S = " << S << endl
       << "T = " << T << endl
       << "U = " << U << endl
       << "V = " << V << endl
       << "W = " << W << endl
       << "X = " << X << endl
       << "Y = " << Y << endl
       << "Z = " << Z << endl
       << "N = " << N << endl;


  return 0;
}

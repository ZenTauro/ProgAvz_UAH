#include "CMonomio.hpp"
#include "CPolinomio.hpp"
#include "utils.hpp"

#include <iostream>

using namespace std;

auto pause = utils::CUtils::pause;

int main() {
  cout << "Hello world" << endl;

  CPolinomio P{}, Q{}, R{}, S{}, T{}, U{}, V{}, W{}, X{}, Y{}, Z{}, N{}, G{};
  CMonomio m1{}, m2{2, 2}, m3{3, 3}, m4{4, 4}, m5{3, 2}, m6{2, 1};

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

  cout << "A = P (Constructor Copia) \n";
  CPolinomio A = P;
  cout << "\tA = " << A << '\n';
  // pause();

  CPolinomio B;
  cout << "\nB = Q (Operador de asignacion)\n";
  B = Q;
  cout << "\tB = " << B << '\n';
  // pause();

  cout << "\nP = P (Evitar auto-asignacion)\n";
  P = P;
  cout << "\tP = " << P << '\n';
  // pause();

  cout << "\nProbando el constructor con un coef. y un exp. \n";
  CPolinomio C(2.5), D(2.5, 5);
  cout << "\tC = " << C << '\n';
  cout << "\tD = " << D << '\n';
  // pause();

  cout << "\nProbando el constructor con un monomio. \n";
  CMonomio mon(4, 4);
  CPolinomio E(mon);
  cout << "\tE = " << E << '\n';
  // pause();

  cout << "\nObteniendo el grado del polinomio \n";
  int mayor = U;
  cout << "\tEl grado de U es: " << mayor << "\n";
  // pause();

  cout << "\nProbando el constructor con vector <CMonomio> \n";
  vector<CMonomio> monomio_vector{m4, m3, m2};
  CPolinomio F(monomio_vector);
  cout << "\tF = " << F << '\n';
  // pause();

  cout << "\nProbando el operador > \n";
  cout << "\tP = " << P << '\n';
  cout << "\tU = " << U << '\n';
  bool mayorp = P > U;
  if (mayorp == true)
    cout << "\tP es de mayor grado que U\n";
  else
    cout << "\tU es de mayor grado que P\n";
  // pause();

  cout << "\nProbando el operador == \n";
  cout << "\tP = " << P << '\n';
  cout << "\tQ = " << Q << '\n';
  bool igual = P == Q;
  if (igual == true)
    cout << "\tP es de igual grado que Q\n";
  else
    cout << "\tP es de distinto grado que Q\n";
  // pause();

  cout << "\nProbando el operador - unario \n";
  cout << "\tQ = " << Q << '\n';
  cout << "\t-Q = " << -Q << '\n';
  // pause();

  cout << "\nProbando el operador + \n";
  cout << "\tN = " << N << '\n';
  cout << "\tU = " << U << '\n';
  cout << "\tN + U : " << N + U << '\n';
  // pause();

  cout << "\nProbando los operadores  - y +=\n";
  cout << "\tR = " << R << '\n';
  cout << "\tS = " << S << '\n';
  cout << "\tR - S : " << R - S << '\n';
  cout << "\tR += S : " << (R += S) << '\n';
  // pause();

  cout << "\nProbando el operador -= \n";
  cout << "\tN = " << N << '\n';
  cout << "\tY = " << Y << '\n';
  cout << "\tN -= Y : " << (N -= Y) << '\n';
  // pause();

  cout << "\nProbando el operador [] \n";
  cout << "\tPolinomio P= " << P << '\n';
  cout << "\tCoeficiente de P[4]: " << P[4] << '\n';
  // pause();

  cout << "\nProbando el operador () \n";
  G << m5 << -m6;
  cout << "\tPolinomio G: " << G << " , G(0.5) = " << G(0.5) << '\n';
  // pause();

  cout << "\nProbando el operador * \n";
  cout << "\tQ = " << Q << '\n';
  cout << "\tS = " << S << '\n';
  cout << "\tQ * S : " << Q * S << '\n';
  // pause();

  cout << "\nProbando el operador *= \n";
  cout << "\tP = " << P << '\n';
  cout << "\tQ = " << Q << '\n';
  cout << "\tP *= Q : " << (P *= Q) << '\n';
  // pause();

  return 0;
}

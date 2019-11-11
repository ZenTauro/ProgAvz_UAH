#include "CMonomio.hpp"
#include "CPolinomio.hpp"
#include "utils.hpp"

#include <iostream>

using namespace std;

auto pause = utils::CUtils::pause;

int main() {
  cout << "Hello world" << endl;

  CPolinomio P, Q, R, S, T, U, V, W, X, Y, Z, N, G;
  CMonomio m1, m2(2, 2), m3(3, 3), m4(4, 4), m5(3, 2), m6(2, 1);

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

  std::cout << "A = P (Constructor Copia) \n";
  CPolinomio A = P;
  std::cout << "\tA = " << A << '\n';
  pause();

  CPolinomio B;
  std::cout << "\nB = Q (Operador de asignacion)\n";
  B = Q;
  std::cout << "\tB = " << B << '\n';
  pause();

  std::cout << "\nP = P (Evitar auto-asignacion)\n";
  P = P;
  std::cout << "\tP = " << P << '\n';
  pause();

  std::cout << "\nProbando el constructor con un coef. y un exp. \n";
  CPolinomio C(2.5), D(2.5, 5);
  std::cout << "\tC = " << C << '\n';
  std::cout << "\tD = " << D << '\n';
  pause();

  std::cout << "\nProbando el constructor con un monomio. \n";
  CMonomio mon(4, 4);
  CPolinomio E(mon);
  std::cout << "\tE = " << E << '\n';
  pause();

  std::cout << "\nObteniendo el grado del polinomio \n";
  int mayor = U;
  std::cout << "\tEl grado de U es: " << mayor << "\n";
  pause();

  std::cout << "\nProbando el constructor con vector <CMonomio> \n";
  std::vector<CMonomio> monomio_vector{ m4,m3,m2 };
  CPolinomio F(monomio_vector);
  std::cout << "\tF = " << F << '\n';
  pause();

  std::cout << "\nProbando el operador > \n";
  std::cout << "\tP = " << P << '\n';
  std::cout << "\tU = " << U << '\n';
  bool mayorp = P > U;
  if (mayorp == true)
    std::cout << "\tP es de mayor grado que U\n";
  else
    std::cout << "\tU es de mayor grado que P\n";
  pause();

  std::cout << "\nProbando el operador == \n";
  std::cout << "\tP = " << P << '\n';
  std::cout << "\tQ = " << Q << '\n';
  bool igual = P == Q;
  if (igual == true)
    std::cout << "\tP es de igual grado que Q\n";
  else
    std::cout << "\tP es de distinto grado que Q\n";
  pause();

  std::cout << "\nProbando el operador - unario \n";
  std::cout << "\tQ = " << Q << '\n';
  std::cout << "\t-Q = " << -Q << '\n';
  pause();

  std::cout << "\nProbando el operador + \n";
  std::cout << "\tN = " << N << '\n';
  std::cout << "\tU = " << U << '\n';
  std::cout << "\tN + U : " << N + U << '\n';
  pause();

  std::cout << "\nProbando los operadores  - y +=\n";
  std::cout << "\tR = " << R << '\n';
  std::cout << "\tS = " << S << '\n';
  std::cout << "\tR - S : " << R - S << '\n';
  std::cout << "\tR += S : " << (R += S) << '\n';
  pause();

  std::cout << "\nProbando el operador -= \n";
  std::cout << "\tN = " << N << '\n';
  std::cout << "\tY = " << Y << '\n';
  std::cout << "\tN -= Y : " << (N -= Y) << '\n';
  pause();

  std::cout << "\nProbando el operador [] \n";
  std::cout << "\tPolinomio P= " << P << '\n';
  std::cout << "\tCoeficiente de P[4]: " << P[4] << '\n';
  pause();

  std::cout << "\nProbando el operador () \n";
  G << m5 << -m6;
  std::cout << "\tPolinomio G: " << G << " , G(0.5) = " << G(0.5) << '\n';
  pause();

  std::cout << "\nProbando el operador * \n";
  std::cout << "\tQ = " << Q << '\n';
  std::cout << "\tS = " << S << '\n';
  std::cout << "\tQ * S : " << Q * S << '\n';
  pause();

  std::cout << "\nProbando el operador *= \n";
  std::cout << "\tP = " << P << '\n';
  std::cout << "\tQ = " << Q << '\n';
  std::cout << "\tP *= Q : " << (P *= Q) << '\n';
  pause();

  return 0;
}

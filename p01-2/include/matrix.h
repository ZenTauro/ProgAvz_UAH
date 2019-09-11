#include <vector>
#include <optional>

using namespace std;

typedef vector<vector<float>> mat;

class floatMatrix {
public:
  optional<mat> mtr;

  void modify();
  void remove();
  void show();
  ~floatMatrix();
  floatMatrix(int nFilas, int nColumnas);
  floatMatrix();
};

  std::tuple<int, int> auxMatrixConstructor();
  mat ConstruirMatriz(int nFilas, int nColumnas);
  void IntroducirDatos(mat &v);

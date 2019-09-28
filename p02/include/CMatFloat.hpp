typedef unsigned int uint;

class CMatFloat {
private:
  float **data;
  uint nRows;
  uint nCols;

public:
  /// Executed each time a new matrix is created
  void Init();
  /// Assigns dynamic memory to accomodate a 2D matrix
  void Build2DMatrix(int nRows, int nCols);
  /// Assigns dynamic memory to accomodate a 1D matrix
  void Build1DMatrix(int nElem);
  /// Validates and introduces data into the matrix
  void Enter();
  /// Shows the contents of the matrix
  void Show();
  /// Frees the matrix and its memory
  void Destroy();
  /// Returns true if data points to a valid memory location
  bool Exists();

  CMatFloat();
  CMatFloat(int, int);
  ~CMatFloat();
};

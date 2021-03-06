#include <CMatFloat.hpp>

#include <cstring>
#include <iostream>
#include <string>

using namespace std;

CMatFloat::CMatFloat() {
  cout << "Se llama a Iniciar\n";
  Init();
}
CMatFloat::CMatFloat(int nRows, int nCols) {
this->  Init();
  Build2DMatrix(nRows, nCols);
}
CMatFloat::~CMatFloat() {
  if(Exists()) {
    Destroy();
  }
}

/// Sets all the fields to a NULL state
void CMatFloat::Init() {
  if (this->data) {
    cout << "La matriz existe, destruyala para crear una nueva" << endl;
    return;
  }
  this->nCols = 0;
  this->nRows = 0;
  this->data = NULL;
}

/// Assigns dynamic memory to accomodate a 2D matrix
void CMatFloat::Build2DMatrix(int nRows, int nCols) {
  this->nRows = nRows;
  this->data = new float *[nRows];

  this->Build1DMatrix(nCols);
}

/// Assigns dynamic memory to accomodate a 1D matrix
void CMatFloat::Build1DMatrix(int nElem) {
  this->nCols = nElem;

  for (int i = 0; i < nElem; ++i) {
    this->data[i] = new float[nElem];
    for (int j = 0; j < nElem; ++j)
      this->data[i][j] = 0;
  }
}

/// Validates and introduces data into the matrix
void CMatFloat::Enter() {
  string buf{};

  for (uint i = 0; i < this->nRows; i++) {
    for (uint j = 0; j < this->nCols; j++) {
      cout << " [" << i << "][" << j << "]: ";
      cin >> buf;

      try {
        this->data[i][j] = stof(buf);
      } catch (invalid_argument &) {
        cout << endl << "Argumento invalido" << endl;
        j--;
      } catch (out_of_range &) {
        cout << endl << "Argumento fuera del rango permitido" << endl;
        j--;
      }
    }
    cout << endl;
  }
}

/// Shows the contents of the matrix
void CMatFloat::Show() {
  if (this->data == NULL || this->nRows == 0 || this->nCols == 0) return;

  for (uint j = 0; j < this->nRows; j++) {
    for (uint i = 0; i < this->nCols; i++) {
      cout << data[j][i] << " ";
    }
    cout << endl;
  }
}

/// Frees the matrix and its memory
void CMatFloat::Destroy() {
  if (this->data != NULL) {
    for (uint i=0; i<nRows; i++) {
      if (this->data[i] != NULL) {
        delete[] this->data[i];
        // cout << "destroyed " << i << " row" << endl;
      }
    }

    delete[] this->data;
    // cout << "destroyed main column" << endl;
    this->data = NULL;
    this->nCols = 0;
    this->nRows = 0;
  }
}

/// Returns true if data points to a valid memory location
bool CMatFloat::Exists() {
  return this->data ? true : false;
}

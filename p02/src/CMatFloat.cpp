#include <CMatFloat.hpp>

#include <iostream>
#include <string>

CMatFloat::CMatFloat() {}
CMatFloat::~CMatFloat() {}

typedef unsigned int uint;

using namespace std;

/// Sets all the fields to a NULL state
void CMatFloat::Init() {
  this->nCols = 0;
  this->nRows = 0;
  this->data = NULL;
}

/// Assigns dynamic memory to accomodate a 2D matrix
void CMatFloat::Build2DMatrix(int nRows, int nCols) {
  this->nRows = nRows;
  this->data = new float *[nRows];

  this->Build1DMatrix(nRows);
}

/// Assigns dynamic memory to accomodate a 1D matrix
void CMatFloat::Build1DMatrix(int nElem) {
  this->nCols = nElem;

  for (int i = 0; i < nCols; i++) {
    this->data[i] = new float[this->nRows];
    this->data[i] = 0;
  }
}

/// Validates and introduces data into the matrix
void CMatFloat::Enter() {
  string buf{};

  for (long unsigned int i = 0; i < this->nRows; i++) {
    for (long unsigned int j = 0; j < this->nCols; j++) {
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
  for (uint j = 0; j < nRows; j++) {
    for (uint i = 0; i < nCols; i++) {
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
      }
    }

    delete[] this->data;
    this->data = NULL;
  }
}

/// Returns true if data points to a valid memory location
bool CMatFloat::Exists() {
  return this->data ? true : false;
}

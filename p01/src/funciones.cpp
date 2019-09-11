#include <iostream>
#include <string>
#include <sstream>

#include <funciones.h>

using namespace std;

void Destruir(MatFloat *pMatFloat) {
  pMatFloat->nColumnas = 0;
  pMatFloat->nFilas = 0;

  if (pMatFloat->ppMatriz == NULL) {
    cout << "La matriz no existe" << endl;
    return;
  }

  for (int i = 0; i < pMatFloat->nFilas; ++i) {
    delete pMatFloat->ppMatriz[i];
  }

  delete pMatFloat->ppMatriz;

  pMatFloat->ppMatriz = NULL;
}

float** ConstruirMatriz(int nFilas, int nColumnas) {
  MatFloat mat {nFilas, nColumnas, NULL};
  try {
    mat.ppMatriz = new float*[nFilas];
  } catch (bad_alloc &) {
    cout << "OOM error";
    mat.nFilas = 1;
    mat.nColumnas = 0;
    Destruir(&mat);

    return NULL;
  }


  for ( int i=0; i < nFilas; i++ ) {
    try {
      mat.ppMatriz[i] = new float[nColumnas];
    } catch (bad_alloc &) {
      mat.nFilas = nFilas;
      mat.nColumnas = i+1;
      Destruir(&mat);

      return NULL;
    }

    for ( int j=0; j < nColumnas; j++ ) {
      mat.ppMatriz[i][j] = 0.0;
    }
  }

  return mat.ppMatriz;
}

void Mostrar(const MatFloat mOrigen) {
  if (mOrigen.ppMatriz == NULL) {
    cout << "La matriz no existe" << endl;
    return;
  }

  for ( int i=0; i<mOrigen.nFilas; i++ ) {
    for ( int j=0; j<mOrigen.nColumnas; j++ ) {
      std::cout << mOrigen.ppMatriz[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

void IntroducirDatos(MatFloat *pDestino) {
  if (pDestino->ppMatriz == NULL) {
    cout << "La matriz no existe" << endl;
    return;
  }

  cout << "Introduzca los datos:" << endl;

  string buf;

  for (int i = 0; i < pDestino->nFilas; i++) {
    for (int j = 0; j < pDestino->nFilas; j++) {
      cout << "[" << i << "] " << "[" << j << "]:";
      cin >> buf;
      try {
        pDestino->ppMatriz[i][j] = stof(buf);
      } catch (invalid_argument &) {
        cout << endl << "Argumento invalido" << endl;
        j--;
      } catch (out_of_range &) {
        cout << endl << "Argumento fuera del rango permitido" << endl;
        j--;
      }
    }
  }
}

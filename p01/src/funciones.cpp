#include <iostream>
#include <string>
#include <sstream>

#include <funciones.h>

using namespace std;

/**
 * Libera la memoria de la matriz y pone el puntero a NULL una vez liberada
 * @param pMatFloat Puntero a la estructura que contiene la matriz
 */
void Destruir(MatFloat *pMatFloat) {
  // Si por accidente llega una matriz que apunta a NULL, para prevenir
  // segfault, retornamos inmediatamente
  if (pMatFloat->ppMatriz == NULL) {
    cout << "La matriz no existe" << endl;
    pMatFloat->nColumnas = 0;
    pMatFloat->nFilas = 0;
    return;
  }

  // Liberamos todas las filas
  for (int i = 0; i < pMatFloat->nFilas; i++) {
    delete[] pMatFloat->ppMatriz[i];

#ifndef NDEBUG
    cerr << "  [-] " << i << " Matrix row direcction:   0x" << hex
         << reinterpret_cast<intptr_t>(pMatFloat->ppMatriz[i]) << endl;
#endif
  }

  // Y por ultimo el vector principal de la matriz
  delete[] pMatFloat->ppMatriz;

#ifndef NDEBUG
  cerr << "  [-] Matrix initial direcction: 0x" << hex
       << reinterpret_cast<intptr_t>(pMatFloat->ppMatriz) << endl;
#endif

  // Una vez liberada la matriz, se ponen los campos a 0
  pMatFloat->nColumnas = 0;
  pMatFloat->nFilas = 0;

  pMatFloat->ppMatriz = NULL;
}

/**
 * Con \p nFilas y \p nColumnas construye una matriz de pFilas x pColumnas
 * @param nFilas
 * @param nColumnas
 * @return Matriz
 */
float** ConstruirMatriz(int nFilas, int nColumnas) {
  // Inicializamos una estructura para la matriz temporal con los
  // y campos que se han pasado
  MatFloat mat{nFilas, nColumnas, NULL};

  // Intentamos reservar memoria, si no es posible, liberamos la ya
  // obtenida.
  try {
    mat.ppMatriz = new float*[nFilas];

#ifndef NDEBUG
    cerr << "  [+] Matrix initial direcction: 0x" << hex
         << reinterpret_cast<intptr_t>(mat.ppMatriz) << endl;
#endif

  } catch (bad_alloc &) {
    cout << "OOM error";
    mat.nFilas = 1;
    mat.nColumnas = 0;
    Destruir(&mat);

    return NULL;
  }

  // Para cada fila intentamos reservar memoria, si no es posible,
  //  liberamos la ya obtenida.
  for ( int i=0; i < nFilas; i++ ) {
    try {
      mat.ppMatriz[i] = new float[nColumnas];

#ifndef NDEBUG
      cerr << "  [+] " << i << " Matrix row direcction:   0x" << hex
           << reinterpret_cast<intptr_t>(mat.ppMatriz[i]) << endl;
#endif

    } catch (bad_alloc &) {
      mat.nFilas = nFilas;
      mat.nColumnas = i+1;
      Destruir(&mat);

      return NULL;
    }

    // Una vez la matriz tiene memoria se inicia a 0.0 todos los campos
    for ( int j=0; j < nColumnas; j++ ) {
      mat.ppMatriz[i][j] = 0.0;
    }
  }

  return mat.ppMatriz;
}

/**
 * Muestra la matriz separando cada casilla por un espacio y cada
 * fila por un salto de linea
 *
 * @param mOrigen La matriz en cuestion
 */
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

/**
 * Con un puntero a la matriz modifica los campos internos con
 * los valores proporcionados por stdin
 *
 * @param[out] pDestino La matriz en cuestion
 */
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

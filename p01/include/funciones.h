struct MatFloat {
  int     nFilas;
  int     nColumnas;
  float **ppMatriz;
};

float** ConstruirMatriz (int nFilas, int nColumnas);
void    IntroducirDatos (MatFloat *pDestino);
void    Mostrar         (MatFloat Origen);
void    Destruir        (MatFloat *pMatFloat);

# Como ejecutar el programa
Dado que esta práctica es mas avanzada que las demás, se ha usado
la librería GTest de Google para realizar tests de unidad, junto
con valgrind y varios sanitizer (las implementaciones de llvm y de
gcc).

Para poder hacer uso de estas herramientas a la hora de demostrar
que el programa es correcto, hay que compilarlo con unas opciones
específicas.

Por defecto se intentan construir los test, lo cual incrementa el
tiempo de enlazado, para desactivarlos hay que pasar el flag
`-DPACKAGE_TESTS=OFF`.

## GCC Release `CFicha**`
Para compilar el programa con GCC, se utilizará el siguiente comando
```sh
CC="gcc" \                    # Especificamos gcc
CXX="g++" \                   #               gcc
LDFLAGS="-fuse-ld=gold" \     # Usamos gold por su eficiencia
CXXFLAGS="-march=native -O2 -flto" \    # Con -flto activamos
cmake \                                 # comprobaciones en
    -Bbuild \                           # el enlazado
    -GNinja \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=YES \
    -DCMAKE_BUILD_TYPE=Release

cmake --build build
```

## Clang Debug `vector<CFicha *>`
Para compilar el programa con clang, se utilizará el siguiente comando
```sh
CC="clang" \                  # Especificamos clang
CXX="clang++" \
LDFLAGS="-fuse-ld=lld" \      # Usamos lld por su eficienca
CXXFLAGS="-fsanitize=address -march=native -O0 -flto" \
cmake \
    -DCMAKE_BUILD_TYPE=debug -BDebug \
    -GNinja -DCMAKE_EXPORT_COMPILE_COMMANDS=YES

cmake --build build
```

# Flags
- `-fsanitize=address` Activa análisis en tiempo de ejecución de fugas
  de memoria, sobreescritura de stack, etc.
- `-flto` Activa las optimizaciones de enlazado y comprobaciones adicionales

# Ejecución
Una vez compilado el programa con uno de los perfiles, podemos ejecutarlo de
la siguiente forma.

## Tests
```sh
LSAN_OPTIONS=verbosity=1:log_threads=1:report_objects=1 ./Debug/test/practica8_tst
```

## Programa
```sh
./build/practica8
```

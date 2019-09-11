# Compilacion
Para compilar el proyecto es necesario el uso de cmake. Una vez instalado el comando
para iniciarlo es:

``` sh
cmake -BDebug -DCMAKE_BUILD_TYPE=debug -DCMAKE_EXPORT_COMPILE_COMMANDS=YES
```

y para compilarlo es:

``` sh
cmake --build Debug
```

el binario se encuentra en `Debug/practica${version}` donde version es el numero de
practica.

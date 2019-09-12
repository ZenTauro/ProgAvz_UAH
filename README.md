# Proyectos
## Compilacion
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

## Debugging
Dado que no es posible utilizar el MemoryManager, Valgrind cumple con su funcion:

``` sh
valgrind --xtree-leak=yes  --num-callers=40 --log-file='valgrind.log' ./Debug/practica1
```

Lo corremos de esta forma para generar un reporte al final que puede ser leido con
`less valgrind.log` o si esta instalado `colour-valgrind` con el siguiente comando.

``` sh
colour-valgrind --test valgrind.log | less -R
```

# Licencia
A no ser que este explicitamente declarado, todos los archivos y trabajos en este repositorio
se encuentran bajo la licencia GPL3, puede ser encontrada en LICENSE.md. La licencia presente
en este repositorio es puramente informativa, para efectos legales refierase a la original, la
cual puede ser encontrada en [este link](https://www.gnu.org/licenses/gpl-3.0.html).

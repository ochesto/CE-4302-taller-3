# CE-4302-taller-3
##CE4302 - Arquitectura de Computadores II - Taller 3

Por Ernesto Ulate Ramírez - 2014092260.

###Para compilar los programas:
1. Ejemplo provisionado en el enunciado del taller:
Dentro del directorio src/jni/ se ejecutan los siguientes comandos:
* /opt/android-ndk-build-r18/ndk-build
* adb push ../libs/armeabi-v7a/pi_par /data/local/tmp
* adb shell /data/local/tmp/pi_par

2. Ejercicio 1:
Dentro del directorio saxpy/jni/ se ejecutan los siguientes comandos:
* /opt/android-ndk-build-r18/ndk-build
* adb push ../libs/armeabi-v7a/saxpy /data/local/tmp
* adb shell /data/local/tmp/saxpy param1 param2
NOTA: param1 = tamano de arreglo.
NOTA: param2 = constante.

3. Ejercicio 2:
Dentro del directorio example/jni/ se ejecutan los siguientes comandos:
* /opt/android-ndk-build-r18/ndk-build
* adb push ../libs/armeabi-v7a/example /data/local/tmp
* adb shell /data/local/tmp/example param1 param2
NOTA: param1 = cantidad de iteraciones.
NOTA: param2 = constante.
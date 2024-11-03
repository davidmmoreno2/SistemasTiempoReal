#include <stdlib.h>
#include <stdio.h>
#include "funciones_time.h"
#include <ClasesPosix.h>
//Añadir la librería de utilización de señales
#include <signal.h>

//Añadir el include de los relojes
#include <time.h>


void imprimir_senial_capturada(int capturadas, int max_capturas) {
	printf("Se han capturado %d señales SIGINT de %d.\n", capturadas, max_capturas);
}

void imprimir_fecha_hora(int dia, int mes, int anio, int hora, int minuto, int segundos, int milisegundos) {
	printf("%d/%d/%d - %d:%d:%d.%03d\n", dia, mes, anio, hora, minuto, segundos, milisegundos);
}

//Definir un tipo de datos seniales_t que sea una estructura con dos campos de tipo entero, uno para almacenar las señales recibidas y otro para almacenar las señales esperadas
struct seniales_t {
	int recibidas;
	int esperadas;
};

void *HiloSigInt(void *param) {
	seniales_t *seniales = (seniales_t *)param;
	sigset_t conjunto_seniales;
	sigemptyset(&conjunto_seniales);
	sigaddset(&conjunto_seniales, SIGINT);
	sigaddset(&conjunto_seniales, SIGUSR1);
	pthread_sigmask(SIG_BLOCK, &conjunto_seniales, NULL);
	sigdelset(&conjunto_seniales, SIGUSR1);
	while (seniales->recibidas < seniales->esperadas) {
		int senal;
		sigwait(&conjunto_seniales, &senal);
		seniales->recibidas++;
		imprimir_senial_capturada(seniales->recibidas, seniales->esperadas);
	}
}
/*Definir la función HiloSigInt para la creación de un hilo (seguir el formato indicado para este fin, ver el anexo I de la práctica) que capture la señal SIGINT.
Tendrá un parámetro de entrada de tipo puntero a seniales_t (esta estructura es compartida por todos los hilos, de ahí que sea un puntero)*/

	//Definir una variable de tipo puntero a seniales_t (debe ser puntero porque es compartida por todos los hilos)

	//Asignar el contenido del parámetro de entrada a la variable anterior siguiento la forma indicada en clase (ver apuntes del tema 2 o el anexo I de la práctica)

	//Crear un conjunto de señales

	//Inicializar el conjunto de señales a vacío

	//Añadir SIGINT al conjunto de señales. Esta señal es la que vamos a controlar en este hilo

	//Añadir SIGUSR1 al conjunto de señales. Es necesario bloquear esta señal porque se usa en otro hilo

	//Añadir el conjunto de señales a la máscara de señales bloqueadas

	//Quitar SIGUSR1 del conjunto de señales. Esto es necesario ya que, aunque bloqueamos las dos señales, en este hilo solamente esperamos por SIGINT

	//Mientras las señales recibidas no lleguen a las esperadas

		//Esperar por el conjunto de señales, que solamente contiene SIGINT (habrá que crear una variable para usarla como segundo parámetro de la función sigwait)

		//Incrementar las señales recibidas

	//Fin mientras

// Fin de la función HiloSigInt

void *HiloPeriodicoConRetardos(void *param) {
	seniales_t *seniales = (seniales_t *)param;
	sigset_t conjunto_seniales;
	sigemptyset(&conjunto_seniales);
	sigaddset(&conjunto_seniales, SIGINT);
	sigaddset(&conjunto_seniales, SIGUSR1);
	pthread_sigmask(SIG_BLOCK, &conjunto_seniales, NULL);
	struct timespec hora_actual, siguiente_instante, periodo_repeticion;
	struct tm *hora_calendario;
	clock_gettime(CLOCK_MONOTONIC, &hora_actual);
	periodo_repeticion.tv_sec = 5;
	periodo_repeticion.tv_nsec = 0;
	siguiente_instante = SumaTimeSpec(hora_actual, periodo_repeticion);
	while (seniales->recibidas < seniales->esperadas) {
		clock_gettime(CLOCK_MONOTONIC, &hora_actual);
		hora_calendario = localtime(&hora_actual.tv_sec);
		imprimir_fecha_hora(hora_calendario->tm_mday, hora_calendario->tm_mon+1, hora_calendario->tm_year+1900, hora_calendario->tm_hour, hora_calendario->tm_min, hora_calendario->tm_sec, hora_actual.tv_nsec/1000000);
		clock_gettime(CLOCK_REALTIME, &hora_actual);
		hora_calendario = localtime(&hora_actual.tv_sec);
		imprimir_fecha_hora(hora_calendario->tm_mday, hora_calendario->tm_mon+1, hora_calendario->tm_year+1900, hora_calendario->tm_hour, hora_calendario->tm_min, hora_calendario->tm_sec, hora_actual.tv_nsec/1000000);
		clock_gettime(CLOCK_THREAD_CPUTIME_ID, &hora_actual);
		hora_calendario = localtime(&hora_actual.tv_sec);
		imprimir_fecha_hora(hora_calendario->tm_mday, hora_calendario->tm_mon+1, hora_calendario->tm_year+1900, hora_calendario->tm_hour, hora_calendario->tm_min, hora_calendario->tm_sec, hora_actual.tv_nsec/1000000);
		for (int i=0; i<100000000; i++);
		clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &siguiente_instante, NULL);
		siguiente_instante = SumaTimeSpec(siguiente_instante, periodo_repeticion);
	}
}
/*Definir la función HiloPeriodicoConRetardos para la creación de un hilo (seguir el formato indicado para este fin, ver el anexo I de la práctica) que, mediante retardos,
muestre la hora de diferentes relojes. Tendrá un parámetro de entrada de tipo puntero a seniales_t (esta estructura es compartida por todos los hilos, de ahí que sea un puntero)*/

	//Definir una variable de tipo puntero a seniales_t (debe ser puntero porque es compartida por todos los hilos)

	//Asignar el contenido del parámetro de entrada a la variable anterior siguiento la forma indicada en clase (ver apuntes del tema 2 o el anexo I de la práctica 3)

	//Crear un conjunto de señales

	//Inicializar el conjunto de señales a vacío

	//Añadir SIGINT al conjunto de señales. Es necesario bloquear esta señal porque se usa en otro hilo

	//Añadir SIGUSR1 al conjunto de señales. Es necesario bloquear esta señal porque se usa en otro hilo

	//Añadir el conjunto de señales a la máscara de señales bloqueadas

	//Definir tres variables de tipo struct timespec para almacenar la lectura de la hora actual, el instante siguiente y el periodo de repetición

	/*Definir una variable de tipo puntero a struct tm para almacenar la transformación de la hora en formato calendario (no se debe reservar memoria).
	Debe ser de tipo puntero porque la función localtime devuelve la dirección de memoria donde se almacena la conversión.*/

	//Leer la hora actual usando el reloj CLOCK_MONOTONIC

	//Inicializar el periodo de repetición a 5 segundos (hay que inicializar también los nanosegundos)

	//Calcular el siguiente instante como la suma de la hora actual y el periodo de repetición (usar las funciones definidas en la librería funciones_time)

	//Mientras las señales recibidas no lleguen a las esperadas

		//Leemos la hora actual de CLOCK_MONOTONIC

		//Transformamos la hora actual a formato struct tm (usar la variable definida fuera del bucle) mediante la función localtime (usar los segundos de la hora actual)

		//Mostrar la hora en formato día/mes/año horas:minutos:segundos.milisegundos. Los milisegundos se obtienen al dividir los nanosegundos de la hora actual por 1000000 (usar la función imprimir_fecha_hora)

		//Leemos la hora actual de CLOCK_REALTIME

		//Transformamos la hora actual a formato struct tm (usar la variable definida fuera del bucle) mediante la función localtime (usar los segundos de la hora actual)

		//Mostrar la hora en formato día/mes/año horas:minutos:segundos.milisegundos. Los milisegundos se obtienen al dividir los nanosegundos de la hora actual por 1000000 (usar la función imprimir_fecha_hora)

		//Leemos la hora actual de CLOCK_THREAD_CPUTIME_ID

		//Transformamos la hora actual a formato struct tm (usar la variable definida fuera del bucle) mediante la función localtime (usar los segundos de la hora actual)

		//Mostrar la hora en formato día/mes/año horas:minutos:segundos.milisegundos. Los milisegundos se obtienen al dividir los nanosegundos de la hora actual por 1000000 (usar la función imprimir_fecha_hora)

		//Crear un bucle que realice 100000000 de vueltas (el cuerpo del bucle estará vacío). Esta acción incrementará el tiempo de procesador del hilo debido a las sumas y comparaciones del buble

		//Dormir el hilo hasta el siguiente instante calculado, usando CLOCK_MONOTONIC y retardo absoluto

		//Añadir el periodo de repetición al siguiente instante (el valor calculado previamente) (usar las funciones definidas en la librería funciones_time)

	//Fin mientras

//Fin de la función HiloPeriodicoConRetardos

void *HiloPeriodicoConTemporizador(void *param) {
	seniales_t *seniales = (seniales_t *)param;
	sigset_t conjunto_seniales;
	sigemptyset(&conjunto_seniales);
	sigaddset(&conjunto_seniales, SIGINT);
	sigaddset(&conjunto_seniales, SIGUSR1);
	pthread_sigmask(SIG_BLOCK, &conjunto_seniales, NULL);
	sigdelset(&conjunto_seniales, SIGINT);
	timer_t temporizador;
	struct sigevent evento;
	evento.sigev_notify = SIGEV_SIGNAL;
	evento.sigev_signo = SIGUSR1;
	timer_create(CLOCK_MONOTONIC, &evento, &temporizador);
	struct itimerspec datos_temporizador;
	clock_gettime(CLOCK_MONOTONIC, &datos_temporizador.it_value);
	datos_temporizador.it_value = SumaTimeSpec(datos_temporizador.it_value, segundos2timespec(2));
	datos_temporizador.it_interval.tv_sec = 2;
	datos_temporizador.it_interval.tv_nsec = 0;
	timer_settime(temporizador, TIMER_ABSTIME, &datos_temporizador, NULL);
	while (seniales->recibidas < seniales->esperadas) {
		imprimir_senial_capturada(seniales->recibidas, seniales->esperadas);
		int senal;
		sigwait(&conjunto_seniales, &senal);
	}
}
/*Definir la función HiloPeriodicoConTemporizador para la creación de un hilo (seguir el formato indicado para este fin, ver el anexo I de la práctica) que, mediante un temporizador,
muestre las señales capturadas actualmente. Tendrá un parámetro de entrada de tipo puntero a seniales_t (esta estructura es compartida por todos los hilos, de ahí que sea un puntero)*/

	//Definir una variable de tipo puntero a seniales_t

	//Asignar el contenido del parámetro de entrada a la variable anterior siguiento la forma indicada en clase (ver apuntes del tema 2 o el anexo I de la práctica 3)

	//Crear un conjunto de señales

	//Inicializar el conjunto de señales a vacío

	//Añadir SIGINT al conjunto de señales. Es necesario bloquear esta señal porque se usa en otro hilo

	//Añadir SIGUSR1 al conjunto de señales. Esta señal es la que vamos a controlar en este hilo

	//Añadir el conjunto de señales a la máscara de señales bloqueadas

	//Quitar SIGINT del conjunto de señales. Esto es necesario ya que, aunque bloqueamos las dos señales, solamente esperamos por SIGUSR1

	//Definir una variable tipo timer_t que sirva de manejador del temporizador

	//Definir una variable evento de tipo struct sigevent para indicar la acción del temporizador

	//Indicar en la variable evento que el temporizador generará una señal

	//Indicar en la variable evento que la señal generada por el temporizador es SIGUSR1

	//Crear el temporizador usando CLOCK_MONOTONIC, evento y el manejador del temporizador

	//Definir una variable datos_temporizador de tipo struct itimerspec

	//Leer la hora actual de CLOCK_MONOTONIC y almacenarla en el campo it_value de datos_temporizador

	//Añadir dos segundos al campo it_value de datos_temporizador

	//Establecer el campo it_interval de datos_temporizador a 2 segundos (hay que inicializar también los nanosegundos)

	/*Armar el temporizador usando el manejador del temporizador, retardos absolutos y datos_temporizador (no es necesario guardar el tiempo restante en caso
	de salida prematura, por lo que se puede usar NULL)*/

	//Mientras las señales recibidas no lleguen a las esperadas

		//Imprimir el número de señales recibidas actualmente (usar la función imprimir_senial_capturada)

		//Esperar por el conjunto de señales, que solamente contiene SIGUSR1 (habrá que crear una variable para usarla como segundo parámetro de la función sigwait)

	//Fin mientras

//Fin de la función HiloPeriodicoConTemporizador

int main (int argc, char *argv[]) {
	if (argc!=2) {
		printf("Error en la ejecución. El formato correcto es %s num_capturas\n", argv[0]);
		return 0;
	}
	int num_capturas=atoi(argv[1]);
	if (num_capturas<1) {
		printf("Error en la ejecución. El número mínimo señales a capturar debe ser 1\n");
		return 0;
	}
	seniales_t seniales;
	seniales.esperadas= atoi(argv[1]);
	seniales.recibidas=0;
	//Crear un conjunto de señales
	sigset_t conjunto_seniales;

	//Inicializar el conjunto de señales a vacío
	sigemptyset(&conjunto_seniales);

	//Añadir SIGINT al conjunto de señales. Es necesario bloquear esta señal porque se usa en otro hilo
	sigaddset(&conjunto_seniales, SIGINT);

	//Añadir SIGUSR1 al conjunto de señales. Es necesario bloquear esta señal porque se usa en otro hilo
	sigaddset(&conjunto_seniales, SIGUSR1);

	//Añadir el conjunto de señales a la máscara de señales bloqueadas
	pthread_sigmask(SIG_BLOCK, &conjunto_seniales, NULL);

	//Crear un manejador de hilo para cada uno de los hilos que se van a crear (uno por cada una de las funciones anteriores)
	hilo_t hilo_sigint, hilo_periodico_con_retardos, hilo_periodico_con_temporizador;

	//Crear un hilo con la función HiloSigInt y el parámetro seniales
	hilo_sigint.AsignarFuncionYDato(HiloSigInt, &seniales);

	//Crear un hilo con la función HiloPeriodicoConRetardos y el parámetro seniales
	hilo_periodico_con_retardos.AsignarFuncionYDato(HiloPeriodicoConRetardos, &seniales);

	//Crear un hilo con la función HiloPeriodicoConTemporizador y el parámetro seniales
	hilo_periodico_con_temporizador.AsignarFuncionYDato(HiloPeriodicoConTemporizador, &seniales);
	
	hilo_sigint.Lanzar();
	hilo_periodico_con_retardos.Lanzar();
	hilo_periodico_con_temporizador.Lanzar();

	//Esperar al hilo HiloSigInt
	hilo_sigint.Join();

	//Esperar al hilo HiloPeriodicoConRetardos
	hilo_periodico_con_retardos.Join();

	//Esperar al hilo HiloPeriodicoConTemporizador
	hilo_periodico_con_temporizador.Join();

}

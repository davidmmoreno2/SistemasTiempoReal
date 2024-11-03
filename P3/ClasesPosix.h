//Incluir la librería de utilización de hilos posix
#include <pthread.h>

/*
**********************************************************
********************** Clase hilo_t **********************
**********************************************************
*/

//Definir la clase hilo_t
class hilo_t {
	//Parte privada
	private:
		int idHilo;
		pthread_t manejador;
		pthread_attr_t atributoH;
		void *(*funcionAsig)(void*);
		void *dato;
		
		//Definir un atributo de clase de tipo pthread_t. Este atributo será el manejador del hilo asociado a la clase
		
		//Definir un atributo de clase de tipo pthread_attr_t para guardar los atributos de creación del hilo
		
		/*Definir un atributo de clase para almacenar la función asignada al hilo. La definición debe cumplir el formato void *(*Atributo)(void *),
		donde Atributo es el nombre que se le dará al atributo de la clase (se recomienda usar nombres descriptivos y no dejar Atributo como nombre)*/
		
		//Definir un atributo de clase de tipo puntero a void para almacenar los datos enviados a la función
		
	//Parte pública
	public:
		//Definir el constructor sin parámetros.
		hilo_t();

		//Definir el destructor sin parámetros.
		~hilo_t();
		
		//Definir el método Lanzar sin parámetros y que retorna un entero
		int Lanzar();

		/*Definir el método AsignarFuncion con un parámetro que será la función que utilice el hilo. La definición debe cumplir el formato void *(*Atributo)(void *),
		donde Atributo es el nombre que se le dará al atributo de la función (se recomienda usar nombres descriptivos y no dejar Atributo como nombre).
		La función no devuelve ningún dato. */
		void AsignarFuncion (void *(*hilo)(void *));

		/*Definir el método AsignarDato con un parámetro de tipo puntero a void que será el dato que se usará con la función que utilice el hilo.
		La función no devuelve ningún dato. */
		void AsignarDato (void *dat);

		/*Definir el método AsignarFuncionYDato con dos parámetros, uno con la función que usará el hilo y el otro con el dato que usará dicha función
		(misma definición que en los métodos AsignarFuncion y AsignarDato). La función no devuelve ningún dato.*/
		void AsignarFuncionYDato(void *(*hilo)(void *), void *dat);

		//Definir el método Join sin parámetros y que devuelva un puntero a void.
		void * Join();

		//Definir el método ObtenerManejador sin parámetros y que devuelva el manejador del hilo (pthread_t).
		pthread_t ObtenerManejador();

		//Definir el método ObtenerIdentificador sin parámetros y que devuelva el identificador del hilo (int).
		int ObtenerIdentificador();
};


/*
**********************************************************
********************** Clase mutex_t *********************
**********************************************************
*/

//Definir la clase mutex_t
class mutex_t {
	//Parte privada
	private:
		//Definir un atributo de clase de tipo pthread_mutex_t. Este atributo será el manejador del mutex asociado a la clase
		pthread_mutex_t manejadorMutex;

		//Definir un atributo de clase de tipo pthread_mutexattr_t para guardar los atributos de creación del mutex
		pthread_mutexattr_t datosMutex;
	//Parte pública
	public:
		//Definir el constructor sin parámetros.
		mutex_t();
		
		//Definir el destructor sin parámetros.
		~mutex_t();

		//Definir el método Inicializar sin parámetros y que retorne un entero.
		int Inicializar();

		//Definir el método Lock sin parámetros y que retorna un entero.
		int Lock();
		
		//Definir el método Unlock sin parámetros y que retorna un entero.
		int Unlock();
		
		//Definir el método ObtenerManejador sin parámetros y que retorna un puntero a pthread_mutex_t
		pthread_mutex_t *ObtenerManejador();
		
};

/*
**********************************************************
*************** Clase variable_condicion_t ***************
**********************************************************
*/

//Definir la clase variable_condicion_t
class variable_condicion_t {
	//Parte privada
	private:
		//Definir un atributo de clase de tipo pthread_cond_t. Este atributo será el manejador de la variable de condición asociada a la clase.
		pthread_cond_t manejadorCondicion;

		//Definir un atributo de clase de tipo pthread_condattr_t para guardar los atributos de creación de la variable de condición.
		pthread_condattr_t datosCondicion;
		
		//Definir un atributo de clase de tipo puntero a pthread_mutex_t para guardar el mutex al que se asociará la variable de condición.
		pthread_mutex_t* variableCondicion;

	//Parte pública
	public:
		//Definir el constructor sin parámetros.
		variable_condicion_t();

		//Definir el destructor sin parámetros.
		~variable_condicion_t();

		//Definir el método Inicializar sin parámetros y que retorne un entero.
		int Inicializar();
		
		//Definir el método Inicializar con un parámetro de tipo puntero a pthread_mutex_t y que retorne un entero.
		int Inicializar(pthread_mutex_t* condicion);

		//Definir el método AsociarManejadorMutex con un parámetro de tipo puntero a pthread_mutex_t y que no retorne nada.
		void AsociarManejadorMutex(pthread_mutex_t* condicion);

		//Definir el método Wait sin parámetros y que retorna un entero.
		int Wait();

		//Definir el método TimedWait con un parámetro de tipo struct timespec y que retorna un entero.
		int TimedWait(struct timespec tiempo);

		//Definir el método Signal sin parámetros y que retorna un entero.
		int Signal();
		
		//Definir el método Broadcast sin parámetros y que retorna un entero.
		int Broadcast();
		
};
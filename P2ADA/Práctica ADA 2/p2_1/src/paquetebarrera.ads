--Inicio el paquete paquetebarrera
package paquetebarrera is
   -- Definir el tipo Barrera_t privado y limitado (type NombreTipo is limited private) para poder usarlo fuera del paquete. Recibirá un parámetro de tipo positive
   -- (al ser de tipo positive, debe ser un valor mayor que 0) con el número de tareas que bloqueará (10 por defecto)
   type Barrera_t (Num_Tareas:Positive := 10)  is limited private;  

   -- Definir el procedimiento SincronizarEnBarrera con un parámetro de entrada salida de tipo Barrera_t
   procedure SincronizarEnBarrera(Barrera: in out Barrera_t);

   -- Definir el procedimiento ResetearBarrera con dos parámetros, uno de entrada salida de tipo Barrera_t y otro de entrada de tipo Positive para cambiar
   -- el límite de la barrera
   procedure ResetearBarrera(Barrera: in out Barrera_t; Nuevo_Limite:Positive);
    

   -- Definir la región privada del paquete
private

   -- Definir el objeto protegido Barrera_t. Debe coincidir con la definición privada del comienzo del paquete
   protected type Barrera_t (Num_Tareas:Positive := 10) is

      -- Definir el procedimiento Sincronizar sin parámetros
      procedure Sincronizar;

      -- Definir la entrada Wait sin parámetros
      entry Wait;

      -- Definir el procedimiento Resetear con un parámetro de tipo positive
      procedure Resetear(Nuevo_Limite:Positive);
        
      -- Definir la región privada del objeto protegido
   private

      -- Definir una variable de tipo natural (al ser de tipo natural, no puede tener valores negativos) para llevar la cuenta de las tereas que tienen que llegar a la barrera
      Contador_Tareas:Natural:=0;

      -- Definir una variable de tipo positive para almacenar el número de tareas que se vab a bloquear en la tarea. Inicializarlo con el parámetro de creación del objeto protegido
      Limite_Tareas:Positive:=Num_Tareas;

      -- Definir una variable de tipo booleano para indicar que las tareas pueden pasar o no e inicializarla a falso
      Tareas_Posibles:Boolean:=False;

      -- Fin del objeto protegido Barrera_t
   end Barrera_t;

   --Fin del paquete paquetebarrera
end paquetebarrera;

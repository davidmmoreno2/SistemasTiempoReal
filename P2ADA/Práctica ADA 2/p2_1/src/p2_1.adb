with GNAT.IO; use GNAT.IO;
-- A�adir el paquete paquetebarrera
with paquetebarrera;


procedure p2_1 is
   procedure imprimir_bloqueo is begin
      Put_line("Una tarea se ha bloqueado en la barrera");
   end imprimir_bloqueo;

   procedure imprimir_desbloqueo is begin
      Put_line("Una tarea ha abandonado la barrera");
   end imprimir_desbloqueo;

   -- Definir una constante de tipo Positive para indicar el n�mero de tareas que se bloquear�n en la barrera (establecer la constante en 10)
   Num_Tareas:constant Positive:=10;

   -- Definir el tipo PBarrera_t de tipo puntero a Barrera_t de la forma "type TipoPuntero is access all TipoNoPuntero;". Esto es necesario para que la barrera
   -- sea compartida por todas las tareas
   type PBarrera_t is access all paquetebarrera.Barrera_t;
  
   -- Definir una variable de tipo Barrera_t. Deberemos permitir el acceso a su direcci�n de memoria (usar la palabra reservada aliased delante del tipo).
   -- Usar la constante definida anteriormente como dato de inicializaci�n
   Barrera: aliased paquetebarrera.Barrera_t(Num_Tareas);
 
   -- Dejinir el tipo tarea TareaEnBarrera con un par�metro de tipo PBarrera_t
   task type TareaEnBarrera(Barrera:PBarrera_t);

   -- Implementar el cuerpo del tipo tarea
   task body TareaEnBarrera is
      begin

      -- Mostrar el mensaje Entrando en la barrera (usar el procedimiento imprimir_bloqueo)
      imprimir_bloqueo;   

      -- Invocar al procedimiento SincronizarEnBarrera pasando como par�metro el campo .all del par�metro de la tarea (el par�metro de la tarea es un puntero a
      -- Barrera_t y el procedimiento SincronizarEnBarrera recibe un Barrera_t, por lo que se usa .all para acceder al contenido del puntero)
      paquetebarrera.SincronizarEnBarrera(Barrera.all);      

      -- Mostrar el mensaje Saliendo de la barrera (usar el procedimiento imprimir_desbloqueo)
      imprimir_desbloqueo;

   --Fin cuerpo de la tarea TareaEnBarrera
   end TareaEnBarrera;

   -- Definir una variable de tipo array de TareaEnBarrera usando la constante definida anteriormente para establecer el n�mero de elementos del array.
   -- Hay que usar la direcci�n de la barrera definida en el comienco del programa principal como par�metro de TareaEnBarrera (atributo 'Access de dicha variable)
   Tareas:array(1..Num_Tareas) of TareaEnBarrera(Barrera'Access);
   

begin
   null;
end p2_1;

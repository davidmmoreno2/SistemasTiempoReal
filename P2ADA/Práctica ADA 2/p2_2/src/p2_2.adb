with GNAT.IO; use GNAT.IO;
-- A�adir el paquete controlador
with controlador;


procedure p2_2 is
   procedure senial_capturada(capturadas: Natural; max_capturas: Positive) is begin
      Put_line("Se han capturado" & integer'image(capturadas) & " se�ales SIGINT de" & integer'image(max_capturas));
   end senial_capturada;

   -- Definir el tipo tarea EsperarCtrlC con un par�metro de tipo positive (tiene que ser mayor que 0) para indicar el n�mero de se�ales esperadas
 task type EsperarCtrlC(max_capturas: Positive) is
   end EsperarCtrlC;

   -- Implementaci�n el cuerpo del tipo tarea EsperarCtrlC
   task body EsperarCtrlC is

      
   -- Zona de declaraci�n
   
     -- Declarar una variable de tipo Natural (puede contener valores mayores o iguales que 0) para contar el n�mero de ocurrencias de la se�al SIGINT e inicializarla a 0
      capturadas: Natural := 0;

   -- Zona de c�digo
   begin

      -- Mientras no se hayan recibido las se�ales esperadas
      while capturadas < max_capturas loop

         -- Invocar a la entrada Wait de ControladorSigInt para esperar a que se pulse Ctrl+C
         controlador.ControladorSigInt.Wait;

         -- Incrementar las se�ales recibidas
         capturadas := capturadas + 1;

         -- Mostrar el mensaje "Se han capturado xxxx se�ales SIGINT de yyyy" siendo xxxx el n�mero de se�ales capturadas e yyyy el n�mero de se�ales esperadas (usar el procedimiento
         -- senial_capturada)
         senial_capturada(capturadas, max_capturas);

      -- Fin mientras
      end loop;

   -- Fin del cuerpo del tipo tarea EsperarCtrlC
   end EsperarCtrlC;

   -- Crear una tarea de tipo EsperarCtrlC pasando por par�metros el n�mero de se�ales SIGINT que debe recibir
   tarea_ctrl_c: EsperarCtrlC( 3);

begin
   null;
end p2_2;

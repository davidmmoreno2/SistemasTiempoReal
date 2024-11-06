with GNAT.IO; use GNAT.IO;
-- Incluir el paquete pila_acotada (con with y use)
with pila_acotada; use pila_acotada;


procedure p1 is
   NUM_HILOS:constant integer:=5;
   REPETICIONES:constant integer:=50;

   procedure imprimir_escritura(dato: integer) is begin
      Put_line("Se ha añadido el valor" & integer'image(dato) & " a la pila");
   end imprimir_escritura;

   procedure imprimir_lectura(dato: integer) is begin
      Put_line("Se ha leído el valor" & integer'image(dato) & " de la pila");
   end imprimir_lectura;
	
   -- Definir una variable Pila de tipo PilaAcotada iniciándola a 20 permitiendo el acceso a su dirección de memoria (usar la palabra reservada aliased delante del tipo)
   Pila:aliased PilaAcotada(20);
   -- Definir un tipo PPila_Acotada_t de tipo puntero a PilaAcotada de la forma "type TipoPuntero is access all TipoNoPuntero;"
   type PPila_Acotada_t is access all PilaAcotada;
   -- Definir un tipo tarea TProductor con un parámetro P de tipo PPila_Acotada_t. Lo hacemos de tipo puntero para que la pila sea compartida por todas las tareas
   
   -- Implementar el cuerpo del tipo tarea TProductor
   task type TProductor(P:PPila_Acotada_t);
                         
   task body TProductor is
   begin
      for i in 0..REPETICIONES-1 loop
         P.PilaAniadir(i);
         imprimir_escritura(i);
      end loop;
   end TProductor;
                        
   --Comienzo del código de la tarea TProductor

      -- Para i desde 0 hasta REPETICIONES-1

         -- Llamar al método PilaAniadir del objeto P con el parámetro i

         -- Imprimir el mensaje "Se ha añadido el valor xxxx a la pila", siendo xxxx el valor añadido

      -- Fin para

   -- Fin cuerpo de Tproductor


   -- Definir un tipo tarea TConsumidor con un parámetro P de tipo PPila_Acotada_t. Lo hacemos de tipo puntero para que la pila sea compartida por todas las tareas

   -- Implementar el cuerpo del tipo tarea TConsumidor
   task type TConsumidor(P:PPila_Acotada_t);
                         
   task body TConsumidor is
      Dato:Integer;
   begin
      for i in 0..REPETICIONES-1 loop
         P.PilaSacar(Dato);
         imprimir_lectura(Dato);
      end loop;
   end TConsumidor;

      -- Definir una variable entera para almacenar el dato leído

   -- Comienzo del código de la tarea TConsumidor

      -- Para i desde 0 hasta REPETICIONES-1

         -- Llamar al método PilaSacar del objeto P usando como parámetro la variable entera definida anteriormente

         -- Imprimir el mensaje "Se ha leído el valor xxxx de la pila", siendo xxxx el valor leído

      -- Fin para

   -- Fin cuerpo de TConsumidor


   -- Definir una variable Prods de tipo array de 1 hasta NUM_HILOS de tipo TProductor. Usar la dirección de Pila como parámetro de entrada (atributo Access de Pila)
   Prods:array(1..NUM_HILOS) of TProductor(Pila'Access);
   Cons:array(1..NUM_HILOS) of TConsumidor(Pila'Access);
   -- Definir una variable Cons de tipo array de 1 hasta NUM_HILOS de tipo TConsumidor. Usar la dirección de Pila como parámetro de entrada (atributo Access de Pila)

begin
   null;
end p1;

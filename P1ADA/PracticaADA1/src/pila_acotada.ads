--Inicio del paquete pila_acotada
package pila_acotada is
   type VectorEntero is array(integer range <>) of integer;
   protected type PilaAcotada (T:positive:=10) is
      entry PilaAniadir(Item: in integer);
      entry PilaSacar (Item: out integer);
   private
      Tamanio_Pila: positive:=T;
      cima: Natural:= 0;
      Pila: VectorEntero(1..T);
   end PilaAcotada;
end pila_acotada;
   --Definir un tipo VectorEntero como un array de tamaño indefinido (usar "integer range <>" como rango) de tipo entero

   -- Definir el objeto protegido PilaAcotada con un parámetro entero que indicará el tamaño de la pila. Darle 10 como valor por defecto

      -- Añadir la entrada PilaAniadir que reciva el dato a insertar

      -- Añadir la entrada PilaSacar que devuelva el dato leído

   -- definir la zona privada del objeto

      -- Definir la variable Tamanio_Pila e inicializarla al valor que recibe el objeto por parámetro

      -- Definir e inicializar el atributo cima de tipo Natural e inicializarlo a 0. Este atributo va a indicar el número de elementos que tiene la pila así como la posición del
      -- último elemento añadido (si Cima>0). Por tanto, para añadir un elemento, se incrementa en la posición indicada por Cima y luego se inserta en la posición indicada
      -- por dicho atributo y para sacar un elemento se accede a la posición indicada por Cima y después se decrementa dicho atributo

      -- Definir el atributo Pila de tipo VectorEntero estableciendo el rango entre 1 y el valor que recibe el objeto por parámetro para definir el tamaño del array

      --Final del objeto protegido PilaAcotada

--Fin del paquete pila_acotada

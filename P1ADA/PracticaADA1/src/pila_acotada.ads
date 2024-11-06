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
   --Definir un tipo VectorEntero como un array de tama�o indefinido (usar "integer range <>" como rango) de tipo entero

   -- Definir el objeto protegido PilaAcotada con un par�metro entero que indicar� el tama�o de la pila. Darle 10 como valor por defecto

      -- A�adir la entrada PilaAniadir que reciva el dato a insertar

      -- A�adir la entrada PilaSacar que devuelva el dato le�do

   -- definir la zona privada del objeto

      -- Definir la variable Tamanio_Pila e inicializarla al valor que recibe el objeto por par�metro

      -- Definir e inicializar el atributo cima de tipo Natural e inicializarlo a 0. Este atributo va a indicar el n�mero de elementos que tiene la pila as� como la posici�n del
      -- �ltimo elemento a�adido (si Cima>0). Por tanto, para a�adir un elemento, se incrementa en la posici�n indicada por Cima y luego se inserta en la posici�n indicada
      -- por dicho atributo y para sacar un elemento se accede a la posici�n indicada por Cima y despu�s se decrementa dicho atributo

      -- Definir el atributo Pila de tipo VectorEntero estableciendo el rango entre 1 y el valor que recibe el objeto por par�metro para definir el tama�o del array

      --Final del objeto protegido PilaAcotada

--Fin del paquete pila_acotada

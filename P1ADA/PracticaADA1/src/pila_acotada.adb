--Inicio del cuerpo del paquete pila_acotada
package body pila_acotada is

-- Definir el cuerpo del objeto protegido PilaAcotada
   protected body PilaAcotada is
      entry PilaAniadir(Item: in integer)
        when Cima < Tamanio_Pila is
      begin
         Cima:= Cima + 1;
         Pila(Cima):=Item;
      end PilaAniadir;
      entry PilaSacar(Item: out integer)
        when Cima > 0 is
      begin
         Item:=Pila(Cima);
         Cima:=Cima-1;
      end PilaSacar;
   end PilaAcotada;

end pila_acotada;
      -- A�adir la cabecera de la entrada PilaAniadir (debe ser igual que en el fichero .ads)

      -- A�adir la condici�n de acceso a la entrada (Pila no llena) de la forma "when Condici�n is", siendo Condici�n la condici�n que se debe cumplir para entrar en la entrada

	  -- Comienzo del c�digo de la entrada PilaAniadir

		 -- Incrementar Cima

		 -- A�adir Item a la posici�n Cima de Pila

      -- Fin de la entrada PilaAniadir


      -- A�adir la cabecera de la entrada PilaSacar (debe ser igual que en el fichero .ads)

      -- A�adir la condici�n de acceso a la entrada (Pila no vac�a) de la forma "when Condici�n is", siendo Condici�n la condici�n que se debe cumplir para entrar en la entrada

      -- Comienzo del c�digo de la entrada PilaSacar

         -- Guardar en Item el contenido de la posici�n Cima de Pila

         -- Decrementar Cima

      -- Fin de la entrada PilaSacar

   -- Fin del cuerpo del del objeto protegido PilaAcotada

--Fin del paquete pila_acotada

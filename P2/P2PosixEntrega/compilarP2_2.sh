if [ -z $1 ]; then echo "Debe incluirse la ruta del fichero ClasesPosix.cpp"
else
	if [ ! -d $1 ]; then echo "la ruta al fichero ClasesPosix.cpp es errónea"
	else g++ -I$1 p2_2.cpp $1/ClasesPosix.cpp $1/Identificador.cpp -o p2_2 -lpthread
	fi
fi

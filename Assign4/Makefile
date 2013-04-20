

main: sale.o menu4.o register.o
			g++ -o main sale.o menu4.o register.o

sale.o: sale.cpp sale.h 
		g++ -c sale.cpp sale.h 

register.o: register.cpp register.h sale.o
				g++ -c register.cpp register.h

menu4.o: menu4.cpp



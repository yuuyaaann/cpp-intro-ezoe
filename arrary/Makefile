gcc_ options = -std=c++17 -Wall --pedantic-error

program :
	g++ $(gcc_options) $(CFLAGS) src/main.cpp -include ../all.h include/array.h include/array_iterator.h

run : 
	program ./program

clean : 
	rm -f ./program 
	rm -f ./all.h.gch

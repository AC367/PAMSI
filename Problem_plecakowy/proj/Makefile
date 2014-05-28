__start__: obj p_plecakowy
	./p_plecakowy

CPPFLAGS=-Wall -pedantic -Iinc -c
LDFLAGS=-Wall


obj:
	mkdir obj

p_plecakowy: obj/main.o obj/p_plecakowy.o
	g++ ${LDFLAGS} -o p_plecakowy obj/main.o obj/p_plecakowy.o

obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/p_plecakowy.o: src/p_plecakowy.cpp inc/p_plecakowy.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/p_plecakowy.o src/p_plecakowy.cpp
	

clean:
	rm -f p_plecakowy obj/* core*

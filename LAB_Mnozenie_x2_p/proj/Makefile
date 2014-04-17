__start__: obj mnozenie
	./mnozenie

CPPFLAGS=-Wall -pedantic -Iinc -c
LDFLAGS=-Wall



obj:
	mkdir obj

mnozenie: obj/main.o obj/funkcje.o

	g++ ${LDFLAGS} -o mnozenie obj/main.o obj/funkcje.o

obj/main.o: src/main.cpp inc/funkcje.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/funkcje.o: src/funkcje.cpp
	g++ -c -Wall -pedantic -g -Iinc -o obj/funkcje.o src/funkcje.cpp

clean:
	rm -f mnozenie obj/* core*

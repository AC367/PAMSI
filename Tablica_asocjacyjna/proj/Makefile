__start__: obj tablica_a
	./tablica_a

CPPFLAGS=-Wall -pedantic -Iinc -c
LDFLAGS=-Wall


obj:
	mkdir obj

tablica_a: obj/main.o
	g++ ${LDFLAGS} -o tablica_a obj/main.o

obj/main.o: src/main.cpp inc/tablica_asocjacyjna.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f tablica_a obj/* core*

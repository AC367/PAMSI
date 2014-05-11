__start__: obj graf
	./graf

CPPFLAGS=-Wall -pedantic -Iinc -c
LDFLAGS=-Wall



obj:
	mkdir obj

graf: obj/main.o obj/graf.o
	g++ ${LDFLAGS} -o graf obj/main.o obj/graf.o

obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/graf.o: src/graf.cpp inc/graf.hh
	g++ ${CPPFLAGS} -o obj/graf.o src/graf.cpp

clean:
	rm -f graf obj/* core*

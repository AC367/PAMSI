__start__: obj tablica_a
	./tablica_a

CPPFLAGS=-Wall -pedantic -Iinc -c
LDFLAGS=-Wall


obj:
	mkdir obj

tablica_a: obj/main.o obj/drzewo_binarne.o obj/funkcje.o obj/tablica_haszujaca.o
	g++ ${LDFLAGS} -o tablica_a obj/main.o obj/drzewo_binarne.o obj/funkcje.o obj/tablica_haszujaca.o

obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/drzewo_binarne.o: src/drzewo_binarne.cpp inc/drzewo_binarne.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/drzewo_binarne.o src/drzewo_binarne.cpp

obj/funkcje.o: src/funkcje.cpp inc/funkcje.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/funkcje.o src/funkcje.cpp

obj/tablica_haszujaca.o: src/tablica_haszujaca.cpp inc/tablica_haszujaca.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/tablica_haszujaca.o src/tablica_haszujaca.cpp	

clean:
	rm -f tablica_a obj/* core*

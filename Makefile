OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o Bici.o Estacio.o Cjt_bici.o Bicing.o
	g++ -o program.exe program.o Bici.o Estacio.o Cjt_bici.o Bicing.o

program.o: program.cc Bicing.hh Estacio.hh Bici.hh Cjt_bici.hh
	g++ -c program.cc $(OPCIONS)

Bici.o: Bici.cc Bici.hh
	g++ -c Bici.cc $(OPCIONS)

Estacio.o: Estacio.cc Estacio.hh Bici.hh
	g++ -c Estacio.cc $(OPCIONS)

Cjt_bici.o: Cjt_bici.cc Cjt_bici.hh Bici.hh
	g++ -c Cjt_bici.cc $(OPCIONS)

Bicing.o: Bicing.cc Bicing.hh Bici.hh Estacio.hh
	g++ -c Bicing.cc $(OPCIONS)

tar:
	tar -cvf practica.tar *.cc *.hh Makefile 

clean:
	rm -f *.o
	rm -f *.gch
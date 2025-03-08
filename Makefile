
all: reading.exe

reading.exe: reader.o
	g++ reader.o -o reading.exe

reader.o: reader.cc
	g++ -c reader.cc

clean:
	rm -f *.o
	rm -f *.exe

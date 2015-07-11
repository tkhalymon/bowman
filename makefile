UNAME = $(shell uname -o)
ifeq ($(OS),Windows_NT)
	EXEEXT = .exe
	COMPILE_OPT = -lopengl32 -lglu32 -lfreeglut -Wl,--subsystem,windows
else
	COMPILE_OPT = -lGL -lglut -lGLU
endif


ifeq ($(UNAME), Msys)
	EXEEXT = .exe
endif

all: bowman
bowman: main.o bowman.o arrow.o pos.o pngtex.o lodepng.o
	g++ main.o bowman.o arrow.o pos.o pngtex.o lodepng.o $(COMPILE_OPT) -o bowman
main.o: main.cpp
	g++ -c main.cpp
bowman.o: bowman.cpp
	g++ -c bowman.cpp
arrow.o: arrow.cpp
	g++ -c arrow.cpp
pos.o: pos.cpp
	g++ -c pos.cpp
pngtex.o: pngtex.cpp
	g++ -c pngtex.cpp
lodepng.o: lodepng.cpp
	g++ -c lodepng.cpp
run:
	./bowman$(EXEEXT)
clean:
	rm *.o bowman$(EXEEXT)
test:
	valgrind ./bowman$(EXEEXT)
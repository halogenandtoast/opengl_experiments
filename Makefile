CC = g++
LDFLAGS=-framework GLUT -framework OpenGL -lGLEW
all: main

main: main.o shader.o program.o
	${CC} ${LDFLAGS} main.o shader.o program.o -o main

main.o: main.cc
	${CC} -c main.cc

shader.o: shader.cc
	${CC} -c shader.cc

program.o: program.cc
	${CC} -c program.cc

clean:
	rm -rf *o main

CC = g++
LDFLAGS = -framework GLUT -framework OpenGL -lGLEW
CFLAGS = -O
SRC = src/main.cc src/program.cc src/shader.cc
OBJ = ${SRC:.c=.o}

all: main

.c.o:
	${CC} -c ${CFLAGS} -o $@ $<

main: ${OBJ}
	${CC} ${LDFLAGS} ${OBJ} -o main


clean:
	rm -rf src/*.o main

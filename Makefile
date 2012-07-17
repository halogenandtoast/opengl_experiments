CC = g++
LDFLAGS=-framework GLUT -framework OpenGL -lGLEW
all: main
clean:
	rm main

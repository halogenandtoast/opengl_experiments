#define GLEW_STATIC

#include <iostream>
#include <GL/glew.h>
#include <GLUT/glut.h>

#include "shader.h"

GLuint program;
GLint position;
GLuint vbo;

GLfloat vertices[] = {
  0, 0.5, 0.5, -0.5, -0.5, -0.5
};

void display(void)
{
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);
  glUseProgram(program);
  glEnableVertexAttribArray(position);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glutSwapBuffers();
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(640, 480);
  glutCreateWindow("Titan");
  glutDisplayFunc(display);

  glewExperimental = GL_TRUE;
  glewInit();

  Shader vert(GL_VERTEX_SHADER, "main.vert.glsl");
  Shader frag(GL_FRAGMENT_SHADER, "main.frag.glsl");
  program = glCreateProgram();
  glAttachShader(program, vert.shader());
  glAttachShader(program, frag.shader());
  glLinkProgram(program);

  position = glGetAttribLocation(program, "position");
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(position, 2, GL_FLOAT, GL_TRUE, 0, 0);

  glutMainLoop();

  return 0;
}

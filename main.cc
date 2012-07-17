#define GLEW_STATIC

#include <iostream>
#include <GL/glew.h>
#include <GLUT/glut.h>

void display(void)
{
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor4f(1, 0, 1, 1);
  glBegin(GL_TRIANGLES);
    glVertex3f(0, 0.5, 0);
    glVertex3f(0.5, -0.5, 0);
    glVertex3f(-0.5, -0.5, 0);
  glEnd();
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

  glutMainLoop();

  return 0;
}

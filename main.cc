#include <iostream>
#include <GLUT/glut.h>

void display(void)
{
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);
  glutSwapBuffers();
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(640, 480);

  glutCreateWindow("Titan");

  glutDisplayFunc(display);

  glutMainLoop();
  return 0;
}

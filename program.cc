#include "program.h"
#include "shader.h"
#include <OpenGL/gl.h>

Program::Program (const char* vertex_shader_file, const char* fragment_shader_file) {
  Shader vert(GL_VERTEX_SHADER, vertex_shader_file);
  Shader frag(GL_FRAGMENT_SHADER, fragment_shader_file);
  vertex_shader = vert.shader();
  fragment_shader = frag.shader();
  program = glCreateProgram();

  glAttachShader(program, vertex_shader);
  glAttachShader(program, fragment_shader);
  glLinkProgram(program);
}

GLuint Program::getProgram(void) const {
  return program;
}

void Program::use(void) {
  glUseProgram(program);
}

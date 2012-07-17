#include "shader.h"
#include <fstream>
#include <iterator>
#include <string>
#include <iostream>
#include <OpenGL/gl.h>

Shader::Shader (GLenum type, const char *file)
{
  filename = file;
  shaderType = type;
}

const char *Shader::source(void) const
{
  std::ifstream file(filename);
  std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
  const char *source = str.c_str();
  return source;
}

GLuint Shader::shader() {
  GLuint shader = glCreateShader(shaderType);
  const char *shader_source = source();
  glShaderSource(shader, 1, &shader_source, NULL);
  glCompileShader(shader);
  GLint status;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
  if(status == GL_FALSE) {
    char buffer[513];
    glGetShaderInfoLog(shader, 512, NULL, buffer);
    std::cout << filename << std::endl;
    std::cout << buffer << std::endl;
  }
  return shader;
}

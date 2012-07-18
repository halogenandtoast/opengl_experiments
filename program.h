#pragma once
#include <OpenGL/gl.h>
class Program {
    GLuint vertex_shader;
    GLuint fragment_shader;
    GLuint program;
  public:
    Program (const char* vertex_shader_file, const char* fragment_shader_file);
    void use(void);
    GLuint getProgram(void) const;
};

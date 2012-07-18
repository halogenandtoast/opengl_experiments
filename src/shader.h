#pragma once
#include <OpenGL/gl.h>
class Shader {
    const char *filename;
    GLenum shaderType;
  public:
    Shader (GLenum type, const char *file);
    const char *source (void) const;
    GLuint shader();
};

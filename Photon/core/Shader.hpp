#pragma once
#include "../pch.h"
#include <string>
namespace Photon {
namespace Shader {
class Shader {
  public:
    void load( std::string fpath, std::string vpath ) {}

  private:
    unsigned int vertexShader;
    unsigned int fragShader;
};
} // namespace Shader
} // namespace Photon
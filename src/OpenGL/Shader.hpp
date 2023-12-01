#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    unsigned int ID;

    // default constructor
    Shader();

    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Shader(const char* vertexPath, const char* fragmentPath);

    // activate the shader
    // ------------------------------------------------------------------------
    void use();

    // utility uniform functions
    // ------------------------------------------------------------------------
    void setBool(const std::string &name, bool value);

    // ------------------------------------------------------------------------
    void setInt(const std::string &name, int value);

    // ------------------------------------------------------------------------
    void setFloat(const std::string &name, float value);

private:
    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    void checkCompileErrors(unsigned int shader, std::string type);
};
#


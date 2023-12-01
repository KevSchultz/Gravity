//  ██╗  ██╗███████╗
//  ██║ ██╔╝██╔════╝
//  █████╔╝ ███████╗
//  ██╔═██╗ ╚════██║
//  ██║  ██╗███████║
//  ╚═╝  ╚═╝╚══════╝
/*
 *  Mesh.hpp
 *  The mesh class is used to store vertices and indices.
 *  It is used by the renderer class.
 * 
*/
#pragma once

#include <vector>
#include "Shader.hpp"

class Mesh
{
public:

    /** @brief constructor for the Mesh class
     * 
     * @param vertices vector of vertices
     * 
     * @param indices vector of indices
     * 
     * @return Mesh object
    */
    Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);

    /** @brief destructor for the Mesh class
     * 
     * @return void
     */
    ~Mesh();

    /**
     * 
    */
   void draw(Shader &shader);
    
private:
    unsigned int VAO, VBO, EBO;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
};
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
#include "Mesh.hpp"
#include "Shader.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

/** @brief constructor for the Mesh class
 *
 * @param vertices vector of vertices
 *
 * @param indices vector of indices
 *
 * @return Mesh object
 */
Mesh::Mesh(const std::vector<float> &vertices, const std::vector<unsigned int> &indices)
{
    this->vertices = vertices;
    this->indices = indices;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // unbind buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // unbind vertex array
    glBindVertexArray(0);
}

/** @brief destructor for the Mesh class
 *
 * @return void
 */
Mesh::~Mesh()
{
    std::cout << "In Mesh destructor" << std::endl;
    // glDeleteVertexArrays(1, &VAO);
    // glDeleteBuffers(1, &VBO);
}

void Mesh::draw(Shader &shader)
{
    //std::cout << "Attempting to draw VAO: " << VAO << std::endl;
    shader.use();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

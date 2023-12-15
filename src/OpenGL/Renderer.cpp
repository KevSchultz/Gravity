//  ██╗  ██╗███████╗
//  ██║ ██╔╝██╔════╝
//  █████╔╝ ███████╗
//  ██╔═██╗ ╚════██║
//  ██║  ██╗███████║
//  ╚═╝  ╚═╝╚══════╝
/*
 *  Renderer.cpp
 *
 *
 */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Renderer.hpp"
#include "Shader.hpp"

/** @brief Constructor for the Renderer class.
 *
 * 
 * @return Renderer object
 */
Renderer::Renderer()
{
	shaderProgram = Shader("/home/kevin/Source/gravity/src/OpenGL/shaders/vertex.glsl", "/home/kevin/Source/gravity/src/OpenGL/shaders/fragment.glsl");
	std::cout << "GL error number : " << glGetError() << std::endl;
}

/** @brief Destructor for the Renderer class.
 *
 * @return void
 *
 */
Renderer::~Renderer()
{
	std::cout << "In Renderer destructor" << std::endl;

	// empty meshes
	meshes.clear();
}

/** @brief Draw Mesh objects to window
 *
 * @return void
 */
void Renderer::draw()
{
	for (Mesh *mesh : meshes)
	{
		// render
		mesh->draw(shaderProgram);
	}
}

/** @brief Add Meshes to renderer vector
 *
 * @return void
 */
void Renderer::addMesh(Mesh *mesh)
{
	meshes.push_back(mesh);
}

/** @brief clear screen
 *
 * @return void
 *
 */
void Renderer::clearScreen()
{
	// clear screen
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT); // also clear the depth buffer now!
}

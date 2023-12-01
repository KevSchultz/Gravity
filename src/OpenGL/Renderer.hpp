//  ██╗  ██╗███████╗
//  ██║ ██╔╝██╔════╝
//  █████╔╝ ███████╗
//  ██╔═██╗ ╚════██║
//  ██║  ██╗███████║
//  ╚═╝  ╚═╝╚══════╝
/*
 *  Renderer.hpp
 *  The renderer class is used to render objects.
 *  It uses the window class.
 *
 */
#pragma once

#include "Mesh.hpp"
#include "Shader.hpp"

#include <string>
#include <vector>

class Renderer
{
public:
	/** @brief Constructor for the Renderer class.
	 * 
	 * @return Renderer object
	 */
	Renderer();

	/** @brief Destructor for the Renderer class.
	 *
	 * @return void
	 *
	 */
	~Renderer();

	/** @brief Draw Mesh objects to window
	 * 
	 * @return void
	*/
	void draw();

	/** @brief clear screen
	 *
	 * @return void
	 *
	 */
	void clearScreen();

	/** @brief Add Meshes to renderer vector 
	 * 
	 * @return void
	*/
	void addMesh(Mesh *mesh);

private:
	Shader shaderProgram;
	std::vector<Mesh *> meshes;
};
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

#include "Window.hpp"
#include "Mesh.hpp"

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

	/** @brief clear screen
	 *
	 * @return void
	 *
	 */
	void clearScreen();

private:
	Window window;
	std::vector<Mesh> meshes;
};
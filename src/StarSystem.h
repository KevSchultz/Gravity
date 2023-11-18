/*
 * StarSystem.h
 * This file defines the StarSystem class, which represents a N-body gravity simulation.
 * The StarSystem class includes methods for updating and rendering the star system.
 * Created by Kevin Schultz.
 */

#pragma once

#include "shader.h"

#include <glm/glm.hpp>


// struct Particle
// {
// 	glm::vec2 Position;
// };

class StarSystem
{
public:


	/** @brief constructor for the StarSystem class
	 * 
	 * @param n number of particles in the system
	 * 
	 * @return a StarSystem object
	 */
	StarSystem(int n);

	// Destructor for the StarSystem class.

	void onUpdate();

	void onRender();

private:
	int n;
	unsigned int VBO, VAO;
	
	glm::vec2 position;

};
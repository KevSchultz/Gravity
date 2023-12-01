//  ██╗  ██╗███████╗
//  ██║ ██╔╝██╔════╝
//  █████╔╝ ███████╗
//  ██╔═██╗ ╚════██║
//  ██║  ██╗███████║
//  ╚═╝  ╚═╝╚══════╝
/*
 *  Gravity
 *  A simple n-body gravity simulator
 *
 */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Renderer.hpp>
#include <Mesh.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

int main()
{

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// window creation
	GLFWwindow *window = glfwCreateWindow(1000, 1000, "Default", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit(EXIT_FAILURE);
	}

	Renderer renderer = Renderer();

	// Number of segments to represent the circle
	const int segments = 100;

	// Radius of the circle
	const float radius = 0.1f;

	std::vector<float> vertices;
	std::vector<unsigned int> indices;

	// Center of the circle
	vertices.push_back(0.8f);
	vertices.push_back(0.0f);
	vertices.push_back(0.0f);

	for (int i = 0; i <= segments; ++i)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(segments);
		float dx = radius * cosf(theta) + 0.8f;
		float dy = radius * sinf(theta);

		vertices.push_back(dx);
		vertices.push_back(dy);
		vertices.push_back(0.0f);

		if (i > 0)
		{
			indices.push_back(0);
			indices.push_back(i);
			indices.push_back(i + 1);
		}
	}

	// Fix the last triangle
	indices.back() = 1;

	Mesh *circle = new Mesh(vertices, indices);
	renderer.addMesh(circle);
	// std::cout << "After mesh" << std::endl;

	// vertices for square
	vertices = {
		0.5f, 0.5f, 0.0f,	// top right
		0.5f, -0.5f, 0.0f,	// bottom right
		-0.5f, -0.5f, 0.0f, // bottom left
		-0.5f, 0.5f, 0.0f	// top left
	};
	indices = {
		// note that we start from 0!
		0, 1, 3, // first Triangle
		1, 2, 3	 // second Triangle
	};

	Mesh *square = new Mesh(vertices, indices);

	vertices = {
		-0.7f, -0.5f, 0.0f, // bottom right
		-0.9f, -0.5f, 0.0f, // bottom left
		-0.8f, 0.5f, 0.0f	// top
	};

	indices = {
		// note that we start from 0!
		0, 1, 2, // triangle
	};

	Mesh *triangle = new Mesh(vertices, indices);

	renderer.addMesh(square);
	renderer.addMesh(triangle);

	// std::cout << "After add mesh" << std::endl;

	while (!glfwWindowShouldClose(window))
	{
		renderer.clearScreen();
		renderer.draw();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}
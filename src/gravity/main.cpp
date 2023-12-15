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
#include <random>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

Mesh *createCircle(float x, float y, float radius, int segments)
{
	std::vector<float> vertices;
	std::vector<unsigned int> indices;

	// Center of the circle
	vertices.push_back(x);
	vertices.push_back(y);
	vertices.push_back(0.0f);

	for (int i = 0; i <= segments; ++i)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(segments);
		float dx = radius * cosf(theta) + x;
		float dy = radius * sinf(theta) + y;

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
	return circle;
}

int main()
{

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// window creation
	GLFWwindow *window = glfwCreateWindow(1440, 1440, "Default", NULL, NULL);

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

	std::cout << "Create all the random circles!" << std::endl;

	// Initialize a random number generator
	std::random_device rd;
	std::mt19937 gen(rd());

	// Define the range for the random float
	std::uniform_real_distribution<> points(-1.0, 1.0);

	std::uniform_real_distribution<> rad(0, 0.005);

	// std::cout << "After add mesh" << std::endl;

	while (!glfwWindowShouldClose(window))
	{

		for (int i = 0; i < 1000; ++i)
		{
			Mesh *circle = createCircle(points(gen), points(gen), rad(gen), 5);
			renderer.addMesh(circle);
		}

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
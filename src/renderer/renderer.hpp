#pragma once

#include "shader.hpp"
#include <string>

// Forward declare GLFWwindow to avoid including glfw3.h
struct GLFWwindow;

namespace renderer
{
	class Window
	{
	public:
		Window(int width, int  height, const std::string& title);
		~Window();

		void pollEvents();

		void swapBuffers();

        void drawSquare();

	private:
		GLFWwindow* window;
        Shader shaderProgram;
        unsigned int VAO;
	};
}
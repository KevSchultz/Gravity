//  ██╗  ██╗███████╗
//  ██║ ██╔╝██╔════╝
//  █████╔╝ ███████╗
//  ██╔═██╗ ╚════██║
//  ██║  ██╗███████║
//  ╚═╝  ╚═╝╚══════╝
/*
 *  Window.cpp
 *  The window class is a wrapper around GLFWwindow.
 *  It is used to create a window and handle events.
 *  It is also used to swap the front and back buffers.
 *  The window class is used by the renderer class.
 *
 */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Window.hpp"


/** @brief Constructor for the Window class.
 *
 * @param width width of the glfw window
 *
 * @param height height of the glfw window
 *
 * @return Window object
 */
Window::Window(int width, int height, const std::string &title)
{
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // window creation
    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}

/** @brief Destructor for the Window class.
 *
 * @return void
 */
Window::~Window()
{
    window = NULL;
    glfwTerminate();
}

/** @brief Returns whether the window should close.
 *
 * @return bool whether the window should close
 */
bool Window::shouldClose()
{
    return glfwWindowShouldClose(window);
}

/** @brief Polls events.
 *
 * @return void
 */
void Window::pollEvents()
{
    glfwPollEvents();
}

/** @brief Swap the color buffer.
 *
 * @return void
 */
void Window::swapBuffers()
{
    glfwSwapBuffers(window);
}

/* main.cpp
 * This is the main driver file for the StarSystem object.
 * It sets up the OpenGL context, creates a window using GLFW, and initializes GLAD.
 * It also defines the window input handling and resize callback functions.
 * The main rendering loop is contained within this file, which continues running until the window is closed.
 * After the rendering loop ends, it cleans up the allocated resources.
 * Created by Kevin Schultz.
 */

#include "StarSystem.h"
#include "../include/glad/glad.h"

#include <iostream>
#include <math.h>
#include <vector>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


#define WIDTH 500
#define HEIGHT 500

/** @brief obtains input and routes it to the appropriate function
 *
 *  @param window pointer to GLFW window object
 */
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

/** @brief callback function for window resizing
 *
 *  @param window pointer to GLFW window object
 *  @param width new width of window
 *  @param height new height of window
 */
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

/** @brief application entry point containing the main rendering loop
 * 
 *  @return exit code
 */
int main()
{
    // Start the opengl context.
    glfwInit();

    // Set our context versions.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window with glfw.
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Gravity", NULL, NULL);

    // If the window doesn't exist then terminate.
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Show the window on the screen.
    glfwMakeContextCurrent(window);

    // Initialize glad.
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set window dimensions within glad.
    glViewport(0, 0, WIDTH, HEIGHT);

    // Enable resize.
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Create a StarSystem object.
    StarSystem StarSystem(100);

    // Render Loop (stop only when told to).
    while (!glfwWindowShouldClose(window))
    {
        // Check for specific key presses.
        processInput(window);

        // Rendering Commands.
        
        // render star system
        StarSystem.onRender();


        // Check for any events (keyboard input, mouse movement, etc).
        glfwPollEvents();

        // Swap color buffer to output on the screen.
        glfwSwapBuffers(window);
    }


    // Clean up memory.
    glfwTerminate();
    return 0;
}
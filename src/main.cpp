#include <iostream>
#include <math.h>
#include <vector>
#include "../include/glad/glad.h"
#include "shader.h"
#include "stb_image.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


/* Handle window input. */
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

/* Window resize callback. */
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    // Start the opengl context.
    glfwInit();

    // Set our context versions.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window with glfw.
    GLFWwindow *window = glfwCreateWindow(800, 600, "Gravity", NULL, NULL);

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
    glViewport(0, 0, 800, 600);

    // Enable resize.
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Build and compile our shader program.
    Shader ourShader("../src/shaders/vertex.glsl", "../src/shaders/fragment.glsl");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    // float vertices[] = {
    //     -0.5f, -0.5f, 0.0f, // bottom left
    //     0.5f, -0.5f, 0.0f,  // bottom right
    //     0.5f, 0.5f, 0.0f,   // top right
    // };

    // unsigned int VBO, VAO;
    // glGenVertexArrays(1, &VAO);
    // glGenBuffers(1, &VBO);

    // glBindVertexArray(VAO);

    // glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // gv
    //     (void *)0 // array buffer offset
    // );
    // glEnableVertexAttribArray(0);

    // Define the number of triangles to use for the circle.
    const int numTriangles = 32;

    // Define the radius of the circle.
    const float radius = 0.01f;

    // Define the center point of the circle.
    const glm::vec2 center(0.0f, 0.0f);

    // Define the vertex data for the circle.
    std::vector<glm::vec2> vertices;
    vertices.push_back(center);
    for (int i = 0; i <= numTriangles; i++) {
        float angle = i * (2.0f * glm::pi<float>()) / numTriangles;
        glm::vec2 vertex(radius * glm::cos(angle), radius * glm::sin(angle));
        vertices.push_back(center + vertex);
    }

    // Upload the vertex data to the GPU.
    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec2), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    // Render the circle.
    glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size());



    // Render Loop (stop only when told to).
    while (!glfwWindowShouldClose(window))
    {
        // Check for specific key presses.
        processInput(window);

        // Rendering Commands.

        // Clear the whole screen with a color.
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        

        // render the triangle
        ourShader.use();
        glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size());


        // Check for any events (keyboard input, mouse movement, etc).
        glfwPollEvents();

        // Swap color buffer to output on the screen.
        glfwSwapBuffers(window);
    }

    // Clean up.
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    // Clean up memory.
    glfwTerminate();
    return 0;
}
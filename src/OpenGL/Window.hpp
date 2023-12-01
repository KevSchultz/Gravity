//  ██╗  ██╗███████╗
//  ██║ ██╔╝██╔════╝
//  █████╔╝ ███████╗
//  ██╔═██╗ ╚════██║
//  ██║  ██╗███████║
//  ╚═╝  ╚═╝╚══════╝
/*
 *  Window.hpp
 *  The window class is a wrapper around GLFWwindow.
 *  It is used to create a window and handle events.
 *  It is also used to swap the front and back buffers.
 *  The window class is used by the renderer class.
 *
*/
#pragma once

#include <string>

// Forward declare GLFWwindow to avoid including glfw3.h
struct GLFWwindow;

class Window
{
public:

    /** @brief Constructor for the Window class.
     * 
     * @param width width of the glfw window
     * 
     * @param height height of the glfw window
     * 
     * @return Window object
     */
    Window(int width, int height, const std::string &title);
    
    /** @brief Destructor for the Window class.
     * 
     * @return void
     */
    ~Window();

    /** @brief Returns whether the window should close.
     * 
     * @return bool whether the window should close
     */
    bool shouldClose();

    /** @brief Polls events.
     * 
     * @return void
     */
    void pollEvents();

    /** @brief Swap the color buffer.
     * 
     * @return void
     */
    void swapBuffers();

private:
    GLFWwindow *window;
};

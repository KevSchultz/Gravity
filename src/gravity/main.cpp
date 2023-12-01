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

#include <Window.hpp>
#include <iostream>

int main()
{
	Window window{ 800, 600, "Hello World!" };

	while (!window.shouldClose())
	{
        window.pollEvents();
		window.swapBuffers();
	}

	return 0;
}
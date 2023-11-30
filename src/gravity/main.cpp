#include <renderer.hpp>
#include <iostream>

int main()
{
    using namespace renderer;
	Window window{ 800, 600, "Hello World!" };

	while (1)
	{
        // std::cout << "In loop\n" << std::endl;
        window.drawSquare();
	}

	return 0;
}
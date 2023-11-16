# Gravity
This is a simple C++ project that demonstrates gravity with glfw3.

## Prerequisites
Before you can build and run this project, you need to have the following software installed on your system:

- CMake
- C++ compiler (e.g. g++, clang++)
- Make
- glfw3

## Building the Project

To build the project, follow these steps:

1. Open a terminal window and navigate to the root directory of the project.
2. Change directory to `build`:

   ```
   cd build
   ```

3. Run CMake to generate the build files:

   ```
   cmake ..
   ```

   This will generate the build files in the `build` directory.

4. Run `make` to build the project:

   ```
   make
   ```

   This will compile the source code and create an executable file called `gravity` in the `build` directory.

## Running the Application

To run the application, navigate to the `build` directory and run the `gravity` executable:

```
cd build
./gravity
```

This will run the application and open new window.

## Cleaning the Build

To clean the build, navigate to the `build` directory and run the following command:

```
cd build
make clean
```

This will remove all the build files and the `gravity` executable.
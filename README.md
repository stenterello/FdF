# FdF

The "FdF" repository contains my implementation of the FdF project from the 42School curriculum. FdF stands for "Fil de Fer" (Wireframe in English) and is a 3D wireframe viewer that displays a landscape represented by a grid of height values.

The project includes the mandatory part, as well as additional bonus features that enhance the functionality and visual experience of the wireframe viewer.

## Description

The FdF project aims to create a simple but visually appealing wireframe viewer using the graphics library provided by the 42School, MiniLibX. The program reads a file containing height data and uses it to generate a 3D representation of a landscape.

The main features of the FdF project include:

- Displaying the wireframe representation of the landscape using straight lines
- Applying different color gradients based on the height values
- Applying basic transformations such as scaling, translation, and rotation
- Adjusting the camera position and angle to change the viewing perspective
- Implementing interactivity to zoom in/out and reset the view
- Handling user input for navigation and manipulation of the wireframe

The bonus features of the project expand the functionality and allow for more customization options, such as:

- Applying smooth color transitions between points
- Using more advanced projection techniques (isometric, parallel, etc.)
- Enhancing the user interface with interactive controls and menus

## Usage

1. Clone the repository to your local system:
	```shell
	git clone https://github.com/stenterello/FdF.git

2. Navigate to the repository's directory:
	```shell
	cd FdF

3. Note: The Makefile and event code definitions are based on macOS and require modifications to run on Linux.

4. Compile the program using the modified Makefile:
	```shell
	make

5. Execute the program with the desired map file:
	```shell
	./FdF map.fdf
Replace map.fdf with the path to your map file. Examples of map files can be found in the test_maps directory.

6. Explore the 3D wireframe representation using the provided controls (refer to the program's documentation or source code for details).

7. Press Esc to exit the program.

## Bonus features

The FdF project includes additional bonus features that enhance the functionality and visual experience of the wireframe viewer. These features may include smooth color transitions, advanced projections, extra transformation options, and improved user interfaces. The bonus features are implemented in the project to showcase creativity and provide an enhanced user experience.
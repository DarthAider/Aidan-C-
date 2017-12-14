//**************************************************************************** 
// File name:	main.cpp
// Author:		Chadd Williams
// Date:		1/8/2016
// Class:		CS 250
// Assignment:	SDL_SimpleGraphics
// Purpose:		Demonstrate rendering simple graphics to the screen
//*****************************************************************************

#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include <iostream>
#include "Circle.h"
#include "Donut.h"
using namespace std;

//****************************************************************************
// Fucntion:	  main
//
// Description:	Draw a circle and a donut on the screen then pause for 3 secs.
//
// Parameters:	int argc - number of command line arguments
//              char *argv[] - the actual command line arguments
//
// Returned:		int - EXIT_SUCCESS or EXIT_FAILURE
//***************************************************************************

int main(int argc, char *argv[])
{
  int windowXPos = 100,
    windowYPos = 100,
    windowSizeX = 1024,
    windowSizeY = 1024;

  SDL_Window *pWindow;
  SDL_Renderer *pRenderer;
  const int NUMBER_OF_CIRCLES = 5;

  SDL_Color sTeal = { 0, 128, 128, 255 };
  Donut cDelicious (50, 50, 30, { 50, 60, 23, 255 }, 20, { 200, 69, 96, 255 });
  // the Circle to draw!
  Circle cCircle(100, 100, 25, { 255, 0, 0, 255 });

 
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
  {
    std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
    return false;
  }

  pWindow = SDL_CreateWindow("Simple Graphics", windowXPos, windowYPos,
    windowSizeX, windowSizeY, 0);

  if (nullptr == pWindow)
  {
    std::cout << "Failed to create window : " << SDL_GetError();
    return false;
  }

  pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

  if (nullptr == pRenderer)
  {
    std::cout << "Failed to create renderer : " << SDL_GetError();
    return false;
  }

  // Set size of renderer to the same as window
  SDL_RenderSetLogicalSize(pRenderer, windowSizeX, windowSizeY);

  // Set color of renderer to teal
  SDL_SetRenderDrawColor(pRenderer, sTeal.r, sTeal.g, sTeal.b, sTeal.a);

  // Clear the window and make it all teal
  SDL_RenderClear(pRenderer);

  cDelicious.draw (pRenderer);

  // Render the changes above
  SDL_RenderPresent(pRenderer);
  SDL_Delay(3000);

  SDL_DestroyRenderer(pRenderer);
  SDL_DestroyWindow(pWindow);
  SDL_Quit();

  return EXIT_SUCCESS;
}
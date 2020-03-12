#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballManager.setInput(input);
	ballManager.setWindow(window);

	manager.setInput(input);
	manager.setWindow(window);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	//ballManager.handleInput(dt);
	manager.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ballManager.update(dt);
	manager.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	ballManager.render(window);
	manager.render(window);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}
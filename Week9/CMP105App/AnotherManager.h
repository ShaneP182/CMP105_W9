#pragma once
#include "Ball.h"
#include "Framework/GameObject.h"
#include <math.h>
#include <vector>

class AnotherManager :
	public GameObject
{
public:
	AnotherManager();
	~AnotherManager();

	void spawn();
	void update(float dt);
	void handleInput(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
	int countObjects();

	void setWindow(sf::RenderWindow* hwnd) { renderWindow = hwnd; };
	void setInput(Input* in) { input = in; };

private:
	sf::RenderWindow* renderWindow;
	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	sf::Text ballsNumber;
	sf::Font font;
	

};


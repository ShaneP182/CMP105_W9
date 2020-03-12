#pragma once
#include "Framework/GameObject.h"
#include "Ball.h"
#include <math.h>
#include <vector>

class BallManager :
	public GameObject
{
public:
	BallManager();
	~BallManager();

	void spawn();
	void update(float dt);
	void handleInput(float dt);
	void deathCheck();
	bool allDeadCheck();
	void render(sf::RenderWindow* window);

	void setWindow(sf::RenderWindow* hwnd) { renderWindow = hwnd; };
	void setInput(Input* in) { input = in; };

private:
	sf::RenderWindow* renderWindow;
	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	
};


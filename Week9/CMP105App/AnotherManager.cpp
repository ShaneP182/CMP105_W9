#include "AnotherManager.h"

AnotherManager::AnotherManager()
{
	texture.loadFromFile("gfx/Beach_Ball.png");
	font.loadFromFile("font/arial.ttf");

	ballsNumber.setFont(font);
	ballsNumber.setCharacterSize(20);

	for (int i = 0; i < 40; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

AnotherManager::~AnotherManager()
{
}

void AnotherManager::spawn()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(0, 100);
			balls[i].setPosition(sf::Vector2f(rand() % renderWindow->getSize().x, -100));
			return;
		}
	}
}

void AnotherManager::update(float dt)
{
	ballsNumber.setString("Number of balls: " + std::to_string(countObjects()));
	ballsNumber.setPosition(renderWindow->getSize().x / 2, 50);
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			balls[i].update(dt);
		}
	}
	deathCheck();
}

void AnotherManager::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		input->setKeyUp(sf::Keyboard::Space);
		spawn();
	}
}

void AnotherManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().y > renderWindow->getSize().y)
			{
				balls[i].setAlive(false);
			}
		}
	}
}

void AnotherManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
	window->draw(ballsNumber);
}

int AnotherManager::countObjects()
{
	int counter = 0;
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			counter++;
		}
	}
	return counter;
}

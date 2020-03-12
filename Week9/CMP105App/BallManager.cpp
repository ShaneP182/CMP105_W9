#include "BallManager.h"

BallManager::BallManager()
{
	texture.loadFromFile("gfx/Beach_Ball.png");

	for (int i = 0; i < 20; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

BallManager::~BallManager()
{

}

void BallManager::spawn()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			balls[i].setPosition(spawnPoint);
			return;
		}
	}

	if (allDeadCheck())
	{
		balls.push_back(Ball());
		balls[balls.size()-1].setAlive(false);
		balls[balls.size()-1].setTexture(&texture);
		balls[balls.size()-1].setSize(sf::Vector2f(100, 100));
	}

}

void BallManager::update(float dt)
{
	spawnPoint = sf::Vector2f(renderWindow->getSize().x / 2, renderWindow->getSize().y / 2);
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			balls[i].update(dt);
		}
	}
	deathCheck();
}

void BallManager::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		input->setKeyUp(sf::Keyboard::Space);
		spawn();
	}
}

void BallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().x < -balls[i].getSize().x)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().x > renderWindow->getSize().x)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y < -balls[i].getSize().y)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y > renderWindow->getSize().y)
			{
				balls[i].setAlive(false);
			}
		}
	}
}

bool BallManager::allDeadCheck()
{
	for (int i = 0; i < balls.size() - 1; i++)
	{
		if (!balls[i].isAlive() != !balls[i + 1].isAlive())
		{
			return false;
		}
		return true;
	}
}

void BallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
	
}

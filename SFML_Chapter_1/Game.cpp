#include "Game.h"
#include <iostream>
Game::Game()
	: m_window{ sf::VideoMode(680, 640), "SFML Window!" }
	, m_texture{}
	, m_player{}
	//, m_font{}
	//, m_text{}
{
	//if (!m_font.loadFromFile("Media/arial.ttf"))
	//{
	//	// Handle Error
	//}
	if (!m_texture.loadFromFile("Media/eagle.png"))
	{
		// Handle Error loading
	}
	m_player.setTexture(m_texture);
	m_player.setPosition(100.f, 100.f);

}
void Game::run()
{
	sf::Clock clock{};
	sf::Time timeSinceLastUpdate{sf::Time::Zero};
	while (m_window.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}
void Game::processEvents()
{
	sf::Event event {};
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{

			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;

		}
	}
}
void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement{0.0f, 0.0f};
	if (m_isMovingUp)
		movement.y -= 1.f;
	if (m_isMovingDown)
		movement.y += 1.f;
	if (m_isMovingLeft)
		movement.x -= 1.f;
	if (m_isMovingRight)
		movement.x += 1.f;
	m_player.move(movement * deltaTime.asSeconds());
}
void Game::render()
{
	m_window.clear();
	m_window.draw(m_player);
	m_window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		m_isMovingUp = true;
	else if (key == sf::Keyboard::A)
		m_isMovingLeft = true;
	else if (key == sf::Keyboard::S)
		m_isMovingDown = true;
	else if (key == sf::Keyboard::D)
		m_isMovingRight = true;

}


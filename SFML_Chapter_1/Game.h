#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
class Game
{
private:
	sf::RenderWindow m_window{};
	sf::Texture m_texture{};
	sf::Sprite m_player{};
	//sf::Font m_font{};
	//sf::Text m_text{};
	
	bool m_isMovingUp{};
	bool m_isMovingDown{};
	bool m_isMovingLeft{};
	bool m_isMovingRight{};
public:
	Game();
	void run();
private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();

	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

};
#endif
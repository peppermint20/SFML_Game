#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H
#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <utility>
#include <cassert>


namespace Textures
{
	enum class ID
	{
		Landscape,
		Airplane,
		Missle,
		Max_ID
	};
}

class TextureHolder
{
private:
	std::map<Textures::ID, std::unique_ptr<sf::Texture>> m_TextureMap{};
public:
	void load(Textures::ID id, const std::string& filename);
	sf::Texture& get(Textures::ID id);
	const sf::Texture& get(Textures::ID id) const;

};

#endif
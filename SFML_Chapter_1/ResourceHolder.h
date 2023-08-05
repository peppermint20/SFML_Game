#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H
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

template <typename Resource, typename Identifier>
class ResourceHolder
{
private:
	std::map<Identifier, std::unique_ptr<Resource>> m_TextureMap{};
public:
	void load(Identifier id, const std::string& filename);
	sf::Texture& get(Identifier id);
	const sf::Texture& get(Identifier id) const;

};


template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
	std::unique_ptr<sf::Texture> texture { std::make_unique<sf::Texture>() };
	if (texture->loadFromFile(filename));
	{
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
	}

	auto inserted{ m_TextureMap.insert(std::make_pair(id, std::move(texture))) };
	assert(inserted.second);
}

template <typename Resource, typename Identifier>
sf::Texture& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
	auto found = m_TextureMap.find(id);
	assert((found != m_TextureMap.end()) && "No texture found");
	return *found->second;
}

template <typename Resource, typename Identifier>
const sf::Texture& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
	auto found = m_TextureMap.find(id);
	assert((found != m_TextureMap.end()) && "No texture found");
	return *found->second;
}

#endif










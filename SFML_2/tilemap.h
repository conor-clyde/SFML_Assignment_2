#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iterator>
#include <sstream>
class tilemap : public sf::Drawable, public sf::Transformable
{
public:



private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {

    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};


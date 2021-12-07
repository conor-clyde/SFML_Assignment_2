#include "tilemap.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iterator>
#include <sstream>

class tileMap : public sf::Drawable, public sf::Transformable
{
public:

    bool load(const std::string& tileset, sf::Vector2u tileSize)
    {
        // load the tileset texture
        if (!m_tileset.loadFromFile(tileset))
            return false;

        std::vector<std::vector<int> > tiles;
        std::ifstream map_stream("map.txt");
        for (std::string line; std::getline(map_stream, line);) {
            tiles.push_back(std::vector<int>());
            std::stringstream line_stream(line);
            std::copy(std::istream_iterator<int>(line_stream), std::istream_iterator<int>(), std::back_inserter(tiles.back()));
        }

        unsigned int height = tiles.size();

        m_vertices.setPrimitiveType(sf::Quads);


        // populate the vertex array, with one quad per tile
        for (unsigned int j = 0; j < height; ++j) {
            unsigned int width = tiles[j].size();
            for (unsigned int i = 0; i < width; ++i)
            {
                // get the current tile number
                int tileNumber = tiles[j][i];

                // find its position in the tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // get a pointer to the current tile's quad
                sf::Vertex quad[4];

                // define its 4 corners
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

                for (int k = 0; k < 4; ++k)
                    m_vertices.append(quad[k]);
            }
        }
        return true;
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};



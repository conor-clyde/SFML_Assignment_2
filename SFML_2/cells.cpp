#include <iostream>  
#include <SFML/Graphics.hpp> 

void randomiseCells(int num_xCells, int num_yCells, std::vector< std::vector<int> >& cells)
{
    for (int row = 0; row < num_xCells; ++row)
    {
        for (int col = 0; col < num_xCells; ++col)
        {
            cells[row][col] = rand() % 2;
        }
    }
};

void drawCells(int num_xCells, int num_yCells, std::vector< std::vector<int> >& cells, sf::RectangleShape _pixel, sf::RenderWindow& _window)
{
    for (int row = 0; row < num_xCells; ++row)
    {
        for (int col = 0; col < num_yCells; ++col)
        {
            if (cells[row][col] == 1)
            {
                _pixel.setPosition(col * _pixel.getSize().x, row * _pixel.getSize().y);

                if (row == 0 || col==0 || row==num_yCells-1 || col==num_xCells-1)
                    _pixel.setFillColor(sf::Color::Color(156, 214, 226, 255));
                if ((col==0 && row==4) || (col==0 && row==5) || (col==num_xCells-1 && row==num_yCells-5))
                    _pixel.setFillColor(sf::Color::Color(169, 169, 169));

                if (!(row == 0 || col == 0 || row == num_yCells - 1 || col == num_xCells - 1 || col == 0 && row == 4) || (col == 0 && row == 5) || (col == num_xCells - 1 && row == num_yCells - 5))
                    _pixel.setFillColor(sf::Color::Black);

                _window.draw(_pixel);
            }
        }
    }
}

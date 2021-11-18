/*
* An SFML application using a vector list to store point data - Darryl Charles
* SFML Documentation https://www.sfml-dev.org/documentation/2.5.1/
* Set up your own VS2019 project https://www.youtube.com/watch?v=lFzpkvrscs4
*/

#include <iostream>  
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp> 
#include "cells.h"
#include "InputManagement.h"

#define winWidth 900
#define winHeight 900

float playerSpriteSpeed = 1;

//build a grid
int rows = 20;
int columns = 20;
//if a cell is true it's an obstacle
//boolean[][] grid = new boolean[rows][columns];

//where the player is in the grid
int playerIndexX = 90;
int playerIndexY = 90;

int main()
{
    sf::Keyboard::Key keyCode{};

#pragma region ~ Initialise render window ~
    sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Coin Chaser");                            
#pragma endregion

    sf::Font font;
    if (!font.loadFromFile(".\\fonts\\arial.ttf"))
        return EXIT_FAILURE;

    sf::Text txtStart("START!", font, 24); txtStart.setFillColor(sf::Color::Black); txtStart.setPosition(4, 2);

    sf::Text txtEscape("ESCAPE!", font, 24); txtEscape.setFillColor(sf::Color::Black); txtEscape.setPosition(window.getSize().x-110, window.getSize().y-30);

#pragma region ~ Create a square pixel (SFML graphics object), size it, and give it a color ~
    sf::RectangleShape pixel(sf::Vector2f(30.0f, 30.0f));
    pixel.setFillColor(sf::Color::Black);
    int numXCells = int(winWidth / pixel.getSize().x);                         // Get pixel width and height of the 2d grid (based on pixel size)
    int numYCells = int(winHeight / pixel.getSize().y);
#pragma endregion

    sf::Texture texture;
    if (!texture.loadFromFile("assets/car.jpg"))
    {
        std::cout << "Could not load player texture" << std::endl;
        return 0;
    }

    sf::Sprite playerSprite;
    playerSprite.setTexture(texture);
    playerSprite.setPosition(playerIndexX, playerIndexY);
    playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, playerSprite.getLocalBounds().height / 2);
    playerSprite.setScale(3, 3);
    playerSprite.setRotation(0);
  

    sf::Time elapsed;

#pragma region ~ Create 2d vector array for holding pixel values (integers) ~
    std::vector<std::vector<int>> mapGrid;                                  // Vector list of map tiles 

#pragma endregion

#pragma region ~ Load map from file ~
    std::ifstream dataStream;
    std::string line;

    dataStream.open(".\\map.csv");
    if (dataStream.is_open())
    {
        while (std::getline(dataStream, line))
        {
            std::stringstream lineStream(line);
            std::string character;
            std::vector<int> parsedRow;
            while (std::getline(lineStream, character, ','))
            {
                parsedRow.push_back(std::stoi(character));
                std::cout << std::stoi(character);
            }
            std::cout << std::endl;
            mapGrid.push_back(parsedRow);
        }
    }
#pragma endregion  

    int x = playerIndexX;
    int y = playerIndexY;

    bool upFlag = false;
    bool downFlag = false;
    bool leftFlag = false;
    bool rightFlag = false;

    sf::Clock timer;
    while (window.isOpen())                                                    
    {
#pragma region ~ Check for a close window event ~
        sf::Event event; 
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //If a key is pressed
            if (event.type == sf::Event::KeyPressed)
            {
             
                switch (event.key.code)
                {
                //If escape is pressed, close the application
                case  sf::Keyboard::Escape:
                    window.close();
                    break;

                //Process the up, down, left and right keys
                case sf::Keyboard::Up:   
                    upFlag = true; 
                    break;

                case sf::Keyboard::Down:  
                    downFlag = true; 
                    break;

                case sf::Keyboard::Left: 
                    leftFlag = true; 
                    break;

                case sf::Keyboard::Right: 
                    rightFlag = true;
                    break;

                default: 
                    break;
                }
            }

            //If a key is released
            if (event.type == sf::Event::KeyReleased)
            {
                keyCode = event.key.code;
                //switch (event.key.code)
                //{
                ////Process the up, down, left and right keys
                //case sf::Keyboard::Up:  
                //    upFlag = false;
                //    break;

                //case sf::Keyboard::Down: 
                //    downFlag = false; 
                //    break;

                //case sf::Keyboard::Left: 
                //    leftFlag = false; 
                //    break;

                //case sf::Keyboard::Right:
                //    rightFlag = false; 
                //    break;

                //default: 
                //    break;
                //}
            }
        }
#pragma endregion
       

        if (keyCode == sf::Keyboard::Up)
        {
            //if we aren't in the top row and the cell above us doesn't contain an obstacle
            //then we can move up
            //if (playerIndexY > 0 && mapGrid[playerIndexY/30 - 1][playerIndexX/30] =={0[0])
            {
                playerIndexY--;
            }
        }
        else if (keyCode == sf::Keyboard::Down)
        {
            //if we aren't in the bottom row and the cell below us doesn't contain an obstacle
            //then we can move down
            if (playerIndexY < rows - 1 && !mapGrid[playerIndexY + 1][playerIndexX])
            {
                playerIndexY++;
            }
        }
        else if (keyCode == sf::Keyboard::Left)
        {
            //if we aren't in the left-most column and the cell to our left doesn't contain an obstacle
            //then we can move left
            if (playerIndexX > 0 && !mapGrid[playerIndexY][playerIndexX - 1])
            {
                playerIndexX--;
            }
        }
        else if (keyCode == sf::Keyboard::Right)
        {
            //if we aren't in the right-most column and the cell to our right doesn't contain an obstacle
            //then we can move right
            if (playerIndexX < columns - 1 && !mapGrid[playerIndexY][playerIndexX + 1])
            {
                playerIndexX++;
            }
        }

        //background(128);

        //float cellWidth = width / columns;
        //float cellHeight = height / rows;

        for (int row = 0; row < numXCells; ++row)
        {
            for (int col = 0; col < numYCells; ++col)
            {

                //float cellX = cellWidth * column;
                //float cellY = cellHeight * row;

                //fill the obstacles in with red
                if (mapGrid[row][col])
                {
                    sf::Color::Color(255, 0, 0);
                }
                else
                {
                    //noFill();
                }

                //rect(cellX, cellY, cellWidth, cellHeight);
            }
        }

        //fill the player's cell with green
        //float playerPixelX = playerIndexX * cellWidth;
        //float playerPixelY = playerIndexY * cellHeight;
        //fill(0, 255, 0);
        //rect(playerPixelX, playerPixelY, cellWidth, cellHeight);

        //if (leftFlag) 
        //    x -= 1;
        //if (rightFlag) 
        //    x += 1;
        //if (upFlag) 
        //    y -= 1;
        //if (downFlag)
        //    y += 1;


        window.clear(sf::Color::Color(159, 187, 80));
        
        drawCells(numXCells, numYCells, mapGrid, pixel, window);
   
        playerSprite.setPosition(x, y);
        window.draw(playerSprite);
        window.draw(txtStart);
        window.draw(txtEscape);

        window.display();                                               
    }

    return 0;


}

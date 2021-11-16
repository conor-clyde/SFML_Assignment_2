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

int main()
{
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
    playerSprite.setPosition(sf::Vector2f(winWidth / 2, winHeight / 2));
    playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, playerSprite.getLocalBounds().height / 2);
    playerSprite.setScale(4, 4);
    playerSprite.setRotation(0);
  

    sf::Time elapsed;

#pragma region ~ Create 2d vector array for holding pixel values (integers) ~
    std::vector<std::vector<int>> cellsGrid2D;                                  // Vector list of map tiles  
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
            cellsGrid2D.push_back(parsedRow);
        }
    }
#pragma endregion  

    int x = window.getSize().x / 2.;
    int y = window.getSize().y / 2.;

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
                switch (event.key.code)
                {
                //Process the up, down, left and right keys
                case sf::Keyboard::Up:  
                    upFlag = false;
                    break;

                case sf::Keyboard::Down: 
                    downFlag = false; 
                    break;

                case sf::Keyboard::Left: 
                    leftFlag = false; 
                    break;

                case sf::Keyboard::Right:
                    rightFlag = false; 
                    break;

                default: 
                    break;
                }
            }
        }
#pragma endregion


        //if (playerSprite.getPosition().x);

        //if (playerSprite.getPosition)
            //cellsGrid2D.



        if (leftFlag) 
            x -= 1;
        if (rightFlag) 
            x += 1;
        if (upFlag) 
            y -= 1;
        if (downFlag)
            y += 1;


    //     if (keyCode == UP)
    //{
    //    //if we aren't in the top row and the cell above us doesn't contain an obstacle
    //    //then we can move up
    //    if (PlayerSprite.y > 0 && !grid[playerIndexY - 1][playerIndexX]) 
    //    {
    //        playerIndexY--;
    //    }
    //}
    //else if (keyCode == DOWN) {
    //    //if we aren't in the bottom row and the cell below us doesn't contain an obstacle
    //    //then we can move down
    //    if (playerIndexY < rows - 1 && !grid[playerIndexY + 1][playerIndexX]) {
    //        playerIndexY++;
    //    }
    //}
    //else if (keyCode == LEFT) {
    //    //if we aren't in the left-most column and the cell to our left doesn't contain an obstacle
    //    //then we can move left
    //    if (playerIndexX > 0 && !grid[playerIndexY][playerIndexX - 1]) {
    //        playerIndexX--;
    //    }
    //}
    //else if (keyCode == RIGHT) {
    //    //if we aren't in the right-most column and the cell to our right doesn't contain an obstacle
    //    //then we can move right
    //    if (playerIndexX < columns - 1 && !grid[playerIndexY][playerIndexX + 1]) {
    //        playerIndexX++;
    //    }
    //}



        window.clear(sf::Color::Color(159, 187, 80));
        
        drawCells(numXCells, numYCells, cellsGrid2D, pixel, window);   
   
        playerSprite.setPosition(x, y);
        window.draw(playerSprite);
        window.draw(txtStart);
        window.draw(txtEscape);

        window.display();                                               
    }

    return 0;


}

void keyPressed() 
{
    //if (keyCode == UP)
    //{
    //    //if we aren't in the top row and the cell above us doesn't contain an obstacle
    //    //then we can move up
    //    if (PLAYER > 0 && !grid[playerIndexY - 1][playerIndexX]) 
    //    {
    //        playerIndexY--;
    //    }
    //}
    //else if (keyCode == DOWN) {
    //    //if we aren't in the bottom row and the cell below us doesn't contain an obstacle
    //    //then we can move down
    //    if (playerIndexY < rows - 1 && !grid[playerIndexY + 1][playerIndexX]) {
    //        playerIndexY++;
    //    }
    //}
    //else if (keyCode == LEFT) {
    //    //if we aren't in the left-most column and the cell to our left doesn't contain an obstacle
    //    //then we can move left
    //    if (playerIndexX > 0 && !grid[playerIndexY][playerIndexX - 1]) {
    //        playerIndexX--;
    //    }
    //}
    //else if (keyCode == RIGHT) {
    //    //if we aren't in the right-most column and the cell to our right doesn't contain an obstacle
    //    //then we can move right
    //    if (playerIndexX < columns - 1 && !grid[playerIndexY][playerIndexX + 1]) {
    //        playerIndexX++;
    //    }
    //}
}


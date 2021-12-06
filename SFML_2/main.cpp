/*
* An SFML application using a vector list to store point data - Darryl Charles
* SFML Documentation https://www.sfml-dev.org/documentation/2.5.1/
* Set up your own VS2019 project https://www.youtube.com/watch?v=lFzpkvrscs4
*/

#include <iostream>  
#include <fstream>
#include <sstream>
#include<SFML/Audio.hpp>
#include <SFML/Graphics.hpp> 
#include "cells.h"
#include "InputManagement.h"
#include "gameAudio.h"

#define winWidth 900
#define winHeight 900

float playerSpriteSpeed = 1;

//build a grid
int rows = 20;
int columns = 20;
//if a cell is true it's an obstacle
//boolean[][] grid = new boolean[rows][columns];

//where the player is in the grid
float playerIndexX = 45;
float playerIndexY = 75;

int main()
{


	std::string previousScore = "100";

#pragma region ~ Initialise render window ~
	sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Coin Chaser");
#pragma endregion

	sf::Font font;
	if (!font.loadFromFile(".\\fonts\\arial.ttf"))
		return EXIT_FAILURE;

	sf::Text txtStart("START!", font, 24); txtStart.setFillColor(sf::Color::Black); txtStart.setPosition(4, 2);
	sf::Text txtEscape("ESCAPE!", font, 24); txtEscape.setFillColor(sf::Color::Black); txtEscape.setPosition(window.getSize().x - 110, window.getSize().y - 30);
	sf::Text txtPreviousScore("", font, 24);

#pragma region ~ Create a square pixel (SFML graphics object), size it, and give it a color ~
	sf::RectangleShape pixel(sf::Vector2f(30.0f, 30.0f));
	pixel.setFillColor(sf::Color::Black);
	int numXCells = int(winWidth / pixel.getSize().x);                         //Get pixel width and height of the 2d grid (based on pixel size)
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

	std::cout << playerSprite.getLocalBounds().width << std::endl;
	std::cout << playerSprite.getLocalBounds().height << std::endl;

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

	bool upFlag = false;
	bool downFlag = false;
	bool leftFlag = false;
	bool rightFlag = false;

	bool upInBuffer = false;
	bool downInBuffer = false;
	bool leftInBuffer = false;
	bool rightInBuffer = false;

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
					upInBuffer = true;
					break;

				case sf::Keyboard::Down:
					downFlag = true;
					downInBuffer = true;
					break;

				case sf::Keyboard::Left:
					leftFlag = true;
					leftInBuffer = true;
					break;

				case sf::Keyboard::Right:
					rightFlag = true;
					rightInBuffer = true;
					break;

				default:
					break;
				}
			}
		}
#pragma endregion
		
		restartGame(playerIndexX, playerIndexY, upFlag, downFlag, leftFlag, rightFlag, upInBuffer, downInBuffer, leftInBuffer, rightInBuffer, previousScore, txtPreviousScore, font, window);

		if (mapGrid[((playerIndexY - 14) - 1) / 30][playerIndexX / 30] && upInBuffer == true)
		{
			moveUpNextTurn(playerIndexX, playerIndexY, upFlag, downFlag, leftFlag, rightFlag, upInBuffer, mapGrid);
		}

		if (mapGrid[((playerIndexY + 14) + 1) / 30][playerIndexX / 30] && downInBuffer == true)
		{
			moveDownNextTurn(playerIndexX, playerIndexY, upFlag, downFlag, leftFlag, rightFlag, downInBuffer, mapGrid);
			rightInBuffer = false;
		}

		if (mapGrid[playerIndexY / 30][((playerIndexX - 14) + 1) / 30] && leftInBuffer == true)
		{
			moveLeftNextTurn(playerIndexX, playerIndexY, upFlag, downFlag, leftFlag, rightFlag, leftInBuffer, mapGrid);
		}

		if (mapGrid[playerIndexY / 30][((playerIndexX + 14) + 1) / 30] && rightInBuffer == true)
		{
			moveRightNextTurn(playerIndexX, playerIndexY, upFlag, downFlag, leftFlag, rightFlag, rightInBuffer, mapGrid);
		}

		if (upFlag == true)
		{
			moveUp(playerIndexX, playerIndexY, upFlag, mapGrid);
		}
		else if (downFlag == true)
		{
			moveDown(playerIndexX, playerIndexY, downFlag, mapGrid);

		}
		else if (leftFlag == true)
		{
			moveLeft(playerIndexX, playerIndexY, leftFlag, mapGrid);
		}
		else if (rightFlag == true)
		{
			moveRight(playerIndexX, playerIndexY, rightFlag, mapGrid);
		}
		
		window.clear(sf::Color::Color(159, 187, 80));

		drawCells(numXCells, numYCells, mapGrid, pixel, window);
		playerSprite.setPosition(playerIndexX, playerIndexY);
		window.draw(playerSprite);
		window.draw(txtStart);
		window.draw(txtEscape);
		window.draw(txtPreviousScore);
		
		window.display();
	}

	return 0;
}

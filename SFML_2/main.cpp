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
#include "AnimatedSprite.h"
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
	int score = 0;
	int highScore = 0;
	int counter = 0;

#pragma region ~ Initialise render window ~
	sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Coin Chaser");
#pragma endregion

	sf::Font font;
	if (!font.loadFromFile(".\\fonts\\arial.ttf"))
		return EXIT_FAILURE;

	sf::Text txtStart("START!", font, 24); txtStart.setFillColor(sf::Color::Black); txtStart.setPosition(4, 2);
	sf::Text txtEscape("ESCAPE!", font, 24); txtEscape.setFillColor(sf::Color::Black); txtEscape.setPosition(window.getSize().x - 110, window.getSize().y - 30);
	sf::Text txtPreviousScore("Previous Score: 0 ", font, 18); txtPreviousScore.setFillColor(sf::Color::Black); txtPreviousScore.setPosition(150, 4);
	sf::Text txtCurrentScore("Current Score: 0", font, 18); txtCurrentScore.setFillColor(sf::Color::Black); txtCurrentScore.setPosition(400, 4);
	sf::Text txtHighScore("High Score: 0", font, 18); txtHighScore.setFillColor(sf::Color::Black); txtHighScore.setPosition(650, 4);
	sf::Text txtRoundInfo("", font, 18); txtRoundInfo.setFillColor(sf::Color::Black); txtRoundInfo.setPosition(400, 34); txtRoundInfo.setLineSpacing(1.2);

#pragma region ~ Create a square pixel (SFML graphics object), size it, and give it a color ~
	sf::RectangleShape pixel(sf::Vector2f(30.0f, 30.0f));
	pixel.setFillColor(sf::Color::Black);
	int numXCells = int(winWidth / pixel.getSize().x);                         //Get pixel width and height of the 2d grid (based on pixel size)
	int numYCells = int(winHeight / pixel.getSize().y);
#pragma endregion
	sf::Texture texture1;
	if (!texture1.loadFromFile("assets/CoinSprite.png"))
	{
		std::cout << "Could not load player texture" << std::endl;
		return 0;
	}
	sf::Texture texture;
	if (!texture.loadFromFile("assets/playerSprite.png"))
	{
		std::cout << "Could not load player texture" << std::endl;
		return 0;
	}
	
	sf::Sprite playerSprite;
	playerSprite.setTexture(texture);
	playerSprite.setPosition(playerIndexX, playerIndexY);
	playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, playerSprite.getLocalBounds().height / 2);
	playerSprite.setScale(1,1);
	playerSprite.setRotation(0);

	//std::cout << carSpriteRight.getLocalBounds().width << std::endl;
	//std::cout << carSpriteRight.getLocalBounds().height << std::endl;

	sf::Time elapsed;
	sf::Sprite coinSprite;
	coinSprite.setTexture(texture1);
	coinSprite.setPosition(playerIndexX+40, playerIndexY);
	coinSprite.setOrigin(coinSprite.getLocalBounds().width / 2, coinSprite.getLocalBounds().height / 2);
	coinSprite.setScale(0.05, 0.05);
	coinSprite.setRotation(0);

	std::cout << coinSprite.getLocalBounds().width << std::endl;
	std::cout << coinSprite.getLocalBounds().height << std::endl;


	sf::Time elapsed1;

	sf::Sprite CarSpriteLeft;
	CarSpriteLeft.setTexture(texture);
	CarSpriteLeft.setPosition(playerIndexX, playerIndexY);
	//CarSpriteLeft.setOrigin(carSpriteRight.getLocalBounds().width / 2, CarSpriteLeft.getLocalBounds().height / 2);
	CarSpriteLeft.setScale(3, 3);
	CarSpriteLeft.setRotation(0);

	std::cout << CarSpriteLeft.getLocalBounds().width << std::endl;
	std::cout << CarSpriteLeft.getLocalBounds().height << std::endl;

	sf::Time elapsed2;

	sf::Sprite CarSpriteUp;
	CarSpriteUp.setTexture(texture);
	CarSpriteUp.setPosition(playerIndexX, playerIndexY);
	CarSpriteUp.setOrigin(CarSpriteUp.getLocalBounds().width / 2, CarSpriteUp.getLocalBounds().height / 2);
	CarSpriteUp.setScale(3, 3);
	CarSpriteUp.setRotation(0);

	std::cout << CarSpriteUp.getLocalBounds().width << std::endl;
	std::cout << CarSpriteUp.getLocalBounds().height << std::endl;
	sf::Time lapsed3;

	sf::Sprite CarSprite2;
	CarSprite2.setTexture(texture);
	CarSprite2.setPosition(playerIndexX, playerIndexY);
	CarSprite2.setOrigin(CarSprite2.getLocalBounds().width / 2, CarSprite2.getLocalBounds().height / 2);
	CarSprite2.setScale(3, 3);
	CarSprite2.setRotation(0);

	std::cout << CarSprite2.getLocalBounds().width << std::endl;
	std::cout << CarSprite2.getLocalBounds().height << std::endl;
	sf::Time lapsed4;

	sf::Sprite CoinSprite;
	CoinSprite.setTexture(texture);
	CoinSprite.setPosition(playerIndexX, playerIndexY);
	CoinSprite.setOrigin(CoinSprite.getLocalBounds().width / 2, CoinSprite.getLocalBounds().height / 2);
	CoinSprite.setScale(3, 3);
	CoinSprite.setRotation(0);

	sf::Sprite CoinSprite2;
	CoinSprite2.setTexture(texture);
	CoinSprite2.setPosition(playerIndexX, playerIndexY);
	CoinSprite2.setOrigin(CoinSprite2.getLocalBounds().width / 2, CoinSprite2.getLocalBounds().height / 2);
	CoinSprite2.setScale(3, 3);
	CoinSprite2.setRotation(0);

	sf::Sprite CoinSprite3;
	CoinSprite3.setTexture(texture);
	CoinSprite3.setPosition(playerIndexX, playerIndexY);
	CoinSprite3.setOrigin(CoinSprite3.getLocalBounds().width / 2, CoinSprite3.getLocalBounds().height / 2);
	CoinSprite3.setScale(3, 3);
	CoinSprite3.setRotation(0);

	sf::Sprite CoinSprite4;
	CoinSprite4.setTexture(texture);
	CoinSprite4.setPosition(playerIndexX, playerIndexY);
	CoinSprite4.setOrigin(CoinSprite4.getLocalBounds().width / 2, CoinSprite4.getLocalBounds().height / 2);
	CoinSprite4.setScale(3, 3);
	CoinSprite4.setRotation(0);

	sf::Sprite CoinSprite5;
	CoinSprite5.setTexture(texture);
	CoinSprite5.setPosition(playerIndexX, playerIndexY);
	CoinSprite5.setOrigin(CoinSprite5.getLocalBounds().width / 2, CoinSprite5.getLocalBounds().height / 2);
	CoinSprite5.setScale(3, 3);
	CoinSprite5.setRotation(0);

	sf::Sprite CoinSprite6;
	CoinSprite6.setTexture(texture);
	CoinSprite6.setPosition(playerIndexX, playerIndexY);
	CoinSprite6.setOrigin(CoinSprite6.getLocalBounds().width / 2, CoinSprite6.getLocalBounds().height / 2);
	CoinSprite6.setScale(3, 3);
	CoinSprite6.setRotation(0);



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

	// Game clock and timer by Ryan Featherstone
	sf::Clock clock;
	int countdown = 60;

	//making countdown a string
	std::string countdownString;
	std::ostringstream convert;
	convert << countdown;
	countdownString = convert.str();

	//Setting timer font and text
	sf::Text timerText;
	timerText.setFont(font);
	timerText.setString(countdownString);
	timerText.setPosition(10, 0);
	timerText.setCharacterSize(40);

	//TIMER - 60 SECONDS
	int timer = clock.getElapsedTime().asSeconds();
	std::cout << timer << std::endl;

	if (timer > 0)
	{
		countdown--;
		timerText.setString(std::to_string(countdown));
		clock.restart();
	}

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

		//Input Management
		checkIfAtWater(playerIndexX, playerIndexY, upFlag, downFlag, leftFlag, rightFlag, upInBuffer, downInBuffer, leftInBuffer, rightInBuffer, font, score, highScore, txtCurrentScore, txtPreviousScore, txtHighScore, txtRoundInfo, window, playerSprite);

		checkIfAtStart(playerIndexX, playerIndexY, upFlag, downFlag, leftFlag, rightFlag, upInBuffer, downInBuffer, leftInBuffer, rightInBuffer, font, window);

		restartGame(playerIndexX, playerIndexY, upFlag, downFlag, leftFlag, rightFlag, upInBuffer, downInBuffer, leftInBuffer, rightInBuffer, font, score, highScore, txtCurrentScore, txtPreviousScore, txtHighScore, txtRoundInfo, window, playerSprite);

		if (mapGrid[((playerIndexY - 14) - 1) / 30][playerIndexX / 30] && upInBuffer == true && downFlag == false)
		{
			moveUpNextTurn(counter, playerIndexX, playerIndexY, upFlag, downFlag, leftFlag, rightFlag, upInBuffer, downInBuffer, leftInBuffer, rightInBuffer,mapGrid, playerSprite);
			downInBuffer = false;
		}

		if (mapGrid[((playerIndexY + 14) + 1) / 30][playerIndexX / 30] && downInBuffer == true && upFlag == false)
		{

			moveDownNextTurn(counter, playerIndexX, playerIndexY, upFlag, downFlag, leftFlag, rightFlag, upInBuffer, downInBuffer, leftInBuffer, rightInBuffer, mapGrid, playerSprite);
			upInBuffer = false;
		}

		if (mapGrid[playerIndexY / 30][((playerIndexX - 14) + 1) / 30] && leftInBuffer == true && rightFlag == false)
		{
			moveLeftNextTurn(playerIndexX, playerIndexY, upFlag, downFlag, leftFlag, rightFlag, leftInBuffer, mapGrid, playerSprite);
			rightInBuffer = false;
		}

		if (mapGrid[playerIndexY / 30][((playerIndexX + 14) + 1) / 30] && rightInBuffer == true && leftFlag == false)
		{
			moveRightNextTurn(playerIndexX, playerIndexY, upFlag, downFlag, leftFlag, rightFlag, rightInBuffer, mapGrid, playerSprite);
			leftInBuffer = false;
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

		txtCurrentScore.setString("Current Score: " + std::to_string(score));

		playerSprite.setPosition(playerIndexX, playerIndexY);

		//Clear window
		window.clear(sf::Color::Color(159, 187, 80));

		//Draw game
		drawCells(numXCells, numYCells, mapGrid, pixel, window);
		window.draw(playerSprite);
		window.draw(coinSprite);
		window.draw(txtStart);
		window.draw(txtEscape);
		window.draw(txtPreviousScore);
		window.draw(txtCurrentScore);
		window.draw(txtHighScore);
		window.draw(txtRoundInfo);

		//Display game
		window.display();
	}

	return 0;
}

#include "AnimatedSprite.h"
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
int playerIndexX = 15;
int playerIndexY = 75;

int main1() {
	sf::Keyboard::Key keyCode{};

#pragma region ~ Initialise render window ~
	sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Coin Chaser");
#pragma endregion

	sf::Font font;
	if (!font.loadFromFile(".\\fonts\\arial.ttf"))
		return EXIT_FAILURE;

	sf::Text txtStart("START!", font, 24); txtStart.setFillColor(sf::Color::Black); txtStart.setPosition(4, 2);

	sf::Text txtEscape("ESCAPE!", font, 24); txtEscape.setFillColor(sf::Color::Black); txtEscape.setPosition(window.getSize().x - 110, window.getSize().y - 30);

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
	if (!texture.loadFromFile("assets/CoinSprite.tif"))
	{
		std::cout << "Could not load player texture" << std::endl;
		return 0;
	}
	if (!texture.loadFromFile("assets/coinSprite1.tif"))
	{
		std::cout << "Could not load player texture" << std::endl;
		return 0;
	}

	sf::Sprite CarSpriteRight;
	CarSpriteRight.setTexture(texture);
	CarSpriteRight.setPosition(playerIndexX, playerIndexY);
	CarSpriteRight.setOrigin(CarSpriteRight.getLocalBounds().width / 2, CarSpriteRight.getLocalBounds().height / 2);
	CarSpriteRight.setScale(3, 3);
	CarSpriteRight.setRotation(0);

	std::cout << CarSpriteRight.getLocalBounds().width << std::endl;
	std::cout << CarSpriteRight.getLocalBounds().height << std::endl;


	sf::Time elapsed1;

	sf::Sprite CarSpriteLeft;
	CarSpriteLeft.setTexture(texture);
	CarSpriteLeft.setPosition(playerIndexX, playerIndexY);
	CarSpriteLeft.setOrigin(CarSpriteRight.getLocalBounds().width / 2, CarSpriteRight.getLocalBounds().height / 2);
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

	int x = playerIndexX;
	int y = playerIndexY;

	bool upFlag = false;
	bool downFlag = false;
	bool leftFlag = false;
	bool rightFlag = false;

	bool upInBuffer = false;
	bool downInBuffer = false;
	bool leftInBuffer = false;
	bool rightInBuffer = false;
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

		window.clear(sf::Color::Color(159, 187, 80));

		drawCells(numXCells, numYCells, mapGrid, pixel, window);

		CarSpriteRight.setPosition(x, y);
		window.draw(CarSpriteRight);



		CarSpriteLeft.setPosition(x, y);
		window.draw(CarSpriteLeft);

		CarSpriteUp.setPosition(x, y);
		window.draw(CarSpriteUp);

		CarSprite2.setPosition(x, y);
		window.draw(CarSprite2);

		CoinSprite.setPosition(x, y);
		window.draw(CoinSprite);

		CoinSprite2.setPosition(x, y);
		window.draw(CoinSprite2);

		window.draw(txtStart);
		window.draw(txtEscape);

		window.display();
	}

	return 0;
}


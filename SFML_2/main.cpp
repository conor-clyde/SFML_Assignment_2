/*
* An SFML application displaying a game - Developed by Conor Clyde, Ryan Featherstone, Joshua Hill,  Daniel Kelly, Caomhan McMonagle
* Game name: Coin Chase
* Last updated on 07/12/2021
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
#include "tilemap.cpp"

//Width and Height of window
#define winWidth 900
#define winHeight 900

//Player Sprite starting position
float playerIndexX = 45;
float playerIndexY = 75;

int main()
{
	//Variables required for Input Management - Conor cLYDE
	int score = 0, highScore = 0, counter = 0;
	bool hideCoin1 = false, hideCoin2 = false, hideCoin3 = false, hideCoin4 = false, hideCoin5 = false;
	bool hideCoin6 = false, hideCoin7 = false, hideCoin8 = false, hideCoin9 = false, hideCoin10 = false;
	bool upFlag = false, downFlag = false, leftFlag = false, rightFlag = false;
	bool upInBuffer = false, downInBuffer = false, leftInBuffer = false, rightInBuffer = false;

	//Initialise render window
	sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Coin Chaser");

	//Load in font
	sf::Font font;
	if (!font.loadFromFile(".\\fonts\\arial.ttf"))
		return EXIT_FAILURE;

	//Text labels required for game - Conor Clyde
	sf::Text txtStart("START!", font, 24); txtStart.setFillColor(sf::Color::Black); txtStart.setPosition(4, 2);
	sf::Text txtEscape("ESCAPE!", font, 24); txtEscape.setFillColor(sf::Color::Black); txtEscape.setPosition(window.getSize().x - 110, window.getSize().y - 30);
	sf::Text txtPreviousScore("Previous Score: 0 ", font, 18); txtPreviousScore.setFillColor(sf::Color::Black); txtPreviousScore.setPosition(150, 4);
	sf::Text txtCurrentScore("Current Score: 0", font, 18); txtCurrentScore.setFillColor(sf::Color::Black); txtCurrentScore.setPosition(400, 4);
	sf::Text txtHighScore("High Score: 0", font, 18); txtHighScore.setFillColor(sf::Color::Black); txtHighScore.setPosition(650, 4);
	sf::Text txtRoundInfo("", font, 18); txtRoundInfo.setFillColor(sf::Color::Black); txtRoundInfo.setPosition(400, 34); txtRoundInfo.setLineSpacing(1.2);

#pragma region ~ Create a square pixel (SFML graphics object), size it, and give it a color ~
	sf::RectangleShape pixel(sf::Vector2f(30.0f, 30.0f));
	pixel.setFillColor(sf::Color::Black);

	//Get pixel width and height of the 2d grid (based on pixel size)
	int numXCells = int(winWidth / pixel.getSize().x);
	int numYCells = int(winHeight / pixel.getSize().y);
#pragma endregion

	//Load in textures - Daniel Kelly
	sf::Texture coinTexture;
	if (!coinTexture.loadFromFile("assets/CoinSprite.png"))
	{
		std::cout << "Could not load player texture" << std::endl;
		return 0;
	}

	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("assets/playerSprite.png"))
	{
		std::cout << "Could not load player texture" << std::endl;
		return 0;
	}
	
	//Sprites - Daniel Kelly
	sf::Sprite playerSprite;
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(playerIndexX, playerIndexY);
	playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, playerSprite.getLocalBounds().height / 2);
	playerSprite.setScale(1,1);
	playerSprite.setRotation(0);

	sf::Time elapsed;
	sf::Sprite coinSprite1;
	coinSprite1.setTexture(coinTexture);
	coinSprite1.setPosition(555, 605);
	coinSprite1.setOrigin(coinSprite1.getLocalBounds().width / 2, coinSprite1.getLocalBounds().height / 2);
	coinSprite1.setScale(0.05, 0.05);
	coinSprite1.setRotation(0);

	sf::Sprite coinSprite2;
	coinSprite2.setTexture(coinTexture);
	coinSprite2.setPosition(105, 735);
	coinSprite2.setOrigin(coinSprite2.getLocalBounds().width / 2, coinSprite2.getLocalBounds().height / 2);
	coinSprite2.setScale(0.05, 0.05);
	coinSprite2.setRotation(0);

	sf::Sprite coinSprite3;
	coinSprite3.setTexture(coinTexture);
	coinSprite3.setPosition(195, 195);
	coinSprite3.setOrigin(coinSprite3.getLocalBounds().width / 2, coinSprite3.getLocalBounds().height / 2);
	coinSprite3.setScale(0.05, 0.05);
	coinSprite3.setRotation(0);

	sf::Sprite coinSprite4;
	coinSprite4.setTexture(coinTexture);
	coinSprite4.setPosition(825, 225);
	coinSprite4.setOrigin(coinSprite4.getLocalBounds().width / 2, coinSprite4.getLocalBounds().height / 2);
	coinSprite4.setScale(0.05, 0.05);
	coinSprite4.setRotation(0);

	sf::Sprite coinSprite5;
	coinSprite5.setTexture(coinTexture);
	coinSprite5.setPosition(765, 465);
	coinSprite5.setOrigin(coinSprite5.getLocalBounds().width / 2, coinSprite5.getLocalBounds().height / 2);
	coinSprite5.setScale(0.05, 0.05);
	coinSprite5.setRotation(0);

	sf::Sprite coinSprite6;
	coinSprite6.setTexture(coinTexture);
	coinSprite6.setPosition(405, 105);
	coinSprite6.setOrigin(coinSprite6.getLocalBounds().width / 2, coinSprite6.getLocalBounds().height / 2);
	coinSprite6.setScale(0.05, 0.05);
	coinSprite6.setRotation(0);

	sf::Sprite coinSprite7;
	coinSprite7.setTexture(coinTexture);
	coinSprite7.setPosition(495, 285);
	coinSprite7.setOrigin(coinSprite7.getLocalBounds().width / 2, coinSprite7.getLocalBounds().height / 2);
	coinSprite7.setScale(0.05, 0.05);
	coinSprite7.setRotation(0);

	sf::Sprite coinSprite8;
	coinSprite8.setTexture(coinTexture);
	coinSprite8.setPosition(675, 105);
	coinSprite8.setOrigin(coinSprite8.getLocalBounds().width / 2, coinSprite8.getLocalBounds().height / 2);
	coinSprite8.setScale(0.05, 0.05);
	coinSprite8.setRotation(0);

	sf::Sprite coinSprite9;
	coinSprite9.setTexture(coinTexture);
	coinSprite9.setPosition(255, 555);
	coinSprite9.setOrigin(coinSprite9.getLocalBounds().width / 2, coinSprite9.getLocalBounds().height / 2);
	coinSprite9.setScale(0.05, 0.05);
	coinSprite9.setRotation(0);

	sf::Sprite coinSprite10;
	coinSprite10.setTexture(coinTexture);
	coinSprite10.setPosition(375, 495);
	coinSprite10.setOrigin(coinSprite10.getLocalBounds().width / 2, coinSprite10.getLocalBounds().height / 2);
	coinSprite10.setScale(0.05, 0.05);
	coinSprite10.setRotation(0);

	sf::Time elapsed1;

	sf::Sprite CarSpriteLeft;
	CarSpriteLeft.setTexture(playerTexture);
	CarSpriteLeft.setPosition(playerIndexX, playerIndexY);
	CarSpriteLeft.setOrigin(CarSpriteLeft.getLocalBounds().width / 2, CarSpriteLeft.getLocalBounds().height / 2);
	CarSpriteLeft.setScale(3, 3);
	CarSpriteLeft.setRotation(0);

	std::cout << CarSpriteLeft.getLocalBounds().width << std::endl;
	std::cout << CarSpriteLeft.getLocalBounds().height << std::endl;

	sf::Time elapsed2;

	sf::Sprite CarSpriteUp;
	CarSpriteUp.setTexture(playerTexture);
	CarSpriteUp.setPosition(playerIndexX, playerIndexY);
	CarSpriteUp.setOrigin(CarSpriteUp.getLocalBounds().width / 2, CarSpriteUp.getLocalBounds().height / 2);
	CarSpriteUp.setScale(3, 3);
	CarSpriteUp.setRotation(0);

	std::cout << CarSpriteUp.getLocalBounds().width << std::endl;
	std::cout << CarSpriteUp.getLocalBounds().height << std::endl;
	sf::Time lapsed3;

	sf::Sprite CarSprite2;
	CarSprite2.setTexture(playerTexture);
	CarSprite2.setPosition(playerIndexX, playerIndexY);
	CarSprite2.setOrigin(CarSprite2.getLocalBounds().width / 2, CarSprite2.getLocalBounds().height / 2);
	CarSprite2.setScale(3, 3);
	CarSprite2.setRotation(0);

	std::cout << CarSprite2.getLocalBounds().width << std::endl;
	std::cout << CarSprite2.getLocalBounds().height << std::endl;
	sf::Time lapsed4;

#pragma region ~Load music from files ~
		//Load background music from audio folder 
		sf::Music music;
		if (!music.openFromFile(".\\audio\\background music.wav"))
			std::cout << "Could not load background music" << std::endl;

		music.play();

		//Loop background music
		music.setLoop(true);
#pragma endregion  

	//Vector list of map tiles
	std::vector<std::vector<int>> mapGrid;  

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

	//Create tilemap from level definition
	tileMap map;
	if (!map.load("assets/tileset.png", sf::Vector2u(30, 30)))
		return -1;
#pragma endregion  

	//Game clock and timer - Ryan Featherstone
	sf::Clock clock;
	int countdown = 60;

	//Making countdown a string
	std::string countdownString;
	std::ostringstream convert;
	convert << countdown;
	countdownString = convert.str();

	//Setting timer font and text
	sf::Text timerText;
	timerText.setFont(font);
	timerText.setString(countdownString);
	timerText.setPosition(700, 40);
	timerText.setCharacterSize(40);

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

					//Process up, down, left and right keys
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
		
		checkForCoin(score, playerSprite, coinSprite1, coinSprite2, coinSprite3, coinSprite4, coinSprite5, coinSprite6, coinSprite7, coinSprite8, coinSprite9, coinSprite10, hideCoin1, hideCoin2, hideCoin3, hideCoin4, hideCoin5, hideCoin6, hideCoin7, hideCoin8, hideCoin9, hideCoin10);

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
			moveLeftNextTurn(counter, playerIndexX, playerIndexY, upFlag, downFlag, leftFlag, rightFlag, upInBuffer, downInBuffer, leftInBuffer, rightInBuffer, mapGrid, playerSprite);
			rightInBuffer = false;
		}

		if (mapGrid[playerIndexY / 30][((playerIndexX + 14) + 1) / 30] && rightInBuffer == true && leftFlag == false)
		{
			moveRightNextTurn(counter, playerIndexX, playerIndexY, upFlag, downFlag, leftFlag, rightFlag, upInBuffer, downInBuffer, leftInBuffer, rightInBuffer, mapGrid, playerSprite);
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

		//TIMER - 60 SECONDS by Ryan Featherstone
		int timer = clock.getElapsedTime().asSeconds();
		std::cout << timer << std::endl;

		if (timer > 0)
		{
			countdown--;
			timerText.setString(std::to_string(countdown));
			clock.restart();
		}


		txtCurrentScore.setString("Current Score: " + std::to_string(score));

		playerSprite.setPosition(playerIndexX, playerIndexY);

		//Clear window
		window.clear(sf::Color::Color(159, 187, 80));

		//Draw game

		drawCells(numXCells, numYCells, mapGrid, pixel, window);
		window.draw(map);
		window.draw(playerSprite);
		window.draw(timerText);

		if (!hideCoin1)
			window.draw(coinSprite1);

		if (!hideCoin2)
			window.draw(coinSprite2);

		if (!hideCoin3)
			window.draw(coinSprite3);

		if (!hideCoin4)
			window.draw(coinSprite4);

		if (!hideCoin5)
			window.draw(coinSprite5);

		if (!hideCoin6)
			window.draw(coinSprite6);

		if (!hideCoin7)
			window.draw(coinSprite7);

		if (!hideCoin8)
			window.draw(coinSprite8);

		if (!hideCoin9)
			window.draw(coinSprite9);

		if (!hideCoin10)
			window.draw(coinSprite10);

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

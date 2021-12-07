//Input Management implementation file - Conor Clyde
#include <iostream>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

void checkIfAtStart(float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, sf::Font font)
{
	//If at starting position, player sprite can not move left
	if ((playerIndexX - 15) <= 30 && playerIndexY >= 60 && playerIndexY <= 90)
	{
		leftFlag = false;
		leftInBuffer = false;
	}
}

void checkIfAtWater(float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, sf::Font font, int& score, int& highScore, sf::Text& txtCurrentScore, sf::Text& txtPreviousScore, sf::Text& txtHighScore, sf::Text& txtRoundInfo, sf::Sprite& playerSprite)
{
	if (!((playerIndexX - 15) <= 30 && playerIndexY >= 60 && playerIndexY <= 90) && !((playerIndexX + 15) >= 870 && playerIndexY >= 810 && playerIndexY <= 840) && ((playerIndexX - 15) <= 30 || (playerIndexX + 15) >= 870 || (playerIndexY - 15) <= 30 || (playerIndexY + 15) >= 870))
	{
		//Adjust score due to falling in water
		score -= 500;

		//Set previous round info and score
		txtRoundInfo.setString("You Drowned!!	-500 points");

		if (score < 0)
			txtPreviousScore.setString("Previous Score: 0");
		else
			txtPreviousScore.setString("Previous Score: " + std::to_string(score));

		//Set high score if score is higher than current high score
		if (score > highScore)
		{
			highScore = score;
			txtHighScore.setString("High Score: " + std::to_string(score));
		}

		//Reset score, player starting position and key presses
		txtCurrentScore.setString("Current Score: 0");
		score = 0;

		playerIndexX = 45;
		playerIndexY = 75;
		playerSprite.setRotation(0);

		upFlag = false;
		downFlag = false;
		leftFlag = false;
		rightFlag = false;

		upInBuffer = false;
		downInBuffer = false;
		leftInBuffer = false;
		rightInBuffer = false;
	}
}

void escapeRestart(float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, sf::Font font, int& score, int& highScore, sf::Text& txtCurrentScore, sf::Text& txtPreviousScore, sf::Text& txtHighScore, sf::Text& txtRoundInfo, sf::Sprite& playerSprite)
{
	//Check if player is at the escape position
	if (playerIndexX >= 870 && playerIndexY >= 810 && playerIndexY <= 840)
	{
		//Adjust score due to escaping
		score += 1000;

		//Set previous round info and score
		txtRoundInfo.setString("You Escaped!!	+1000 points");
		txtPreviousScore.setString("Previous Score: " + std::to_string(score));

		//Set high score if score is higher than current high score
		if (score > highScore)
		{
			highScore = score;
			txtHighScore.setString("High Score: " + std::to_string(score));
		}

		//Reset score, player starting position and key presses
		txtCurrentScore.setString("Current Score: 0");
		score = 0;

		playerIndexX = 45;
		playerIndexY = 75;
		playerSprite.setRotation(0);

		upFlag = false;
		downFlag = false;
		leftFlag = false;
		rightFlag = false;

		upInBuffer = false;
		downInBuffer = false;
		leftInBuffer = false;
		rightInBuffer = false;
	}
}

void timerRestart(float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, sf::Font font, int& score, int& highScore, sf::Text& txtCurrentScore, sf::Text& txtPreviousScore, sf::Text& txtHighScore, sf::Text& txtRoundInfo, sf::Sprite& playerSprite)
{
		//Set previous round info and score
		txtRoundInfo.setString("Timer Ran out!!");
		txtPreviousScore.setString("Previous Score: " + std::to_string(score));

		//Set high score if score is higher than current high score
		if (score > highScore)
		{
			highScore = score;
			txtHighScore.setString("High Score: " + std::to_string(score));
		}

		//Reset score, player starting position and key presses
		txtCurrentScore.setString("Current Score: 0");
		score = 0;

		playerIndexX = 45;
		playerIndexY = 75;
		playerSprite.setRotation(0);

		upFlag = false;
		downFlag = false;
		leftFlag = false;
		rightFlag = false;

		upInBuffer = false;
		downInBuffer = false;
		leftInBuffer = false;
		rightInBuffer = false;
}


void checkForCoin(int& score, sf::Sprite playerSprite, sf::Sprite coinSprite1, sf::Sprite coinSprite2, sf::Sprite coinSprite3, sf::Sprite coinSprite4, sf::Sprite coinSprite5, sf::Sprite coinSprite6, sf::Sprite coinSprite7, sf::Sprite coinSprite8, sf::Sprite coinSprite9, sf::Sprite coinSprite10, bool& hideCoin1, bool& hideCoin2, bool& hideCoin3, bool& hideCoin4, bool& hideCoin5, bool& hideCoin6, bool& hideCoin7, bool& hideCoin8, bool& hideCoin9, bool& hideCoin10)
{
	//Check if player has collided with each coin sprite
	//If player does collid with a coin sprite, increase the score and hide the coin sprite
	if (playerSprite.getGlobalBounds().intersects(coinSprite1.getGlobalBounds()) && hideCoin1 == false)
	{
		score += 100;
		hideCoin1 = true;
	}

	if (playerSprite.getGlobalBounds().intersects(coinSprite2.getGlobalBounds()) && hideCoin2 == false)
	{
		score += 100;
		hideCoin2 = true;
	}

	if (playerSprite.getGlobalBounds().intersects(coinSprite3.getGlobalBounds()) && hideCoin3 == false)
	{
		score += 100;
		hideCoin3 = true;
	}

	if (playerSprite.getGlobalBounds().intersects(coinSprite4.getGlobalBounds()) && hideCoin4 == false)
	{
		score += 100;
		hideCoin4 = true;
	}

	if (playerSprite.getGlobalBounds().intersects(coinSprite5.getGlobalBounds()) && hideCoin5 == false)
	{
		score += 100;
		hideCoin5 = true;
	}

	if (playerSprite.getGlobalBounds().intersects(coinSprite6.getGlobalBounds()) && hideCoin6 == false)
	{
		score += 100;
		hideCoin6 = true;
	}

	if (playerSprite.getGlobalBounds().intersects(coinSprite7.getGlobalBounds()) && hideCoin7 == false)
	{
		score += 100;
		hideCoin7 = true;
	}

	if (playerSprite.getGlobalBounds().intersects(coinSprite8.getGlobalBounds()) && hideCoin8 == false)
	{
		score += 100;
		hideCoin8 = true;
	}

	if (playerSprite.getGlobalBounds().intersects(coinSprite9.getGlobalBounds()) && hideCoin9 == false)
	{
		score += 100;
		hideCoin9 = true;
	}

	if (playerSprite.getGlobalBounds().intersects(coinSprite10.getGlobalBounds()) && hideCoin10 == false)
	{
		score += 100;
		hideCoin10 = true;
	}
}

void moveUpNextTurn(int& counter, float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, std::vector<std::vector<int>>& mapGrid, sf::Sprite& playerSprite)
{
	if (counter == 0)
	{
		leftInBuffer = false;
		rightInBuffer = false;
	}

	counter = 1;

	upFlag = false;
	downFlag = false;
	rightFlag = false;
	leftFlag = false;

	//Move player up
	playerIndexY -= 0.8;

	//Rotate player
	playerSprite.setRotation(270);

	if (!mapGrid[((playerIndexY - 14) - 1) / 30][playerIndexX / 30] && upInBuffer == true)
	{
		upInBuffer = false;
		counter = 0;
	}
}

void moveDownNextTurn(int& counter, float& playerIndexX, float& playerIndexY, bool& downFlag, bool& upFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, std::vector<std::vector<int>>& mapGrid, sf::Sprite& playerSprite)
{
	if (counter == 0)
	{
		leftInBuffer = false;
		rightInBuffer = false;
	}

	upFlag = false;
	rightFlag = false;
	leftFlag = false;

	counter=1;

	//Move player down
	playerIndexY += 0.8;

	//Rotate player
	playerSprite.setRotation(90);

	if (!mapGrid[((playerIndexY + 14) + 1) / 30][playerIndexX / 30] && downInBuffer == true)
	{
		downInBuffer = false;
		counter = 0;
	}
}

void moveLeftNextTurn(int& counter, float& playerIndexX, float& playerIndexY, bool& downFlag, bool& upFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, std::vector<std::vector<int>>& mapGrid, sf::Sprite& playerSprite)
{
	if (counter == 0)
	{
		upInBuffer = false;
		downInBuffer = false;
	}

	counter = 1;

	upFlag = false;
	downFlag = false;
	rightFlag = false;
	leftFlag = false;

	//Move player left
	playerIndexX -= 0.8;

	//Rotate player
	playerSprite.setRotation(180);

	if (!mapGrid[playerIndexY / 30][((playerIndexX - 14) - 1) / 30] && leftInBuffer == true)
	{
		leftInBuffer = false;
		counter = 0;
	}
}

void moveRightNextTurn(int& counter, float& playerIndexX, float& playerIndexY, bool& downFlag, bool& upFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, std::vector<std::vector<int>>& mapGrid, sf::Sprite& playerSprite)
{
	if (counter == 0)
	{
		upInBuffer = false;
		downInBuffer = false;
	}

	counter = 1;

	upFlag = false;
	downFlag = false;
	rightFlag = false;
	leftFlag = false;

	//Move player right
	playerIndexX += 0.8;

	//Rotate player
	playerSprite.setRotation(0);

	if (!mapGrid[playerIndexY / 30][((playerIndexX + 14) + 1) / 30] && rightInBuffer == true)
	{
		rightInBuffer = false;
		counter = 0;
	}
}

void moveUp(float& playerIndexX, float& playerIndexY, bool& upFlag, std::vector<std::vector<int>>& mapGrid)
{
	if (mapGrid[((playerIndexY - 14) - 1) / 30][playerIndexX / 30])
		//Move player up
		playerIndexY -= 0.8;
	else
		upFlag = false;
}

void moveDown(float& playerIndexX, float& playerIndexY, bool& downFlag, std::vector<std::vector<int>>& mapGrid)
{
	//If we aren't in the bottom row and the cell below us doesn't contain an obstacle then we can move down
	if (mapGrid[((playerIndexY + 14) + 1) / 30][playerIndexX / 30])
		//Move player down
		playerIndexY += 0.8;
	else
		downFlag = false;
}


void moveLeft(float& playerIndexX, float& playerIndexY, bool& leftFlag, std::vector<std::vector<int>>& mapGrid)
{
	//If we aren't in the left-most column and the cell to our left doesn't contain an obstacle then we can move left
	if (mapGrid[playerIndexY / 30][((playerIndexX - 14) + 1) / 30])
		//Move player left
		playerIndexX -= 0.8;
	else
		leftFlag = false;
}

void moveRight(float& playerIndexX, float& playerIndexY, bool& rightFlag, std::vector<std::vector<int>>& mapGrid)
{
	//If we aren't in the right-most column and the cell to our right doesn't contain an obstacle then we can move right
	if (mapGrid[playerIndexY / 30][((playerIndexX + 14) + 1) / 30])
		//Move player right
		playerIndexX += 0.8;
	else
		rightFlag = false;
}
#include <iostream>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>


void checkIfAtStart(float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, sf::Font font, sf::RenderWindow& _window)
{
	if ((playerIndexX - 15) <= 30 && playerIndexY >= 60 && playerIndexY <= 90)
	{
		leftFlag = false;
		leftInBuffer = false;
	}
}

void checkIfAtWater(float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, sf::Font font, int& score, int& highScore, sf::Text& txtCurrentScore, sf::Text& txtPreviousScore, sf::Text& txtHighScore, sf::Text& txtRoundInfo, sf::RenderWindow& _window, sf::Sprite& playerSprite)
{
	if (!((playerIndexX - 15) <= 30 && playerIndexY >= 60 && playerIndexY <= 90) && !((playerIndexX + 15) >= 870 && playerIndexY >= 810 && playerIndexY <= 840) && ((playerIndexX - 15) <= 30 || (playerIndexX + 15) >= 870 || (playerIndexY - 15) <= 30 || (playerIndexY + 15) >= 870))
	{

		txtRoundInfo.setString("You Drowned!!\n-500 points");

		txtCurrentScore.setString("Current Score: 0");

		score -= 1000;

		if (score < 0)
			txtPreviousScore.setString("Previous Score: 0");
		else
			txtPreviousScore.setString("Previous Score: " + std::to_string(score));

		if (score > highScore)
		{
			highScore = score;
			txtHighScore.setString("High Score: " + std::to_string(score));
		}


		playerIndexX = 45;
		playerIndexY = 75;

		upFlag = false;
		downFlag = false;
		leftFlag = false;
		rightFlag = false;

		upInBuffer = false;
		downInBuffer = false;
		leftInBuffer = false;
		rightInBuffer = false;

		playerSprite.setRotation(0);

		score = 0;
	}
}

void restartGame(float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, sf::Font font, int& score, int& highScore, sf::Text& txtCurrentScore, sf::Text& txtPreviousScore, sf::Text& txtHighScore, sf::Text& txtRoundInfo, sf::RenderWindow& _window, sf::Sprite& playerSprite)
{

	if (playerIndexX >= 870 && playerIndexY >= 810 && playerIndexY <= 840)
	{
		txtRoundInfo.setString("You Escaped!!\n+1000 points");
		score += 1000;

		if (score > highScore)
		{
			highScore = score;
			txtHighScore.setString("High Score: " + std::to_string(score));
		}

		playerIndexX = 45;
		playerIndexY = 75;

		upFlag = false;
		downFlag = false;
		leftFlag = false;
		rightFlag = false;

		upInBuffer = false;
		downInBuffer = false;
		leftInBuffer = false;
		rightInBuffer = false;

		txtPreviousScore.setString("Previous Score: " + std::to_string(score));

		txtCurrentScore.setString("Current Score: 0");

		playerSprite.setRotation(0);

		score = 0;
	}


}
void checkForCoin()
{

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

	playerIndexY -= 0.8;



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
	//downFlag = false;
	rightFlag = false;
	leftFlag = false;

	counter=1;

	playerIndexY += 0.8;

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
	playerIndexX -= 0.8;

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
	playerIndexX += 0.8;

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
	{
		playerIndexY -= 0.8;
	}
	else
		upFlag = false;
}

void moveDown(float& playerIndexX, float& playerIndexY, bool& downFlag, std::vector<std::vector<int>>& mapGrid)
{
	//if we aren't in the bottom row and the cell below us doesn't contain an obstacle then we can move down
	if (mapGrid[((playerIndexY + 14) + 1) / 30][playerIndexX / 30])
	{
		playerIndexY += 0.8;
		
	}
	else
		downFlag = false;
	

}


void moveLeft(float& playerIndexX, float& playerIndexY, bool& leftFlag, std::vector<std::vector<int>>& mapGrid)
{
	//if we aren't in the left-most column and the cell to our left doesn't contain an obstacle then we can move left
	if (mapGrid[playerIndexY / 30][((playerIndexX - 14) + 1) / 30])
	{
		playerIndexX -= 0.8;
	}
	else
		leftFlag = false;
}

void moveRight(float& playerIndexX, float& playerIndexY, bool& rightFlag, std::vector<std::vector<int>>& mapGrid)
{
	//if we aren't in the right-most column and the cell to our right doesn't contain an obstacle then we can move right
	if (mapGrid[playerIndexY / 30][((playerIndexX + 14) + 1) / 30])
	{
		playerIndexX += 0.8;
	}
	else
		rightFlag = false;
}


#include <iostream>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


void checkIfAtStart()
{

}

void restartGame(float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, std::string previousScore, sf::Text& txtPreviousScore, sf::Font font, sf::RenderWindow&_window)
{

	if (playerIndexX == 860 && playerIndexY >= 810 && playerIndexY <= 840)
	{
		playerIndexX = 15;
		playerIndexY = 75;

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

void moveUp(float& playerIndexX, float& playerIndexY, bool& upFlag, std::vector<std::vector<int>>& mapGrid)
{
	if (mapGrid[((playerIndexY - 14) - 1) / 30][playerIndexX / 30])
	{
		playerIndexY -= 0.25;
	}
	else
		upFlag = false;
}
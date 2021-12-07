#pragma once

void checkIfAtStart(float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, sf::Font font, sf::RenderWindow& _window);

void checkIfAtWater(float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, sf::Font font, int& score, int& highScore, sf::Text& txtCurrentScore, sf::Text& txtPreviousScore, sf::Text& txtHighScore, sf::Text& txtRoundInfo, sf::RenderWindow& _window, sf::Sprite& playerSprite);

void restartGame(float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, sf::Font font, int& score, int& highScore, sf::Text& txtCurrentScore, sf::Text& txtPreviousScore, sf::Text& txtHighScore, sf::Text& txtRoundInfo, sf::RenderWindow& _window, sf::Sprite& playerSprite);

void checkForCoin();

void moveUpNextTurn(int& counter, float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, std::vector<std::vector<int>>& mapGrid, sf::Sprite& playerSprite);

void moveDownNextTurn(int& counter, float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, std::vector<std::vector<int>>& mapGrid, sf::Sprite& playerSprite);

void moveLeftNextTurn(int& counter, float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, std::vector<std::vector<int>>& mapGrid, sf::Sprite& playerSprite);

void moveRightNextTurn(int& counter, float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, std::vector<std::vector<int>>& mapGrid, sf::Sprite& playerSprite);

void moveUp(float& playerIndexX, float& playerIndexY, bool& upFlag, std::vector<std::vector<int>>& mapGrid);

void moveDown(float& playerIndexX, float& playerIndexY, bool& downFlag, std::vector<std::vector<int>>& mapGrid);

void moveLeft(float& playerIndexX, float& playerIndexY, bool& leftFlag, std::vector<std::vector<int>>& mapGrid);

void moveRight(float& playerIndexX, float& playerIndexY, bool& rightFlag, std::vector<std::vector<int>>& mapGrid);



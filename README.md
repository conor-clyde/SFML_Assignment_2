# UU2OOP-SFMLGame
[UU Year 2 - Object-Oriented Programming] / Group Assignment - Game (Coin Chaser) Developed on Visual Studio using SFML and C++

**To run the application from Visual Studio, clone the repository, then double click on the SFML_Assignment_2 solution in the Solution Explorer**

Group Project. Submitted as part of my Object-Oriented Programming class.<br />
The purpose of the project was to develop an simple window game using SFML.<br />
The game is called Coin Chaser.<br />
I received 82% for this assignment.

This is a Window application.<br />
Developed on Visual Studio using SFML.<br />
C++ Programming Language<br />

# My personal contribution to the project:
1. Wrote all the code related to the player's movement of the car (this took up most of my time while working on this project)
2. Wrote all the code related to the game's scoring system. This included showing three score counters at the top of the window, and updating these three score counters depending on what the player does.

Scoring System Explained:
- If the player collects a coin, 100 points is added to the player's current score
- If the player crashes into the water, 500 points is taken from the current score, and then the game is reset
- If the player reaches the escape point, 1000 points is added to the current score, and then the game is reset
- During each game reset, the player's current score is checked if it is higher than the current high score. If it is, the high score is changed to the newest score.
- During each game reset, the player's current score is made the previous score of the new game.

Known Problems:
- After the game is reset, the coins are not placed back on the map.

## Screenshots showing the game developed<br />
**Upon opening game**<br />
![image](https://user-images.githubusercontent.com/91070226/152667388-7b54fd27-d792-4afc-9b55-4b3cef378a5b.png)<br /><br />

**Upon collecting the first coin**<br />
![image](https://user-images.githubusercontent.com/91070226/152668621-1d8fb6c5-e79e-4bf7-a48a-a32da9a9d08e.png)<br /><br />

**Upon collecting every coin**<br />
![image](https://user-images.githubusercontent.com/91070226/152668645-614ebdba-36f8-4eb7-ae45-000e4718fb37.png)<br /><br />

**Player moves next to escape after collecting every coin**<br />
![image](https://user-images.githubusercontent.com/91070226/152668662-e241c726-8c47-45d1-abbf-b66ec5e25fef.png)<br /><br />

**Player passes escape after collecting every coin**<br />
![image](https://user-images.githubusercontent.com/91070226/152668671-cd43f5cf-acbc-482a-942c-5884db0c82d9.png)<br /><br />

**Player has collected six coins and is about to crash into the water**<br />
![image](https://user-images.githubusercontent.com/91070226/152668682-b0e3836d-4db0-4fbf-821f-a6e38d76185d.png)<br /><br />

**Player after crashing into water with six coins collected**<br />
![image](https://user-images.githubusercontent.com/91070226/152668689-9bae3789-9c1f-4dd2-b846-afbfce5984a0.png)<br /><br />



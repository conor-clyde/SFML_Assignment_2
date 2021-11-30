#include <iostream>      
#include <SFML/Audio.hpp>

void loadBackgroundMusic(sf::String filename) {
    sf::Music music;
    if (!music.openFromFile(filename))
    {
        std::cout << "Could not load background music" << std::endl;
        
    }

    music.play();

        
}

void loadDefeatMusic(sf::String filename) {
    sf::Music music2;
    if (!music2.openFromFile(filename))
    {
        std::cout << "Could not load defeat music" << std::endl;

    }


}

void loadVictoryMusic(sf::String filename) {
    sf::Music music3;
    if (!music3.openFromFile(filename))
    {
        std::cout << "Could not load victory music" << std::endl;

    }

}


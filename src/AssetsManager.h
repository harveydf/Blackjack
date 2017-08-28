#ifndef BLACKJACK_ASSETSMANAGER_H
#define BLACKJACK_ASSETSMANAGER_H

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

class AssetsManager {
private:
    std::map<std::string, sf::Texture> textures_;
    std::map<std::string, sf::Font>fonts_;
public:
    AssetsManager();
    void LoadTexture(std::string name, std::string fileName);
    sf::Texture &GetTexture(std::string name);
    void LoadFont(std::string name, std::string fileName);
    sf::Font &GetFont(std::string name);
};


#endif //BLACKJACK_ASSETSMANAGER_H

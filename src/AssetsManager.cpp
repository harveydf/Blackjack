#include "AssetsManager.h"

AssetsManager::AssetsManager() = default;

void AssetsManager::LoadTexture(std::string name, std::string fileName) {
    sf::Texture texture;
    if (texture.loadFromFile(fileName)) {
        textures_[name] = texture;
    } else {
        std::cout << "Error loading texture: " << fileName << "\n";
        exit(EXIT_FAILURE);
    }
}

sf::Texture &AssetsManager::GetTexture(std::string name) {
    return textures_.at(name);
}

void AssetsManager::LoadFont(std::string name, std::string fileName) {
    sf::Font font;
    if (font.loadFromFile(fileName)) {
        fonts_[name] = font;
    } else {
        std::cout << "Error loading font: " << fileName << "\n";
        exit(EXIT_FAILURE);
    }
}

sf::Font &AssetsManager::GetFont(std::string name) {
    return fonts_.at(name);
}

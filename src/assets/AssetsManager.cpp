#include "AssetsManager.hpp"
#include <iostream>

AssetsManager::AssetsManager () {
    loadFonts();
}

void AssetsManager::loadFonts() {
    sf::Font fontOpenSans;
    // path relative to build folder
    if(!fontOpenSans.loadFromFile("../src/assets/OpenSans-Light.ttf"))
    {
        std::cout << "failed to load text" << std::endl;
    }
    
    m_fonts[FontType::Regular] = fontOpenSans;
    std::cout << "AssetsManager::LoadedFonts" << std::endl;
}

sf::Font& AssetsManager::getFont(FontType fontType) {
    return m_fonts.at(fontType);
}

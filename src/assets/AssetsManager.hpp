#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include <memory>

enum FontType {
    Regular
};

class AssetsManager {
    public:
        AssetsManager();
        ~AssetsManager() {
            std::cout << "Destory Assetsmanager" << std::endl;
        }
        sf::Font& getFont(FontType fontType);

    private:
         void loadFonts();
         void loadTextures();
         std::map<FontType, sf::Font> m_fonts;    
};
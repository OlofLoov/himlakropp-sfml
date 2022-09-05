#pragma once

#include "CelestialBody.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include "AssetsManager.hpp"

class CelestialBodyCreator {
    private:

        std::shared_ptr<AssetsManager> _assets;
        int m_noOfCreated = 0;

    public:
        ~CelestialBodyCreator() {
            std::cout << "Destorying creator" << std::endl;
        }
        CelestialBodyCreator(std::shared_ptr<AssetsManager> assets);

        CelestialBody create(CelestialBodyType type, 
        sf::Vector2f startPosition,
        sf::Vector2f velocity);
};
#pragma once
#include "IScene.hpp"
#include <memory>
#include "AssetsManager.hpp"
#include <iostream>
#include "CelestialBody.hpp"
#include "CelestialBodyCreator.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class SolarSystemScene: public IScene {
    public:
        SolarSystemScene(std::shared_ptr<AssetsManager> assets, std::shared_ptr<sf::RenderWindow> window);
        ~SolarSystemScene() {
            std::cout<<"Destorying SolarSystemScene" << std::endl;
        };
        
        void update(float deltaTime);
        void render();
        void initialize();
    
    private:
        std::shared_ptr<AssetsManager> _assets;
        std::shared_ptr<sf::RenderWindow> _window;
        std::vector<CelestialBody> m_bodies;
        
        void createCelestialBody(CelestialBodyType type, 
            sf::Vector2f startPosition, 
            sf::Vector2f startVelocity, 
            CelestialBodyCreator &creator);
};
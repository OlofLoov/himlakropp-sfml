#pragma once
#include "IScene.hpp"
#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "AssetsManager.hpp"

class MenuScene: public IScene {
    public:
        MenuScene(std::shared_ptr<AssetsManager> assets, std::shared_ptr<sf::RenderWindow> window);
        ~MenuScene() {
            std::cout<<"Destorying MenuScene" << std::endl;
        };

        void update(float deltaTime);
        void render();
        void initialize();
    
    private:
        std::shared_ptr<AssetsManager> _assets;
        std::shared_ptr<sf::RenderWindow> _window;
};
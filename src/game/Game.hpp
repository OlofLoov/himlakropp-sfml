#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "CelestialBody.hpp"
#include "CelestialBodyCreator.hpp"
#include "AssetsManager.hpp"
#include "Scenes.hpp"
#include "IScene.hpp"
#include <memory>
#include <stack>

class SolarSystemScene;

class Game {
    public:
        Game();
        ~Game() {
            std::cout << "Destroying Game" << std::endl;
        };

        void run();

    private:
        void render();
        void update();

        float m_dt;
        sf::Clock m_clock;

        std::shared_ptr<sf::RenderWindow> _window = std::make_shared<sf::RenderWindow>();
        std::shared_ptr<AssetsManager> _assets;
        std::stack<std::unique_ptr<IScene>> m_scenes;
};
#include "SolarSystemScene.hpp"

SolarSystemScene::SolarSystemScene(std::shared_ptr<AssetsManager> assets, std::shared_ptr<sf::RenderWindow> window)
{
    _assets = assets;
    _window = window;
    initialize();
}

void SolarSystemScene::initialize()
{
    std::cout << "GameState::initialize" << std::endl;
    auto creator = CelestialBodyCreator(_assets);

    createCelestialBody(Star, sf::Vector2f(800.0f, 550.0f), sf::Vector2f(0.0f, 0.f), creator);
    createCelestialBody(Planet, sf::Vector2f(325.0f, 550.0f), sf::Vector2f(0.0f, 100.0f), creator);
    createCelestialBody(Asteroid, sf::Vector2f(270.0f, 550.0f), sf::Vector2f(0.0f, 110.f), creator);
    createCelestialBody(Planet, sf::Vector2f(1100.0f, 545.0f), sf::Vector2f(0.0f, -100.f), creator);
    createCelestialBody(Asteroid, sf::Vector2f(290.0f, 550.0f), sf::Vector2f(0.0f, 140.f), creator);
}

void SolarSystemScene::createCelestialBody(CelestialBodyType type, 
        sf::Vector2f startPosition, 
        sf::Vector2f startVelocity, 
        CelestialBodyCreator & creator) {
    auto cb = creator.create(type, startPosition, startVelocity);
    m_bodies.push_back(cb);    
}

void SolarSystemScene::update(float deltaTime) {
    for(auto& cb: m_bodies)
        cb.update(m_bodies, deltaTime);
}

void SolarSystemScene::render() {
    for(auto& cb: m_bodies)
        cb.render(_window);
}
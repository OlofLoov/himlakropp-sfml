#include "Game.hpp"
#include <iostream>

Game::Game() {
    _window->create(sf::VideoMode(1600, 1200),"himlakropp");
    _window->setFramerateLimit(60); 
    _assets = std::make_shared<AssetsManager>();
    m_scenes.push(std::make_unique<SolarSystemScene>(_assets, _window));
}

void Game::run() {   
    while (_window->isOpen()) {
        update();
        render();
    }
}

void Game::update() {
    sf::Event event;
    m_dt = m_clock.restart().asSeconds();

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window->close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) 
            _window->close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            m_scenes.push(std::make_unique<MenuScene>(_assets, _window));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            if (m_scenes.size() > 1) {
                m_scenes.pop();
            } else {
                _window->close();
            }
        }
    }

    if (!this->m_scenes.empty())
        m_scenes.top()->update(m_dt);
}

void Game::render() {
    _window->clear();
    if (!this->m_scenes.empty())
        m_scenes.top()->render();
    _window->display();
}
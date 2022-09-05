#include "MenuScene.hpp"
#include <iostream>

MenuScene::MenuScene(std::shared_ptr<AssetsManager> assets, std::shared_ptr<sf::RenderWindow> window) {
    _assets = assets;
    _window = window;
    initialize();
}

void MenuScene::initialize() { }

void MenuScene::update(float deltaTime) { }

void MenuScene::render() { }
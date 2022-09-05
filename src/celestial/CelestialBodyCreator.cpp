#include "CelestialBodyCreator.hpp"

CelestialBodyCreator::CelestialBodyCreator(std::shared_ptr<AssetsManager> assets) {
    _assets = assets;
}

CelestialBody CelestialBodyCreator::create(CelestialBodyType type, 
        sf::Vector2f startPosition,
        sf::Vector2f velocity) {
    float mass;
    sf::Color color;
    float radius;
    std::string name = "";
    
    switch (type) {
    case CelestialBodyType::Asteroid:
        radius = 3.0f;
        color = sf::Color::Magenta;
        name = "A";
        mass = 0.05f;
        break;
    case CelestialBodyType::Planet:
        radius = 20.0f;
        color = sf::Color::Green;
        name = "P";
        mass = 60000.0f;
        break;
    case CelestialBodyType::Star:
        radius = 70.0f;
        color = sf::Color::Yellow;
        name = "S";
        mass = 5000000.0f;
        break;
    }

    m_noOfCreated += 1;       

    return CelestialBody(
            startPosition,
            mass,
            velocity,
            type == CelestialBodyType::Star,
            name + std::to_string(m_noOfCreated),
            _assets->getFont(FontType::Regular),
            color,
            radius
    );
}
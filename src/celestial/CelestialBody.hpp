#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>  
#include <memory>
#include <queue>

enum CelestialBodyType {
    Asteroid,
    Planet,
    Star
};

class CelestialBody {
    sf::Vector2f m_position;
    sf::Vector2f m_velocity;
    float m_mass;
    sf::CircleShape m_shape;
    bool m_isStatic;
    sf::Text m_text;
    sf::VertexArray m_trail;
      
public:
    CelestialBody(
        sf::Vector2f position, 
        float mass, 
        sf::Vector2f initialVelocity, 
        bool is_static, 
        std::string name, 
        sf::Font &font,
        sf::Color color, 
        float radius
    );

    void update(const std::vector<CelestialBody> &cbs, float deltaTime);
    void render(const std::shared_ptr<sf::RenderWindow> &window);
    const sf::Vector2f getPosition();
    const float getMass();

private:
    
    void updatePosition(const sf::Vector2f &pos, const float &radius);
    void updateTrail(const sf::Vector2f &pos, const float& radius);
    std::deque<sf::Vertex> m_trailVertices;

};
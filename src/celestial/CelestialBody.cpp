#include "CelestialBody.hpp"
#include <iostream>

#include "AssetsManager.hpp"
 
CelestialBody::CelestialBody(sf::Vector2f position,
        float mass, 
        sf::Vector2f initialVelocity, 
        bool is_static, 
        std::string name,
        sf::Font& font,
        sf::Color color,
        float radius) {
    m_position = position;
    m_mass = mass;
    m_velocity = initialVelocity;
    m_isStatic = is_static;

    m_shape.setFillColor(color);
    m_shape.setRadius(radius);
    m_shape.setPosition(position);

    m_text = sf::Text(name,font);
    m_text.setCharacterSize(20);
    m_text.setFillColor(sf::Color::White);    

    m_trail = sf::VertexArray();
    m_trail.setPrimitiveType(sf::PrimitiveType::LinesStrip);

    // position static object text
    if (m_isStatic) { 
        auto pos = getPosition();
        float radius = m_shape.getRadius();
        updatePosition(pos, radius);
    }   
}

const sf::Vector2f CelestialBody::getPosition() {
    return m_position;
}

const float CelestialBody::getMass() {
    return m_mass;
}

void CelestialBody::update(const std::vector<CelestialBody> &cbs, float deltaTime) {    
    sf::Vector2f sum_acc;

    for(auto cb : cbs) {
        if(cb.getPosition() == getPosition())
            continue;

        // normalizing vectors so that the distance vector (which is the celestial body - other celestial body distance) has lenth of 1.0f
        auto v_distance = sf::Vector2f(cb.getPosition().x - m_position.x, cb.getPosition().y - m_position.y);
        float distance = sqrt(v_distance.x * v_distance.x + v_distance.y * v_distance.y);
        auto v_distance_normalized = sf::Vector2f(v_distance.x / distance, v_distance.y / distance);

        // inverse square law
        // the strength should be the m1 x m2 according to newtons law of universal gravitation
        // f1 = f2 = G * (m1 * m2) / d^2,
        // f=ma
        float distance_squared = distance * distance;
        auto v_force = sf::Vector2f(
                v_distance_normalized.x * m_mass * cb.getMass() / distance_squared, 
                v_distance_normalized.y * m_mass * cb.getMass() / distance_squared
        );
        
        sf::Vector2f acc = sf::Vector2f(
            v_force.x / m_mass,
            v_force.y / m_mass
        );

        // since there will be multiple mass-objs we need to calculate each and every one of them
        // thus we need to calc the net acc
        sum_acc.x += acc.x;
        sum_acc.y += acc.y;
    }        

    m_velocity.x += sum_acc.x * deltaTime;
    m_velocity.y += sum_acc.y * deltaTime;

    m_position.x += m_velocity.x * deltaTime;
    m_position.y += m_velocity.y * deltaTime;
    m_shape.setPosition(m_position);    
    float radius = m_shape.getRadius();

    updatePosition(m_position, radius);
    updateTrail(m_position, radius);
}

void CelestialBody::updateTrail(const sf::Vector2f &pos, const float& radius) {
    auto trail_position = pos;
    trail_position.x = trail_position.x + radius;
    trail_position.y = trail_position.y + radius;       
    m_trailVertices.insert(m_trailVertices.end(), trail_position);
    m_trail.clear();    

    if (m_trailVertices.size() >= 250)
        m_trailVertices.pop_front();
    
    for(auto& v : m_trailVertices)
        m_trail.append(v);   
}

void CelestialBody::updatePosition(const sf::Vector2f &pos, const float &radius) {
    auto text_position = pos;
    text_position.y = text_position.y + 2 * radius;
    text_position.x = text_position.x + 0.5 * radius;
    m_text.setPosition(text_position);
}

void CelestialBody::render(const std::shared_ptr<sf::RenderWindow> &window) {
    window->draw(m_trail);
    window->draw(m_text);
    window->draw(m_shape);
}

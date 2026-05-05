//
// Created by frostbite on 2026-05-02.
//

#include "CanvasSprite.h"
#include <SFML/Graphics.hpp>
#include <optional>

class CanvasSprite::Inner {
public:
    std::optional<sf::Sprite> sprite;
    sf::Vector2f position;
    float scale;
    Inner() : scale(1.0f) {}
};

CanvasSprite::CanvasSprite() {
    impl = new Inner();
}
CanvasSprite::~CanvasSprite() {
    delete impl;
}

void CanvasSprite::setTexture(const sf::Texture &texture) {
    impl->sprite.emplace(texture);
    impl->sprite->setPosition(impl->position);
    impl->sprite->setScale({impl->scale, impl->scale});
}
void CanvasSprite::setPosition(sf::Vector2f pos) {
    impl->position = pos;
    impl->sprite->setPosition(pos);
}
void CanvasSprite::setScale(float scale) {
    impl->scale = scale;
    impl->sprite->setScale({scale, scale});
}
void CanvasSprite::draw(sf::RenderWindow &window) {
    if (impl->sprite) {
        window.draw(*impl->sprite);
    }
}

//
// Created by frostbite on 2026-05-02.
//

#ifndef TP_CANVASSPRITE_H
#define TP_CANVASSPRITE_H
#include <SFML/System/Vector2.hpp>
#include "TextureManager.h"

namespace sf {
    class Texture;
    class RenderWindow;
}

class CanvasSprite {
private:
    class Inner;
    Inner *impl;

public:
    CanvasSprite();
    ~CanvasSprite();

    void setTexture(const sf::Texture &texture);
    void setPosition(sf::Vector2f &position);
    void setScale(float scale);
    void draw(sf::RenderWindow &window);
};


#endif //TP_CANVASSPRITE_H

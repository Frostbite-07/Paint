#ifndef ITOOL_H
#define ITOOL_H

#include <SFML/System.hpp>

class PixelBuffer;

class ITool
{
public:
    virtual ~ITool() = default;
    virtual void pushMouse(const sf::Vector2i& position, PixelBuffer& buffer) = 0;
    virtual void moveMouse(const sf::Vector2i& position, PixelBuffer& buffer) = 0;
    virtual void releaseMouse(const sf::Vector2i& position, PixelBuffer& buffer) = 0;
};

#endif

#ifndef ITOOL_H
#define ITOOL_H

class PixelBuffer; //tas pats, kas include .h faila, taciau sumazina runtime


class ITool
{
public:
    virtual ~ITool() = default;
    virtual void onMouseDown(const sf::Vector2i& position, PixelBuffer& buffer) = 0;
    virtual void onMouseMove(const sf::Vector2i& position, PixelBuffer& buffer) = 0;
    virtual void onMouseUp(const sf::Vector2i& position, PixelBuffer& buffer) = 0;
};

#endif

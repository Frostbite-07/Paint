#ifndef BRUSHTOOL_H
#define BRUSHTOOL_H 

#include "itool.h"
#include <SFML/Graphics/Color.hpp>

class PixelBuffer;

class BrushTool : public ITool
{
public:
    BrushTool();
    ~BrushTool() override = default;

    void pushMouse(const sf::Vector2i& position, PixelBuffer& buffer) override;
    void moveMouse(const sf::Vector2i& position, PixelBuffer& buffer) override;
    void releaseMouse(const sf::Vector2i& position, PixelBuffer& buffer) override;
    void setColor(const sf::Color& color);
    void setSize(int size) override;

private:
    sf::Color brushColor;
    int brushSize;
};

#endif
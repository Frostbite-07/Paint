#ifndef MOUSE_CONTROLLER_H
#define MOUSE_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

class PixelBuffer; 
class MouseController {
private:
    bool isDrawing;
    sf::Color brushColor;
    int brushSize;
    float scale;

public:
    MouseController();
    void processEvent(const sf::Event& event);
    void update(const sf::Vector2i& mousePos, PixelBuffer& buffer);
    sf::Vector2i screenToPixel(const sf::Vector2i& screenPos);
    void setBrushColor(const sf::Color& color);
    void setBrushSize(int size);
    void setScale(float newScale);

};

#endif

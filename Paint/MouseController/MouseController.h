#ifndef MOUSE_CONTROLLER_H
#define MOUSE_CONTROLLER_H

#include <SFML/Graphics.hpp>

class MouseController {
private:
    bool isDrawing;
    sf::Color brushColor;
    int brushSize;
    float scale;

public:
    MouseController();
    void processEvent(const sf::Event& event);
    void update(const sf::Vector2i& mousePos);
    sf::Vector2i screenToPixel(const sf::Vector2i& screenPos);
};

#endif

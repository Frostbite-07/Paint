#ifndef MOUSE_CONTROLLER_H
#define MOUSE_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

enum class ToolType {
    Brush,
    Eraser
};

class PixelBuffer;
class MouseController {
private:
    bool isDrawing;
    sf::Color brushColor;
    sf::Color eraserColor;
    int brushSize;
    float scale;
    ToolType currentTool;

public:
    MouseController();
    void processEvent(const sf::Event& event);
    void update(const sf::Vector2i& mousePos, PixelBuffer& buffer);
    sf::Vector2i screenToPixel(const sf::Vector2i& screenPos);
    void setBrushColor(const sf::Color& color);
    void setBrushSize(int size);
    void setScale(float newScale);
    void setTool(ToolType tool);
};

#endif

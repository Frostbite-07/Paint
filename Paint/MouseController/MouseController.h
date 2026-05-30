#ifndef MOUSE_CONTROLLER_H
#define MOUSE_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include "../Itool/itool.h"
#include "ToolType.h"

class PixelBuffer;

class MouseController {
private:
    bool isDrawing;
    bool isNewStroke;
    float scale;
    int brushSize;
    sf::Color brushColor;
    sf::Color eraserColor;
    ITool* currentToolPointer; 
    std::unique_ptr<ITool> brushTool;
    std::unique_ptr<ITool> eraserTool;
    sf::Vector2i screenToPixel(const sf::Vector2i& screenPos);

public:
    MouseController();
    void processEvent(const sf::Event& event);
    void update(const sf::Vector2i& mousePos, PixelBuffer& buffer);
    void setBrushColor(const sf::Color& color);
    void setBrushSize(int size);
    void setScale(float newScale);
    void setTool(ToolType tool);
};

#endif

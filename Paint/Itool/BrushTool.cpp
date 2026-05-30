#include "BrushTool.h"
#include "../PixelBuffer/PixelBuffer.h"

BrushTool::BrushTool() : brushColor(sf::Color::Black), brushSize(5) {}

void BrushTool::pushMouse(const sf::Vector2i& position, PixelBuffer& buffer) {
    moveMouse(position, buffer); 
}

void BrushTool::moveMouse(const sf::Vector2i& position, PixelBuffer& buffer) {
    int halfSize = brushSize / 2;
    for (int x = -halfSize; x <= halfSize; ++x) {
        for (int y = -halfSize; y <= halfSize; ++y) {
            int targetX = position.x + x;
            int targetY = position.y + y;
            if (targetX >= 0 && targetX < buffer.getWidth() && 
                targetY >= 0 && targetY < buffer.getHeight()) {
                buffer.setPixel(targetX, targetY, brushColor.r, brushColor.g, brushColor.b, 255);
            }
        }
    }
}

void BrushTool::releaseMouse(const sf::Vector2i& position, PixelBuffer& buffer) {}
void BrushTool::setSize(int size) { brushSize = size; }
void BrushTool::setColor(const sf::Color& color) { brushColor = color; }
#include "EraserTool.h"
#include "../PixelBuffer/PixelBuffer.h"

EraserTool::EraserTool() : eraserSize(5) {}

void EraserTool::pushMouse(const sf::Vector2i& position, PixelBuffer& buffer) {
    moveMouse(position, buffer);
}

void EraserTool::moveMouse(const sf::Vector2i& position, PixelBuffer& buffer) {
    int halfSize = eraserSize / 2;
    for (int x = -halfSize; x <= halfSize; ++x) {
        for (int y = -halfSize; y <= halfSize; ++y) {
            int targetX = position.x + x;
            int targetY = position.y + y;
            if (targetX >= 0 && targetX < buffer.getWidth() && 
                targetY >= 0 && targetY < buffer.getHeight()) {
                buffer.setPixel(targetX, targetY, 255, 255, 255, 255);
            }
        }
    }
}

void EraserTool::releaseMouse(const sf::Vector2i& position, PixelBuffer& buffer) {}
void EraserTool::setSize(int size) { eraserSize = size; }
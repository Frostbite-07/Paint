#include "MouseController.h"
#include "../PixelBuffer/PixelBuffer.h"
#include "../Itool/BrushTool.h"
#include "../Itool/EraserTool.h"
#include "ToolType.h"

MouseController::MouseController () {
    isDrawing = false;
    isNewStroke = false;
    brushColor = sf::Color::Black;
    eraserColor = sf::Color::White;
    brushSize = 5;
    scale = 1.0f;
    brushTool = std::make_unique<BrushTool>();
    eraserTool = std::make_unique<EraserTool>();
    currentToolPointer = brushTool.get();
}

void MouseController::setBrushColor(const sf::Color& color) {
    brushColor = color;
    brushTool->setColor(color);
}

void MouseController::setBrushSize(int size) {
    if (size > 0 && size < 100) { 
        brushSize = size;
        brushTool->setSize(size);
        eraserTool->setSize(size);
    }
}

void MouseController::setScale(float newScale) {
    if (newScale > 0.001f) { 
        scale = newScale;
    }
}

void MouseController::setTool(ToolType tool) {
    if (tool == ToolType::Brush) {
        currentToolPointer = brushTool.get();
    } else if (tool == ToolType::Eraser) {
        currentToolPointer = eraserTool.get();
    }
}

void MouseController::processEvent(const sf::Event& event) {
    if (const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>()) {
        if (mousePressed->button == sf::Mouse::Button::Left) {
            isDrawing = true;
            isNewStroke = true;
        }
    }

    if (const auto* mouseReleased = event.getIf<sf::Event::MouseButtonReleased>()) {
        if (mouseReleased->button == sf::Mouse::Button::Left) {
            isDrawing = false;
        }
    }

}

void MouseController::update(const sf::Vector2i& mousePos, PixelBuffer& buffer) {
    if (!isDrawing || currentToolPointer == nullptr) return;

    sf::Vector2i pixelPos = screenToPixel(mousePos);
    if (isNewStroke) {
            currentToolPointer->pushMouse(pixelPos, buffer);
            isNewStroke = false;
        } else {
            currentToolPointer->moveMouse(pixelPos, buffer);
        }
}

sf::Vector2i MouseController::screenToPixel(const sf::Vector2i& screenPos) {
    return sf::Vector2i(
        static_cast<int>(screenPos.x / scale),
        static_cast<int>(screenPos.y / scale)
    );
}


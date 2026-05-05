#include "MouseController.h"
#include "PixelBuffer.h"

MouseController::MouseController () {
    isDrawing = false;
    brushColor = sf::Color::Black;
    brushSize = 5;
    scale = 1.0f;
}

void MouseController::setBrushColor(const sf::Color& color) {
    brushColor = color;
}

void MouseController::setBrushSize(int size) {
    if (size > 0 && size < 100) { 
        brushSize = size;
    }
}

void MouseController::setScale(float newScale) {
    if (newScale > 0.001f) { 
        scale = newScale;
    }
}

void MouseController::processEvent(const sf::Event& event) {
    if (const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>()) {
        if (mousePressed->button == sf::Mouse::Button::Left) {
            isDrawing = true;
        }
    }

    if (event.is<sf::Event::MouseButtonReleased>()) {
        isDrawing = false;
    }

}

void MouseController::update(const sf::Vector2i& mousePos, PixelBuffer& buffer) {
    if (!isDrawing) return;

    sf::Vector2i pixelPos = screenToPixel(mousePos);

    int halfSize = brushSize / 2;
    for (int x = -halfSize; x <= halfSize; ++x) {
        for (int y = -halfSize; y <= halfSize; ++y) {
            buffer.setPixel(pixelPos.x + x, pixelPos.y + y, brushColor.r, brushColor.g, brushColor.b, 255);//255, kad nebutu permatoma
        }
    }
}

sf::Vector2i MouseController::screenToPixel(const sf::Vector2i& screenPos) {
    return sf::Vector2i(
        static_cast<int>(screenPos.x / scale),
        static_cast<int>(screenPos.y / scale)
    );
}


#include "MouseController.h"

MouseController::MouseController () {
    isDrawing = false;
    brushColor = sf::Color::Black;
    brushSize = 5;
    scale = 1.0f;
}

void MouseController::processEvent(const sf::Event& event) {
    if(event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left) {
            isDrawing = true;
        }
    }
    if(event.type == sf::Event::MouseButtonReleased) {
        if(event.mouseButton.button == sf::Mouse::Left) {
            isDrawing = false;
        }
    }
}

void MouseController::update(const sf::Vector2i& mousePos) {

}

sf::Vector2i MouseController::screenToPixel(const sf::Vector2i& screenPos) {

    return sf::Vector2i(screenPos.x / (int)scale, screenPos.y / (int)scale);
}

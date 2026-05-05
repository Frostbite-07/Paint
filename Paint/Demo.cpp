#include <SFML/Graphics.hpp>
#include "PixelBuffer/PixelBuffer.h"
#include "MouseController/MouseController.h"
#include "Display/TextureManager.h"
#include "Display/CanvasSprite.h"


int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Progress Demo: Gradient + Paint");
    window.setFramerateLimit(60);

    PixelBuffer pixelBuffer(800, 600);
    TextureManager textureManager;
    CanvasSprite canvasSprite;

    for (int y = 0; y < 600; ++y) {
        for (int x = 0; x < 800; ++x) {
            uint8_t r = 0;
            uint8_t g = static_cast<uint8_t>((static_cast<float>(x) / 800.f) * 255);
            uint8_t b = static_cast<uint8_t>((static_cast<float>(y) / 600.f) * 255);
            pixelBuffer.setPixel(x, y, r, g, b, 255);
        }
    }

    textureManager.update(pixelBuffer);
    canvasSprite.setTexture(textureManager.getTexture());

    bool isDrawing = false;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) window.close();
            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mousePressed->button == sf::Mouse::Button::Left) isDrawing = true;
            }
            if (event->is<sf::Event::MouseButtonReleased>()) {
                isDrawing = false;
            }
        }

        if (isDrawing) {
            sf::Vector2i m = sf::Mouse::getPosition(window);
            int brushSize = 12; 

            for (int offsetX = -brushSize/2; offsetX < brushSize/2; ++offsetX) {
                for (int offsetY = -brushSize/2; offsetY < brushSize/2; ++offsetY) {
                    pixelBuffer.setPixel(m.x + offsetX, m.y + offsetY, 255, 255, 255, 255);
                }
            }
            textureManager.update(pixelBuffer);
        }

        window.clear(sf::Color::Black);
        canvasSprite.draw(window);
        window.display();
    }

    return 0;
}
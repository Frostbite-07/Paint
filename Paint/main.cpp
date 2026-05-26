#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "PixelBuffer/PixelBuffer.h"
#include "MouseController/MouseController.h"
#include "Display/TextureManager.h"
#include "Display/CanvasSprite.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Paint 0.9.0");
    window.setFramerateLimit(60);

    PixelBuffer pixelBuffer(800, 600);
    TextureManager textureManager;
    CanvasSprite canvasSprite;
    MouseController mouseController;

    pixelBuffer.clearPixels(255, 255, 255, 255);
    textureManager.update(pixelBuffer);
    canvasSprite.setTexture(textureManager.getTexture());

    sf::RectangleShape brushButton(sf::Vector2f(40.f, 40.f));
    brushButton.setPosition({10.f, 10.f});
    brushButton.setFillColor(sf::Color::Green);
    brushButton.setOutlineThickness(2.f);
    brushButton.setOutlineColor(sf::Color::Black);

    sf::RectangleShape eraserButton(sf::Vector2f(40.f, 40.f));
    eraserButton.setPosition({60.f, 10.f});
    eraserButton.setFillColor(sf::Color::Red);
    eraserButton.setOutlineThickness(2.f);
    eraserButton.setOutlineColor(sf::Color::Black);

    sf::RectangleShape saveButton(sf::Vector2f(40.f, 40.f));
    saveButton.setPosition(sf::Vector2f(10.f, 60.f));
    saveButton.setFillColor(sf::Color::Blue);
    saveButton.setOutlineThickness(2.f);
    saveButton.setOutlineColor(sf::Color::Black);
    

    std::cout << "Green button: brush | Red button: eraser | Blue button: save\n";

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            bool uiClicked = false;

            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mousePressed->button == sf::Mouse::Button::Left) {
                    sf::Vector2f mousePos(static_cast<float>(mousePressed->position.x), static_cast<float>(mousePressed->position.y));

                    if (brushButton.getGlobalBounds().contains(mousePos)) {
                        mouseController.setTool(ToolType::Brush);
                        std::cout << "Switched to brush\n";
                        uiClicked = true;
                    } 
                    else if (eraserButton.getGlobalBounds().contains(mousePos)) {
                        mouseController.setTool(ToolType::Eraser);
                        std::cout << "Switched to eraser\n";
                        uiClicked = true;
                    }
                    else if (saveButton.getGlobalBounds().contains(mousePos)) {
                        sf::Image saveImage = textureManager.getTexture().copyToImage();
                        if (saveImage.saveToFile("my_drawing.png")) {
                            std::cout << "Saved successfully to my_drawing.png\n";
                        } else {
                            std::cerr << "Failed to save\n";
                        }
                        uiClicked = true;
                }
            }
        }
            if (!uiClicked) {
                mouseController.processEvent(*event);
            }
    }
        mouseController.update(sf::Mouse::getPosition(window), pixelBuffer);

        textureManager.update(pixelBuffer);

        window.clear(sf::Color(150, 150, 150));
        
        canvasSprite.draw(window);
        
        window.draw(brushButton);
        window.draw(eraserButton);
        window.draw(saveButton);

        window.display();
    }

    return 0;
}
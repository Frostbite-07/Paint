#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <cstdint>

int main() {
    unsigned int pixels_w = 600;
    unsigned int pixels_h = 600;

    std::vector<uint8_t> pixels(pixels_w * pixels_h * 4, 0);

    sf::RenderWindow window(sf::VideoMode({600, 600}), "Paint");

    sf::Texture texture;
    if (!texture.resize({pixels_w, pixels_h})) {
        return -1;
    }

    sf::Sprite sprite(texture);
    float scale = static_cast<float>(window.getSize().x) / pixels_w;

    sprite.setScale({scale, scale});

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (mousePos.x >= 0 && mousePos.y >= 0) {
                unsigned int x = static_cast<unsigned int>(mousePos.x / scale);
                unsigned int y = static_cast<unsigned int>(mousePos.y / scale);

                if (x < pixels_w && y < pixels_h) {
                    unsigned int ir = (pixels_w * y + x) * 4;

                    pixels[ir] = 255;
                    pixels[ir + 1] = 255;
                    pixels[ir + 2] = 255;
                    pixels[ir + 3] = 255;

                    texture.update(pixels.data());
                }
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}

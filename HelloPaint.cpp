#include <SFML/Graphics.hpp>
#include <vector>

int main() {
    unsigned int pixels_w = 600;
    unsigned int pixels_h = 600;

    std::vector<uint8_t> pixels(pixels_w * pixels_h * 4, 0);

    sf::RenderWindow window(sf::VideoMode({600, 600}), "Paint");

    sf::Texture texture({pixels_w, pixels_h});
    sf::Sprite sprite(texture);
    float scale = window.getSize().x / pixels_w;
    sprite.setScale({scale, scale});

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                unsigned int x = mousePos.x / scale;
                unsigned int y = mousePos.y / scale;

                if (x < (int) pixels_w && y < (int) pixels_h) {
                    unsigned int ir = (pixels_w * y + x) * 4;
                    unsigned int ig = ir + 1;
                    unsigned int ib = ig + 1;
                    unsigned int ia = ib + 1;

                    pixels[ir] = 255;
                    pixels[ig] = 255;
                    pixels[ib] = 255;
                    pixels[ia] = 255;

                    texture.update(pixels.data());
                }
            }
            window.draw(sprite);

            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.display();
    }
}

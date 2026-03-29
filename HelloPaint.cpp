#include <SFML/Graphics.hpp>
#include <vector>

int main() {
    unsigned int pixels_w = 600;
    unsigned int pixels_h = 600;

    std::vector<uint8_t> pixels(pixels_w * pixels_h * 4, 0);

    sf::RenderWindow window(sf::VideoMode({600, 600}), "Paint");

    sf::Texture texture({pixels_w, pixels_h});

    sf::Sprite sprite(texture);
    float scale = (float)window.getSize().x / pixels_w;

    sprite.setScale({scale, scale});

    while (window.isOpen()) {
#ifdef __linux__        //MinGW32 does not support c++20 from my findings and std::optional, which is required by SFML 3, was added then, thus, to make it work with MinGW32, this is the solution I have
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
#else
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
#endif

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (mousePos.x >= 0 && mousePos.y >= 0) {
                unsigned int x = mousePos.x / scale;
                unsigned int y = mousePos.y / scale;

                if (x < pixels_w && y < pixels_h) {
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
        }
        
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
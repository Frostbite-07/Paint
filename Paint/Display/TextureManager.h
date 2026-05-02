//
// Created by frostbite on 2026-05-02.
//

#ifndef TP_TEXTUREMANAGER_H
#define TP_TEXTUREMANAGER_H
#include <vector>
#include <SFML/Graphics/Texture.hpp>

class TextureManager {
    private:
    sf::Texture texture;
    bool needsUpdate;

    public:
    void update(std::vector<uint8_t> pixels, PixelBuffer buffer);
    sf::Texture& getTexture(sf::Texture& texture) const;

};

#endif //TP_TEXTUREMANAGER_H

//
// Created by frostbite on 2026-05-02.
//

#ifndef TP_TEXTUREMANAGER_H
#define TP_TEXTUREMANAGER_H
#include <SFML/Graphics/Texture.hpp>
#include "../PixelBuffer/PixelBuffer.h"

namespace sf {
    class Texture;
}

class TextureManager {
private:
    class Inner;
    Inner *impl;

public:
    TextureManager();
    ~TextureManager();

    void update(const PixelBuffer buffer);
    const sf::Texture &getTexture() const;
};

#endif //TP_TEXTUREMANAGER_H

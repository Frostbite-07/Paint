//
// Created by frostbite on 2026-05-02.
//

#include "TextureManager.h"
#include "../PixelBuffer/PixelBuffer.h"
#include <SFML/Graphics.hpp>

class TextureManager::Inner {
public:
    sf::Texture texture;
    bool needsUpdate;

    Inner() : needsUpdate(true) {
    }
};

TextureManager::TextureManager() {
    impl = new Inner();
}
TextureManager::~TextureManager() {
    delete impl;
}

void TextureManager::update(const PixelBuffer& pixels) {
    impl->texture.update(pixels.getPixels().data());
    impl->needsUpdate = false;
}
const sf::Texture& TextureManager::getTexture() const {
    return impl->texture;
}

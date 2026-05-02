#define PIXELBUFFER_H

#include <vector>
#include <cstdint>

class PixelBuffer
{
private:
    class Inner;
    Inner *impl;
public:
    PixelBuffer(int width, int height);
    void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    const std::vector<uint8_t> &getPixels() const;
    int getWidth() const;
    int getHeight() const;
    void clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
};


#endif

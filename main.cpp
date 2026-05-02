#include <iostream>
#include <vector>

using namespace std;

class PixelBuffer::Inner
{
    vector<uint8_t> pixels;
    int width;
    int height;
public:
    void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    {
        if ((x < 0) || (x >= width) || (y < 0) || (y >= height))
            return;
        int index = (y * width + x) * 4;
        pixels[index + 0] = r;
        pixels[index + 1] = g;
        pixels[index + 2] = b;
        pixels[index + 3] = a;
    }
    const std::vector<uint8_t> &getPixels() const
    {
        return pixels;
    }
    int PixelBuffer::getWidth() const
    {
        return width;
    }
    int PixelBuffer::getHeight() const
    {
        return height;
    }
    void PixelBuffer::clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    {
        for (int i = 0; i < width * height; ++i)
        {
            pixels[i * 4 + 0] = r;
            pixels[i * 4 + 1] = g;
            pixels[i * 4 + 2] = b;
            pixels[i * 4 + 3] = a;
        }
    }
};


int main()
{

    return 0;
}

#ifndef ERASERTOOL_H
#define ERASERTOOL_H

#include "itool.h"

class PixelBuffer;

class EraserTool : public ITool
{
public:
    EraserTool();
    ~EraserTool() override = default;
    
    void pushMouse(const sf::Vector2i& position, PixelBuffer& buffer) override;
    void moveMouse(const sf::Vector2i& position, PixelBuffer& buffer) override;
    void releaseMouse(const sf::Vector2i& position, PixelBuffer& buffer) override;
    
    void setSize(int size) override;

private:
    int eraserSize;
};

#endif

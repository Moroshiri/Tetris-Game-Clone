#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include "Grid.hpp"
#include "../../graphics/texture/Texture.hpp"
#include "../../graphics/entity/Entity.hpp"
#include "../../util/Types.hpp"

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;

const int BOARD_POS_X = 96;
const int BOARD_POS_Y = 288;

class Board : public Grid, public Entity, public Rectangle
{
public:
    Board(Size grid_size, Size px_size, Point position);
    ~Board();

    virtual void Render(SDL_Renderer* rend);

    bool TryMerge(Grid obj);
    void SetTextureArray(Texture** ptr);

private:
    Texture** _texturesArray; // Tablica wskaźników na tekstury do wyświetlania
};

#endif
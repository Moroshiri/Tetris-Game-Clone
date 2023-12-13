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

enum MergeResult
{
    MRES_EE, // Empty - Empty
    MRES_NE, // Not Emty - Empty
    MRES_EN, // Empty - Not Empty
    MRES_NN, // Not Empty - Not Empty
    MRES_LAST
};

class Board : public Grid, public Entity, public Rectangle
{
public:
    Board(Size grid_size, Size px_size, Point position);
    ~Board();

    virtual void Render(SDL_Renderer* rend);

    bool TryMerge(Grid* obj, Point pos);
    void Merge(Grid* obj, Point pos);
    void SetTextureArray(Texture** ptr);
    Texture* GetTexture(int index) const;
    bool IsTexReady() const;

private:
    Texture** _texturesArray; // Tablica wskaźników na tekstury do wyświetlania
    int _nTex;
    bool _texReady;
};

#endif
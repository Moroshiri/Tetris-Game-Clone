#ifndef _TSHAPE_HPP_
#define _TSHAPE_HPP_

#include "Sprite.hpp"
#include "../../mechanics/grid/Grid.hpp"

enum TPattern
{
    SHAPE_I,
    SHAPE_J,
    SHAPE_L,
    SHAPE_O,
    SHAPE_S,
    SHAPE_Z,
    SHAPE_T,
    SHAPE_LAST
};

class TShape : public Sprite, public Grid
{
public:
    TShape();
    ~TShape();

    TPattern GetPattern();
    void SetPattern();

    virtual void Render();

private:

    TPattern _pat;
};

#endif
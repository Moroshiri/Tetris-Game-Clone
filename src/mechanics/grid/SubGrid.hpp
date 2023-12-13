#ifndef _SUBGRID_HPP_
#define _SUBGRID_HPP_

#include "../../graphics/entity/transform/Transform.hpp"
#include "Board.hpp"

class SubGrid : public Grid, public Entity
{
public:
    SubGrid(Size size, Point position, Board* host);
    ~SubGrid();

    Point GetPosition() const;
    void SetPosition(Point pos);
    void SetPosition(int x, int y);
    void Move(Direction dir, int steps);

    Board* GetHost() const;
    void Render(SDL_Renderer* rend);

protected:
    Point _pos;
    Board* const _host;
};

#endif
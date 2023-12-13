#include "SubGrid.hpp"

SubGrid::SubGrid(Size size, Point position, Board* host) : Grid(size), _host(host)
{
    _pos = position;
}

SubGrid::~SubGrid() { }

Point SubGrid::GetPosition() const
{
    return _pos;
}

void SubGrid::SetPosition(Point pos)
{
    _pos = pos;
}

void SubGrid::SetPosition(int x, int y)
{
    _pos.x = x;
    _pos.y = y;
}

void SubGrid::Move(Direction dir, int steps)
{
    switch(dir)
    {
        case DIR_UP:
            _pos.y -= steps;
        break;
        case DIR_RIGHT:
            _pos.x += steps;
        break;
        case DIR_DOWN:
            _pos.y += steps;
        break;
        case DIR_LEFT:
            _pos.x -= steps;
        break;
        default:
        break;
    }
}

Board* SubGrid::GetHost() const
{
    return _host;
}

void SubGrid::Render(SDL_Renderer* rend)
{
    if(_host->IsTexReady())
    {
        Rect rect;
        rect.w = TILE_SIZE;
        rect.h = TILE_SIZE;
        for(int i = 0; i < _nTiles; i++)
        {
            if(_tileArray[i] != TILE_EMPTY)
            {
                // Obliczanie pozycji
                rect.x = i % _gridSize.w * TILE_SIZE + _host->GetRect().x + _pos.x * TILE_SIZE;
                rect.y = i / _gridSize.w * TILE_SIZE + _host->GetRect().y + _pos.y * TILE_SIZE;

                SDL_RenderCopy(rend, _host->GetTexture(_tileArray[i])->GetSDLTexture(), NULL, &rect);
            }
        }
    }
}
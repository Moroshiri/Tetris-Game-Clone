#include "TShape.hpp"

TShape::TShape(Point pos) : Grid(newSize(4, 4))
{
    _pos = pos;
    _rotDir = DIR_UP;
    _pat = SHAPE_NULL;
}

TShape::~TShape()
{

}

TPattern TShape::GetPattern()
{
    return _pat;
}

void TShape::SetPattern(TPattern pat, Tile tile)
{
    _pat = pat;
    _tile = tile;
    _patArray = (bool*)(shapePatterns[pat]);
    _nPat = sizeof(_patArray) / sizeof(_patArray[0]); // Liczba elementów tablicy
    _nPat = _nPat / (PATTERN_NTILES / 8) - 1; // Liczba patternów od 0
    AssignTileArray();
}

Direction TShape::GetRotation()
{
    return _rotDir;
}

void TShape::SetRotation(Direction dir)
{
    _rotDir = dir;
    AssignTileArray();
}

void TShape::Rotate(int dir)
{
    int shift = dir > 0 ? 1 : (dir < 0 ? -1 : 0);
    if(shift != 0) 
    {
        int res = _rotDir + shift;
        _rotDir = (Direction)(res < 0 ? DIR_LAST - 1 : (res >= DIR_LAST ? 0 : res));

        AssignTileArray();
    }
}

Point TShape::GetPosition()
{
    return _pos;
}

void TShape::SetPosition(Point pos)
{
    _pos = pos;
}

void TShape::SetPosition(int x, int y)
{
    _pos.x = x;
    _pos.y = y;
}

void TShape::Move(Direction dir, int steps)
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

void TShape::AssignTileArray()
{
    int patArrayShift = _nPat < 1 ? 0 : PATTERN_NTILES * (_rotDir % _nPat); // Obliczanie przesunięcia w zależkości od ilości patternów
    for(int i = 0; i < PATTERN_NTILES; i++)
    {
        _tileArray[i] = _patArray[i + patArrayShift] ? _tile : TILE_EMPTY;
    }
}
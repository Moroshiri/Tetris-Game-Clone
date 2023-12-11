#include "TShape.hpp"

int TShape::nShapeTiles = 16;

TShape::TShape(Point pos) : Grid(newSize(4, 4))
{
    _pos = pos;
    _rotDir = DIR_UP;
    _patType = SHAPE_NULL;
}

TShape::~TShape()
{

}

TPattern TShape::GetPattern()
{
    return _patType;
}

void TShape::SetPattern(TPattern pat, Tile tile)
{
    _patType = pat;
    _tile = tile;
    _patStruct = shapePatterns[pat];

    // constexpr std::size_t arraySize = std::extent<decltype(shapePatterns[pat])>::value;
    // _nPat = sizeof(_patArray) / sizeof(_patArray[0]);
    // _nPat = _nPat / (PATTERN_NTILES / 8) - 1; // Liczba patternów od 0
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

void TShape::Rotate(TRotation rot)
{
    int shift = rot == ROT_RIGHT ? 1 : -1;
    int res = _rotDir + shift;
    _rotDir = (Direction)(res < 0 ? DIR_LAST - 1 : (res >= DIR_LAST ? 0 : res));
    AssignTileArray();
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
    int patWidth = _patStruct->w;
    int nTiles = patWidth * patWidth;
    int patRotShift = _patStruct->n == 1 || _rotDir == DIR_UP ? 0 : nTiles * (_rotDir % _patStruct->n); // Przesunięcie ze względu na obrót, czyli wybranie odpowiedniego patternu z tablicy
    
    for(int i = 0, row = 0, col = 0; i < nShapeTiles; i++, row = i / _gridSize.h, col = i % _gridSize.w)
    {
        if(row < patWidth && col < patWidth) // Przepisanie wartości z tablicy
        {
            int patWidthShift = (_gridSize.w - patWidth) * row; // Przesunięcie ze względu na różnicę szerokości patternu i siatki
            _tileArray[i] = _patStruct->arr[i + patRotShift - patWidthShift] ? _tile : TILE_EMPTY;
        }
        else // Dodawanie pustych linii
            _tileArray[i] = TILE_EMPTY;
    }
}
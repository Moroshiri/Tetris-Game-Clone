#include "Grid.hpp"

Grid::Grid(Size size) : _gridSize(size), _nTiles(size.w * size.h)
{
    _tileArray = new Tile[_nTiles];

    for(int i = 0; i < _nTiles; i++)
    {
        _tileArray[i] = TILE_EMPTY;
    }
}

Grid::~Grid()
{
    delete _tileArray;
}

Tile* Grid::GetGridArray()
{
    return _tileArray;
}

Error Grid::SetGridArray(Tile* arr)
{
    if(arr != NULL)
    {
        int arrSize = sizeof(arr) / sizeof(arr[0]);
        int gridSize = _gridSize.h * _gridSize.w;
        if(arrSize == gridSize)
        {
            _tileArray = arr;
        }
        else return Error(ERROR_GRID_SIZESET, "Tile array has wrong size");
    }
    return Error(ERROR_GRID_SIZESET, "Tile array is empty");
}

void Grid::SetTile(Tile tile, Point pos)
{
    if (pos.x < _gridSize.w && pos.y < _gridSize.h)
    {
        _tileArray[pos.x + (pos.y * _gridSize.w)] = tile;
    }
    else Error::PrintError(Error(ERROR_GRID_OUTOFRANGE, "Position is out of grid range"));
}

void Grid::SetTile(Tile tile, int x, int y)
{
    Point pt;
    pt.x = x;
    pt.y = y;
    return SetTile(tile, pt);
}

const Size Grid::GetGridSize()
{
    return _gridSize;
}

void Grid::Clear(Tile tile)
{
    for(int i = 0; i < _nTiles; i++)
        _tileArray[i] = tile;
}

void Grid::Clear()
{
    Clear(TILE_EMPTY);
}
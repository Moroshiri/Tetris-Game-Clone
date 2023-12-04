#ifndef _GRID_HPP_
#define _GRID_HPP_

#include "../../util/Types.hpp"
#include "../../util/Error.hpp"

enum Tile
{
    TILE_EMPTY,
    TILE_RED,
    TILE_GREEN,
    TILE_BLUE,
    TILE_YELLOW,
    TILE_CYAN,
    TILE_MAGENTA,
    TILE_ORANGE,
    TILE_LAST
};

const int TILE_SIZE = 32;

class Grid
{
public:
    Grid(Size size);
    ~Grid();

    virtual Tile* GetGridArray();
    virtual Error SetGridArray(Tile* arr);

    virtual void SetTile(Tile tile, Point pos);
    virtual void SetTile(Tile tile, int x, int y);

    virtual const Size GetGridSize();

protected:
    Tile* _tileArray; // Tablica pól siatki
    const Size _gridSize; // Wymiary siatki
    const int _nTiles; // Liczba pól
};

#endif
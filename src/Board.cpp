#include "Board.hpp"

Board::Board(Size grid_size, Size px_size, Point position) : Grid(grid_size), Rectangle(position, px_size)
{
    _texturesArray = nullptr;
}

Board::~Board()
{ }

void Board::Render(SDL_Renderer* rend)
{
    if(_texturesArray != nullptr)
    {
        int nTex = sizeof(_texturesArray) - 1;
        if(nTex == TILE_LAST-1) 
        {
            Rect rect;
            rect.w = TILE_SIZE;
            rect.h = TILE_SIZE;
            for(int i = 0; i < _nTiles; i++)
            {
                if(_tileArray[i] != TILE_EMPTY)
                {
                    // Obliczanie pozycji
                    rect.x = i % _gridSize.w * TILE_SIZE + _rect.x;
                    rect.y = i / _gridSize.w * TILE_SIZE + _rect.y;

                    SDL_RenderCopy(rend, _texturesArray[_tileArray[i]]->GetSDLTexture(), NULL, &rect);
                }
            }
        }
    }
    
}

bool Board::TryMerge(Grid obj)
{
    return true;
}

void Board::SetTextureArray(Texture** ptr)
{
    _texturesArray = ptr;
}
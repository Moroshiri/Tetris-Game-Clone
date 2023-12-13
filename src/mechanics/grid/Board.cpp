#include "Board.hpp"

Board::Board(Size grid_size, Size px_size, Point position) : Grid(grid_size), Rectangle(position, px_size)
{
    _texturesArray = nullptr;
    _nTex = 0;
    _texReady = false;
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

bool Board::TryMerge(Grid* obj, Point pos)
{

    // TODO: zmiany przeprowadzać na tablicy tymczasowej, nie na oryginalnej, aby w razie niepowodzenia, odrzucić zmiany
    // TODO: dodać zapezpieczenia przed wyjściem poza zakres tablicy _tileArray

    
    int startPos = pos.x + (pos.y * _gridSize.w);
    Size shapeSize = obj->GetGridSize();
    int nTiles = shapeSize.w * shapeSize.h;
    int widthDiff = _gridSize.w - shapeSize.w; // Różnica szerokości planszy i siatki szktałtu
    for(int i = 0; i < nTiles; i++)
    {
        int corrShift = i / shapeSize.h * widthDiff; // Przesunięcie ze względu na różnicę szerokości planszy i kształtu
        int arrayPos = i + startPos + corrShift; // Indeks tablicy _tileArray
        Tile btile = _tileArray[arrayPos], stile = obj->GetGridArray()[i]; 
        bool canMerge = !(btile != TILE_EMPTY && stile != TILE_EMPTY);

        if(!canMerge) return false;
        if(btile == TILE_EMPTY && stile != TILE_EMPTY) _tileArray[arrayPos] = stile;
    }

    return true;
}

void Board::SetTextureArray(Texture** ptr)
{
    if(ptr != nullptr)
    {
        int nTex = sizeof(ptr) - 1;
        if(nTex == TILE_LAST-1)
        {
            _texturesArray = ptr;
            _nTex = nTex;
            _texReady = true;
        }
    }
}

Texture* Board::GetTexture(int index) const
{
    if (index < _nTex && index > 0)
        return _texturesArray[index];
    else return nullptr;
}

bool Board::IsTexReady() const
{
    return _texReady;
}
#ifndef _TSHAPE_HPP_
#define _TSHAPE_HPP_

#include "SubGrid.hpp"
#include "Patterns.hpp"

enum TRotation
{
    ROT_RIGHT,
    ROT_LEFT
};

class TShape : public SubGrid
{
public:
    static int nShapeTiles;

    TShape(Point position, Board* host);
    ~TShape();

    TPattern GetPattern();
    void SetPattern(TPattern pat, Tile tile);

    Direction GetRotation();
    void SetRotation(Direction dir);
    void Rotate(TRotation rot);

protected:
    Point _pos; // Pozycja na planszy, nie na ekranie
    Direction _rotDir; // Aktualny kierunek oboru
    TPattern _patType; // Aktualny pattern

private:
    void AssignTileArray();
    // bool* _patArray; // Tablica z patternami
    // int _nPat; // Liczba patternów w tablicy
    const ShapePattern* _patStruct; // Pattern kształtu
    Tile _tile; // Aktualny kolor
};

#endif
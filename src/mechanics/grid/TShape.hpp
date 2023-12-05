#ifndef _TSHAPE_HPP_
#define _TSHAPE_HPP_

#include "../../graphics/entity/transform/Transform.hpp"
#include "Grid.hpp"
#include "Patterns.hpp"



class TShape : public Grid
{
public:
    friend class Board;

    TShape(Size grid_size, Point position);
    ~TShape();

    TPattern GetPattern();
    void SetPattern(TPattern pat, Tile tile);

    Direction GetRotation();
    void SetRotation(Direction dir);
    void Rotate(int dir); // + w prawo, - w lewo, 0 - brak obrotu

    Point GetPosition();
    void SetPosition(Point pos);
    void SetPosition(int x, int y);
    void Move(Direction dir, int steps);

protected:
    Point _pos; // Pozycja na planszy, nie na ekranie
    Direction _rotDir; // Aktualny kierunek oboru
    TPattern _pat; // Aktualny pattern

private:
    void AssignTileArray();
    bool* _patArray; // Tablica z patternami
    int _nPat; // Liczba patternów w tablicy
    Tile _tile; // Aktualny kolor
};

#endif
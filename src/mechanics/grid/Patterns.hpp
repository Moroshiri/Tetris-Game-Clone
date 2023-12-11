#ifndef _PATTERNS_HPP_
#define _PATTERNS_HPP_

enum TPattern
{
    SHAPE_NULL,
    SHAPE_I,
    SHAPE_J,
    SHAPE_L,
    SHAPE_O,
    SHAPE_S,
    SHAPE_Z,
    SHAPE_T,
    SHAPE_LAST
};

struct ShapePattern
{
    const bool* arr; // Wskaźnik na tablicę patternów
    int w; // Szerokość patternu
    int n; // Liczba patternów
};

const int PATTERN_NTILES = 16;

const bool patArrNull[]
{
    0,0,0,0,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0
};
const ShapePattern patNull { patArrNull, 4, 1 };

const bool patArrShapeI[]
{
    0,0,0,0,
    1,1,1,1,
    0,0,0,0,
    0,0,0,0,

    0,0,1,0,
    0,0,1,0,
    0,0,1,0,
    0,0,1,0
};
const ShapePattern patShapeI {patArrShapeI, 4, 2};

const bool patArrShapeJ[]
{
    0,1,0,
    0,1,0,
    1,1,0,

    1,0,0,
    1,1,1,
    0,0,0,

    0,1,1,
    0,1,0,
    0,1,0,

    0,0,0,
    1,1,1,
    0,0,1
};
const ShapePattern patShapeJ {patArrShapeJ, 3, 4};

const bool patArrShapeL[]
{
    0,1,0,
    0,1,0,
    0,1,1,

    0,0,0,
    1,1,1,
    1,0,0,

    1,1,0,
    0,1,0,
    0,1,0,
    
    0,0,1,
    1,1,1,
    0,0,0
};
const ShapePattern patShapeL {patArrShapeL, 3, 4};

const bool patArrShapeO[]
{
    1,1,
    1,1
};
const ShapePattern patShapeO {patArrShapeO, 2, 1};

const bool patArrShapeS[]
{
    0,1,1,
    1,1,0,
    0,0,0,

    1,0,0,
    1,1,0,
    0,1,0
};
const ShapePattern patShapeS {patArrShapeS, 3, 2};

const bool patArrShapeZ[]
{
    1,1,0,
    0,1,1,
    0,0,0,

    0,1,0,
    1,1,0,
    1,0,0,
};
const ShapePattern patShapeZ {patArrShapeZ, 3, 2};

const bool patArrShapeT[]
{
    0,0,0,
    1,1,1,
    0,1,0,

    0,1,0,
    1,1,0,
    0,1,0,

    0,1,0,
    1,1,1,
    0,0,0,

    0,1,0,
    0,1,1,
    0,1,0
};
const ShapePattern patShapeT {patArrShapeT, 3, 4};

const ShapePattern* const shapePatterns[]
{
    &patNull,
    &patShapeI,
    &patShapeJ,
    &patShapeL,
    &patShapeO,
    &patShapeS,
    &patShapeZ,
    &patShapeT
};

#endif
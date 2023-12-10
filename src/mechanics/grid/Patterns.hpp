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

const int PATTERN_NTILES = 16;

const bool patShapeNull[]
{
    0,0,0,0,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0
};

const bool patShapeI[]
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

const bool patShapeJ[]
{
    0,1,0,0,
    0,1,0,0,
    1,1,0,0,
    0,0,0,0,

    1,0,0,0,
    1,1,1,0,
    0,0,0,0,
    0,0,0,0,

    0,1,1,0,
    0,1,0,0,
    0,1,0,0,
    0,0,0,0,

    0,0,0,0,
    1,1,1,0,
    0,0,1,0,
    0,0,0,0
};

const bool patShapeL[]
{
    0,1,0,0,
    0,1,0,0,
    0,1,1,0,
    0,0,0,0,

    0,0,0,0,
    1,1,1,0,
    1,0,0,0,
    0,0,0,0,

    1,1,0,0,
    0,1,0,0,
    0,1,0,0,
    0,0,0,0,
    
    0,0,1,0,
    1,1,1,0,
    0,0,0,0,
    0,0,0,0
};

const bool patShapeO[]
{
    0,0,0,0,
    0,1,1,0,
    0,1,1,0,
    0,0,0,0
};

const bool patShapeS[]
{
    0,1,1,0,
    1,1,0,0,
    0,0,0,0,
    0,0,0,0,

    0,1,0,0,
    0,1,1,0,
    0,0,1,0,
    0,0,0,0
};

const bool patShapeZ[]
{
    1,1,0,0,
    0,1,1,0,
    0,0,0,0,
    0,0,0,0,

    0,0,1,0,
    0,1,1,0,
    0,1,0,0,
    0,0,0,0
};

const bool patShapeT[]
{
    0,0,0,0,
    1,1,1,0,
    0,1,0,0,
    0,0,0,0,

    0,1,0,0,
    1,1,0,0,
    0,1,0,0,
    0,0,0,0,

    0,1,0,0,
    1,1,1,0,
    0,0,0,0,
    0,0,0,0,

    0,1,0,0,
    0,1,1,0,
    0,1,0,0,
    0,0,0,0
};

const bool* const shapePatterns[]
{
    patShapeNull,
    patShapeI,
    patShapeJ,
    patShapeL,
    patShapeO,
    patShapeS,
    patShapeZ,
    patShapeT
};

#endif
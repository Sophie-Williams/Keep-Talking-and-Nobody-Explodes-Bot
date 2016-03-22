#include "Bomb.h"

class Maze {
private:
    struct Point {
        unsigned short x;
        unsigned short y;
    };

    std::unordered_map<unsigned short, std::pair<Point, Point> > mazeCircles = {
        { 1,{ Point({ 2, 1 }), Point({ 3, 6 }) } },
        { 2,{ Point({ 2, 5 }), Point({ 4, 2 }) } },
        { 3,{ Point({ 4, 4 }), Point({ 4, 6 }) } },
        { 4,{ Point({ 1, 1 }), Point({ 4, 1 }) } },
        { 5,{ Point({ 3, 5 }), Point({ 6, 4 }) } },
        { 6,{ Point({ 1, 5 }), Point({ 5, 3 }) } },
        { 7,{ Point({ 1, 2 }), Point({ 6, 2 }) } },
        { 8,{ Point({ 1, 4 }), Point({ 4, 3 }) } },
        { 9,{ Point({ 2, 3 }), Point({ 5, 1 }) } }
    };

    Point triangle;
    Point square;

    std::string maze1[11] = {
        "o o o#o o o",
        " ### # ####",
        "o#o o#o o o",
        " # ####### ",
        "o#o o#o o o",
        " ### # ### ",
        "o#o o o#o o",
        " ######### ",
        "o o o#o o#o",
        " ### # ### ",
        "o o#o o#o o"
    };

    std::string maze2[11] = {
        "o o o#o o o",
        "## ### # ##",
        "o o#o o#o o",
        " ### ##### ",
        "o#o o#o o o",
        " # ### ### ",
        "o o#o o#o#o",
        " ### ### # ",
        "o#o#o#o o#o",
        " # # # ### ",
        "o#o o#o o o"
    };

    std::string maze3[11] = {
        "o o o#o#o o",
        " ### # # # ",
        "o#o#o#o o#o",
        "## # ##### ",
        "o o#o#o o#o",
        " # # # # # ",
        "o#o#o#o#o#o",
        " # # # # # ",
        "o#o o#o#o#o",
        " ##### # # ",
        "o o o o#o o"
    };

    std::string maze4[11] = {
        "o o#o o o o",
        " # ####### ",
        "o#o#o o o o",
        " # # ##### ",
        "o#o o#o o#o",
        " ##### ### ",
        "o#o o o o o",
        " ######### ",
        "o o o o o#o",
        " ####### # ",
        "o o o#o o#o"
    };

    std::string maze5[11] = {
        "o o o o o o",
        "######## # ",
        "o o o o o#o",
        " ##### ####",
        "o o#o o#o o",
        " # ##### # ",
        "o#o o o#o#o",
        " ##### ### ",
        "o#o o o o#o",
        " # ####### ",
        "o#o o o o o"
    };

    std::string maze6[11] = {
        "o#o o#o o o",
        " # # ### # ",
        "o#o#o#o o#o",
        " # # # ### ",
        "o o#o#o#o o",
        " ##### # ##",
        "o o#o o#o#o",
        "## # # # # ",
        "o o#o#o#o o",
        " ##### ### ",
        "o o o o#o o"
    };

    std::string maze7[11] = {
        "o o o o#o o",
        " ##### # # ",
        "o#o o#o o#o",
        " # ####### ",
        "o o#o o#o o",
        "#### ### ##",
        "o o#o o o#o",
        " # # ##### ",
        "o#o#o o o#o",
        " ####### # ",
        "o o o o o o"
    };

    std::string maze8[11] = {
        "o#o o o#o o",
        " # ### # # ",
        "o o o#o o#o",
        " ######### ",
        "o#o o o o#o",
        " #  #### # ",
        "o#o o#o o o",
        " ### ######",
        "o#o#o o o o",
        " # ########",
        "o o o o o o"
    };

    std::string maze9[11] = {
        "o#o o o o o",
        " # ##### # ",
        "o#o#o o#o#o",
        " # # ### # ",
        "o o o#o o#o",
        " ##### ### ",
        "o#o#o o#o o",
        " # # ##### ",
        "o#o#o#o o#o",
        " # # # # ##",
        "o o#o o#o o"
    };
};

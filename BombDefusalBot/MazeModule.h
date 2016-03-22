#include "Bomb.h"

#define MAZE_WIDTH 11
#define MAZE_HEIGHT 11

class MazeModule {
private:
    std::unordered_map<std::string, int> circlePointStringsToMazeNumbers = {
        { "2,1", 0 },
        { "3,6", 0 },
        { "2,5", 1 },
        { "4,2", 1 },
        { "4,4", 2 },
        { "4,6", 2 },
        { "1,1", 3 },
        { "4,1", 3 },
        { "3,5", 4 },
        { "6,4", 4 },
        { "1,5", 5 },
        { "5,3", 5 },
        { "1,2", 6 },
        { "6,2", 6 },
        { "1,4", 7 },
        { "4,3", 7 },
        { "2,3", 8 },
        { "5,1", 8 }
    };

    std::string maze0[11] = {
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

    std::string maze1[11] = {
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

    std::string maze2[11] = {
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

    std::string maze3[11] = {
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

    std::string maze4[11] = {
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

    std::string maze5[11] = {
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

    std::string maze6[11] = {
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

    std::string maze7[11] = {
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

    std::string maze8[11] = {
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
    
    unsigned short endX, endY;
    bool visited[MAZE_WIDTH][MAZE_HEIGHT] = { 0 };
    std::vector<char> steps;

    unsigned short* MazeModule::parseCoordinateString(const std::string coordinateString);
    bool getMazeNumberFromCircle(const std::string circlePointString, unsigned short startX, unsigned short startY);
    bool solveMazeModuleRecursive(const std::string maze[11], const unsigned short startX, const unsigned short startY);
    void printSteps();

public:
    bool MazeModule::solveMazeModule(const std::string circleCoordinateString, const std::string triangleCoordinateString, const std::string squareCoordinateString);
};

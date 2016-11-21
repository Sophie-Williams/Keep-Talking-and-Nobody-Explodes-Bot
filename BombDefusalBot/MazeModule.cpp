#include "MazeModule.h"

namespace Bomb
{
    bool MazeModule::solveMazeModule(const std::string circleCoordinateString, const std::string triangleCoordinateString, const std::string squareCoordinateString) {
        std::vector<unsigned short> parsedCoordinates = parseCoordinateString(triangleCoordinateString);
        unsigned short startX, startY;
        startX = ((parsedCoordinates[0] * 2) - 2);
        startY = ((parsedCoordinates[1] * 2) - 2);

        parsedCoordinates = parseCoordinateString(squareCoordinateString);
        endX = ((parsedCoordinates[0] * 2) - 2);
        endY = ((parsedCoordinates[1] * 2) - 2);

        if (getMazeNumberFromCircle(circleCoordinateString, startX, startY)) {
            printSteps();
            return true;
        }

        _ASSERT_EXPR(false, "Unreachable code - invalid maze!");
        return false;
    }

    std::vector<unsigned short> MazeModule::parseCoordinateString(const std::string coordinateString) {
        _ASSERT_EXPR((coordinateString.length() == 3), "Not enough coordinates given!");

        std::vector<std::string> coordinatesStrings;
        split(coordinateString, coordinatesStrings, ',');

        _ASSERT_EXPR((coordinatesStrings.size() == 2), "Not enough coordinates given!");

        std::vector<unsigned short> coordinates(2, 0);
        coordinates[0] = stoi(coordinatesStrings[0]);
        coordinates[1] = stoi(coordinatesStrings[1]);

        return coordinates;
    }

    bool MazeModule::getMazeNumberFromCircle(const std::string circlePointString, const unsigned short startX, const unsigned short startY) {
        unsigned short mazeNumber = 0;

        if (circlePointStringsToMazeNumbers.find(circlePointString) != circlePointStringsToMazeNumbers.end()) {
            mazeNumber = circlePointStringsToMazeNumbers.at(circlePointString);
        }

        _ASSERT_EXPR(((mazeNumber >= 0) && (mazeNumber <= 8)), "Invalid maze selected!");
        std::cout << mazeNumber << std::endl;

        switch (mazeNumber) {
        case 0:
            return solveMazeModuleRecursive(maze0, startX, startY);
            break;
        case 1:
            return solveMazeModuleRecursive(maze1, startX, startY);
            break;
        case 2:
            return solveMazeModuleRecursive(maze2, startX, startY);
            break;
        case 3:
            return solveMazeModuleRecursive(maze3, startX, startY);
            break;
        case 4:
            return solveMazeModuleRecursive(maze4, startX, startY);
            break;
        case 5:
            return solveMazeModuleRecursive(maze5, startX, startY);
            break;
        case 6:
            return solveMazeModuleRecursive(maze6, startX, startY);
            break;
        case 7:
            return solveMazeModuleRecursive(maze7, startX, startY);
            break;
        case 8:
            return solveMazeModuleRecursive(maze8, startX, startY);
            break;
        default:
            _ASSERT_EXPR(false, "Unreachable code");
            return false;
        }

        _ASSERT_EXPR(false, "Unreachable code");

        return false;
    }

    bool MazeModule::solveMazeModuleRecursive(const std::string maze[11], const unsigned short x, const unsigned short y) {
        if ((x == endX) && (y == endY)) {
            return true;
        }

        if ((maze[x][y] == '#') || (visited[x][y])) {
            return false;
        }

        visited[x][y] = true;
        if (x != 0) {
            if (solveMazeModuleRecursive(maze, (x - 1), y)) {
                if (maze[x][y] == 'o') {
                    steps.push_back('0');
                }
                return true;
            }
        }
        if (x != (MAZE_WIDTH - 1)) {
            if (solveMazeModuleRecursive(maze, (x + 1), y)) {
                if (maze[x][y] == 'o') {
                    steps.push_back('1');
                }
                return true;
            }
        }
        if (y != 0) {
            if (solveMazeModuleRecursive(maze, x, (y - 1))) {
                if (maze[x][y] == 'o') {
                    steps.push_back('2');
                }
                return true;
            }
        }
        if (y != (MAZE_HEIGHT - 1)) {
            if (solveMazeModuleRecursive(maze, x, (y + 1))) {
                if (maze[x][y] == 'o') {
                    steps.push_back('3');
                }
                return true;
            }
        }

        return false;
    }

    void MazeModule::printSteps() {
        for (int i = (steps.size() - 1); i >= 0; --i) {
            switch (steps[i]) {
            case '0':
                std::cout << "UP" << std::endl;
                break;
            case '1':
                std::cout << "DOWN" << std::endl;
                break;
            case '2':
                std::cout << "LEFT" << std::endl;
                break;
            case '3':
                std::cout << "RIGHT" << std::endl;
                break;
            default:
                _ASSERT_EXPR(false, "Unreachable code - invalid maze direction!");
                break;
            }
        }
    }
}

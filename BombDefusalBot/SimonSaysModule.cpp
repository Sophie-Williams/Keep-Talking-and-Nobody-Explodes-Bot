#include "SimonSaysModule.h"

std::string SimonSaysModule::solveSimonSaysModule(std::string color, bool increment) {
    char colorKey = color[0];
    std::string responseColor = getSimonSaysColor(colorKey);

    if (increment) {
        solveSimonSaysModuleIncrement(responseColor);
    }

    return responseColor;
}

std::vector<std::string> SimonSaysModule::solveSimonSaysModuleIncrement(std::string responseColor) {
    colorSequence.push_back(responseColor);

    return colorSequence;
}

std::string SimonSaysModule::getSimonSaysColor(char color) {
    if (_serialHasVowel) {
        if (_strikes == 0) {
            switch (color) {
            case 'r':
                return "blue";
            case 'b':
                return "red";
            case 'g':
                return "yellow";
            case 'y':
                return "green";
            }
        }
        else if (_strikes == 1) {
            switch (color) {
            case 'r':
                return "yellow";
            case 'b':
                return "green";
            case 'g':
                return "blue";
            case 'y':
                return "red";
            }
        }
        else {
            switch (color) {
            case 'r':
                return "green";
            case 'b':
                return "red";
            case 'g':
                return "yellow";
            case 'y':
                return "blue";
            }
        }
    }
    else {
        if (_strikes == 0) {
            switch (color) {
            case 'r':
                return "blue";
            case 'b':
                return "yellow";
            case 'g':
                return "green";
            case 'y':
                return "red";
            }
        }
        else if (_strikes == 1) {
            switch (color) {
            case 'r':
                return "red";
            case 'b':
                return "blue";
            case 'g':
                return "yellow";
            case 'y':
                return "green";
            }
        }
        else {
            switch (color) {
            case 'r':
                return "yellow";
            case 'b':
                return "green";
            case 'g':
                return "blue";
            case 'y':
                return "red";
            }
        }
    }
    
    // This should be unreachable code indicating a parsing error
    _ASSERT(false);
    return "error";
}

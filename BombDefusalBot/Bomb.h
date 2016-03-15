#ifndef Bomb_HEADER
#define Bomb_HEADER

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <iostream>

extern std::string _serial;
extern std::vector<std::string> _ports;
extern std::vector<std::string> _unlitIndicators;
extern int _batteries;
extern std::vector<std::string> _litIndicators;
extern int _strikes;
extern std::vector<int> _existingPorts;
extern bool lastSerialDigitOdd;
extern bool _serialHasVowel;

class Bomb {
private:
    void Initialize();
    void IsLastSerialDigitOdd(std::string serial);
    void serialHasVowel(std::string serial);
    void SetPorts(std::vector<std::string> ports);

public:
    Bomb(int batteries, std::string serial, std::vector<std::string> ports, std::vector<std::string> litIndicators, std::vector<std::string> unlitIndicators);

    //bool passwordMatches[30] = { 0 };
    //bool morseMatches[16] = { 0 };
    //short memoryPositions[4] = { 0 };
    //short memoryValues[4] = { 0 };

    /*struct ComplicatedWire {
        std::string color = "";
        bool led = false;
        bool star = false;
        bool cut = false;
    };*/

    /*const enum Ports {
        Dvi = 0,
        Parallel = 1,
        Ps = 2,
        Rj = 3,
        Serial = 4,
        Stereo = 5
    };*/

    /*std::string solveWireSequenceModule(std::vector<std::string> wires, std::vector<char> connection);

    std::string solveBasicWiresModule(std::vector<std::string> inputWires);
    int countWiresOfColor(const std::string color);

    //ComplicatedWire parseWires(std::string wire);
    //std::string solveComplicatedWiresModule(std::vector<ComplicatedWire> wires);

    std::vector<std::string> solveSymbolsModule(std::string input);

    std::string solveKnobModule(std::vector<bool> lights);

    int solveMemoryModule(const int numbers[5], const int stage);
    int calculateMemoryPositionFromLabel(const int numbers[5], const int label);

    std::string solveMorseModule(std::vector<std::string> letters, int position);

    std::string solvePasswordModule(char dialLetters[6], int dial);

    std::string getSimonSaysColor(char color);
    std::string solveSimonSaysModule(std::vector<std::string> colors);

    std::string solveWhosOnFirstModulePosition(std::string display);
    std::vector<std::string> solveWhosOnFirstModuleWordList(std::string word);*/
};

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

/*extern std::vector<std::string> _unlitIndicators = std::vector<std::string>();
extern const std::vector<std::string> indicators;
extern const std::vector<std::string> ports;
extern const std::vector<std::vector<std::string> > symbolsTable;
extern const std::vector<std::string> passwords;
extern const std::vector<std::string> morseWords;

extern bool passwordMatches[30];
extern bool morseMatches[16];
extern short memoryPositions[4];
extern short memoryValues[4];

extern bool lastSerialDigitOdd;
extern bool _serialHasVowel;
*/
// TODO: const correctness
// TODO: assertions
// TODO: sanitize (lower case) input
// TODO: revisit enums for colors and constants
// TODO: driver->bomb.cpp
// TODO: end input prematurely on num limit
#endif
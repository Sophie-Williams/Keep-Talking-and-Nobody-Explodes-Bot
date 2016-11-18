#ifndef Bomb_HEADER
#define Bomb_HEADER

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <bitset>
#include <utility>

#define DIAL_LETTERS 6
#define NUMBER_OF_PASSWORDS 35

extern std::string _serial;
extern std::vector<std::string> _ports;
extern int _batteries;
extern std::vector<std::string> _litIndicators;
extern int _strikes;
extern std::vector<bool> _existingPorts;
extern bool _lastSerialDigitOdd;
extern bool _serialHasVowel;

class Bomb {
private:
    enum Commands {
        QUIT = -1,
        INITIALIZE,
        BASIC_WIRES,
        BUTTON,
        KEYPAD,
        SIMON_SAYS,
        WHOS_ON_FIRST,
        MEMORY,
        MORSE_CODE,
        COMPLICATED_WIRES,
        WIRE_SEQUENCE,
        MAZE,
        PASSWORD,
        KNOB
    };
    unsigned short currentMemoryStep;

    void isLastSerialDigitOdd(std::string serial);
    void doesSerialHaveVowel(std::string serial);
    void setPorts(std::vector<std::string> ports);
    short parseCommand(const std::string unparsedCommand);
    int convertTextToInteger(std::string word);
    void initializeBomb();
    void handleBasicWiresModule();
    void handleButtonModule();
    void handleKeypadModule();
    void handleSimonSaysModule();
    void handleWhosOnFirstModule();
    void handleMemoryModule();
    void handleMorseCodeModule();
    void handleComplicatedWiresModule();
    void handleWireSequenceModule();
    void handleMazeModule();
    void handlePasswordModule();
    void handleKnobModule();

public:
    Bomb();
    void handleCommands();
};

std::vector<std::string> &split(const std::string &s, std::vector<std::string> &elems, char delim = ' ');

#endif

// *****TODOS*****
// check const correctness
// add assertions
// sanitize all input to be lower case comparisons
// sanitize all input to expected values (who's on first with homophones, for example)
// revisit enums for colors, constants, etc.
// driver->bomb.cpp and header file renaming
// end inputs prematurely on num limit
// passing pointers and such
// remove vars from classes/headers?
// signed->unsigned and int->short (and others)
// vector->arrays? (where applicable
// with limits, use constants? (e.g. memory can only be [1,4], dials have to have 6 letters
// assert-> assert_expr?
// str function in knob is bs
// bomb commands to enum?
// function naming case/convention
// function ordering
// split bomb init and handling back up?
// replace asserts with error strings when it shouldn't crash
// prompt for missing info if not provided
// change morse to ask for more letters like password
// class vs static vars
//hander* -> *handler?
/*
const std::vector<std::string> indicators = std::vector<std::string>({ "snd", "clr", "car", "ind", "frq", "sig", "nsa", "msa", "trn", "bob", "frk" });
const std::vector<std::string> portTypes = std::vector<std::string>({ "dvi", "parallel", "ps", "rj", "serial", "stereo" });
*/
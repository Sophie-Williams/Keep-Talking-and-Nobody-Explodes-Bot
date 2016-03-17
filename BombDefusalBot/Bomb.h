#ifndef Bomb_HEADER
#define Bomb_HEADER

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <bitset>

extern std::string _serial;
extern std::vector<std::string> _ports;
extern std::vector<std::string> _unlitIndicators;
extern int _batteries;
extern std::vector<std::string> _litIndicators;
extern int _strikes;
extern std::vector<int> _existingPorts;
extern bool lastSerialDigitIsOdd;
extern bool _serialHasVowel;

class Bomb {
private:
    void InitializeBomb();
    void IslastSerialDigitIsOdd(std::string serial);
    void serialHasVowel(std::string serial);
    void SetPorts(std::vector<std::string> ports);

public:
    Bomb(int batteries, std::string serial, std::vector<std::string> ports, std::vector<std::string> litIndicators, std::vector<std::string> unlitIndicators);
};

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

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
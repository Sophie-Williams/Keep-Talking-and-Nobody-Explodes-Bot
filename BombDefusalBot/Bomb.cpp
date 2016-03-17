#include "Bomb.h"

int _strikes;
int _batteries;
std::string _serial;
std::vector<std::string> _ports;
std::vector<std::string> _litIndicators;
std::vector<std::string> _unlitIndicators;
std::vector<int> _existingPorts(6, 0);
bool lastSerialDigitIsOdd;
bool _serialHasVowel;

Bomb::Bomb(int batteries, std::string serial, std::vector<std::string> ports, std::vector<std::string> litIndicators, std::vector<std::string> unlitIndicators) {
    _strikes = 0;
    _batteries = batteries;
    _serial = serial;
    _ports = ports;
    _litIndicators = litIndicators;
    _unlitIndicators = unlitIndicators;

    InitializeBomb();
}

void Bomb::InitializeBomb() {
    IslastSerialDigitIsOdd(_serial);
    serialHasVowel(_serial);
    SetPorts(_ports);
}

void Bomb::IslastSerialDigitIsOdd(std::string serial) {
    if ((serial[(serial.length() - 1)] % 2) == 0) {
        lastSerialDigitIsOdd = true;
    }

    lastSerialDigitIsOdd = false;
}

void Bomb::serialHasVowel(std::string serial) {
    for (char c : serial)
    {
        char tmp = tolower(c);

        if ((tmp == 'a') ||
            (tmp == 'e') ||
            (tmp == 'i') ||
            (tmp == 'o') ||
            (tmp == 'u'))
        {
            _serialHasVowel = true;
        }
    }

    _serialHasVowel = false;
}

void Bomb::SetPorts(std::vector<std::string> ports) {
    for (std::string port : ports) {
        if (port == "dvi") {
            _existingPorts[0] = 1;
        }
        else if (port == "parallel") {
            _existingPorts[1] = 1;
        }
        else if (port == "ps") {
            _existingPorts[2] = 1;
        }
        else if (port == "rj") {
            _existingPorts[3] = 1;
        }
        else if (port == "serial") {
            _existingPorts[4] = 1;
        }
        else if (port == "stereo") {
            _existingPorts[5] = 1;
        }
    }
}

/*
const std::vector<std::string> indicators = std::vector<std::string>({ "snd", "clr", "car", "ind", "frq", "sig", "nsa", "msa", "trn", "bob", "frk" });
const std::vector<std::string> portTypes = std::vector<std::string>({ "dvi", "parallel", "ps", "rj", "serial", "stereo" });
*/

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }

    return elems;
}

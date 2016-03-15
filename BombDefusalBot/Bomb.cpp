#include "Bomb.h"

int _strikes;
int _batteries;
std::string _serial;
std::vector<std::string> _ports;
std::vector<std::string> _litIndicators;
std::vector<std::string> _unlitIndicators;
std::vector<int> _existingPorts(6, 0);
bool lastSerialDigitOdd;
bool _serialHasVowel;

Bomb::Bomb(int batteries, std::string serial, std::vector<std::string> ports, std::vector<std::string> litIndicators, std::vector<std::string> unlitIndicators) {
    _strikes = 0;
    _batteries = batteries;
    _serial = serial;
    _ports = ports;
    _litIndicators = litIndicators;
    _unlitIndicators = unlitIndicators;

    Initialize();
}

void Bomb::Initialize() {
    IsLastSerialDigitOdd(_serial);
    serialHasVowel(_serial);
    SetPorts(_ports);
}

void Bomb::IsLastSerialDigitOdd(std::string serial) {
    if ((serial[(serial.length() - 1)] % 2) == 0) {
        lastSerialDigitOdd = true;
    }

    lastSerialDigitOdd = false;
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

const std::vector<std::string> passwords({
    "about", "after", "again", "below", "could", "every", "first", "found", "great", "house",
    "large", "learn", "never", "other", "place", "plant", "point", "right", "small", "sound",
    "spell", "still", "study", "their", "there", "these", "thing", "think", "three", "water",
    "where", "which", "world", "would", "write"
});
const std::vector<std::string> morseWords({
    "shell", "halls", "slick", "trick", "boxes", "leaks", "strobe", "bistro",
    "flick", "bombs", "break", "brick", "steak", "sting", "vector", "beats"
});
*/

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }

    return elems;
}

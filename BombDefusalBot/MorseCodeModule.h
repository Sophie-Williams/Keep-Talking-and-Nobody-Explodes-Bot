#include "Bomb.h"

namespace Bomb
{
    class MorseCodeModule {
    private:
        static const std::unordered_map<std::string, char> morseToLetters;
        static const std::vector<std::string> morseWords;
        static const std::vector<std::string> MorseCodeModule::morseFrequencies;

    public:
        std::string solveMorseModule(std::vector<std::string> letters);
    };
}
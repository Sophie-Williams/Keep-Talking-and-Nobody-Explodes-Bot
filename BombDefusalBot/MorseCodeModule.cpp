#include "MorseCodeModule.h"

const std::unordered_map<std::string, char> MorseCodeModule::morseToLetters({
    { "sl", 'a' }, { "lsss", 'b' }, { "lsls", 'c' }, { "lss", 'd' }, { "s", 'e' }, { "ssls", 'f' }, { "lls", 'g' },
    { "ssss", 'h' }, { "ss", 'i' }, { "slll", 'j' }, { "lsl", 'k' }, { "slss", 'l' }, { "ll", 'm' }, { "ls", 'n' },
    { "lll", 'o' }, { "slls", 'p' }, { "llsl", 'q' }, { "sls", 'r' }, { "sss", 's' }, { "l", 't' }, { "ssl", 'u' },
    { "sssl", 'v' }, { "sll", 'w' }, { "lssl", 'x' }, { "lsll", 'y' }, { "llss", 'z' }
});

const std::vector<std::string> MorseCodeModule::morseWords({
    "beats", "bistro", "bombs", "boxes", "break", "brick", "flick", "halls", 
    "leaks", "shell", "slick", "steak", "sting", "strobe", "trick", "vector"
});

const std::vector<std::string> MorseCodeModule::morseFrequencies({
    "3.600", "3.552", "3.565", "3.535", "3.572", "3.575", "3.555", "3.515",
    "3.542", "3.505", "3.522", "3.582", "3.592", "3.545", "3.532", "3.595"
});

std::string MorseCodeModule::solveMorseModule(const std::vector<std::string> lettersInMorse) {
    size_t size = lettersInMorse.size();
    _ASSERT(size >= 3 && size <= 6);

    bool morseMatches[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    // Break out early point
    int potentialWords = morseWords.size();
    for (size_t i = 0; i < size; ++i) {
        char letter = morseToLetters.at(lettersInMorse[i]);

        int matchPosition = -1;
        for (size_t j = 0; j < morseWords.size(); ++j) {
            if (morseMatches[j] && (letter != morseWords[j][i])) {
                morseMatches[j] = 0;
                --potentialWords;
            }
            else if (morseMatches[j]) {
                matchPosition = j;

                if (potentialWords == 1) {
                    _ASSERT((matchPosition >= 0) && (matchPosition <= (int)morseWords.size()));
                    return morseFrequencies[matchPosition];
                }
            }
           
        }
    }

    // This should be unreachable code indicating a parsing error
    _ASSERT(false);

    return "error";
}

#include "Bomb.h"

#define DIAL_LETTERS 6 // TODO: move to bomb.h
#define NUMBER_OF_PASSWORDS 35

class PasswordModule {
private:
    const std::string passwords[NUMBER_OF_PASSWORDS] = {
        "about", "after", "again", "below", "could", "every", "first", "found", "great", "house",
        "large", "learn", "never", "other", "place", "plant", "point", "right", "small", "sound",
        "spell", "still", "study", "their", "there", "these", "thing", "think", "three", "water",
        "where", "which", "world", "would", "write"
    };
    int potentialPasswords = NUMBER_OF_PASSWORDS;
    int matchPosition = -1;
    bool passwordMatches[NUMBER_OF_PASSWORDS] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

public:
    std::string PasswordModule::solvePasswordModule(const std::string dialLetters, const int dial);
};
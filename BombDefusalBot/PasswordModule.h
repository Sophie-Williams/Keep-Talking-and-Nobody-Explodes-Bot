#include "Bomb.h"

class PasswordModule {
private:
    const std::string passwords[NUMBER_OF_PASSWORDS] = {
        "about", "after", "again", "below", "could", "every", "first", "found", "great", "house",
        "large", "learn", "never", "other", "place", "plant", "point", "right", "small", "sound",
        "spell", "still", "study", "their", "there", "these", "thing", "think", "three", "water",
        "where", "which", "world", "would", "write"
    };

public:
    std::string PasswordModule::solvePasswordModule(const int dialPosition, const std::string dialLetters);
    void clear();
};

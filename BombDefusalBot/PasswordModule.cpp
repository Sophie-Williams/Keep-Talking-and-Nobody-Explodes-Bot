#include "PasswordModule.h"

std::string PasswordModule::solvePasswordModule(const std::string dialLetters, const int dial) {
    _ASSERT(dialLetters.size() == DIAL_LETTERS);
    _ASSERT((dial >= 1) && (dial <= 5));
    int dialOffset = (dial - 1);

    for (size_t i = 0; i < NUMBER_OF_PASSWORDS; ++i)
    {
        if (passwordMatches[i]) {
            bool match = false;
            for (int j = 0; j < dialLetters.size(); ++j) {
                if (passwords[i][dialOffset] == dialLetters[j]) {
                    matchPosition = i;
                    match = true;
                    break;
                }
            }

            if (!match) {
                passwordMatches[i] = 0;
                --potentialPasswords;
            }
        }
    }

    if (potentialPasswords == 1) {
        _ASSERT((matchPosition >= 0) && (matchPosition < NUMBER_OF_PASSWORDS));

        return passwords[matchPosition];
    }
    else {
        return "More dials needed!";
    }

    // This should be unreachable code indicating a parsing error
    _ASSERT(false);

    return "error";
}

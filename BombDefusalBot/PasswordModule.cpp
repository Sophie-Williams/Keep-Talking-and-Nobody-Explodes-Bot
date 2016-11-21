#include "PasswordModule.h"

namespace Bomb
{
    unsigned short potentialPasswords = NUMBER_OF_PASSWORDS;
    short matchPosition = -1;
    bool passwordMatches[NUMBER_OF_PASSWORDS] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    std::string PasswordModule::solvePasswordModule(const int dialPosition, const std::string dialLetters) {
        _ASSERT(dialLetters.size() == DIAL_LETTERS);
        _ASSERT((dialPosition >= 1) && (dialPosition <= 5));
        int dialOffset = (dialPosition - 1);

        for (size_t i = 0; i < NUMBER_OF_PASSWORDS; ++i)
        {
            if (passwordMatches[i]) {
                bool match = false;
                for (size_t j = 0; j < dialLetters.size(); ++j) {
                    if (passwords[i][dialOffset] == dialLetters[j]) {
                        matchPosition = (short)i;
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
            return "";
        }

        // This should be unreachable code indicating a parsing error
        _ASSERT(false);

        return "error";
    }

    void PasswordModule::clear() {
        potentialPasswords = NUMBER_OF_PASSWORDS;
        matchPosition = -1;
        for (int i = 0; i < NUMBER_OF_PASSWORDS; ++i)
        {
            passwordMatches[i] = 1;
        }
    }
}

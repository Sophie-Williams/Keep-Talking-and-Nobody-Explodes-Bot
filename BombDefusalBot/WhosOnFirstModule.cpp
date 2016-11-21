#include "WhosOnFirstModule.h"

namespace Bomb
{
    const std::unordered_map<std::string, std::string> displayTextsToPositions({
        { "yes", "middle left" }, { "first", "top right" }, { "display", "bottom right" },
        { "okay", "top right" }, { "says", "bottom right" }, { "nothing", "middle left" },
        { "null", "bottom left" }, { "blank", "middle right" }, { "no", "bottom right" },
        { "led", "middle left" }, { "lead", "bottom right" }, { "read", "middle right" },
        { "red", "middle right" }, { "reed", "bottom left" }, { "leed", "bottom left" },
        { "hold on", "bottom right" }, { "you", "middle right" }, { "you are", "bottom right" },
        { "your", "middle right" }, { "you're", "middle right" }, { "ur", "top left" },
        { "there", "bottom right" }, { "they're", "bottom left" }, { "their", "middle right" },
        { "they are", "middle left" }, { "see", "bottom right" }, { "c", "top right" }, { "cee", "bottom right" }
    });

    const std::unordered_map<std::string, std::vector<std::string> > wordsToWordLists({
        { "ready", std::vector<std::string>({ "yes", "okay", "what", "middle", "left", "press", "right", "blank", "ready" }) },
        { "first", std::vector<std::string>({ "left", "okay", "yes", "middle", "no", "right", "nothing", "uhhh", "wait", "ready", "blank", "what", "press", "first" }) },
        { "no", std::vector<std::string>({ "blank", "uhhh", "wait", "first", "what", "ready", "right", "yes", "nothing", "left", "press", "okay", "no" }) },
        { "blank", std::vector<std::string>({ "wait", "right", "okay", "middle", "blank" }) },
        { "nothing", std::vector<std::string>({ "uhhh", "right", "okay", "middle", "yes", "blank", "no", "press", "left", "what", "wait", "first", "nothing" }) },
        { "yes", std::vector<std::string>({ "okay", "right", "uhhh", "middle", "first", "what", "press", "ready", "nothing", "yes" }) },
        { "what", std::vector<std::string>({ "uhhh", "what" }) },
        { "uhhh", std::vector<std::string>({ "ready", "nothing", "left", "what", "okay", "yes", "right", "no", "press", "blank", "uhhh" }) },
        { "left", std::vector<std::string>({ "right", "left" }) },
        { "right", std::vector<std::string>({ "yes", "nothing", "ready", "press", "no", "wait", "what", "right" }) },
        { "middle", std::vector<std::string>({ "blank", "ready", "okay", "what", "nothing", "press", "no", "wait", "left", "middle" }) },
        { "okay", std::vector<std::string>({ "middle", "no", "first", "yes", "uhhh", "nothing", "wait", "okay" }) },
        { "wait", std::vector<std::string>({ "uhhh", "no", "blank", "okay", "yes", "left", "first", "press", "what", "wait" }) },
        { "press", std::vector<std::string>({ "right", "middle", "yes", "ready", "press" }) },
        { "you", std::vector<std::string>({ "sure", "you are", "your", "you're", "next", "uh huh", "ur", "hold", "what?", "you" }) },
        { "you are", std::vector<std::string>({ "your", "next", "like", "uh huh", "what?", "done", "uh uh", "hold", "you", "u", "you're", "sure", "ur", "you are" }) },
        { "your", std::vector<std::string>({ "uh uh", "you are", "uh huh", "your" }) },
        { "you're", std::vector<std::string>({ "you", "you're" }) },
        { "ur", std::vector<std::string>({ "done", "u", "ur" }) },
        { "u", std::vector<std::string>({ "uh huh", "sure", "next", "what?", "you're", "ur", "uh uh", "done", "u" }) },
        { "uh huh", std::vector<std::string>({ "uh huh" }) },
        { "uh uh", std::vector<std::string>({ "ur", "u", "you are", "you're", "next", "uh uh" }) },
        { "what?", std::vector<std::string>({ "you", "hold", "you're", "your", "u", "done", "uh uh", "like", "you are", "uh huh", "ur", "next", "what?" }) },
        { "done", std::vector<std::string>({ "sure", "uh huh", "next", "what?", "your", "ur", "you're", "hold", "like", "you", "u", "you are", "uh uh", "done" }) },
        { "next", std::vector<std::string>({ "what?", "uh huh", "uh uh", "your", "hold", "sure", "next" }) },
        { "hold", std::vector<std::string>({ "you are", "u", "done", "uh uh", "you", "ur", "sure", "what?", "you're", "next", "hold" }) },
        { "sure", std::vector<std::string>({ "you are", "done", "like", "you're", "you", "hold", "uh huh", "ur", "sure" }) },
        { "like", std::vector<std::string>({ "you're", "next", "u", "ur", "hold", "done", "uh uh", "what?", "uh huh", "you", "like" }) }
    });

    std::string WhosOnFirstModule::solveWhosOnFirstModuleButtonPosition(const std::string displayText) {
        return displayTextsToPositions.at(displayText);
    }

    std::vector<std::string> WhosOnFirstModule::solveWhosOnFirstModuleWordList(const std::string buttonText) {
        return wordsToWordLists.at(buttonText);
    }
}

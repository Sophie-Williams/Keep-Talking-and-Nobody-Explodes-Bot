#include "Bomb.h"
#include "ButtonModule.h"
#include "BasicWiresModule.h"
#include "KeypadModule.h"
#include "SimonSaysModule.h"
#include "WhosOnFirstModule.h"
#include "MemoryModule.h"
#include "MorseCodeModule.h"
#include "ComplicatedWiresModule.h"
#include "WireSequenceModule.h"
#include "PasswordModule.h"
#include "KnobModule.h"

int main(int argc, char* argv[])
{
    int batteries;
    std::cout << "Number of batteries:" << std::endl;
    std::cin >> batteries;
    std::cin.ignore();

    std::string serial;
    std::cout << "Serial:" << std::endl;
    std::getline(std::cin, serial);

    std::vector<std::string> ports;
    std::string port;
    std::cout << "Enter all the ports, followed by 'done'" << std::endl;
    while (1) {
        std::getline(std::cin, port);

        if (port == "done") {
            break;
        }

        ports.push_back(port);
    }

    std::vector<std::string> litIndicators;
    std::string indicator;
    std::cout << "Enter all the lit indicators, followed by 'done'" << std::endl;
    while (1) {
        std::getline(std::cin, indicator);

        if (indicator == "done") {
            break;
        }

        litIndicators.push_back(indicator);
    }

    Bomb *bomb = new Bomb(batteries, serial, ports, litIndicators, std::vector<std::string>());

    /*
    // Button
    std::string buttonColor;
    std::string buttonText;
    std::cout << "Enter button color:" << std::endl;
    std::getline(std::cin, buttonColor);
    std::cout << "Enter button text:" << std::endl;
    std::getline(std::cin, buttonText);

    ButtonModule *buttonModule = new ButtonModule();
    std::cout << buttonModule->solveButtonModule(buttonColor, buttonText) << std::endl;
    std::cout << "Enter button strip color:" << std::endl;
    std::string buttonStripColor;
    std::getline(std::cin, buttonStripColor);
    std::cout << buttonModule->solveButtonModuleColorStrip(buttonStripColor) << std::endl;
    */

    /*
    // Basic Wires
    std::vector<std::string> wires;
    std::string wire;
    std::cout << "Please enter the wires, followed by 'done': " << std::endl;
    while (1) {
        std::getline(std::cin, wire);

        if (wire == "done") {
            break;
        }

        wires.push_back(wire);
    }

    BasicWiresModule *basicWiresModule = new BasicWiresModule();
    std::cout << basicWiresModule->solveBasicWiresModule(wires) << std::endl;
    */

    /*
    // Keypad
    while (1) {
        std::vector<std::string> symbols;
        std::string symbol;
        std::cout << "Please enter the symbols, followed by 'done': " << std::endl;
        while (1) {
            std::getline(std::cin, symbol);

            if (symbol == "done") {
                break;
            }

            symbols.push_back(symbol);
        }

        KeypadModule *keypadModule = new KeypadModule();
        std::vector<std::string> orderedSymbols = keypadModule->solveSymbolsModule(symbols);
        for (std::string sym : orderedSymbols) {
            std::cout << sym << std::endl;
        }
    }
    */

    /*
    while (1) {
        while (1) {
            std::string color;
            std::cout << "Please enter the color: " << std::endl;
            std::getline(std::cin, color);

            if (color == "done") {
                break;
            }

            SimonSaysModule *simonSaysModule = new SimonSaysModule();
            std::vector<std::string> result = simonSaysModule->solveSimonSaysModule(color);
            for (std::string color : result) {
                std::cout << color << " ";
            }
        }
    }
    */

    /*
    WhosOnFirstModule *whosOnFirstModule = new WhosOnFirstModule();
    while (1) {
        while (1) {
            std::string displayText;
            std::cout << "Please enter the display word: " << std::endl;
            std::getline(std::cin, displayText);

            if (displayText == "done") {
                break;
            }

            std::cout << whosOnFirstModule->solveWhosOnFirstModuleButtonPosition(displayText) << std::endl;
            std::cout << "Please enter the button text:" << std::endl;
            std::string buttonText;
            std::getline(std::cin, buttonText);

            if (buttonText == "done") {
                break;
            }

            std::vector<std::string> wordList = whosOnFirstModule->solveWhosOnFirstModuleWordList(buttonText);
            for (std::string text : wordList) {
                std::cout << text << ", ";
            }

            std::cout << std::endl;
        }
    }
    */
    
    /*
    MemoryModule *memoryModule = new MemoryModule();
    unsigned short numbers[5] = { 0 };
    int count = 1;
    while (1) {
        std::string numbersString;
        std::cout << "Please enter the four button numbers followed by the display number: " << std::endl;
        std::getline(std::cin, numbersString);

        if (numbersString == "done") {
            break;
        }

        std::vector<std::string> nums;
        split(numbersString, ',', nums);

        for (size_t i = 0; i < (nums.size() - 1); ++i) {
            numbers[i+1] = std::stoi(nums[i]);
        }
        numbers[0] = std::stoi(nums[nums.size() - 1]);

        std::cout << memoryModule->solveMemoryModule(numbers, count);
        ++count;
    }
    */

    /*
    MorseCodeModule *morseCodeModule = new MorseCodeModule();
    while (1) {
        std::string morseCode;
        std::cout << "Please enter the morse code letters separated by spaces" << std::endl;
        std::getline(std::cin, morseCode);

        std::vector<std::string> lettersInMorse;
        split(morseCode, ' ', lettersInMorse);

        std::cout << morseCodeModule->solveMorseModule(lettersInMorse) << std::endl;
        std::cout << std::endl;
    }
    */

    /*
    ComplicatedWiresModule *complicatedWiresModule = new ComplicatedWiresModule();
    while (1) {
        std::vector<std::string> complicatedWires;
        std::string complicatedWire;
        std::cout << "Please enter each complicated wire, with comma separated properties, followed by done:" << std::endl;

        while (1) {
            std::getline(std::cin, complicatedWire);

            if (complicatedWire == "done") {
                break;
            }

            complicatedWires.push_back(complicatedWire);
        }

        std::vector<bool> wires = complicatedWiresModule->solveComplicatedWiresModule(complicatedWires);
        for (bool wire : wires) {
            if (wire) {
                std::cout << "CUT" << std::endl;
            }
            else {
                std::cout << "DO NOT CUT" << std::endl;
            }
        }
    }
    */

    /*
    WireSequenceModule *wireSequenceModule = new WireSequenceModule();
    while (1) {
        std::vector<std::string> colors, endpoints;

        while (1) {
            std::cout << "Please enter the each wire color followed by its connection point, and then done:" << std::endl;
            std::string wireConnection;
            std::getline(std::cin, wireConnection);

            if (wireConnection == "done") {
                break;
            }

            std::vector<std::string> wireSequence;
            split(wireConnection, ',', wireSequence);
            colors.push_back(wireSequence[0]);
            endpoints.push_back(wireSequence[1]);
        }

        std::vector<bool> wires = wireSequenceModule->solveWireSequenceModule(colors, endpoints);
        for (bool wire : wires) {
            if (wire) {
                std::cout << "CUT" << std::endl;
            }
            else {
                std::cout << "DO NOT CUT" << std::endl;
            }
        }
    }*/
    
    /*
    PasswordModule *passwordModule = new PasswordModule();
    while (1) {
        std::cout << "Please enter the password dial number:" << std::endl;
        int dial;
        std::cin >> dial;
        std::cin.ignore();
        std::cout << "Please enter the letters on the dial: " << std::endl;
        std::string dialLetters;
        std::getline(std::cin, dialLetters);

        std::string password = passwordModule->solvePasswordModule(dialLetters, dial);
        std::cout << password << std::endl;

        if (password != "More dials needed!") {
            break;
        }
    }*/

    KnobModule *knobModule = new KnobModule();
    while (1) {
        std::cout << "Please enter the knob configuration in binary:" << std::endl;
        std::string ledConfiguration;
        std::getline(std::cin, ledConfiguration);

        std::cout << knobModule->solveKnobModule(ledConfiguration) << std::endl;
    }


    return 0;
}
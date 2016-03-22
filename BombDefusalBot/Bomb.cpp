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
#include "MazeModule.h"
#include "PasswordModule.h"
#include "KnobModule.h"

int _strikes;
int _batteries;
std::string _serial;
std::vector<std::string> _ports;
std::vector<std::string> _litIndicators;
std::vector<bool> _existingPorts(6, 0);
bool _lastSerialDigitOdd;
bool _serialHasVowel;

Bomb::Bomb() {}

void Bomb::initializeBomb() {
    std::string bombProperty;

    while (1) {
        std::cout << "Please enter a bomb property followed by its values, separated by spaces: ";
        std::getline(std::cin, bombProperty);

        std::vector<std::string> bombProperties;
        split(bombProperty, bombProperties);

        if (bombProperties[0] == "batteries") {
            try {
                _batteries = convertTextToInteger(bombProperties[1]);
            }
            catch (std::invalid_argument invalidArgumentException) {
                std::cout << "Invalid number of batteries entered. Please enter a valid number of batteries." << std::endl;
            }
        }
        else if (bombProperties[0] == "serial") {
            _serial = bombProperties[1];
        }
        else if (bombProperties[0] == "ports") {
            _ports = std::vector<std::string>(bombProperties.begin() + 1, bombProperties.end());
        }
        else if (bombProperties[0] == "indicators") {
            _litIndicators = std::vector<std::string>(bombProperties.begin() + 1, bombProperties.end());
        }
        else if (bombProperties[0] == "done") {
            break;
        }
        else if (bombProperties[0] == "strike") {
            ++_strikes;
        }
        else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    if (_strikes == NULL) {
        _strikes = 0;
    }

    if (_lastSerialDigitOdd == NULL) {
        isLastSerialDigitOdd(_serial);
    }
    
    if (_serialHasVowel == NULL) {
        doesSerialHaveVowel(_serial);
    }
    
    if (_ports.empty()) {
        setPorts(_ports);
    }
}

void Bomb::isLastSerialDigitOdd(std::string serial) {
    _ASSERT_EXPR(serial.length() == 6, "Invalid serial!");

    if ((serial[(serial.length() - 1)] % 2) == 0) {
        _lastSerialDigitOdd = false;
        return;
    }

    _lastSerialDigitOdd = true;
}

void Bomb::doesSerialHaveVowel(std::string serial) {
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
            return;
        }
    }

    _serialHasVowel = false;
}

void Bomb::setPorts(std::vector<std::string> ports) {
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
        else {
            _ASSERT_EXPR(false, "Invalid port type!");
        }
    }
}

void Bomb::handleCommands() {
    std::string unparsedCommand;

    while (unparsedCommand != "quit") {
        std::cout << "Please enter a command: ";
        std::getline(std::cin, unparsedCommand);

        short parsedCommand = parseCommand(unparsedCommand);

        switch (parsedCommand) {
        case QUIT:
            return;
            break;
        case INITIALIZE:
            initializeBomb();
            break;
        case BASIC_WIRES:
            handleBasicWiresModule();
            break;
        case BUTTON:
            handleButtonModule();
            break;
        case KEYPAD:
            handleKeypadModule();
            break;
        case SIMON_SAYS:
            handleSimonSaysModule();
            break;
        case WHOS_ON_FIRST:
            handleWhosOnFirstModule();
            break;
        case MEMORY:
            handleMemoryModule();
            break;
        case MORSE_CODE:
            handleMorseCodeModule();
            break;
        case COMPLICATED_WIRES:
            handleComplicatedWiresModule();
            break;
        case WIRE_SEQUENCE:
            handleWireSequenceModule();
            break;
        case MAZE:
            handleMazeModule();
            break;
        case PASSWORD:
            handlePasswordModule();
            break;
        case KNOB:
            handleKnobModule();
            break;
        default:
            break;
        }
    }
    
    _ASSERT_EXPR(false, "Unreachable code");
}

short Bomb::parseCommand(std::string unparsedCommand) {
    if ((unparsedCommand == "quit") || (unparsedCommand == "exit")) {
        return -1;
    }
    else if (unparsedCommand == "start") {
        return 0;
    }
    else if (unparsedCommand == "wires") {
        return 1;
    }
    else if (unparsedCommand == "button") {
        return 2;
    }
    else if (unparsedCommand == "symbols") {
        return 3;
    }
    else if (unparsedCommand == "simon") {
        return 4;
    }
    else if (unparsedCommand == "whos") {
        return 5;
    }
    else if (unparsedCommand == "memory") {
        return 6;
    }
    else if (unparsedCommand == "morse") {
        return 7;
    }
    else if (unparsedCommand == "complex") {
        return 8;
    }
    else if (unparsedCommand == "sequence") {
        return 9;
    }
    else if (unparsedCommand == "maze") {
        return 10;
    }
    else if (unparsedCommand == "password") {
        return 11;
    }
    else if (unparsedCommand == "knob") {
        return 12;
    }
    else {
        std::cout << "Invalid command. Please enter a valid command." << std::endl;
        return SHRT_MIN;
    }

    _ASSERT_EXPR(false, "Unreachable code");
    return SHRT_MIN;
}

int Bomb::convertTextToInteger(std::string word) {
    if (word == "zero") {
        return 0;
    }
    else if (word == "one") {
        return 1;
    }
    else if (word == "two") {
        return 2;
    }
    else if (word == "three") {
        return 3;
    }
    else if (word == "four") {
        return 4;
    }
    else if (word == "five") {
        return 5;
    }
    else if (word == "six") {
        return 6;
    }
    else if (word == "seven") {
        return 7;
    }
    else if (word == "eight") {
        return 8;
    }
    else if (word == "nine") {
        return 9;
    }
    else {
        _ASSERT_EXPR(false, "Unreachable code");
        return -1;
    }

    _ASSERT_EXPR(false, "Unreachable code");
    return -1;
}

void Bomb::handleBasicWiresModule() {
    std::string wire;
    std::vector<std::string> wires;
    
    std::cout << "Please enter the wire colors separated by spaces: ";
    std::getline(std::cin, wire);
    split(wire, wires);

    BasicWiresModule *basicWiresModule = new BasicWiresModule();
    std::cout << "Cut: " << basicWiresModule->solveBasicWiresModule(wires) << std::endl;

    delete(basicWiresModule);
}

void Bomb::handleButtonModule() {
    std::string button;
    std::vector<std::string> buttonProperties;
    
    std::cout << "Please enter the button color and text separated by a space: ";
    std::getline(std::cin, button);
    split(button, buttonProperties);

    ButtonModule *buttonModule = new ButtonModule();
    std::cout << "Button action: " << buttonModule->solveButtonModule(buttonProperties[0], buttonProperties[1]) << std::endl;
    
    delete(buttonModule);
}

void Bomb::handleKeypadModule() {
    std::string keypad;
    std::vector<std::string> symbols;

    std::cout << "Please enter the keypad symbols separated by spaces: ";
    std::getline(std::cin, keypad);
    split(keypad, symbols);

    KeypadModule *keypadModule = new KeypadModule();
    std::vector<std::string> orderedSymbols = keypadModule->solveSymbolsModule(symbols);
    
    std::cout << "Press the symbols in this order: ";
    for (std::string symbol : orderedSymbols) {
        std::cout << symbol << std::endl;
    }
    
    delete(keypadModule);
}

void Bomb::handleSimonSaysModule() {
    std::string color;

    std::cout << "Please enter the color, or blank to start over: ";
    std::getline(std::cin, color);

    SimonSaysModule *simonSaysModule = new SimonSaysModule();
    if (color == "new") {
        simonSaysModule->clear();
        return;
    }

    std::vector<std::string> responseColors = simonSaysModule->solveSimonSaysModule(color);
    
    std::cout << "Press the following colors in this order: ";
    for (std::string color : responseColors) {
        std::cout << color << std::endl;
    }

    delete(simonSaysModule);
}

void Bomb::handleWhosOnFirstModule() {
    std::string displayText, buttonText;

    std::cout << "Please enter the display text: ";
    std::getline(std::cin, displayText);

    WhosOnFirstModule *whosOnFirstModule = new WhosOnFirstModule();
    std::cout << "Please enter the button text at position: " << whosOnFirstModule->solveWhosOnFirstModuleButtonPosition(displayText) << ": ";
    std::getline(std::cin, buttonText);

    std::vector<std::string> orderedResponses = whosOnFirstModule->solveWhosOnFirstModuleWordList(buttonText);

    std::cout << "Please select the first word in this list: ";
    for (std::string response : orderedResponses) {
        std::cout << response << ", ";
    }
    std::cout << std::endl;

    delete(whosOnFirstModule);
}

void Bomb::handleMemoryModule() {
    if ((currentMemoryStep < 1) || (currentMemoryStep > 5)) {
        currentMemoryStep = 1;
    }
    
    std::string numbersString;
    std::vector<std::string> textNumbers;

    std::cout << "Please enter the button numbers followed by the display number separated by spaces, or blank to start over: ";
    std::getline(std::cin, numbersString);
    if (numbersString == "") {
        currentMemoryStep = 0;
        return;
    }

    split(numbersString, textNumbers);

    unsigned short numbers[5] = { 0 };
    for (size_t i = 0; i < (textNumbers.size() - 1); ++i) {
        numbers[i + 1] = convertTextToInteger(textNumbers[i]);
    }
    numbers[0] = convertTextToInteger(textNumbers[textNumbers.size() - 1]);

    MemoryModule *memoryModule = new MemoryModule();
    std::cout << "Press the button with label : " << memoryModule->solveMemoryModule(numbers, currentMemoryStep) << std::endl;
    ++currentMemoryStep;

    delete(memoryModule);
}

void Bomb::handleMorseCodeModule() {
    std::string morseCode;
    std::vector<std::string> lettersInMorse;

    std::cout << "Please enter the morse code letters separated by spaces: ";
    std::getline(std::cin, morseCode);
    split(morseCode, lettersInMorse);

    MorseCodeModule *morseCodeModule = new MorseCodeModule();
    std::cout << "Please set the frequency to: " << morseCodeModule->solveMorseModule(lettersInMorse) << std::endl;

    delete(morseCodeModule);
}

void Bomb::handleComplicatedWiresModule() {
    std::string complicatedWire;
    std::vector<std::string> complicatedWires;

    std::cout << "Please enter each complicated wire, with comma separated properties, separated by spaces: ";
    std::getline(std::cin, complicatedWire);
    split(complicatedWire, complicatedWires);

    ComplicatedWiresModule *complicatedWiresModule = new ComplicatedWiresModule();
    std::vector<bool> wires = complicatedWiresModule->solveComplicatedWiresModule(complicatedWires);
    
    std::cout << "Please cut the wires indicated below" << std::endl;
    for (bool wire : wires) {
        if (wire) {
            std::cout << "CUT" << std::endl;
        }
        else {
            std::cout << "DO NOT CUT" << std::endl;
        }
    }

    delete(complicatedWiresModule);
}

void Bomb::handleWireSequenceModule() {
    std::string wireConnection;
    std::vector<std::string> wireConnections;

    std::cout << "Please enter each wire property separated by a comma, with each wire separated by a space, or nothing to start over: ";
    std::getline(std::cin, wireConnection);
    
    WireSequenceModule *wireSequenceModule = new WireSequenceModule();
    if (wireConnection == "") {
        wireSequenceModule->reset();
        return;
    }

    split(wireConnection, wireConnections);

    std::vector<std::string> colors, endpoints;
    for (std::string wire : wireConnections) {
        std::vector<std::string> wireProperties;
        split(wire, wireProperties, ',');
        colors.push_back(wireProperties[0]);
        endpoints.push_back(wireProperties[1]);
    }

    std::vector<bool> wires = wireSequenceModule->solveWireSequenceModule(colors, endpoints);

    std::cout << "Please cut the wires indicated below" << std::endl;
    for (bool wire : wires) {
        if (wire) {
            std::cout << "CUT" << std::endl;
        }
        else {
            std::cout << "DO NOT CUT" << std::endl;
        }
    }

    delete(wireSequenceModule);
}

void Bomb::handleMazeModule() {
    std::string mazeCoordinateString;
    std::vector<std::string> mazeCoordinates;

    std::cout << "Please enter the maze circle coordinates, square coordinates, and triangle coordinates." << std::endl
        << "Each pair should take the form <x,y>, and each coordinate pair should be separated by a space: ";
    std::getline(std::cin, mazeCoordinateString);
    split(mazeCoordinateString, mazeCoordinates);

    MazeModule *mazeModule = new MazeModule();
    std::cout << "Follow this path" << std::endl;
    mazeModule->solveMazeModule(mazeCoordinates[0], mazeCoordinates[1], mazeCoordinates[2]);

    delete(mazeModule);
}

void Bomb::handlePasswordModule() {
    int dialPosition;
    std::string dialLetters;

    std::cout << "Please enter the password dial position, or -1 to clear: ";
    std::cin >> dialPosition;
    std::cin.ignore();
    
    PasswordModule *passwordModule = new PasswordModule();
    if (dialPosition == -1) {
        passwordModule->clear();
        return;
    }

    std::cout << "Please enter the letters on the dial: ";
    std::getline(std::cin, dialLetters);

    std::string password = passwordModule->solvePasswordModule(dialPosition, dialLetters);
    if (password == "") {
        std::cout << "More dials needed!" << std::endl;
    }
    else {
        std::cout << "The password is: " << password << std::endl;
    }

    delete(passwordModule);
}

void Bomb::handleKnobModule() {
    std::string ledConfiguration;

    std::cout << "Please enter the knob configuration in binary: ";
    std::getline(std::cin, ledConfiguration);

    KnobModule *knobModule = new KnobModule();
    std::cout << "Please turn the knob to position: " << knobModule->solveKnobModule(ledConfiguration) << std::endl;

    delete(knobModule);
}

int main(int argc, char* argv[])
{
    Bomb *bomb = new Bomb();
    bomb->handleCommands();
    std::cout << "Bomb defused!" << std::endl;

    bool playAgain = false;
    do {
        std::string yesOrNo;
        std::cout << "Would you like to defuse another bomb? Y/N: ";
        std::getline(std::cin, yesOrNo);

        if (tolower(yesOrNo[0]) == 'y') {
            bomb->handleCommands();
            playAgain = true;
        }
        else {
            playAgain = false;
        }
    } while (playAgain);

    delete(bomb);
    bomb = nullptr;

    return 0;
}

std::vector<std::string> &split(const std::string &s, std::vector<std::string> &elems, char delim) {
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }

    return elems;
}

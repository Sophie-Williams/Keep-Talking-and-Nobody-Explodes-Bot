#include "Bomb.h"
#include "ButtonModule.h"
#include "BasicWiresModule.h"
#include "KeypadModule.h"
#include "SimonSaysModule.h"

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

    return 0;
}
#include "Bomb.h"

namespace Bomb
{
    class ComplicatedWiresModule {
    private:
        struct ComplicatedWire {
            bool led = false;
            bool star = false;
            std::string color;
        };

        std::vector<ComplicatedWire> ComplicatedWiresModule::parseWires(const std::vector<std::string> wires);

    public:
        std::vector<bool> ComplicatedWiresModule::solveComplicatedWiresModule(const std::vector<std::string> unparsedWires);
    };
}

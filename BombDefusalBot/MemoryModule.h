#include "Bomb.h"

class MemoryModule {
private:
    static unsigned short memoryPositions[4];
    static unsigned short memoryValues[4];
    static unsigned short SIZE;

    unsigned short calculateMemoryButtonPositionFromLabel(const unsigned short numbers[5], const unsigned short label);

public:
    unsigned short solveMemoryModule(const unsigned short numbers[5], const unsigned short stage);
};
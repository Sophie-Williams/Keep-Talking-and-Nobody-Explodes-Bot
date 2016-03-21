#include "MemoryModule.h"

unsigned short MemoryModule::memoryPositions[4] = { 0 };
unsigned short MemoryModule::memoryValues[4] = { 0 };
unsigned short MemoryModule::SIZE = 4;

unsigned short MemoryModule::solveMemoryModule(const unsigned short numbers[5], const unsigned short stage) {
    _ASSERT((stage > 0) && (stage < 6));

    for (int i = 0; i < (sizeof(numbers) / sizeof(unsigned short)); ++i) {
        _ASSERT((numbers[i] >= 1) && (numbers[i] <= 4));
    }

    switch (stage) {
    case 1:
        if ((numbers[0] == 1) || (numbers[0] == 2)) {
            memoryPositions[0] = 2;
            memoryValues[0] = numbers[2];
        }
        else if (numbers[0] == 3) {
            memoryPositions[0] = 3;
            memoryValues[0] = numbers[3];
        }
        else if (numbers[0] == 4) {
            memoryPositions[0] = 4;
            memoryValues[0] = numbers[4];
        }
        return memoryValues[0];
    case 2:
        if (numbers[0] == 1) {
            memoryPositions[1] = calculateMemoryButtonPositionFromLabel(numbers, 4);
            memoryValues[1] = 4;
        }
        else if ((numbers[0] == 2) || (numbers[0] == 4)) {
            memoryPositions[1] = memoryPositions[0];
            memoryValues[1] = numbers[memoryPositions[1]];
        }
        else if (numbers[0] == 3) {
            memoryPositions[1] = 1;
            memoryValues[1] = numbers[1];
        }
        return memoryValues[1];
    case 3:
        if (numbers[0] == 1) {
            memoryPositions[2] = calculateMemoryButtonPositionFromLabel(numbers, memoryValues[1]);
            memoryValues[2] = memoryValues[1];
        }
        else if (numbers[0] == 2) {
            memoryPositions[2] = calculateMemoryButtonPositionFromLabel(numbers, memoryValues[0]);
            memoryValues[2] = memoryValues[0];
        }
        else if (numbers[0] == 3) {
            memoryPositions[2] = 3;
            memoryValues[2] = numbers[3];
        }
        else if (numbers[0] == 4) {
            memoryPositions[2] = calculateMemoryButtonPositionFromLabel(numbers, 4);
            memoryValues[2] = 4;
        }
        return memoryValues[2];
    case 4:
        if (numbers[0] == 1) {
            memoryPositions[3] = memoryPositions[0];
            memoryValues[3] = numbers[memoryPositions[3]];
        }
        else if (numbers[0] == 2) {
            memoryPositions[3] = 1;
            memoryValues[3] = numbers[1];
        }
        else if ((numbers[0] == 3) || (numbers[0] == 4)) {
            memoryPositions[3] = memoryPositions[1];
            memoryValues[3] = numbers[memoryPositions[3]];
        }
        return memoryValues[3];
    case 5:
        if (numbers[0] == 1) {
            return  memoryValues[0];
        }
        if (numbers[0] == 2) {
            return memoryValues[1];
        }
        if (numbers[0] == 3) {
            return memoryValues[3];
        }
        if (numbers[0] == 4) {
            return numbers, memoryValues[2];
        }
    }

    // This should be unreachable code indicating a parsing error
    _ASSERT(false);

    return USHRT_MAX;
}

unsigned short MemoryModule::calculateMemoryButtonPositionFromLabel(const unsigned short numbers[5], const unsigned short label) {
    for (int i = 1; i <= SIZE; ++i) {
        if (label == numbers[i]) {
            return i;
        }
    }

    // This should be unreachable code indicating a parsing error
    _ASSERT(false);

    return USHRT_MAX;
}

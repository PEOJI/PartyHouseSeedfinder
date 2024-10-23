#include <cmath>
#include <cstdint>
using namespace std;
uint64_t rngState1 = -1;
uint64_t rngState2 = -1;

uint64_t rngRandom()
{
    rngState1 = (65192 * (rngState1 & 65535)) + ((rngState1 & 4294901760) >> 16);
    rngState2 = (64473 * (rngState2 & 65535)) + ((rngState2 & 4294901760) >> 16);
    uint64_t result = (((rngState1 & 65535) << 16) + rngState2) & 4294967295;

    return result;
}

void rngSetSeed(int seed)
{
    uint64_t mask = 1431655765;
    rngState1 = 1253089769 ^ (seed & mask);
    rngState2 = 2342871706 ^ (seed & ~mask);

    for (int i = 0; i < 20; i++)
    {
        rngRandom();
    }
}

int rngRandomInt(int lowerBound, int upperBound)
{
    int range = (upperBound - lowerBound) + 1;

    long double scaled_value = (range * rngRandom()) / 4294967296.0;

    int _r = lowerBound + std::floor(scaled_value);

    return _r;
}
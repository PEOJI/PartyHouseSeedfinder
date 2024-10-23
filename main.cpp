#include <iostream>
#include "genScenario.hpp"
using namespace std;

int main()
{
    int characterArray[13];

    rngSetSeed(123456);
    randomScenario(characterArray);

    for (int character : characterArray)
    {
        cout << getCharacterString(character) << endl;
    }
    return 0;
}
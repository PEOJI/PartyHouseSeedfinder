#include <cstdint>
#include "random.hpp"
using namespace std;

const int CHAR_COOL_BUDDY_M = 1;
const int CHAR_COOL_BUDDY_M_2 = 2;
const int CHAR_COOL_BUDDY_F = 3;
const int CHAR_COOL_BUDDY_F_2 = 4;
const int CHAR_RICH_FRIEND_M = 5;
const int CHAR_RICH_FRIEND_F = 6;
const int CHAR_WILD_FRIEND_M = 7;
const int CHAR_WILD_FRIEND_F = 8;
const int CHAR_WILD_FRIEND_M_2 = 9;
const int CHAR_WILD_FRIEND_F_2 = 10;
const int CHAR_START = 11;
const int CHAR_DANCER = 11;
const int CHAR_HIPPY = 12;
const int CHAR_CUTE_DOG = 13;
const int CHAR_SECURITY = 14;
const int CHAR_WRESTLER = 15;
const int CHAR_DOG = 16;
const int CHAR_SPY = 17;
const int CHAR_DRIVER = 18;
const int CHAR_PRIVATE_I = 19;
const int CHAR_GRILLMASTER = 20;
const int CHAR_ATHLETE = 21;
const int CHAR_MR_POPULAR = 22;
const int CHAR_CELEBRITY = 23;
const int CHAR_COMEDIAN = 24;
const int CHAR_PHOTOGRAPHER = 25;
const int CHAR_CATERER = 26;
const int CHAR_TICKET_TAKER = 27;
const int CHAR_AUCTIONEER = 28;
const int CHAR_MONKEY = 29;
const int CHAR_ROCK_STAR = 30;
const int CHAR_GANGSTER = 31;
const int CHAR_GAMBLER = 32;
const int CHAR_WEREWOLF = 33;
const int CHAR_MASCOT = 34;
const int CHAR_INTROVERT = 35;
const int CHAR_COUNSELOR = 36;
const int CHAR_STYLIST = 37;
const int CHAR_BARTENDER = 38;
const int CHAR_WRITER = 39;
const int CHAR_CLIMBER = 40;
const int CHAR_CUPID = 41;
const int CHAR_MAGICIAN = 42;
const int CHAR_HOST = 43;
const int CHAR_CHEERLEADER = 44;
const int CHAR_END = 44;
const int CHAR_PRESTIGE_START = 50;
const int CHAR_ALIEN = 50;
const int CHAR_DINOSAUR = 51;
const int CHAR_LEPRECHAUN = 52;
const int CHAR_GENIE = 53;
const int CHAR_MERMAID = 54;
const int CHAR_DRAGON = 55;
const int CHAR_GHOST = 56;
const int CHAR_UNICORN = 57;
const int CHAR_SUPERHERO = 58;
const int CHAR_PRESTIGE_END = 58;
const int NUM_CHARACTERS = (CHAR_PRESTIGE_END - CHAR_PRESTIGE_START) + 1 + (CHAR_END - CHAR_START) + 1 + 3;
const int CHAR_THE_HOST = 59;

string getCharacterString(int character)
{
    switch (character)
    {
    case CHAR_DANCER:
        return "Dancer";
    case CHAR_HIPPY:
        return "Hippy";
    case CHAR_CUTE_DOG:
        return "Cute Dog";
    case CHAR_SECURITY:
        return "Security";
    case CHAR_WRESTLER:
        return "Wrestler";
    case CHAR_DOG:
        return "Dog";
    case CHAR_SPY:
        return "Spy";
    case CHAR_DRIVER:
        return "Driver";
    case CHAR_PRIVATE_I:
        return "Private I";
    case CHAR_GRILLMASTER:
        return "Grillmaster";
    case CHAR_ATHLETE:
        return "Athlete";
    case CHAR_MR_POPULAR:
        return "Mr Popular";
    case CHAR_CELEBRITY:
        return "Celebrity";
    case CHAR_COMEDIAN:
        return "Comedian";
    case CHAR_PHOTOGRAPHER:
        return "Photographer";
    case CHAR_CATERER:
        return "Caterer";
    case CHAR_TICKET_TAKER:
        return "Ticket Taker";
    case CHAR_AUCTIONEER:
        return "Auctioneer";
    case CHAR_MONKEY:
        return "Monkey";
    case CHAR_ROCK_STAR:
        return "Rock Star";
    case CHAR_GANGSTER:
        return "Gangster";
    case CHAR_GAMBLER:
        return "Gambler";
    case CHAR_WEREWOLF:
        return "Werewolf";
    case CHAR_MASCOT:
        return "Mascot";
    case CHAR_INTROVERT:
        return "Introvert";
    case CHAR_COUNSELOR:
        return "Counselor";
    case CHAR_STYLIST:
        return "Stylist";
    case CHAR_BARTENDER:
        return "Bartender";
    case CHAR_WRITER:
        return "Writer";
    case CHAR_CLIMBER:
        return "Climber";
    case CHAR_CUPID:
        return "Cupid";
    case CHAR_MAGICIAN:
        return "Magician";
    case CHAR_HOST:
        return "Greeter";
    case CHAR_CHEERLEADER:
        return "Cheerleader";
    case CHAR_ALIEN:
        return "Alien";
    case CHAR_DINOSAUR:
        return "Dinosaur";
    case CHAR_LEPRECHAUN:
        return "Leprechaun";
    case CHAR_GENIE:
        return "Genie";
    case CHAR_MERMAID:
        return "Mermaid";
    case CHAR_DRAGON:
        return "Dragon";
    case CHAR_GHOST:
        return "Ghost";
    case CHAR_UNICORN:
        return "Unicorn";
    case CHAR_SUPERHERO:
        return "Superhero";
    default:
        return "woops";
    }
}

bool randomScenario(int characterArray[13])
{
    int numRegChars, numPrestigeChars, i, newChar, j;
    bool unique;

    numRegChars = 11;
    numPrestigeChars = 13 - numRegChars;

    for (int i = 0; i < numRegChars; i++)
    {
        do
        {
            unique = true;
            newChar = rngRandomInt(CHAR_START, CHAR_END);

            for (int j = 0; j < i; j++)
            {
                if (characterArray[j] == newChar)
                {
                    unique = false;
                    break;
                }
            }
        } while (!unique);

        characterArray[i] = newChar;
        rngRandom();
    }

    for (int i = numRegChars; i < 13; i++)
    {
        do
        {
            unique = true;
            newChar = rngRandomInt(CHAR_PRESTIGE_START, CHAR_PRESTIGE_END);

            for (int j = numRegChars; j < i; j++)
            {
                if (characterArray[j] == newChar)
                {
                    unique = false;
                    break;
                }
            }
        } while (!unique);

        characterArray[i] = newChar;
        rngRandom();
    }
    return true;
}
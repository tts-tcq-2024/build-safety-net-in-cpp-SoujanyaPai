#include "Soundex.h"
#include <cctype>
#include <string>

std::string generateSoundex(const std::string& name)
{
    std::string soundexCode(1, toupper(name[0]));

    int matchCount = 1;
    int codeCount = 1;
    while((matchCount < name.length()) && (codeCount < 4))
    {
        if(((name[matchCount] == 'b') || (name[matchCount] == 'p') || (name[matchCount] == 'v') || (name[matchCount] == 'f')) && (soundexCode[codeCount-1] != 1))
        {
            soundexCode[codeCount] = '1';
            codeCount++;
        }
        else if(((name[matchCount] == 'c') || (name[matchCount] == 'g') || (name[matchCount] == 'j') || (name[matchCount] == 'k') || (name[matchCount] == 'q') || (name[matchCount] == 's') || (name[matchCount] == 'x') || (name[matchCount] == 'z')) && (soundexCode[codeCount-1] != 2))
        {
            soundexCode[codeCount] = '2';
            codeCount++;
        }
        else if(((name[matchCount] == 'd') || (name[matchCount] == 't')) && (soundexCode[codeCount-1] != 3))
        {
            soundexCode[codeCount] = '3';
            codeCount++;
        }
        else if((name[matchCount] == 'l') && (soundexCode[codeCount-1] != 4))
        {
            soundexCode[codeCount] = '4';
            codeCount++;
        }
        else if(((name[matchCount] == 'm') || (name[matchCount] == 'n')) && (soundexCode[codeCount-1] != 5))
        {
            soundexCode[codeCount] = '5';
            codeCount++;
        }
        else if((name[matchCount] == 'r') && (soundexCode[codeCount-1] != 6))
        {
            soundexCode[codeCount] = '6';
            codeCount++;
        }
        matchCount++;
    }

    while(codeCount < 4)
    {
        soundexCode[codeCount] = 0;
        codeCount++;
    }
    soundexCode[4] = '\0';

    return soundexCode;
}

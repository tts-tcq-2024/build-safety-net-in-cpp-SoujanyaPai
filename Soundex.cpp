#include "Soundex.h"
#include <cctype>
#include <string>

char getSoundexCode(char c) {
    static const char soundexArray[26] = {
        '0', // A
        '1', // B
        '2', // C
        '0', // D
        '0', // E
        '1', // F
        '2', // G
        '0', // H
        '0', // I
        '1', // J
        '2', // K
        '0', // L
        '0', // M
        '5', // N
        '0', // O
        '1', // P
        '0', // Q
        '0', // R
        '2', // S
        '3', // T
        '0', // U
        '1', // V
        '0', // W
        '0', // X
        '2', // Y
        '2'  // Z
    };

    if (std::isalpha(c)) {
        c = toupper(c);
        return soundexArray[c - 'A'];
    }
    return '0';
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }
    soundex.resize(4, '0');
    return soundex;
}

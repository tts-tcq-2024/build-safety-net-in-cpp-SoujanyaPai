#include "Soundex.h"
#include <unordered_map>
#include <cctype>
#include <string>

char getSoundexCode(char c) {
    static const std::unordered_map<char, char> soundexMap = {
        {'A', '0'}, {'B', '1'}, {'C', '2'}, {'D', '0'}, {'E', '0'},
        {'F', '1'}, {'G', '2'}, {'H', '0'}, {'I', '0'}, {'J', '1'},
        {'K', '2'}, {'L', '0'}, {'M', '0'}, {'N', '5'}, {'O', '0'},
        {'P', '1'}, {'Q', '0'}, {'R', '0'}, {'S', '2'}, {'T', '3'},
        {'U', '0'}, {'V', '1'}, {'W', '0'}, {'X', '0'}, {'Y', '2'},
        {'Z', '2'}
    };
    c = std::toupper(c);
    auto it = soundexMap.find(c);
    return (it != soundexMap.end()) ? it->second : '0';
}

bool isCodeValid(char code, char prevCode) {
    return code != '0' && code != prevCode;
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (isCodeValid(code, prevCode)) {
            soundex += code;
            prevCode = code;
        }
    }
    soundex.resize(4, '0');
    return soundex;
}

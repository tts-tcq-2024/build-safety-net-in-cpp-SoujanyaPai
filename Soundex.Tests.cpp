#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, HandlesSimpleCases) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
    EXPECT_EQ(generateSoundex("Rubin"), "R150");
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("Ashcroft"), "A261");
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
    EXPECT_EQ(generateSoundex("Pfister"), "P236");
}

// Test for a string with all vowels
TEST(SoundexTest, HandlesAllVowels) {
    EXPECT_EQ(generateSoundex("AEIOU"), "A000");
}

// Test for a string with mixed characters
TEST(SoundexTest, HandlesMixedCharacters) {
    EXPECT_EQ(generateSoundex("A1B2C3"), "A123");
}

// Test for a string with uppercase and lowercase letters
TEST(SoundexTest, HandlesCaseInsensitivity) {
    EXPECT_EQ(generateSoundex("robert"), "R163");
    EXPECT_EQ(generateSoundex("ROBERT"), "R163");
}

// Test for a string with numbers
TEST(SoundexTest, HandlesNumbers) {
    EXPECT_EQ(generateSoundex("12345"), "0000");
}

// Test for a string with special characters
TEST(SoundexTest, HandlesSpecialCharacters) {
    EXPECT_EQ(generateSoundex("R@b#e$t"), "R123");
}

// Test for a string where the first letter is followed by identical letters
TEST(SoundexTest, HandlesIdenticalFollowingLetters) {
    EXPECT_EQ(generateSoundex("AABBB"), "A120");
    EXPECT_EQ(generateSoundex("BBA"), "B100");
}

// Test for strings that should result in the same Soundex code
TEST(SoundexTest, HandlesSimilarSoundexCodes) {
    EXPECT_EQ(generateSoundex("Rover"), "R130");
    EXPECT_EQ(generateSoundex("Rov"), "R130");
}

// Test for varying lengths of Soundex codes
TEST(SoundexTest, HandlesVariableLength) {
    EXPECT_EQ(generateSoundex("Robert", 5), "R1630");
    EXPECT_EQ(generateSoundex("Ashcroft", 6), "A2610");
    EXPECT_EQ(generateSoundex("Rubin", 3), "R15");
}

// Test for strings with mixed upper and lower cases
TEST(SoundexTest, HandlesMixedCases) {
    EXPECT_EQ(generateSoundex("RoBeRt"), "R163");
    EXPECT_EQ(generateSoundex("aSHcRoFt"), "A261");
}

// Test for strings that should be truncated
TEST(SoundexTest, HandlesStringTruncation) {
    EXPECT_EQ(generateSoundex("abcdefghij"), "A121");
    EXPECT_EQ(generateSoundex("abcdefghij", 3), "A121");
    EXPECT_EQ(generateSoundex("abcdefghij", 6), "A1210");
}


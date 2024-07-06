#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, HandlesSimpleCases) {
    EXPECT_EQ(generateSoundex("Robert"), "R130");
    EXPECT_EQ(generateSoundex("Rupert"), "R130");
    EXPECT_EQ(generateSoundex("Rubin"), "R150");
    EXPECT_EQ(generateSoundex("Ashcraft"), "A213");
    EXPECT_EQ(generateSoundex("Ashcroft"), "A213");
    EXPECT_EQ(generateSoundex("Tymczak"), "T200");
    EXPECT_EQ(generateSoundex("Pfister"), "P230");
}

TEST(SoundexTest, HandlesNameWithDuplicates) {
    EXPECT_EQ(generateSoundex("Aardvark"), "A120");
    EXPECT_EQ(generateSoundex("Bookkeeper"), "B210");
}

TEST(SoundexTest, HandlesNameWithAllVowels) {
    EXPECT_EQ(generateSoundex("Aeiou"), "A000");
}

TEST(SoundexTest, HandlesNameWithMixedCases) {
    EXPECT_EQ(generateSoundex("roBErt"), "R130");
    EXPECT_EQ(generateSoundex("RuPErt"), "R130");
}

TEST(SoundexTest, HandlesNamesThatMapToSameCode) {
    EXPECT_EQ(generateSoundex("Robert"), generateSoundex("Rupert"));
    EXPECT_EQ(generateSoundex("Ashcraft"), generateSoundex("Ashcroft"));
}

TEST(SoundexTest, HandlesNameThatRequiresPadding) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("R"), "R000");
    EXPECT_EQ(generateSoundex("Ra"), "R000");
    EXPECT_EQ(generateSoundex("Ray"), "R200");
}

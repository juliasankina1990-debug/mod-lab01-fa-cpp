// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>

unsigned int faStr1(const char *str) {
    if (!str) return 0;
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;

    for (const char *p = str; *p; ++p) {
        if (std::isspace(static_cast<unsigned char>(*p))) {
            if (inWord && !hasDigit) ++count;
            inWord = false;
            hasDigit = false;
        } else {
            if (!inWord) {
                inWord = true;
                hasDigit = false;
            }
            if (std::isdigit(static_cast<unsigned char>(*p))) hasDigit = true;
        }
    }
    if (inWord && !hasDigit) ++count;
    return count;
}

unsigned int faStr2(const char *str) {
    if (!str) return 0;
    unsigned int count = 0;
    bool inWord = false;
    bool good = true;
    bool firstChar = true;

    for (const char *p = str; *p; ++p) {
        if (std::isspace(static_cast<unsigned char>(*p))) {
            if (inWord && good) ++count;
            inWord = false;
            good = true;
            firstChar = true;
        } else {
            if (!inWord) {
                inWord = true;
                good = true;
                firstChar = true;
            }
            if (firstChar) {
                if (!std::isupper(static_cast<unsigned char>(*p))) good = false;
                firstChar = false;
            } else {
                if (!std::islower(static_cast<unsigned char>(*p))) good = false;
            }
        }
    }
    if (inWord && good) ++count;
    return count;
}

unsigned int faStr3(const char *str) {
    if (!str) return 0;
    unsigned int totalLen = 0;
    unsigned int wordCount = 0;
    bool inWord = false;
    unsigned int curLen = 0;

    for (const char *p = str; *p; ++p) {
        if (std::isspace(static_cast<unsigned char>(*p))) {
            if (inWord) {
                totalLen += curLen;
                ++wordCount;
                inWord = false;
                curLen = 0;
            }
        } else {
            if (!inWord) {
                inWord = true;
                curLen = 0;
            }
            ++curLen;
        }
    }
    if (inWord) {
        totalLen += curLen;
        ++wordCount;
    }
    if (wordCount == 0) return 0;
    double avg = static_cast<double>(totalLen) / wordCount;
    return static_cast<unsigned int>(avg + 0.5);
}

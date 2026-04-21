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
    return 0; // stub
}

unsigned int faStr3(const char *str) {
    return 0; // stub
}
